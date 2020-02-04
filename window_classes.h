/*
� ������������ ����� �������� ���������� ������� Screen, Menu, Menu_Start, Menu_Info,
Menu_Exit, Input_Window, � �������� ������������ �������� ���������� ���� ����������.
*/

#pragma once
#ifndef _WINDOW_CLASSES_
#define _WINDOW_CLASSES_

#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <stdlib.h>
#include <vector>
#include "const.h"
#include "game_classes.h"
#include "record.h"

/* ��� ������������ ��� ������� ��������, ������� ���������� ���� ����������:
welcome_page - ��������� �������� � ������������;
game_page - �������� �� ����� ����;
info_page - �������� �� �������� �� ����;
end_page - �������� ��� ���������� ���� (��������� ������). */
enum Page { welcome_page, game_page, info_page, end_page };

/* ��� ������������ ��� ����������� ��������� �������� ���� ���������� (������� ����, ���� �����):
usual - �������;
clicked - �� ������ ���� �������� ������;
hovered - �� ����� ���� ������ ������. */
enum State { usual, clicked, hovered };

/* ��� ������������ ��� ������������� ������:
not_centered - ������� ������������, ����� ������������ �� �����;
x_centered - ����� ����� ���������� �� ������ �� �����������;
y_centered - ����� ����� ���������� �� ������ �� ���������;
xy_centered - ����� ����� ���������� �� ������ �� ����������� � ���������. */
enum Centered { not_centered, x_centered, y_centered, xy_centered };

// �������� ������ Screen
class Screen;

// �������� ������ Menu
class Menu;

// �������� ������ Menu_Exit
class Menu_Exit;

// �������� ������ Menu_Info
class Menu_Info;

// �������� ������ Menu_Start
class Menu_Start;

// �������� ������ Input_Window
class Input_Window;

// ����� Screen ���������� ����� ����������
class Screen
{
public:
    bool was_created; // ���� �� ������� �������� ��� ������ ����� ��������� � ����
    int x; // ���������� x �������� ������ ���� ������
    int y; // ���������� y �������� ������ ���� ������
    int height; // ������ ������
    int width; // ������ ������
    Page page; // ����� �������� ����� ���������� ������ ����������
    SDL_Texture* texture_end; // �������� ��� ������ ����� ���������
    SDL_Texture* texture_game; // �������� ��� ������ �� ����� ����
    SDL_Texture* texture_info; // �������� ��� ������ ��� ������ ������� �� ����
    SDL_Texture* texture_welcome; // �������� ��� ������ ��� ������� ����������
    // �����������
    Screen();
    // ����������
    ~Screen();
    // ����� ��� ����������� ������ �������� ������ �� ��������
    void apply_texture(SDL_Renderer*, std::vector<Record*>*);
    // ����� ������� �������� ��� ������ ����� ���������
    void create_end_texture(SDL_Renderer*, std::vector<Record*>*);
    // ����� ������� ��� ����������� �������� ��� ������
    void create_textures(SDL_Renderer*);
};

// ����� Menu ���������� ����� ����
class Menu
{
public:
    int x; // ���������� x �������� ������ ���� ������ ����
    int y; // ���������� y �������� ������ ���� ����� ����
    int height; // ������ ������ ����
    int width; // ������ ������ ����
    State state; // ��������� ������ ���� (�������, �� ����� ���� ������ ������ ��� ��������)
    SDL_Texture* texture; // �������� ��� ��������� ������ ���� � ������� ���������
    SDL_Texture* texture_clicked; // �������� ��� ��������� ������ ���� � ������� ���������
    SDL_Texture* texture_hovered; // �������� ��� ��������� ������ ���� ��� ��������� �� ���� ������
    // �����������
    Menu();
    // ����������
    ~Menu();
    // ����� ��� ����������� ������ �������� ������ ���� �� ��������
    void apply_texture(SDL_Renderer*);
    // ����� ������� ��� ����������� �������� ��� ������ ����
    void create_textures(SDL_Renderer*, std::string*);
    // ����� ����������, ��������� �� ����� ������ ������ ����
    bool is_in(Sint32, Sint32);
    // ����� ������ ��������� ������ ����
    void set_position(Menu*);
    // ����������� ����� ���������� ��������, ����� �������� ������ �� ������ ����
    virtual bool down(bool*, Screen*, Game_Field*, Snake*, Food*, SDL_Renderer*) = 0;
};

// ����� Menu_Exit ���������� ����� ���� �����
class Menu_Exit : public Menu
{
public:
    // �����������
    Menu_Exit();
    // ����� ���������� ��������, ����� �������� ������ �� ������ ���� �����
    bool down(bool*, Screen*, Game_Field*, Snake*, Food*, SDL_Renderer*);
};

// ����� Menu_Info ���������� ����� ���� �������
class Menu_Info : public Menu
{
public:
    // �����������
    Menu_Info();
    // ����� ���������� ��������, ����� �������� ������ �� ������ ���� �������
    bool down(bool*, Screen*, Game_Field*, Snake*, Food*, SDL_Renderer*);
};

// ����� Menu_Start ���������� ����� ���� �����
class Menu_Start : public Menu
{
public:
    // �����������
    Menu_Start();
    // ����� ���������� ��������, ����� �������� ������ �� ������ ���� �����
    bool down(bool*, Screen*, Game_Field*, Snake*, Food*, SDL_Renderer*);
};

// ����� ����_����� ���������� ������ ��� ����� ������ �������������
class Input_Window
{
public:
    int x; // ���������� x �������� ������ ���� ���� �����
    int y; // ���������� y �������� ������ ���� ���� �����
    int height; // ������ ���� �����
    int width; // ������ ���� �����
    bool is_displayed; // ���� true, �� ���� ����� ������������ �� ������ ����������
    std::string text; // �����, ��������� �������������
    std::string input_data; // ��������� ������������� ����������
    State state; // ��������� ���� ����� (�������, �� ���� ����� ������ ������ ��� ��������)
    // �����������
    Input_Window();
    // ����� ��� ����������� ������ �������� ���� ����� �� ��������
    void apply_texture(SDL_Renderer*);
    // ����� ����������, ��������� �� ����� ������ ���� �����
    bool is_in(Sint32, Sint32);
};

#endif