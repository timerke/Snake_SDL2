/*
������������ ���� � ����������� ������������ � ���������� ��������.
*/

#pragma once
#ifndef _CONST_
#define _CONST_

#include <SDL.h>

extern const char FILE_NAME[]; // ��� �����, � ������� ������������ ������� ����
extern const char FONT[]; // ������������ �����
extern const int BLOCK_SIZE; // ������ ������ ����� �� ����������� � ��������� �� ������� ����
extern const int HEIGHT; // ������ ���� ����������
extern const int WIDTH; // ������ ���� ����������
extern const int FONT_MENU_SIZE; // ������ ������ ����
extern const int FONT_TEXT_SIZE; // ������ ������ �������� ������
extern const int FONT_TITLE_SIZE; // ������ ������ ����������
extern const int INPUT_WINDOW_HEIGHT; // ������ ���� �����
extern const int INPUT_WINDOW_WIDTH; // ������ ���� �����
extern const int INPUT_WINDOW_Y; // ���������� y �������� ������ ���� ���� �����
extern const int MENU_HEIGHT; // ������ ����
extern const int MENU_ITEM_NUM; // ���������� ������� � ����: �����, �������, �����
extern const int NAME_MAX_LENGTH; // ������������ ����� �����, ������� ����� ������ ������������
extern const int NX; // ������������ ���������� ������ �� ����������� �� ������� ����
extern const int NX_MIN; // ����������� ���������� ������ �� ����������� �� ������� ����
extern const int NY; // ������������ ���������� ������ �� ��������� �� ������� ����
extern const int NY_MIN; // ����������� ���������� ������ �� ��������� �� ������� ����
extern const int RECORDS_MAX_NUM; // ������������ ���������� ��������, ��������� �� ����� ����������
extern const SDL_Color BLACK; // ������ ����
extern const SDL_Color DIM_GRAY; // �����-����� ����
extern const SDL_Color GREEN; // ������� ����
extern const SDL_Color RED; // ������� ����
extern const SDL_Color WHITE; // ����� ����
extern const SDL_Color GAME_FIELD_COLOR; // ���� �������� ����
extern const SDL_Color INPUT_CLICKED_COLOR; // ���� ���� ����� � ��������� ���������
extern const SDL_Color INPUT_HOVERED_COLOR; // ���� ���� ����� � ���������� ���������
extern const SDL_Color INPUT_USUAL_COLOR; // ���� ���� ����� � ������� ���������
extern const SDL_Color MENU_CLICKED_COLOR; // ���� ������ ���� � ��������� ���������
extern const SDL_Color MENU_HOVERED_COLOR; // ���� ������ ���� � ���������� ���������
extern const SDL_Color MENU_USUAL_COLOR; // ���� ������ ���� � ������� ���������
extern const SDL_Color SCREEN_COLOR; // ���� ������
extern const Uint32 GAME_TIME_INTERVAL; // �������� ����� �������� ������� game_timer_callback �� ����� ����

#endif // !_CONST_

