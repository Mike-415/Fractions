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



void Fraction::set(int inNumerator, int inDenominator) {
    numerator = inNumerator;
    denominator = inDenominator;
}

void Fraction::print() {
    cout << numerator << "/" << denominator;
}

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

Fraction Fraction::addedTo(Fraction otherFraction) {
    return addOrSubtract(true, otherFraction);
}

Fraction Fraction::subtract(Fraction otherFraction) {
    return addOrSubtract(false, otherFraction);
}

Fraction Fraction::multipliedBy(Fraction otherFraction) {
    Fraction temp;
    temp.set((numerator * otherFraction.numerator),
            (denominator * otherFraction.denominator));
    return temp;
}

Fraction Fraction::dividedBy(Fraction otherFraction) {
    Fraction temp;
    temp.set((numerator * otherFraction.denominator),
             (denominator * otherFraction.numerator));
    return temp;
}

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

Write a Fraction class whose objects will represent Fractions.

Note: this is the first part of a multi-part assignment.
 For this week you should not simplify (reduce) fractions,
 you should not use "const,"
 and all of your code should be in a single file.

In this single file, the
 class declaration will come first,
 followed by the definitions of the class member functions,
 followed by the client program.

You must provide the following member functions:

A set() operation that takes two integer arguments,
 a numerator and
 a denominator,
 and sets the calling object accordingly.

Arithmetic operations that
 add,
 subtract,
 multiply, and
 divide Fractions.
 These should be implemented as value returning functions
 that return a Fraction object. They should be named
 addedTo,
 subtract,
 multipliedBy, and
 dividedBy.
 In these functions you will need to declare a local "Fraction" variable,
 assign to it the result of the mathematical operation, and then return it.

A boolean operation named isEqualTo that
 compares two Fraction objects for equality.
 Since you aren't reducing your Fractions,
 you'll need to do this by cross-multiplying.
 A little review:
 if numerator1 * denominator2 equals denominator1 * numerator2,
 then the Fractions are equal.

An output operation named print that displays the value of a Fraction object
 on the screen in the form numerator/denominator.

Your class should have exactly two data members,
 one to represent the numerator of the Fraction being represented,
 and one to represent the denominator of the Fraction being represented.

Here's a hint for how you will set up your arithmetic operation functions:
 You need two Fractions.
    One is the parameter,
    one is the calling object.
 The function multiplies the calling object times
 the parameter and returns the result.
 In some ways it is similar to the comesBefore() function from the lesson.
 That function also needs two Fractions,
 and one is the calling object and one is the parameter.

When adding or subtracting Fractions,
 remember that you must first find the common denominator.
 The easy way to do this is to multiply the denominators together
 and use that product as the common denominator.

I am providing a client program for you below.
 You should copy and paste this and use it as your client program.
 The output that should be produced when the provided client program
 is run with your class is also given below, so that you can check your results.

I strongly suggest that you design your class incrementally.
 For example, you should first implement only the set function
 and the output function,
 and then test what you have so far.
 Once this code has been thoroughly debugged,
 you should add additional member functions,
 testing each one thoroughly as it is added.
 You might do this by creating your own client program to test the code
 at each stage; however, it would probably be better
 to use the provided client program and comment out code
 that relates to member functions that you have not yet implemented.

As you can see from the sample output given below,
 you are not required to reduce Fractions or
 change improper Fractions into mixed numbers for printing.
 Just print it as an improper Fraction.
 You are also not required to deal with negative numbers,
 either in the numerator or the denominator.

 */


