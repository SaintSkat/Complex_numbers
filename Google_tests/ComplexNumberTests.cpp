//
// Created by Лера Корулина on 29.10.2023.
//

#include "gtest/gtest.h"
#include "ComplexNumber.h"

class ComplexNumberTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        one.setRealPart(1);
    }

    ComplexNumber one;
    ComplexNumber zero;
};

TEST_F(ComplexNumberTest, RealPart) {
    ComplexNumber number1;
    EXPECT_DOUBLE_EQ(number1.getRealPart(), 0);
    auto val = (double) rand();
    number1.setRealPart(val);
    EXPECT_DOUBLE_EQ(number1.getRealPart(), val);

    auto realVal = (double) rand();
    auto imaginaryVal = (double) rand();
    ComplexNumber number2(realVal, imaginaryVal);
    EXPECT_DOUBLE_EQ(number2.getRealPart(), realVal);
}

TEST_F(ComplexNumberTest, ComplexPart) {
    ComplexNumber number1;
    EXPECT_DOUBLE_EQ(number1.getImaginaryPart(), 0);
    auto val = (double) rand();
    number1.setImaginaryPart(val);
    EXPECT_DOUBLE_EQ(number1.getImaginaryPart(), val);

    auto realVal = (double) rand();
    auto imaginaryVal = (double) rand();
    ComplexNumber number2(realVal, imaginaryVal);
    EXPECT_DOUBLE_EQ(number2.getImaginaryPart(), imaginaryVal);
}

TEST_F(ComplexNumberTest, Addition) {
    ComplexNumber number3;
    auto r1 = (double) rand();
    auto r2 = (double) rand();
    auto c1 = (double) rand();
    auto c2 = (double) rand();
    ComplexNumber number1(r1, c1);
    ComplexNumber number2(r2, c2);

    number3 = number1 + number2;
    EXPECT_DOUBLE_EQ(number3.getRealPart(), r1 + r2);
    EXPECT_DOUBLE_EQ(number3.getImaginaryPart(), c1 + c2);

    number3 = number2 + number1;
    EXPECT_DOUBLE_EQ(number3.getRealPart(), r2 + r1);
    EXPECT_DOUBLE_EQ(number3.getImaginaryPart(), c2 + c1);

    number3 = number1 + zero;
    EXPECT_DOUBLE_EQ(number3.getRealPart(), number1.getRealPart());
    EXPECT_DOUBLE_EQ(number3.getImaginaryPart(), number1.getImaginaryPart());
}

TEST_F(ComplexNumberTest, Substraction) {
    ComplexNumber number3;
    auto r1 = (double) rand();
    auto r2 = (double) rand();
    auto c1 = (double) rand();
    auto c2 = (double) rand();
    ComplexNumber number1(r1, c1);
    ComplexNumber number2(r2, c2);

    number3 = number1 - number2;
    EXPECT_DOUBLE_EQ(number3.getRealPart(), r1 - r2);
    EXPECT_DOUBLE_EQ(number3.getImaginaryPart(), c1 - c2);

    number3 = number2 - number1;
    EXPECT_DOUBLE_EQ(number3.getRealPart(), r2 - r1);
    EXPECT_DOUBLE_EQ(number3.getImaginaryPart(), c2 - c1);

    number3 = number1 - zero;
    EXPECT_DOUBLE_EQ(number3.getRealPart(), number1.getRealPart());
    EXPECT_DOUBLE_EQ(number3.getImaginaryPart(), number1.getImaginaryPart());
}

TEST_F(ComplexNumberTest, Multiplication) {
    ComplexNumber number3;
    auto r1 = (double) rand();
    auto r2 = (double) rand();
    auto c1 = (double) rand();
    auto c2 = (double) rand();
    ComplexNumber number1(r1, c1);
    ComplexNumber number2(r2, c2);

    number3 = number1 * number2;
    EXPECT_DOUBLE_EQ(number3.getRealPart(), r1 * r2 - c1 * c2);
    EXPECT_DOUBLE_EQ(number3.getImaginaryPart(), r1 * c2 + r2 * c1);

    number3 = number2 * number1;
    EXPECT_DOUBLE_EQ(number3.getRealPart(), r1 * r2 - c1 * c2);
    EXPECT_DOUBLE_EQ(number3.getImaginaryPart(), r1 * c2 + r2 * c1);

    number3 = number1 * zero;
    EXPECT_DOUBLE_EQ(number3.getRealPart(), zero.getRealPart());
    EXPECT_DOUBLE_EQ(number3.getImaginaryPart(), zero.getImaginaryPart());

    number3 = number1 * one;
    EXPECT_DOUBLE_EQ(number3.getRealPart(), number1.getRealPart());
    EXPECT_DOUBLE_EQ(number3.getImaginaryPart(), number1.getImaginaryPart());
}

TEST_F(ComplexNumberTest, Division) {
    ComplexNumber number3;
    auto r1 = (double) rand();
    auto r2 = (double) rand();
    auto c1 = (double) rand();
    double c2 = 0;
    while (c2 == 0)
        c2 = (double) rand();
    ComplexNumber number1(r1, c1);
    ComplexNumber number2(r2, c2);

    number3 = number1 / number2;
    double d = r2 * r2 + c2 * c2;
    EXPECT_DOUBLE_EQ(number3.getRealPart(), (r1 * r2 + c1 * c2) / d);
    EXPECT_DOUBLE_EQ(number3.getImaginaryPart(), (c1 * r2 - r1 * c2) / d);

    number3 = zero / number1;
    EXPECT_DOUBLE_EQ(number3.getRealPart(), zero.getRealPart());
    EXPECT_DOUBLE_EQ(number3.getImaginaryPart(), zero.getImaginaryPart());

    number3 = number1 / one;
    EXPECT_DOUBLE_EQ(number3.getRealPart(), number1.getRealPart());
    EXPECT_DOUBLE_EQ(number3.getImaginaryPart(), number1.getImaginaryPart());

    bool catch_exception = false;
    try {
        number3 = number1 / zero;
    }
    catch (...) {
        catch_exception = true;
    }
    EXPECT_EQ(catch_exception, true);
}

TEST_F(ComplexNumberTest, Length) {
    EXPECT_DOUBLE_EQ(zero.getLength(), 0);
    EXPECT_DOUBLE_EQ(one.getLength(), 1);

    auto r = (double) rand();
    auto c = (double) rand();
    ComplexNumber number(r, c);
    EXPECT_DOUBLE_EQ(number.getLength(), sqrt(r * r + c * c));
}

TEST_F(ComplexNumberTest, Comparision) {
    auto r1 = (double) rand();
    auto r2 = (double) rand();
    auto c1 = r1 * 2;
    auto c2 = c1 * 2;
    int i = (int) r1;
    ComplexNumber number1(r1, c1);
    ComplexNumber number2(r2, c2);
    ComplexNumber number3(0, 1);

    EXPECT_EQ(number1 < number2, true);
    EXPECT_EQ(number1 > number2, false);
    EXPECT_EQ(number2 > number1, true);
    EXPECT_EQ(number1 > number2, false);
    EXPECT_EQ(number3 == one, true);
    EXPECT_EQ(number3 != one, false);
    EXPECT_EQ(number3 != zero, true);
    EXPECT_EQ(number3 == zero, false);
    EXPECT_EQ(number1 > r1, true);
    EXPECT_EQ(r1 > number1, false);
    EXPECT_EQ(number1 < r1, false);
    EXPECT_EQ(r1 < number1, true);
    EXPECT_EQ(one == (double) 1, true);
    EXPECT_EQ((double) 1 == one, true);
    EXPECT_EQ(zero == (double) 1, false);
    EXPECT_EQ((double) 1 == zero, false);
    EXPECT_EQ(one != (double) 0, true);
    EXPECT_EQ((double) 0 != one, true);
    EXPECT_EQ(zero != (double) 0, false);
    EXPECT_EQ((double) 0 != zero, false);
    EXPECT_EQ(number1 > i, true);
    EXPECT_EQ(i > number1, false);
    EXPECT_EQ(number2 < i, false);
    EXPECT_EQ(i < number2, true);
    EXPECT_EQ(one == 1, true);
    EXPECT_EQ(1 == one, true);
    EXPECT_EQ(zero == 1, false);
    EXPECT_EQ(1 == zero, false);
    EXPECT_EQ(one != 0, true);
    EXPECT_EQ(0 != one, true);
    EXPECT_EQ(zero != 0, false);
    EXPECT_EQ(0 != zero, false);
}

TEST_F(ComplexNumberTest, Power) {
    auto r1 = (double) rand();
    auto c1 = r1 * 2;
    ComplexNumber number1(r1, c1);
    ComplexNumber number2 = number1 ^ 2;
    ComplexNumber number3 = number1 * number1;

    EXPECT_DOUBLE_EQ(number2.getRealPart(), number3.getRealPart());
    EXPECT_DOUBLE_EQ(number2.getImaginaryPart(), number3.getImaginaryPart());
    EXPECT_EQ(one ^ r1 == one, true);
}