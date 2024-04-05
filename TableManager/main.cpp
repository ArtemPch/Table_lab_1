#include <iostream>
#include "..\\TableManager\TableManager.h"
using namespace std;



int main() {
    setlocale(LC_ALL, "ru");
    TableManager<int, TPolinom> manager;

   
    UnorderedTable_mas<int, TPolinom> table1;
    SortArrayTable<int, TPolinom> table2;
    Unordered_Table<int, TPolinom>table3;
    AVL_Tree<int, TPolinom> table4;
    ProbingHashTable<int, TPolinom>table5;
    ChainingHashTable<int, TPolinom>table6;
    manager.AddTable(&table1);
    manager.AddTable(&table2);
    manager.AddTable(&table3);
    manager.AddTable(&table4);
    manager.AddTable(&table5);
    manager.AddTable(&table6);
    int choice;
    typedef int TKey; 
    typedef TPolinom TValue;

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
        TKey key;
        TValue value;
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