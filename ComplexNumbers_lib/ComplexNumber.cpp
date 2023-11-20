#include "ComplexNumber.h"

#include <iostream>
#include <limits>

double ComplexNumber::getRealPart() const {
    return this->realPart;
}

void ComplexNumber::setRealPart(double value) {
    this->realPart = value;
}

double ComplexNumber::getImaginaryPart() const {
    return this->imaginaryPart;
}

void ComplexNumber::setImaginaryPart(double value) {
    this->imaginaryPart = value;
}

ComplexNumber::ComplexNumber() : ComplexNumber(0, 0) {}

ComplexNumber::ComplexNumber(double realValue, double imaginaryValue) {
    this->realPart = realValue;
    this->imaginaryPart = imaginaryValue;
}

ComplexNumber ComplexNumber::operator+(ComplexNumber &number) const {
    return ComplexNumber(
            this->getRealPart() + number.getRealPart(),
            this->getImaginaryPart() + number.getImaginaryPart()
    );
}

ComplexNumber ComplexNumber::operator-(ComplexNumber &number) const {
    return ComplexNumber(
            this->getRealPart() - number.getRealPart(),
            this->getImaginaryPart() - number.getImaginaryPart()
    );
}

ComplexNumber ComplexNumber::operator*(ComplexNumber &number) const {
    return ComplexNumber(
            this->getRealPart() * number.getRealPart() - this->getImaginaryPart() * number.getImaginaryPart(),
            this->getRealPart() * number.getImaginaryPart() + this->getImaginaryPart() * number.getRealPart()
    );
}

ComplexNumber ComplexNumber::operator/(ComplexNumber &number) const {
    double d = number.getSquareLength();
    if (d < std::numeric_limits<double>::epsilon())
        throw std::runtime_error("Cannot divide by zero");
    return ComplexNumber(
            (this->getRealPart() * number.getRealPart() + this->getImaginaryPart() * number.getImaginaryPart()) / d,
            (this->getImaginaryPart() * number.getRealPart() - this->getRealPart() * number.getImaginaryPart()) / d
    );
}

ComplexNumber ComplexNumber::operator^(double power) const {
    double magnitude = std::pow(this->getLength(), power);
    double angle = std::atan2(this->getImaginaryPart(), this->getRealPart()) * power;
    return ComplexNumber(magnitude * std::cos(angle), magnitude * std::sin(angle));
}

double ComplexNumber::getSquareLength() const {
    return getRealPart() * getRealPart() + getImaginaryPart() * getImaginaryPart();
}

double ComplexNumber::getLength() const {
    return sqrt(this->getSquareLength());
}

bool ComplexNumber::operator<(const ComplexNumber &number) const {
    return this->getLength() < number.getLength();
}

bool ComplexNumber::operator<=(const ComplexNumber &number) const {
    return this->getLength() <= number.getLength();
}

bool ComplexNumber::operator>(const ComplexNumber &number) const {
    return this->getLength() > number.getLength();
}

bool ComplexNumber::operator>=(const ComplexNumber &number) const {
    return this->getLength() >= number.getLength();
}

bool ComplexNumber::operator==(const ComplexNumber &number) const {
    return this->getLength() == number.getLength();
}

bool ComplexNumber::operator!=(const ComplexNumber &number) const {
    return this->getLength() != number.getLength();
}

bool ComplexNumber::operator<(double d) const{
    return this->getLength() < d;
}

bool ComplexNumber::operator<=(double d) const{
    return this->getLength() <= d;
}

bool ComplexNumber::operator>(double d) const{
    return this->getLength() > d;
}

bool ComplexNumber::operator>=(double d) const{
    return this->getLength() >= d;
}

bool ComplexNumber::operator==(double d) const{
    return this->getLength() == d;
}

bool ComplexNumber::operator!=(double d) const{
    return this->getLength() != d;
}

bool operator >(double d, ComplexNumber &number) {
    return number < d;
}

bool operator >=(double d, ComplexNumber &number) {
    return number <= d;
}

bool operator <(double d, ComplexNumber &number) {
    return number > d;
}

bool operator <=(double d, ComplexNumber &number) {
    return number >= d;
}

bool operator ==(double d, ComplexNumber &number) {
    return number == d;
}

bool operator !=(double d, ComplexNumber &number) {
    return number != d;
}

bool ComplexNumber::operator<(int i) const{
    return this->getLength() < i;
}

bool ComplexNumber::operator<=(int i) const{
    return this->getLength() <= i;
}

bool ComplexNumber::operator>(int i) const{
    return this->getLength() > i;
}

bool ComplexNumber::operator>=(int i) const{
    return this->getLength() >= i;
}

bool ComplexNumber::operator==(int i) const{
    return this->getLength() == i;
}

bool ComplexNumber::operator!=(int i) const{
    return this->getLength() != i;
}

bool operator>(int i, ComplexNumber &number) {
    return number < i;
}

bool operator>=(int i, ComplexNumber &number) {
    return number <= i;
}

bool operator<(int i, ComplexNumber &number) {
    return number > i;
}

bool operator<=(int i, ComplexNumber &number) {
    return number >= i;
}

bool operator==(int i, ComplexNumber &number) {
    return number == i;
}

bool operator!=(int i, ComplexNumber &number) {
    return number != i;
}

std::ostream &operator<<(std::ostream &cout, const ComplexNumber &number) {
    cout << "ComplexNumber(" << number.getRealPart() << ", " << number.getImaginaryPart() << ")";
    return cout;
}