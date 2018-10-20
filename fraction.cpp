#include <iostream>
#include "fraction.h"
using namespace std;


/**
 * The default constructor, which assigns a default value of 0/1
 */
fraction::fraction() {
    numerator = 0;
    denominator = 1;
}






/**
 * The parameterized constructor that checks if the denominator is 0
 */
fraction::fraction(int inNumerator, int inDenominator) {
    assert(inDenominator != 0);
    numerator = inNumerator;
    denominator = inDenominator;
    simplify();
}







void fraction::print() {
    cout << numerator << "/" << denominator;
}






/**
 * Simplifies this Fraction
 */
void fraction::simplify() {
    //First: check for negative numerators or denominators
    //       if both are negative, make positive
    //       if denominator is negative and numerator positive,
    //              make numerator negative and denominator positive
    //Second:Before simplifying, check if the numerator is negative
    //       if so, mark a flag as negative, since you'll be working with
    //         the absolute value of both the numerator
    //Third: Find the smallest value between the numerator and denominator
    //
    //Fourth:Use a decremental for-loop and a nest conditional statement
    //       to determine if BOTH the numerator and denominator are divisible
    //       by the for-loop's variable.
    //       REMEMBER: the loop has to decrement until it reaches 2, not 1
    bool isNegative = fractionNegative();
    //Using the absolute value of the numerator to prevent an infinite loop
    int absNumerator = abs(numerator);
    int smallestValue = (absNumerator < denominator)? absNumerator : denominator;
//    cout << "isNegative: " << isNegative << "\nabsNumerator: " << absNumerator << "\ndenominator: " << denominator;
//    cout << "\n\nEntering the while loop" << endl << endl;
    while( smallestValue > 1 ){
        if(absNumerator % smallestValue == 0 &&
           denominator  % smallestValue == 0){
//            cout << "both values divisible by " << smallestValue << endl;
            absNumerator /= smallestValue;
            denominator /= smallestValue;
        }
//        cout << "\n\tsmallestValue"<< smallestValue << "\n\tabsNumerator: " << absNumerator << "\n\tdenominator: " << denominator << endl;
        smallestValue--;
    }
    numerator = (isNegative)? absNumerator * -1 : absNumerator;
}



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
 *
 * @param isAddition
 * @param otherFraction
 * @return
 */
fraction fraction::addOrSubtract(bool isAddition, fraction otherFraction) {
    int crossMultiply1 = numerator * otherFraction.denominator;
    int crossMultiply2 = denominator * otherFraction.numerator;
    int commonDenominator = denominator * otherFraction.denominator;
    int results = (isAddition)? (crossMultiply1 + crossMultiply2) :
                  (crossMultiply1 - crossMultiply2);
    fraction temp(results, commonDenominator);
    temp.simplify();
    return temp;
}







fraction fraction::addedTo(fraction otherFraction) {
    return addOrSubtract(true, otherFraction);
}







fraction fraction::subtract(fraction otherFraction) {
    return addOrSubtract(false, otherFraction);
}







fraction fraction::multipliedBy(fraction otherFraction) {
    fraction temp((numerator * otherFraction.numerator),
                  (denominator * otherFraction.denominator));
    temp.simplify();
    return temp;
}







fraction fraction::dividedBy(fraction otherFraction) {
    fraction temp((numerator * otherFraction.denominator),
                  (denominator * otherFraction.numerator));
    temp.simplify();
    return temp;
}







bool fraction::isEqualTo(fraction otherFraction) {
    return (numerator * otherFraction.denominator ) ==
           (denominator * otherFraction.numerator);
}