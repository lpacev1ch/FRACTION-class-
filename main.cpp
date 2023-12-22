#include <iostream>
#include "cmake-build-debug/drob.h"

using namespace std;

int main() {
    drob frac1(1, 2);
    drob frac2(3, 4);

    cout << "frac1: " << frac1 << endl;
    cout << "frac2: " << frac2 << endl;

    drob sum = frac1 + frac2;
    cout << "Sum: " << sum << endl;

    drob difference = frac1 - frac2;
    cout << "Difference: " << difference << endl;

    drob product = frac1 * frac2;
    cout << "Product: " << product << endl;

    drob quotient = frac1 / frac2;
    cout << "Quotient: " << quotient << endl;

    if (frac1 == frac2) {
        cout << "frac1 is equal to frac2" << endl;
    } else {
        cout << "frac1 is not equal to frac2" << endl;
    }

    ++frac1;
    cout << "After incrementing, frac1: " << frac1 << endl;

    --frac2;
    cout << "After decrementing, frac2: " << frac2 << endl;

    double decimalValue = static_cast<double>(frac1);
    cout << "frac1 as a decimal: " << decimalValue << endl;

    drob inputFraction;
    cout << "Enter a fraction in the format (numerator/denominator): ";
    cin >> inputFraction;
    cout << "You entered: " << inputFraction << endl;

    return 0;
}