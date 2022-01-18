#include <iostream>
#include <vector>
#include <ranges>
#include <iomanip>
#include <map>
#include <cassert>
#include <type_traits>
#include <initializer_list>
#define LEN 10

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

constexpr int fibonacci(const int n) {
    return n == 1 || n == 2 ? 1 : fibonacci(n-1) + fibonacci(n-2);
}

[[noreturn]]
auto my_try_2__Function_definition();

template<int n>
struct constN
{
    constN() { std::cout << n << '\n'; }
};

class Foo {
public:
    std::vector<int> vec;
    Foo(std::initializer_list<int> list) {
        for (std::initializer_list<int>::iterator it = list.begin();
            it != list.end(); ++it) vec.push_back(*it);
    }
};

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

    std::cout << "Fibonacci 20 (Compile Time) = ";
    constN<fibonacci(20)> out1; 
    
    const int my_compile_time_number = fibonacci(20);
    std::cout << "Fibonacci 20 (Compile Time) = " << my_compile_time_number << '\n'; 
    std::cout << "Fibonacci 20 (Run Time) = " << fibonacci(20) << '\n'; 

    std::vector<int> vec = {1, 2, 3, 4, 5};

    auto itr = std::find(vec.begin(), vec.end(), 2);
    if (itr != vec.end()) {
        *itr = 3;
    }

    if (auto itr = std::find(vec.begin(), vec.end(), 3);
        itr != vec.end()) {
        *itr = 4;
    }

    for (std::vector<int>::iterator element = vec.begin(); element != vec.end(); ++element)
        std::cout << *element << std::endl;


    int arr[3] = {1, 2, 3};
    Foo foo {1, 2, 12, 19, 16, 113};

    std::cout << "arr[0]: " << arr[0] << std::endl;
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << std::endl;
    }
     for (std::vector<int>::iterator it = foo.vec.begin(); it != foo.vec.end(); ++it) {
        std::cout << *it << std::endl;
    }

    return 0;
}

void foo(char *) {
    std::cout << "foo(char*) is called" << std::endl;
}
void foo(int i) {
    std::cout << "foo(int) is called" << std::endl;
}
