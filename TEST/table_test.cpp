#include <gtest.h>
#include "..\\TableManager\TableManager.h"

TEST(ProbingHashTableTest, InsertAndFind) {
    ProbingHashTable<int, std::string> table;

    // ��������� �������
    table.Insert(1, "One");

    // ���������, ��� ������� ������
    EXPECT_NE(table.Find(1), nullptr);
    EXPECT_EQ(*table.Find(1), "One");

    // ���������, ��� �������, �������� ���, �� ������
    EXPECT_EQ(table.Find(2), nullptr);
}

// ���� �������� ���������� ��������
TEST(ProbingHashTableTest, Update) {
    ProbingHashTable<int, std::string> table;

    // ��������� �������
    table.Insert(1, "One");

    // ��������� �������� ��������
    table.Insert(1, "New One");

    // ���������, ��� �������� ���������
    EXPECT_NE(table.Find(1), nullptr);
    EXPECT_EQ(*table.Find(1), "New One");
}

// ���� �������� �������� ��������
TEST(ProbingHashTableTest, Delete) {
    ProbingHashTable<int, std::string> table;

    // ��������� �������
    table.Insert(1, "One");

    // ������� �������
    table.Delete(1);

    // ���������, ��� ������� ������ �� ������
    EXPECT_EQ(table.Find(1), nullptr);
}
