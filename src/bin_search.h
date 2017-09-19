void sort(int *begin, int *end);

int * bin_search(int *begin, int *end, int item);

// adapters
int * sort(std::vector<int> &vec)
{
    int *data = vec.data();
    sort(data, data + vec.size());
}

int * bin_search(std::vector<int> &vec, int item)
{
    int *data = vec.data();
    bin_search(data, data + vec.size(), item);
}
