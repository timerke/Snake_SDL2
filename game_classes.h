/*
� ������������ ����� �������� ���������� ������� Game_Field, Snake � Food,
� �������� ������������ ������� �������.
*/

#pragma once
#ifndef _GAME_CLASSES_
#define _GAME_CLASSES_

#include <SDL.h>
#include <vector>

/* ��� ������������ ��� ����������� �������� ������:
down - ����;
left - �����;
right - ������;
up - �����. */
enum Direction { down, left, right, up };

// �������� ������ Game_Field
class Game_Field;

// �������� ������ Snake
class Snake;

// �������� ������ Food
class Food;

// ����� Game_Field ���������� ������� ����
class Game_Field
{
public:
    int x; // ���������� x �������� ������ ���� �������� ����
    int y; // ���������� y �������� ������ ���� �������� ����
    int height; // ������ ����� ������
    int width; // ������ ����� ������
    int nx; // ���������� ������ �� ������� ���� �� �����������
    int ny; // ���������� ������ �� ������� ���� �� ���������
    // �����������
    Game_Field();
    // ����� ����������, ����� �� ������ ��������� � �������� ��������� �� ������� ����
    bool available_position(Snake*);
    // ����� ��� ����������� �������� �������� ���� �� ��������
    void apply_texture(SDL_Renderer*);
    // ����� ������� ������� ����
    void create_field(SDL_Renderer*);
};

// ����� Snake ���������� ������ ������, ������� �������� � ����
class Snake
{
public:
    bool do_eat; // ���� true, �� ������ ����� � �� ��������� ���� ����� ��������� �� �����
    int n; // ����� ������
    int n_max; // ������������ ��������� ����� ������
    std::vector<int> i_x; // ������ � ������������ x ������ ������ �� ������� ����
    std::vector<int> i_y; // ������ � ������������ y ������ ������ �� ������� ����
    int height; // ������ ������ ����� ������
    int width; // ������ ������ ����� ������
    int i_x_for_tail; // ���������� x ������ ������; ������������, ����� ������ ������� ���
    int i_y_for_tail; // ���������� y ������ ������; ������������, ����� ������ ������� ���
    Direction direction; // ����������� �������� ������
    Direction changed_direction; // ���������� ����������� �������� ������
    // �����������
    Snake();
    // ����� ��������� �������
    bool control(Food*);
    // ����� ����������, ������ �� ����� �� ������� ���� �������
    bool is_occupied(int, int);
    // ����� ����������, ������������ �� ������ ���� � �����
    bool is_self_cross();
    // ����� ��� ����������� �������� ������ �� ��������
    void apply_texture(SDL_Renderer*, Game_Field*);
    // ����� �������� ����������� ��������
    void change_direction(Direction);
    // ����� ����������� ����� ������
    void eat(Food*);
    // ����� ����������� ������
    void move();
    // ����� ������ ��������� ������ � ������ ����
    void start(Game_Field*);
};

// ����� Food ���������� ������ ��� ��� ������
class Food
{
public:
    int i_x; // ���������� x ����� ���
    int i_y; // ���������� y ����� ���
    int height; // ������ ����� ���
    int width; // ������ ����� ���
    bool is_eaten; // ���� true, �� ��� �������
    // �����������
    Food();
    // ����� ���������� ��������� ����� ���
    bool set_position(Snake*, Game_Field*);
    // ����� ����������, ���� �� ������� ���
    bool was_eaten(Snake*, Game_Field*);
    // ����� ��� ����������� ��������� ����� ��� �� ��������
    void apply_texture(SDL_Renderer*, Game_Field*);
};

#endif // !_GAME_CLASSES_

