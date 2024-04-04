#include <iostream>
#include "..\\TableManager\TableManager.h"
using namespace std;



int main() {
    setlocale(LC_ALL, "ru");
    TableManager<int, TPolinom> manager;

   
    UnorderedTable_mas<int, TPolinom> table1;
    SortArrayTable<int, TPolinom> table2;
    AVL_Tree<int, TPolinom> table3;
    ProbingHashTable<int, TPolinom>table4;
    ChainingHashTable<int, TPolinom>table5;
    Unordered_Table<int, TPolinom>table6;
    manager.AddTable(&table1);
    manager.AddTable(&table2);
    manager.AddTable(&table3);
    manager.AddTable(&table4);
    manager.AddTable(&table5);
    manager.AddTable(&table6);

    
    TPolinom p1, p2,p3,p4;
    TMonom a(3.22, 2, 2, 1);
    TMonom b(2.5, 1, 3, 3);
    TMonom c(3.4, 2, 4, 4);
    TMonom d(4.22, 2, 2, 3);
    TMonom e(2.5, 3, 7, 7);
    p2.AddMonom(d);
    p2.AddMonom(e);
    p1.AddMonom(a);
    p1.AddMonom(b);
    p1.AddMonom(c);
    p3.AddMonom(a);
    p3.AddMonom(b);
    p4.AddMonom(a);
    p4.AddMonom(e);

    int choice;
    typedef int TKey; // �������� ��� ������ int �� ��������������� ��� �����
    typedef TPolinom TValue; // �������� TPolinom �� ��������������� ��� ��������
    TKey key;
    TValue value;

    do {
        cout << "�������� ��������:" << endl;
        cout << "1. �������� �������" << endl;
        cout << "2. ������� �������" << endl;
        cout << "3. �������� ��� �������" << endl;
        cout << "4. ����� �������" << endl;
        cout << "5. ���������, ��������� �� ������� ���������" << endl;
        cout << "6. ������� ��� �������" << endl;
        cout << "7. ������� ���������� �������" << endl;
        cout << "0. ����� �� ���������" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "������� ���� � �������� ��� ����������:" << endl;
            cin >> key >> value;
            manager.InsertElement(key, value);
            break;
        case 2:
            cout << "������� ���� ��� �������� ��������:" << endl;
            cin >> key;
            manager.DeleteElement(key);
            break;
        case 3:
            manager.ResetAllTables();
            break;
        case 4:
            cout << "������� ���� ��� ������:" << endl;
            cin >> key;
            manager.FindElement(key);
            break;
        case 5:
            manager.IsFullElement();
            break;
        case 6:
            manager.PrintAllTables();
            break;
        case 7:
            int tableIndex;
            cout << "������� ������ ������� ��� ������:" << endl;
            cin >> tableIndex;
            manager.PrintTable(tableIndex);
            break;
        case 0:
            cout << "����� �� ���������." << endl;
            break;
        default:
            cout << "�������� �����. ���������� ��� ���." << endl;
        }
    } while (choice != 0);

    return 0;
}