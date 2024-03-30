#pragma once
#include "Base_Table.h"

#include <algorithm>
#include <iostream>
#include <locale>
#include <string>
using namespace std;

template <typename TKey, typename TValue>
class SortArrayTable : public Base_Table<TKey, TValue> {
private:
    size_t currentIndex;
    struct TabRec {
        TKey key;
        TValue* value;
    };
    vector<TabRec> data{};

public:
    size_t size() const noexcept { return data.size(); }
    TValue& operator[](size_t pos) { return data[pos].value; }
    SortArrayTable() : currentIndex(0) {}

    ~SortArrayTable() {
        for (auto& tab : data) {
            delete tab.value;
        }
    }

    TValue* Find(TKey key) override {
        for (auto& val : data)
            if (val.key == key) return val.value;
        return nullptr;
    }

    void Insert(TKey key, TValue value) override {
        TValue* newValue = new TValue(value);
        TabRec tab = { key, newValue };
        data.push_back(tab);
        count++;
        sort(data.begin(), data.end(),
            [](const TabRec& a, const TabRec& b) { return a.key < b.key; });
    }

    bool IsFull() const override { return size() >= TabMaxSize; }

    void Delete(TKey key) override {
        auto it = find_if(data.begin(), data.end(), [key](const TabRec& entry) { return entry.key == key; });
        if (it != data.end()) {
            // �������� �������� �� �������
            data.erase(it);

            // ���������� �������� ������
            for (auto& entry : data) {
                if (entry.key > key) {
                    entry.key--; // ����� ������
                }
            }
        }
    }

    int Reset() override {
        currentIndex = 0;
        return currentIndex;
    }

    int IsTabEnded() const override { return currentIndex >= data.size(); }

    int GoNext() override {
        currentIndex++;
        return currentIndex;
    }

    TKey GetKey() const override { return data[currentIndex].key; }
    TValue GetValuePtr() const override { return *data[currentIndex].value; }

    ostream& Print(ostream& os) const override {
        os << "������������� ������� �� �������:" << endl;
        for (size_t i = 0; i < data.size(); ++i) {
            os << " �����: " << data[i].key << " ��������: " << *data[i].value << endl;
        }
        return os;
    }
};

template <typename TKey, typename TValue>
ostream& operator<<(ostream& os, const SortArrayTable<TKey, TValue>& table) {
    return table.Print(os);
}