#include <iostream>
#include <vector>
#include <ranges>
#include <iomanip>
#include <map>
#include <cassert>

class X
{
    int a, b, i, j;
public:
    const int& r;
    X(int i)
      : r(a)
      , b{i}
      , i(i)
      , j(this->i)
    {}
};

[[deprecated("Here I'm trying to use attributes!")]]
void my_try__Function_definition [[maybe_unused]] (int i) try {
    std::map<std::string, std::string> my_map [[maybe_unused]] {
        {"Hello", "World"},
        {"Hello", "Earth"}
    };

    if (true) [[expect_true]] [[likely]] {
        std::cout << "Attribute inside if statement" << std::endl;
    }

    throw my_map;
} catch(std::exception& e) {
    assert(i == 4);
    std::cout << "An Exception: " << e.what() << std::endl;
}

[[noreturn]]
auto my_try_2__Function_definition();

int main(int, char**) {
    std::vector<int> v = {2, 4, 6, 8, 1, 3, 5, 7, 9, 11};
    auto even = [](int i) { return 0 == i % 2; };
    auto odd = [](int i) { return 0 != i % 2; };

    std::cout.flags(std::ios::left);
    for (auto &&i : v | std::views::filter(even))
    {
        for (auto &&i : v | std::views::filter(odd)) 
        {
            std::cout << std::setw(17) << "Hello World!";
        }
        std::cout << std::endl;
    }
    
    return 0;
}
