/*
� ����� �������� ����������� ������� ������ Record � ������ ���������������
�������, ������� ������ ��� ������ � ������ ������ � ������������ ���� � �������� ����.
*/

#include <fstream>
#include "const.h"
#include "record.h"

// ����������� ������ Record
Record::Record()
{
}

// ����������� ������ Record
Record::Record(std::string* name, int length)
{
    set_record(name, length);
}

// ����������� ������ Record
Record::Record(Record* record)
{
    set_record(record);
}

// ����� ������ Record ������ ��� ������ � ����� ������, ���������� �������
void Record::set_record(std::string* name, int length)
{
    if (name->size() == 0)
    {
        // ���� ����� �� ���� ������� ���
        (*name) = "anonymous";

    }
    // � ������� name ������ Record �� ����� �������� ��� �� ������� (name_max_length-1)
    // (��������� ������ �� ����� ������ '\0'). ������ ����� ���������, ��� ������:
    // ����� ������ name, ���������� � �������, ��� (name_max_length-1)
    int n = name->size() < name_max_length - 1 ? name->size() : name_max_length - 1;
    int i;
    for (i = 0; i < n; i++)
    {
        this->name[i] = (*name)[i];
    }
    this->name[i] = '\0'; // ��������� ����� ������ � �����
    this->length = length;
}

// ����� ������ Record ������ ��� ������ � ����� ������, ���������� �������
void Record::set_record(Record* record)
{
    for (int i = 0; i < name_max_length; i++)
    {
        this->name[i] = record->name[i];
    }
    this->length = record->length;
}

// ��������������� ��������� ��������� ��� �������� ������ Record
bool operator == (Record r1, Record r2)
{
    if (r1.length == r2.length)
    {
        for (int i = 0; i < Record::name_max_length; i++)
        {
            if (r1.name[i] != r2.name[i])
            {
                // ���� ���� ���� ������ � �������� �������� name ���� �������� �� ������, �� ������� �� �����
                return false;
            }
            else if (r1.name[i] == r2.name[i] && r1.name[i] == '\0')
            {
                // ���� ���� ����� �� ������� ����� ������ � �������� name ����� ��������, �� ������� �����
                return true;
            }
        }
    }
    // ���� �������� �������� length �������� �� �������, �� ������� �� �����
    return false;
}

// ��������������� ��������� ����������� ��� �������� ������ Record
bool operator != (Record r1, Record r2)
{
    if (r1.length == r2.length)
    {
        for (int i = 0; i < Record::name_max_length; i++)
        {
            if (r1.name[i] != r2.name[i])
            {
                // ���� ���� ���� ������ � �������� �������� name ���� �������� �� ������, �� ������� �� �����
                return true;
            }
            else if (r1.name[i] == r2.name[i] && r1.name[i] == '\0')
            {
                // ���� ���� ����� �� ������� ����� ������ � �������� name ����� ��������, �� ������� �����
                return false;
            }
        }
    }
    // ���� �������� �������� length �������� �� �������, �� ������� �� �����
    return true;
}

// ������� selection_sort ��� ���������� �������� � ���� �� ��������. ��� ���������� ����������� ����� ������
void selection_sort(std::vector<Record*>* records)
{
    int size = records->size();
    for (int i = 0; i < size - 1; i++)
    {
        int max_i = i;
        for (int j = i + 1; j < size; j++)
        {
            if (records->at(max_i)->length < records->at(j)->length)
            {
                max_i = j;
            }
        }
        if (max_i != i)
        {
            Record* temp = records->at(i);
            records->at(i) = records->at(max_i);
            records->at(max_i) = temp;
        }
    }
}

/* ������� read_file ������ �������� ���� � �������� � ����������� ����, �������� ������ � �������
���� Record, ��������� �� ������� �������� � ������ records */
void read_file(std::vector<Record*>* records)
{
    std::ifstream file;
    file.open(FILE_NAME, std::ios::binary); // ��������� ���� � �������� ��� ������
    if (!file)
    {
        // ���� ���� �� ��� ������
        std::cout << "File with records was not opened for reading.\n";
        return;
    }
    file.seekg(0, file.end); // ������������ � ����� �����
    int n = file.tellg() / sizeof(Record); // ���������� ������� � �����
    file.seekg(0, file.beg); // ������������ � ������ �����
    int i = 0;
    while (i < n)
    {
        Record* record = new Record; // ������, � ������� ����� ������ ������ �� ��������� ����� � ���������
        file.read((char*)record, sizeof(Record)); // ������ ������ � ������ record
        records->push_back(record); // �������� ��������� �� ����������� ������ � ������ � �����������
        std::cout << i << " - " << records->at(i)->name << " - " << records->at(i)->length << "\n";
        i++;
    }
    file.close(); // ��������� ����
}

// ������� write_file ���������� ��������� ������� �� ������� records � �������� ����
void write_file(std::vector<Record*>* records)
{
    std::ofstream file;
    file.open(FILE_NAME, std::ofstream::app | std::ofstream::binary); // ��������� ���� � �������� � ����������� ���� ��� ������
    if (!file)
    {
        // ���� ���� �� ��� ������
        std::cout << "File with records was not opened for writing.\n";
        return;
    }
    // ���� ���� ��� ������
    std::cout << "write_file: " << records->at(records->size() - 1)->name << " - " << records->at(records->size() - 1)->length << std::endl;
    file.write((char*)records->at(records->size() - 1), sizeof(Record)); // ���������� � ����
    file.close(); // ��������� ����
}

/* ������� write_record ���������� ��������� ������ � ������ � ������������.
records - ������ � ������������;
name - ��� ������;
length - ��������� ������ - ����� ������ � ��������� ��������� ���� */
void write_record(std::vector<Record*>* records, std::string* name, int length)
{
    Record* record = new Record(name, length); // ������� ������ �� ���� ���� Record
    records->push_back(record); // �������� ������ � ������ � ������������ ����
    write_file(records); // ���������� ��������� ������� ������� � ������������ � ����
}