#pragma once

#include <vector>

void sort(int *begin, int *end);

int * bin_search(int *begin, int *end, int item);

// adapters
inline void sort(std::vector<int> &vec)
{
    int *data = vec.data();
    sort(data, data + vec.size());
}

inline int * bin_search(std::vector<int> &vec, int item)
{
    int *data = vec.data();
    return bin_search(data, data + vec.size(), item);
}
