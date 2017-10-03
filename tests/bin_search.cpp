#include "bin_search.h"
#include <gtest/gtest.h>

#include <vector>

TEST(Sort, sort)
{
    using vector = std::vector<int>;

    // пустой вектор
    {
        vector actual{};
        sort(actual);
        vector expected{};
        ASSERT_EQ(expected, actual);
    }

    // один элемент
    {
        vector actual{10};
        sort(actual);
        vector expected{10};
        ASSERT_EQ(expected, actual);
    }

    //  отсортированный вектор
    {
        vector actual{-10, 0, 10, 20, 30};
        sort(actual);
        vector expected{-10, 0, 10, 20, 30};
        ASSERT_EQ(expected, actual);
    }

    //  нечётное число элементов в векторе
    {
        vector actual{0, 20, -10, 10, 30};
        sort(actual);
        vector expected{-10, 0, 10, 20, 30};
        ASSERT_EQ(expected, actual);
    }

    //  чётное число элементов в векторе
    {
        vector actual{0, 20, -10, 10, 30, -30};
        sort(actual);
        vector expected{-30, -10, 0, 10, 20, 30};
        ASSERT_EQ(expected, actual);
    }
}

TEST(BinSearch, bin_search)
{
    using vector = std::vector<int>;

    // пустой массив
    {
        vector vec{};
        int *res = bin_search(vec, 10);
        ASSERT_FALSE(res);
    }

    // один элемент
    {
        vector vec{0};
        ASSERT_FALSE(bin_search(vec, 10));
        ASSERT_TRUE(bin_search(vec, 0));
        ASSERT_EQ(bin_search(vec, 0), vec.data());
    }

    // два элемента
    {
        vector vec{5, 10};

        // проверяем элементы, которые
        // находятся между -inf, 5, 10 и +inf
        ASSERT_FALSE(bin_search(vec, 0));
        ASSERT_FALSE(bin_search(vec, 7));
        ASSERT_FALSE(bin_search(vec, 12));

        // ищем 5
        ASSERT_TRUE(bin_search(vec, 5));
        ASSERT_EQ(bin_search(vec, 5), vec.data());

        // ищем 10
        ASSERT_TRUE(bin_search(vec, 10));
        ASSERT_EQ(bin_search(vec, 10), vec.data() + 1);
    }

    // три элемента
    {
        vector vec{5, 10, 15};

        // проверяем элементы, которые
        // находятся между -inf, 5, 10, 15 и +inf
        ASSERT_FALSE(bin_search(vec, 0));
        ASSERT_FALSE(bin_search(vec, 6));
        ASSERT_FALSE(bin_search(vec, 9));
        ASSERT_FALSE(bin_search(vec, 11));
        ASSERT_FALSE(bin_search(vec, 17));

        // ищем 5
        ASSERT_TRUE(bin_search(vec, 5));
        ASSERT_EQ(bin_search(vec, 5), vec.data());

        // ищем 10
        ASSERT_TRUE(bin_search(vec, 10));
        ASSERT_EQ(bin_search(vec, 10), vec.data() + 1);

        // ищем 15
        ASSERT_TRUE(bin_search(vec, 15));
        ASSERT_EQ(bin_search(vec, 15), vec.data() + 2);
    }

    // много элементов
    {
        vector vec{1, 2, 3, 4, 5, 6, 70, 80, 90, 100};

        ASSERT_FALSE(bin_search(vec, 0));
        ASSERT_FALSE(bin_search(vec, 7));
        ASSERT_FALSE(bin_search(vec, 12));
        ASSERT_FALSE(bin_search(vec, 95));

        // ищем первые 6 элементов
        for (int i = 0; i < 6; ++i) {
            int number = i + 1;
            ASSERT_TRUE(bin_search(vec, number));
            ASSERT_EQ(bin_search(vec, number), vec.data() + i);
        }

        // последние 4 элемента
        for (int i = 6; i < 10; ++i) {
            int number = (i + 1) * 10;
            ASSERT_TRUE(bin_search(vec, number));
            ASSERT_EQ(bin_search(vec, number), vec.data() + i);
        }
    }
}

