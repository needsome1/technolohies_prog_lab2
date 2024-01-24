#include <iostream>
using namespace std;
class Complex {
public:
    double real;
    double imaginary;

    Complex() : real(0.0), imaginary(0.0) {}
    Complex(double r, double i) : real(r), imaginary(i) {}

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imaginary * other.imaginary,
            real * other.imaginary + imaginary * other.real);
    }

    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imaginary * other.imaginary;
        return Complex((real * other.real + imaginary * other.imaginary) / denominator,
            (imaginary * other.real - real * other.imaginary) / denominator);
    }

    
    void display() const {
        cout << real << " + " << imaginary << "i";
    }
};


Complex addComplexVectors(const Complex& vec1, const Complex& vec2) {
    return vec1 + vec2;
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    Complex vector1(2.0, 3.0);
    Complex vector2(1.0, -1.0);

    Complex result = addComplexVectors(vector1, vector2);

  cout << "Сумма комплексных векторов: ";
    result.display();
    cout << endl;

    return 0;
}
