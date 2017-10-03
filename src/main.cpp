#include <vector>
#include <iostream>
#include "bin_search.h"

int main()
{
    std::vector<int> vec{1, 17, -10, 0};
    sort(vec);
    int *p1 = bin_search(vec, 16);
    std::cout << "should be true: " << (p1 == nullptr) << std::endl;
    int *p2 = bin_search(vec, 17);
    std::cout << "should be true: " << (p2 == &vec[3]) << std::endl;
}
