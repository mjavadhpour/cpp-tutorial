#include <iostream>
#include <vector>
#include <ranges>
#include <iomanip>
#include <map>

void my_try__Function_definition(int i) try {
    std::map<std::string, std::string> my_map {
        {"Hello", "World"},
        {"Hello", "Earth"}
    };
} catch(std::exception& e) {
    std::cout << "an exception: " << e.what() << std::endl;
};

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
