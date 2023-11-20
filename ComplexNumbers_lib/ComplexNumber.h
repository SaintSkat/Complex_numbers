#ifndef COMPLEXNUMBERS_LIB_LIBRARY_H
#define COMPLEXNUMBERS_LIB_LIBRARY_H

#include <iostream>

class ComplexNumber {
private:
    double realPart;
    double imaginaryPart;

    double getSquareLength() const;

public:
    ComplexNumber();

    ComplexNumber(double realValue, double imaginaryValue);

    double getRealPart() const;

    void setRealPart(double value);

    double getImaginaryPart() const;

    void setImaginaryPart(double value);

    ComplexNumber operator+(ComplexNumber &number) const;

    ComplexNumber operator-(ComplexNumber &number) const;

    ComplexNumber operator*(ComplexNumber &number) const;

    ComplexNumber operator/(ComplexNumber &number) const;

    ComplexNumber operator^(double power) const;

    double getLength() const;

    bool operator<(const ComplexNumber &number) const;

    bool operator<=(const ComplexNumber &number) const;

    bool operator>(const ComplexNumber &number) const;

    bool operator>=(const ComplexNumber &number) const;

    bool operator==(const ComplexNumber &number) const;

    bool operator!=(const ComplexNumber &number) const;

    bool operator<(double d) const;

    bool operator<=(double d) const;

    bool operator>(double d) const;

    bool operator>=(double d) const;

    bool operator==(double d) const;

    bool operator!=(double d) const;

    friend bool operator>(double d, ComplexNumber &number);

    friend bool operator>=(double d, ComplexNumber &number);

    friend bool operator<(double d, ComplexNumber &number);

    friend bool operator<=(double d, ComplexNumber &number);

    friend bool operator==(double d, ComplexNumber &number);

    friend bool operator!=(double d, ComplexNumber &number);

    bool operator<(int i) const;

    bool operator<=(int i) const;

    bool operator>(int i) const;

    bool operator>=(int i) const;

    bool operator==(int i) const;

    bool operator!=(int i) const;

    friend bool operator>(int i, ComplexNumber &number);

    friend bool operator>=(int i, ComplexNumber &number);

    friend bool operator<(int i, ComplexNumber &number);

    friend bool operator<=(int i, ComplexNumber &number);

    friend bool operator==(int i, ComplexNumber &number);

    friend bool operator!=(int i, ComplexNumber &number);

//    Возведение в степень

    friend std::ostream &operator<<(std::ostream &cout, const ComplexNumber &number);
};

#endif //COMPLEXNUMBERS_LIB_LIBRARY_H
