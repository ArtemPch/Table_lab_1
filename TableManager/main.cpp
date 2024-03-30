#include <iostream>
#include "..\\TableManager\TableManager.h"
using namespace std;



int main() {
    // ������� �������� ������
    TableManager<int, TPolinom> manager;

    // ������� � ��������� ������� � ��������
    SortArrayTable<int, TPolinom> table1;
    manager.AddTable(&table1);

    // ������� ��������
    TPolinom p1, p2;
    // ��������� �������� � ������� ����� ��������
    manager.InsertElement(0, 1, p1);
    manager.InsertElement(0, 2, p2);

    // ������� ���������� ������� ����� ��������
    manager.PrintTable(0);

    return 0;
}