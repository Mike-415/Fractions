#include <iostream>
#include "fraction.h"
using namespace std;






fraction::fraction() {
    numerator = 0;
    denominator = 1;
}







fraction::fraction(int inNumerator, int inDenominator) {
    assert(inDenominator != 0);
    numerator = inNumerator;
    denominator = inDenominator;
    simplify();
}








void fraction::print() const {
    cout << numerator << "/" << denominator;
}






/**
 * Simplifies this Fraction
 */
void fraction::simplify() {
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
bool fraction::fractionNegative() {
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
fraction fraction::addOrSubtract(bool isAddition, const fraction &otherFraction) const {
    int crossMultiply1 = numerator * otherFraction.denominator;
    int crossMultiply2 = denominator * otherFraction.numerator;
    int commonDenominator = denominator * otherFraction.denominator;
    int results = (isAddition)? (crossMultiply1 + crossMultiply2) :
                  (crossMultiply1 - crossMultiply2);
    fraction temp(results, commonDenominator);
    temp.simplify();
    return temp;
}








fraction fraction::addedTo(const fraction &otherFraction) const {
    return addOrSubtract(true, otherFraction);
}








fraction fraction::subtract( const fraction &otherFraction) const {
    return addOrSubtract(false, otherFraction);
}








fraction fraction::multipliedBy( const fraction &otherFraction) const {
    fraction temp((numerator * otherFraction.numerator),
                  (denominator * otherFraction.denominator));
    temp.simplify();
    return temp;
}








fraction fraction::dividedBy( const fraction &otherFraction) const {
    fraction temp((numerator * otherFraction.denominator),
                  (denominator * otherFraction.numerator));
    temp.simplify();
    return temp;
}








bool fraction::isEqualTo( const fraction &otherFraction) const {
    return (numerator * otherFraction.denominator ) ==
           (denominator * otherFraction.numerator);
}