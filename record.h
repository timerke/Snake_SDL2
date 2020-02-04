/*
� ������������ ����� �������� ���������� ������ Record � ������ ��������������� �������,
������� ������ ��� ������ � ������ ������ � ������������ ���� � �������� ����.
*/

#pragma once
#ifndef _RECORD_
#define _RECORD_

#include <iostream>
#include <vector>

// ����� Record ��� ������ � �������� ����������� ����
class Record
{
public:
    static const int name_max_length = 19; // ������������ ����� ����� ������
    char name[name_max_length]; // ��� ������
    int length; // ����� ������, ����������� ������� � ����
    // ������������
    Record();
    Record(std::string*, int);
    Record(Record*);
    // ����� ������ ��� ������ � ����� ������, ���������� �������
    void set_record(std::string*, int);
    void set_record(Record*);
};
// ��������������� ��������� ��������� ��� �������� ������ Record
bool operator == (Record, Record);
// ��������������� ��������� ����������� ��� �������� ������ Record
bool operator != (Record, Record);

// ������� selection_sort ��� ���������� �������� � ���� �� ��������. ��� ���������� ����������� ����� ������
void selection_sort(std::vector<Record*>*);

/* ������� read_file ������ �������� ���� � ���������, �������� ������ � �������
���� Record, ������� �������� � ������ */
void read_file(std::vector<Record*>*);

// ������� write_file ���������� ������ �� ������� ���� Records � �������� ����
void write_file(std::vector<Record*>*);

/* ������� write_record ���������� ��������� ������ � ������ � ���������.
records - ������ � ���������;
name - ��� ������;
length - ��������� ������ - ����� ������ � ��������� ��������� ���� */
void write_record(std::vector<Record*>* records, std::string* name, int length);

#endif // !_RECORD_
