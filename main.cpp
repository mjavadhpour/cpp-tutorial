#include <iostream>
#include <vector>
#include <ranges>
#include <iomanip>
#include <map>
#include <cassert>
#include <type_traits>

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
    ~X();
};

X::~X() try { std::cout << "Disctructor" << std::endl; } catch(...) {}

[[deprecated("Here I'm trying to use attributes!")]]
void my_try__Function_definition [[maybe_unused]] (int i) try {
    std::map<std::string, std::string> my_map [[maybe_unused]] {
        {"Hello", "World"},
        {"Hello", "Earth"}
    };

    if (true) [[likely]] {
        std::cout << "Attribute inside if statement" << std::endl;
    }

    throw my_map;
} catch(std::exception& e) {
    assert(i == 4);
    std::cout << "An Exception: " << e.what() << std::endl;
}

extern "C" {
    int add(int x, int y) {
        return x+y;
    }
}

void foo(char *);
void foo(int);

[[noreturn]]
auto my_try_2__Function_definition();

int main(int, char**) {
    std::vector<int> v = {2, 4, 6, 8, 1, 3, 5, 7, 9, 11};
    auto even = [](int i) { return 0 == i % 2; };
    auto odd = [](int i) { return 0 != i % 2; };
    const char* my_str = "Hello World!";
    int my_number = 5;

    std::cout.flags(std::ios::left);
    for (auto &&i : v | std::views::filter(even))
    {
        for (auto &&i : v | std::views::filter(odd)) 
        {
            std::cout << std::setw(17) << "Hello World!";
        }
        std::cout << std::endl;
    }

    auto my_class = new X(5);

    delete my_class;

    foo(0);
    foo(nullptr);

    [out = std::ref(std::cout << "Result from C code: " << add(1, 2))](){
        out.get() << ".\n";
    }();
    
    return 0;
}

void foo(char *) {
    std::cout << "foo(char*) is called" << std::endl;
}
void foo(int i) {
    std::cout << "foo(int) is called" << std::endl;
}
