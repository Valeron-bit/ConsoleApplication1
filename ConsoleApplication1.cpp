#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
    int a, b, c;  // Declaration of variables for the sides of the triangle
    double p, S;  // Variables for the semi-perimeter and area

    cout << "Enter side a: ";
    cin >> a;
    cout << "Enter side b: ";
    cin >> b;
    cout << "Enter side c: ";
    cin >> c;

    if (a <= 0 || b <= 0 || c <= 0) {
        cout << "The sides of the triangle must be positive numbers" << endl;
        return 1;
    }

    // Check if the triangle exists:
    if (a + b > c && b + c > a && c + a > b) {

        // Maximum and minimum side of the triangle:
        int ma = std::max({ a, b, c });  // Maximum side
        int mi = std::min({ a, b, c });  // Minimum side
        int cr = a + b + c - ma - mi;    // Middle side

        // Type of triangle by angles, Pythagorean theorem:
        if (mi * mi + cr * cr < ma * ma) {
            std::cout << "By angle type - obtuse" << endl;
        }
        else if (mi * mi + cr * cr == ma * ma) {
            std::cout << "By angle type - right-angled" << endl;
        }
        else {
            std::cout << "By angle type - acute" << endl;
        }

        // Type of triangle by sides:
        if (a == b && b == c) {
            cout << "By side type - equilateral" << endl;
        }
        else if (a == b || b == c || c == a) {
            cout << "By side type - isosceles" << endl;
        }
        else {
            cout << "By side type - scalene" << endl;
        }

        // Area of the triangle:
        p = (a + b + c) / 2.0;  // Semi-perimeter
        S = sqrt(p * (p - a) * (p - b) * (p - c));  // Heron's formula
        cout << "Area of the triangle: " << S << endl;

        // Inscribed circle

    }
    else {
        cout << "The triangle does not exist" << endl;
    }

    return 0;
}
