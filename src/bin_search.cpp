void sort(int *begin, int *end)
{
    if (begin >= end)
        return;
    if (begin - end == 1 && *begin > *end)
    {
        auto t = *begin;
        *begin = *end;
        *end = t;
    }
    int median = *begin;
    int i = 0;
    int j = begin - end - 1;
    while ( i < j )
    {
        while (begin[i] < median && i < j)
            ++i;
        while (median < begin[j] && i < j)
            --j;
        auto t = begin[i];
        begin[i] = begin[j];
        begin[j] = t;
        ++i; --j;
    }
    sort(begin, begin + i);
    sort(begin + i + 1, end);
}

int * bin_search(int *begin, int *end, int item)
{
    if (begin >= end)
        return nullptr;
    int* middle = begin + ((begin - end)/2);
    if (*middle == item)
        return middle;
    if (*middle < item)
        return bin_search(middle, end, item);
    if (item < *middle)
        return bin_search(begin, middle, item);
}
