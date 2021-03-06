#include <algorithm>

void sort(int *begin, int *end)
{
    int length = end - begin;
    for (int i = 0; i < length; ++i)
        for (int j = 0; j < length; ++j)
            if (begin[i] < begin[j])
                std::swap(begin[i], begin[j]);
}

int * bin_search(int *begin, int *end, int item)
{
    if (begin >= end)
        return nullptr;
    int* middle = begin + ((1 + end - begin)/2);
    if (middle >= end) {
        if (begin != middle && *begin == item)
            return begin;

        return nullptr;
    }
    if (*middle == item)
        return middle;
    if (*middle < item)
        return bin_search(middle, end, item);
    if (item < *middle)
        return bin_search(begin, middle, item);
    return nullptr;
}
