#include "../include/color.hpp"
#include <iostream>
using namespace std;
int main()
{
    std::cout << dye::aqua("Hello, World!") << std::endl;
    double a = 0, b = 10;
    cout << dye::colorize(a, a > 0 ? "green" : "red").invert() << endl;
    cout << dye::colorize(b, b > 0 ? "green" : "red").invert() << endl;

    const char ca[] = "ca";
    string str = "str";
    cout << "[ " + dye::red(ca) + " | " + dye::aqua(str) + " ]" << endl;
    return 0;
}
