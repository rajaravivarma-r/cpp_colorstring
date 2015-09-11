#include <string>
#include <iostream>

#include "color_string.h"

using namespace std;

int main(int argc, char const* argv[])
{
    color_string colorText("Hello World");
    cout << "In Plain: " << colorText << endl;
    cout << "In Red: " << colorText.red() << endl;
    colorText.reset();
    cout << "In Blue: " << colorText.blue() << endl;
    colorText.reset();
    cout << "In Green: " << colorText.green() << endl;
    colorText.reset();
    cout << "In Cyan: " << colorText.cyan() << endl;
    colorText.reset();
    cout << "In Purple: " << colorText.purple() << endl;
    colorText.reset();
    cout << "In Black: " << colorText.black() << endl;
    colorText.reset();
    cout << "In White: " << colorText.white() << endl;
    return 0;
}
