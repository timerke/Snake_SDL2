/*
���� � ������������ ������������ � ���������� ��������.
*/

#include "const.h"

const char FILE_NAME[] = "snake_records.txt"; // ��� �����, � ������� ������������ ������� ����
const char FONT[] = "consola.ttf"; // ������������ �����
const int BLOCK_SIZE = 30; // ������ ������ �����/������ �� ����������� � ��������� �� ������� ����
const int HEIGHT = 530; // ������ ���� ����������
const int WIDTH = 500; // ������ ���� ����������
const int FONT_MENU_SIZE = 15; // ������ ������ ����
const int FONT_TEXT_SIZE = 20; // ������ ������ �������� ������
const int FONT_TITLE_SIZE = 25; // ������ ������ ����������
const int INPUT_WINDOW_HEIGHT = 40; // ������ ���� �����
const int INPUT_WINDOW_WIDTH = 200; // ������ ���� �����
const int INPUT_WINDOW_Y = 300; // ���������� y �������� ������ ���� ���� �����
const int MENU_HEIGHT = 30; // ������ ����
const int MENU_ITEM_NUM = 3; // ���������� ������� � ����: �����, �������, �����
const int NAME_MAX_LENGTH = 18; // ������������ ����� �����, ������� ����� ������ ������������
const int NX = 10; // ������������ ���������� ������ �� ����������� �� ������� ����
const int NX_MIN = 5; // ����������� ���������� ������ �� ����������� �� ������� ����
const int NY = 10; // ������������ ���������� ������ �� ��������� �� ������� ����
const int NY_MIN = 5; // ����������� ���������� ������ �� ��������� �� ������� ����
const int RECORDS_MAX_NUM = 5; // ������������ ���������� ��������, ��������� �� ����� ����������
const SDL_Color BLACK = { 0, 0, 0, 0 }; // ������ ����
const SDL_Color DIM_GRAY = { 105, 105, 105, 0 }; // �����-����� ����
const SDL_Color GREEN = { 0, 128, 0, 0 }; // ������� ����
const SDL_Color RED = { 255, 0, 0, 0 }; // ������� ����
const SDL_Color WHITE = { 255, 255, 250, 0 }; // ����� ����
const SDL_Color GAME_FIELD_COLOR = { 245, 222, 179, 0 }; // ���� �������� ����
const SDL_Color INPUT_CLICKED_COLOR = { 255, 255, 255, 0 }; // ���� ���� ����� � ��������� ���������
const SDL_Color INPUT_HOVERED_COLOR = { 255, 204, 204, 0 }; // ���� ���� ����� � ���������� ���������
const SDL_Color INPUT_USUAL_COLOR = { 255, 204, 255, 0 }; // ���� ���� ����� � ������� ���������
const SDL_Color MENU_CLICKED_COLOR = { 51, 102, 102, 0 }; // ���� ������ ���� � ��������� ���������
const SDL_Color MENU_HOVERED_COLOR = { 51, 153, 153, 0 }; // ���� ������ ���� � ���������� ���������
const SDL_Color MENU_USUAL_COLOR = { 153, 204, 204, 0 }; // ���� ������ ���� � ������� ���������
const SDL_Color SCREEN_COLOR = { 153, 153, 255, 0 }; // ���� ������
const Uint32 GAME_TIME_INTERVAL = 500; // �������� ����� �������� ������� game_timer_callback �� ����� ����