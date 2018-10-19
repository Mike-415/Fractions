/*
 Name:        Michael Gonzalez
 Date:        October 18, 2018
 Instructor:  Dave Harden
 File Name:   A9_1.cpp
 Description:

 This programs creates and implements a Fraction class.

 There are two data members:
    -numerator
    -denominator

 There are seven public member functions to implement:
    -set
    -print
    -addedTo
    -subtract
    -multipliedBy
    -dividedBy
    -isEqualTo

 */
#include <iostream>
using namespace std;

class Fraction {
    public:
        void set(int inNumerator, int inDenominator);
        void print();
        Fraction addedTo(Fraction otherFraction);
        Fraction subtract(Fraction otherFraction);
        Fraction multipliedBy(Fraction otherFraction);
        Fraction dividedBy(Fraction otherFraction);
        bool isEqualTo(Fraction otherFraction);

    private:
        int numerator;
        int denominator;
        Fraction addOrSubtract(bool isAddition, Fraction otherFraction);
};






/**
 * Initializes or reinitializes the data members
 *
 * @param inNumerator represents the numerator
 * @param inDenominator represents the denominator
 */
void Fraction::set(int inNumerator, int inDenominator) {
    numerator = inNumerator;
    denominator = inDenominator;
}






/**
 * Formats and displays the data members to the console
 */
void Fraction::print() {
    cout << numerator << "/" << denominator;
}






/**
 * A helper method for either the addition or subtraction operations
 *
 * @param isAddition represents if the client wants an addition operation
 *        if false, perform a subtraction operation
 * @param otherFraction represents the other Fraction object
 *
 * @return a new Fraction object that represents the results of the
 *         arithmetic operation
 */
Fraction Fraction::addOrSubtract(bool isAddition, Fraction otherFraction) {
    Fraction temp;
    int crossMultiply1 = numerator * otherFraction.denominator;
    int crossMultiply2 = denominator * otherFraction.numerator;
    int commonDenominator = denominator * otherFraction.denominator;
    int results = (isAddition)? (crossMultiply1 + crossMultiply2) :
                                (crossMultiply1 - crossMultiply2);
    temp.set(results, commonDenominator);
    return temp;
}






/**
 * Adds this Fraction to another Fraction
 * @param otherFraction represents the other Fraction object
 * @return a new Fraction object that is the sum of this Fraction and
 *         the other Fraction
 */
Fraction Fraction::addedTo(Fraction otherFraction) {
    return addOrSubtract(true, otherFraction);
}






/**
 * Subtracts this Fraction to another Fraction
 * @param otherFraction represents the other Fraction object
 * @return a new Fraction object that is the difference of this Fraction and
 *         the other Fraction
 */
Fraction Fraction::subtract(Fraction otherFraction) {
    return addOrSubtract(false, otherFraction);
}






/**
 * Multiplies this Fraction to another Fraction
 * @param otherFraction represents the other Fraction object
 * @return a new Fraction object that is the product of this Fraction and
 *         the other Fraction
 */
Fraction Fraction::multipliedBy(Fraction otherFraction) {
    Fraction temp;
    temp.set((numerator * otherFraction.numerator),
            (denominator * otherFraction.denominator));
    return temp;
}






/**
 * Divides this Fraction to another Fraction
 * @param otherFraction represents the other Fraction object
 * @return a new Fraction object that is the quotient of this Fraction and
 *         the other Fraction
 */
Fraction Fraction::dividedBy(Fraction otherFraction) {
    Fraction temp;
    temp.set((numerator * otherFraction.denominator),
             (denominator * otherFraction.numerator));
    return temp;
}






/**
 * Determines if this Fraction and another Fraction are equal
 * @param otherFraction represents the other Fraction object
 * @return true if both Fractions are equal, false otherwise
 */
bool Fraction::isEqualTo(Fraction otherFraction) {
    return (numerator * otherFraction.denominator ) ==
           (denominator * otherFraction.numerator);
}






int main() {
    Fraction f1;
    Fraction f2;
    Fraction result;

    f1.set(9, 8);
    f2.set(2, 3);

    cout << "The product of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.multipliedBy(f2);
    result.print();
    cout << endl;

    cout << "The quotient of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.dividedBy(f2);
    result.print();
    cout << endl;

    cout << "The sum of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.addedTo(f2);
    result.print();
    cout << endl;

    cout << "The difference of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.subtract(f2);
    result.print();
    cout << endl;

    if (f1.isEqualTo(f2)){
        cout << "The two Fractions are equal." << endl;
    } else {
        cout << "The two Fractions are not equal." << endl;
    }
}

/*
OUTPUT:

The product of 9/8 and 2/3 is 18/24
The quotient of 9/8 and 2/3 is 27/16
The sum of 9/8 and 2/3 is 43/24
The difference of 9/8 and 2/3 is 11/24
The two Fractions are not equal.

 */


