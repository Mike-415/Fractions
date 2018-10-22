#include <iostream>
#include "Fraction.h"
using namespace std;



/**
 * The default constructor, which assigns a default value of 0/1
 */
Fraction::Fraction() {
    numerator = 0;
    denominator = 1;
}






/**
 * The parameterized constructor that checks if the denominator is 0
 * @param inNumerator represents the numerator
 * @param inDenominator represents the denominator
 */
Fraction::Fraction(int inNumerator, int inDenominator) {
    assert(inDenominator != 0);
    numerator = inNumerator;
    denominator = inDenominator;
    simplify();
}







/**
 * displays the data members in the following format:
 *    <numerator> / <denominator>
 */
void Fraction::print() const {
    cout << numerator << "/" << denominator;
}






/**
 * Simplifies this Fraction to the lowest common multiple
 */
void Fraction::simplify() {
    bool isNegative = fractionNegative();
    int absNumerator = abs(numerator);
    int smallestValue = (absNumerator < denominator)? absNumerator : denominator;
    while( smallestValue > 1 ){
        if(absNumerator % smallestValue == 0 &&
           denominator  % smallestValue == 0){
            absNumerator /= smallestValue;
            denominator /= smallestValue;
        }
        smallestValue--;
    }
    numerator = (isNegative)? absNumerator * -1 : absNumerator;
}






/**
 * Determines if the fraction is negative.  If so, it formats the fraction
 * so that only the numerator is negative.
 * @return true if the fraction is negative
 */
bool Fraction::fractionNegative() {
    // -/+
    if(numerator < 0 && denominator > 0 ){
        return true;
    }
    // +/-
    if(numerator > 0 && denominator < 0 ){
        numerator *= -1;
        denominator = abs(denominator);
        return true;
    }
    // -/-
    if(numerator < 0 && denominator < 0 ){
        numerator = abs(numerator);
        denominator = abs(denominator);
        return false;
    }
    // +/+
    return false;
}




/**
 * A helper function used to either add or subtract
 * the calling object from the other fraction object
 *
 * @param isAddition determines the operation performed.
 *        If true, addition. Otherwise subtraction
 * @param otherFraction represents the other fraction
 *        passed into the calling object
 * @return A new fraction object that represents
 *         either the simplified difference or sum
 */
Fraction Fraction::addOrSubtract(bool isAddition, const Fraction &otherFraction) const {
    int crossMultiply1 = numerator * otherFraction.denominator;
    int crossMultiply2 = denominator * otherFraction.numerator;
    int commonDenominator = denominator * otherFraction.denominator;
    int results = (isAddition)? (crossMultiply1 + crossMultiply2) :
                  (crossMultiply1 - crossMultiply2);
    Fraction temp(results, commonDenominator);
    temp.simplify();
    return temp;
}







/**
 * Adds the calling object to the other fraction object
 *
 * @param otherFraction represent the fraction object passed into
 *        'this' calling object
 * @return the simplified sum of both fractions
 */
Fraction Fraction::addedTo(const Fraction &otherFraction) const {
    return addOrSubtract(true, otherFraction);
}







/**
 * Subtracts the calling object to the other fraction object
 *
 * @param otherFraction represent the fraction object passed into
 *        'this' calling object
 * @return the simplified difference of both fractions
 */
Fraction Fraction::subtract( const Fraction &otherFraction) const {
    return addOrSubtract(false, otherFraction);
}







/**
 * Multiplies the calling object to the other fraction object
 *
 * @param otherFraction represent the fraction object passed into
 *        'this' calling object
 * @return the simplified product of both fractions
 */
Fraction Fraction::multipliedBy( const Fraction &otherFraction) const {
    Fraction temp((numerator * otherFraction.numerator),
                  (denominator * otherFraction.denominator));
    temp.simplify();
    return temp;
}







/**
 * Divides the calling object to the other fraction object
 *
 * @param otherFraction represent the fraction object passed into
 *        'this' calling object
 * @return the simplified quotient of both fractions
 */
Fraction Fraction::dividedBy( const Fraction &otherFraction) const {
    Fraction temp((numerator * otherFraction.denominator),
                  (denominator * otherFraction.numerator));
    temp.simplify();
    return temp;
}







/**
 * Determines if the calling object is equal to the other fraction object
 *
 * @param otherFraction represent the fraction object passed into
 *        'this' calling object
 * @return true if the calling object is equal to the other fraction object
 */
bool Fraction::isEqualTo( const Fraction &otherFraction) const {
    return (numerator * otherFraction.denominator ) ==
           (denominator * otherFraction.numerator);
}