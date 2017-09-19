#include "bin_search.h"
#include <gtest/gtest.h>

#include <vector>

TEST(Sort, sort)
{
    using vector = std::vector<int>;

    vector vec{10, 20};
    sort(vec);
    vector expected{10, 20};
    ASSERT_EQ(expected, vec);
}

TEST(BinSearch, bin_search)
{
    using vector = std::vector<int>;

    vector vec{10, 20};
    int *res = bin_search(vec, 15);
    ASSERT_FALSE(res);
}
