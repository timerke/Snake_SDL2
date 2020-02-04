/*
� ����� �������� ����������� ������� Game_Field, Snake � Food,
� �������� ������������ ������� �������.
*/

#include <iostream>
#include "const.h"
#include "game_classes.h"

// ����������� ������ Game_Field
Game_Field::Game_Field()
{
}

// ����� ������ Game_Filed ����������, ����� �� ������ ���������� �� ������� ���� � �������� ���������
bool Game_Field::available_position(Snake* snake)
{
    if (-1 < snake->i_x.at(0) && snake->i_x.at(0) < nx && -1 < snake->i_y.at(0) && snake->i_y.at(0) < ny)
    {
        // ������ ��������� � ��������� ����������
        return true;
    }
    return false;
}

// ����� ������ Game_Field ��� ����������� �������� �������� ���� �� ��������
void Game_Field::apply_texture(SDL_Renderer* renderer)
{
    SDL_Surface* surface = SDL_CreateRGBSurface(0, width * nx, height * ny, 32, 0, 0, 0, 0);
    // ��������� ������� ���� ����� ������
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, GAME_FIELD_COLOR.r, GAME_FIELD_COLOR.g, GAME_FIELD_COLOR.b));
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.h = height * ny;
    rect.w = width * nx;
    // ���������� ��������
    SDL_RenderCopy(renderer, texture, NULL, &rect);
    // ������������� ���� ��� ��������� �����
    SDL_SetRenderDrawColor(renderer, BLACK.r, BLACK.g, BLACK.b, SDL_ALPHA_OPAQUE);
    // ������ ������������ ����� �� ������� ����
    for (int i = 0; i <= nx; i++)
    {
        SDL_RenderDrawLine(renderer, x + height * i, y, x + width * i, y + height * ny);
    }
    // ������ �������������� ����� �� ������� ����
    for (int i = 0; i <= ny; i++)
    {
        SDL_RenderDrawLine(renderer, x, y + height * i, x + width * nx, y + height * i);
    }
    SDL_DestroyTexture(texture);
}

// ����� ������ Game_Field ������� ������� ����
void Game_Field::create_field(SDL_Renderer* renderer)
{
    nx = NX_MIN + rand() % NX; // ���������� ������ �� ����������� �� ������� ����
    ny = NY_MIN + rand() % NY; // ���������� ������ �� ��������� �� ������� ����
    height = width = BLOCK_SIZE; // ������ � ������ ����� ������ �� ������� ���� 
    x = (WIDTH - width * nx) / 2; // ���������� x �������� ������ ���� �������� ����
    y = MENU_HEIGHT + (HEIGHT - MENU_HEIGHT - height * ny) / 2; // ���������� y �������� ������ ���� �������� ����
}

// ����������� ������ Snake
Snake::Snake()
{
    height = width = BLOCK_SIZE; // ������ � ������ ������ ����� ������
}

// ����� ������ Snake ��������� ������� �� ������� ����
bool Snake::control(Food* food)
{
    move(); // ����������� ������
    eat(food); // �������, ����� �� ������ ������
    return !is_self_cross(); // ���� ������ ��������� ���� ����, ������������ false
}

// ����� ������ Snake ����������, ������ �� ����� �� ������� ���� �������
bool Snake::is_occupied(int i_x_, int i_y_)
{
    for (int i = 0; i < n; i++)
    {
        if (i_x.at(i) == i_x_ && i_y.at(i) == i_y_)
        {
            // ���� ������ �� ������� ���� ������ �������
            return true;
        }
    }
    // ���� ������ �� ������� ���� ��������
    return false;
}

// ����� ������ Snake ����������, ������������ �� ������ ���� � �����
bool Snake::is_self_cross()
{
    int x_head = i_x.at(0), y_head = i_y.at(0); // ���������� ������ ������
    for (int i = 1; i < n; i++)
    {
        if (x_head == i_x.at(i) && y_head == i_y.at(i))
        {
            // ���� ������ ������������ ���� � �����, �� ������������ true
            return true;
        }
    }
    // ������ �� ������������ ���� � �����
    return false;
}

// ����� ������ Snake ��� ����������� �������� ������ �� ��������
void Snake::apply_texture(SDL_Renderer* renderer, Game_Field* game_field)
{
    SDL_Surface* surface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
    int r, g, b;
    r = 255 * n / n_max; // �������� ������� �������� ����� ����� � RGB
    g = 255 - 255 * (n - 1) / n_max; // �������� ������� �������� ����� ����� � RGB
    b = 255 - 255 * (n - 1) / n_max; // �������� ������� ������ ����� ����� � RGB
    // ��������� ���� ������
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, r, g, b));
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_Rect rect;
    rect.h = height;
    rect.w = width;
    for (int i = 0; i < n; i++)
    {
        rect.x = i_x.at(i) * width + game_field->x;
        rect.y = i_y.at(i) * height + game_field->y;
        // ���������� ��������
        SDL_RenderCopy(renderer, texture, NULL, &rect);
    }
    SDL_DestroyTexture(texture);
}

// ����� ������ Snake �������� ����������� ��������
void Snake::change_direction(Direction new_direction)
{
    // � ��������� direction �������� �����������, � ������� ������ ��������.
    // � ��������� changed_direction �������� ���������� ����������� ��������.
    // ���� ����� ������� ����������� ��������, �� ����� ����������� ������� ������������
    // � changed_direction. ����� �������� ����� ������������� ������ (���������� ������� move),
    // �������� direction ��������� �������� changed_direction
    if (n != 1)
    {
        // ���� ����� ������ ������ 1, ��� �� ����� ������ ����������� �������� �� ���������������
        if (direction == up && new_direction == down)
        {
            return;
        }
        if (direction == down && new_direction == up)
        {
            return;
        }
        if (direction == left && new_direction == right)
        {
            return;
        }
        if (direction == right && new_direction == left)
        {
            return;
        }
    }
    changed_direction = new_direction;
}

// ����� ������ Snake ����������� ����� ������
void Snake::eat(Food* food)
{
    if (i_x.at(0) == food->i_x && i_y.at(0) == food->i_y)
    {
        // ���� ���������� ������ ������ ������� � ����������� ���, �� ����������� ����� ������ � ����������� ��������
        i_x_for_tail = i_x.at(n - 1); // ���������� ���������� ������ ������, � ��� �� ��������� ���� �������
        i_y_for_tail = i_y.at(n - 1); // �������������� ���� ��� ������
        do_eat = true; // ������ �����
        // ��� ������� �������
        food->is_eaten = true;
    }
}

// ����� ������ Snake ����������� ������
void Snake::move()
{
    int i_x_prev, i_y_prev; // ���������� �� ������� ���� ����������� ����� ������
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            direction = changed_direction; // ����������� �������� ������ �������� ���������� �������� �����������
            // �������� � ������� ������.
            // ���������� ������ ������ ����� ������������ ����������� ����� ��� ������� �����
            i_x_prev = i_x.at(i);
            i_y_prev = i_y.at(i);
            // ������ ������ �������� � ��������� �����������
            switch (direction)
            {
            case down:
            {
                i_y.at(i)++;
                break;
            }
            case up:
            {
                i_y.at(i)--;
                break;
            }
            case right:
            {
                i_x.at(i)++;
                break;
            }
            case left:
            {
                i_x.at(i)--;
                break;
            }
            }
        }
        else
        {
            // ��������� ����� ������ ������������ �� ����� ������� ������������� ������
            int x_temp = i_x.at(i);
            int y_temp = i_y.at(i);
            i_x.at(i) = i_x_prev;
            i_y.at(i) = i_y_prev;
            i_x_prev = x_temp;
            i_y_prev = y_temp;
        }
    }
    if (do_eat)
    {
        // ���� ������ ����� �� ���������� ����, �� �� ���� ���� ����� ��������� ����� ������
        i_x.push_back(i_x_prev);
        i_y.push_back(i_y_prev);
        n++;
        do_eat = false;
    }
}

// ����� ������ Snake ������ ��������� ������ � ������ ����
void Snake::start(Game_Field* game_field)
{
    n = 1; // ����� ������
    n_max = game_field->nx * game_field->ny;
    // ������������ ����, �� �������� ������� ������, ���������� �� ������ �������� ����
    i_x.clear();
    i_y.clear();
    i_x.push_back(game_field->nx / 2);
    i_y.push_back(game_field->ny / 2);
    direction = changed_direction = left; // ������ �������� ������
    do_eat = false; // ������ ��� ������ �� �����
}

// ����������� ������ Food
Food::Food()
{
    height = width = BLOCK_SIZE; // ������ � ������ ����� ���
}

// ����� ������ Food ���������� ��������� ����� ���
bool Food::set_position(Snake* snake, Game_Field* game_field)
{
    is_eaten = false; // ��� �� �������
    if (game_field->nx * game_field->ny == snake->n)
    {
        // ���� ����� ������ ����� ���������� ������ �� ������� ����
        return false;
    }
    int n = rand() % (game_field->nx * game_field->ny - snake->n); // ����� ������, � ������� ����� �������� ���
    int free_blocks = -1; // ������� ��������� ������ �� �����
    i_x = game_field->nx;
    i_y = game_field->ny;
    for (int i_y_ = 0; i_y_ < game_field->ny; i_y_++)
    {
        for (int i_x_ = 0; i_x_ < game_field->nx; i_x_++)
        {
            if (!snake->is_occupied(i_x_, i_y_))
            {
                // ���� ���� �� ������� ���� �������� �� ������
                free_blocks++;
                if (free_blocks == n)
                {
                    // ��������� ��� ��� �������
                    i_x = i_x_;
                    i_y = i_y_;
                    break;
                }
            }
        }
        if (i_x != game_field->nx)
        {
            // ���� ��������� ��� ��� ���� �������
            break;
        }
    }
    return true;
}

// ����� ������ Food ����������, ���� �� ������� ���
bool Food::was_eaten(Snake* snake, Game_Field* game_field)
{
    if (is_eaten)
    {
        // ���� ��� ���� �������, ����� ��������� ��� � ����� ���������
        return set_position(snake, game_field);
    }
    return true;
}

// ����� ������ Food ��� ����������� ����� ��� �� ��������
void Food::apply_texture(SDL_Renderer* renderer, Game_Field* game_field)
{
    SDL_Surface* surface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
    // ��������� ���� ����� ������
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, GREEN.r, GREEN.g, GREEN.b));
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_Rect rect;
    rect.x = i_x * width + game_field->x;
    rect.y = i_y * height + game_field->y;
    rect.h = height;
    rect.w = width;
    // ���������� ��������
    SDL_RenderCopy(renderer, texture, NULL, &rect);
    SDL_DestroyTexture(texture);
}