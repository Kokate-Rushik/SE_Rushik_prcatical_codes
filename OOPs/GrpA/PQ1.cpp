/Code by Kokate Rushik
#include <iostream>
using namespace std;

class Complex {
    float real, imag;
public:
    Complex() {
        real = 0;
        imag = 0;
    }

    Complex(float r, float i) {
        real = r;
        imag = i;
    }

    Complex operator + (Complex c) {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator * (Complex c) {
        return Complex((real * c.real - imag * c.imag), (real * c.imag + imag * c.real));
    }

    friend ostream& operator << (ostream &out, Complex &c);
    friend istream& operator >> (istream &in, Complex &c);
};

ostream& operator << (ostream &out, Complex &c) {
    out << c.real << " + " << c.imag << "i";
    return out;
}

istream& operator >> (istream &in, Complex &c) {
    cout << "Enter real part: ";
    in >> c.real;
    cout << "Enter imaginary part: ";
    in >> c.imag;
    return in;
}

int main() {
    Complex c1, c2, c3;

    cout << "Enter first complex number:\n";
    cin >> c1;

    cout << "\nEnter second complex number:\n";
    cin >> c2;

    c3 = c1 + c2;
    cout << "\nAddition: " << c3 << endl;

    c3 = c1 * c2;
    cout << "Multiplication: " << c3 << endl;

    return 0;
}
