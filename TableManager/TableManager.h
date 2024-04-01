#include <iostream>
#include <vector>
#include"..\\Three_avl\Three_avl.h"
#include"..\\UnorderedTable_arr\UnorderedTable_arr.h"
#include "..\\Table_arr\Table_arr.h"
#include "..\\Base_Table\Base_Table.h"
#include "..\\polinomlib\TMonom.h"
#include "..\\polinomlib\TPolinom.h"
using namespace std;

// �������� ������
template <typename TKey, typename TValue>
class TableManager {
private:
   vector<Base_Table<TKey, TValue>*> tables;

public:
    // �������� ������� � ��������
    void AddTable(Base_Table<TKey, TValue>* table) {
        tables.push_back(table);
    }

    // �������� ������� � ��������� �������
    void InsertElement(int tableIndex, TKey key, TValue value) {
        if (tableIndex >= 0 && tableIndex < tables.size())
            tables[tableIndex]->Insert(key, value);
        else
            cout << "Error: Table index out of range" << endl;
    }

    // ������� ������� � ��������� �������
    void DeleteElement(int tableIndex, TKey key) {
        if (tableIndex >= 0 && tableIndex < tables.size())
            tables[tableIndex]->Delete(key);
        else
            cout << "Error: Table index out of range" << endl;
    }

    void ResetElement(int tableIndex) {
        if (tableIndex >= 0 && tableIndex < tables.size())
            tables[tableIndex]->Reset();
        else
            cout << "Error: Table index out of range" << endl;
    }

    // ����� �������
    void FindElement(int tableIndex, TKey key) 
    {
        if (tableIndex >= 0 && tableIndex < tables.size())
            tables[tableIndex]->Find(key, value);
        else
            cout << "Error: Table index out of range" << endl;
    }

    void IsFullElement(int tableIndex) 
    {
        if (tableIndex >= 0 && tableIndex < tables.size())
            if (tables[tableIndex]->IsFull() == 0)cout << "� ������� ��� ���� �����" << endl;
            else cout << "������� ������";
        else
            cout << "Error: Table index out of range" << endl;
    }
    // ������� ���������� ��������� �������
    void PrintTable(int tableIndex) {
        if (tableIndex >= 0 && tableIndex < tables.size()) {
            cout << "����������� � �������:" << endl;
            cout << *tables[tableIndex] << endl;
        }
        else {
            cout << "Error: Table index out of range" << endl;
        }
    }

};

template <typename TKey, typename TValue>
ostream& operator<<(ostream& os, const Base_Table<TKey, TValue>& table) {
    return table.Print(os);
}
