#include <string.h>
#include <iostream>

class Test {
    char c;

    public:
        Test(char _c) {
            c = _c;
            std::cout << "constructor" << c << std::endl;
        }
        ~Test() {std::cout << "destructor" << c << std::endl;}
};

void simple_function() {Test b('b');}
int main() {
    Test a('a');
    simple_function();
}