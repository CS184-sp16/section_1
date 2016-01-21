// These are standard library header files
#include <iostream>
#include <string>
#include <cmath>
#include <unistd.h> // c header

// This is my own header file that defines a Printer's set 
// of functions and variables
#include "section_1.h"


/* For convenience and since this is a .cpp file, 
 * we will allow ourselves to use the std namespace.
 * Else we'd have to write std::cout, std::endl, std::string, etc...
 */ 
using namespace std;

static const int text_width = 80;

// This namespace is shared amoung the .cpp and .h file.
namespace GrafixRules {

// Here we have the definition of a function that has been declared elsewhere
void Printer::graph(float x) {

    float frac = (x - left_bound) / (right_bound - left_bound);
    frac = min(1.f, std::max(0.f, frac));
    print(text_width * frac);

}

void Printer::print(int n) {
    cout << string(n, 'x') << endl;
}

}
 
// argc = number of args
// argv = value of args in an array as old-skool c_str
int main(int argc, const char *argv[]) {

    // Hello World style i/o
    int input_val = 0;
    if (argc >= 2) 
        input_val = argv[1][0] - 'a';

	cout << "Hello CS184 " << (input_val % 2 ? ":)" : ":(") << endl;

    string response;
    getline(cin, response);
    cout << "Alright, " << response << " to you too" << endl;
    cout << "Enjoy the ride" << endl;

    GrafixRules::Printer my_printer;

    // Shoutout to the Python fans:
    auto my_function = [] (float x) { 
        return sin(x * 3.1415f/180.f) + cos(5 + 2*x * 3.1415f/180.f); };

    usleep(1000*1000 * 2);
    int i = 0;
    while (true) {
        i += 2;
        my_printer.graph(my_function(i));
        usleep(10000);
    }

	return 0;
}