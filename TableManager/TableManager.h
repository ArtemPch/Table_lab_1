#include <iostream>
#include <vector>

#include "..\\Table_arr\Table_arr.h"
#include "..\\Base_Table\Base_Table.h"
#include "..\\polinomlib\TMonom.h"
#include "..\\polinomlib\TPolinom.h"

// �������� ������
template <typename TKey, typename TValue>
class TableManager {
private:
    std::vector<Base_Table<TKey, TValue>*> tables;

public:
    // �������� ������� � ��������
    void AddTable(Base_Table<TKey, TValue>* table) {
        tables.push_back(table);
    }

    // �������� ������� � ��������� �������
    void InsertElement(int tableIndex, TKey key, const TValue& value) {
        if (tableIndex >= 0 && tableIndex < tables.size()) {
            tables[tableIndex]->Insert(key, value);
        }
        else {
            std::cout << "Error: Table index out of range" << std::endl;
        }
    }

    // ������� ���������� ��������� �������
    void PrintTable(int tableIndex) {
        if (tableIndex >= 0 && tableIndex < tables.size()) {
            std::cout << "Table content:" << std::endl;
            std::cout << *tables[tableIndex] << std::endl;
        }
        else {
            std::cout << "Error: Table index out of range" << std::endl;
        }
    }

    // ������ ������, ����� ��� �������� �������� �� ������� � �. �.
};

