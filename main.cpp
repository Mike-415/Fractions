/*

 After the successful completion of this learning unit,
 you will be able to:

    -Define syntactically correct constructors in classes
     in accordance with good programming practice

    -Divide a project into 3 files:
        specification file,
        implementation file,
        and client program file.

    -Use the const keyword correctly


Assignment 10.1 [45 points]
For this assignment you will be building on the Fraction class
you began last week. You'll be making FIVE(Actually 7)
major changes to the class.

1. Delete your set() function.
   Add two constructors, a default constructor
   (a constructor that takes no parameters) and
   a parameterized constructor (a constructor that takes parameters).
   The default constructor assigns the value 0 to the Fraction.
   In the parameterized constructor, the first parameter will
   represent the initial numerator of the Fraction,
   and the second parameter will represent the initial denominator
   of the Fraction.

2. Since Fractions cannot have denominators of 0,
   the default constructor should assign 0 to the numerator and
   1 to the denominator. Also, the parameterized constructor
   should check to make sure that the second parameter is not a 0
   by using the statement "assert(denominatorParameter != 0);".
   To use the assert() function you'll also need to #include <cassert>.
   (Note, I don't expect the variable to be named "denominatorParameter,"
   that's just my placeholder for the example.)


   assert() is not the best way to handle this,
   but it will have to do until we study exception handling.

3. Add the const keyword to your class wherever appropriate.
   Your class may still work correctly even if you don't do this correctly,
   so this will require extra care!!

4. Add a private "simplify()" function to your class and
   call it from the appropriate member functions.
   (For most of you there will be 5 places where you need to call it.
   This, however, depends on how you write the class,
   so don't assume you are wrong if you don't have exactly 5.)
   The best way to do this is to make the function a void function
   with no parameters that reduces the calling object.

As you can see from the sample output given below,
you are still not required to change improper Fractions
into mixed numbers for printing. Just print it as an improper Fraction.

Make sure that your class will reduce ANY Fraction,
not just the Fractions that are tested in the provided client program.
Fractions should not be simply reduced upon output,
they should be stored in reduced form at all times.

In other words, you should ensure that all Fraction objects are reduced
before the end of any member function.
You are also not required to deal with negative numbers,
either in the numerator or the denominator.

5.  You must create your own algorithm for reducing Fractions.
    Don't look up an already existing algorithm for reducing Fractions
    or finding GCF. The point here is to have you practice solving
    the problem on your own. In particular, don't use
    Euclid's algorithm. Don't worry about being efficient.
    It's fine to have your function check every possible factor,
    even if it would be more efficient to just check prime numbers.
    Just create something of your own that works correctly on ANY Fraction.

    Note: this part of the assignment is worth 5 points.
    If you are having trouble keeping up with the class,
    I suggest you skip this part and take the 5 point deduction.

6.  Put the client program in a separate file from the class,
    and divide the class into specification file (fraction.h)
    and implementation file (fraction.cpp), so your code will be
    in 3 separate files.

7.  Add documentation to your assignment. Be sure to
    carefully read section 1D of the Style Conventions,
    "Commenting in Classes".

    Hint: in this assignment, it turns out that
    none of the functions have preconditions.

Your class should still have exactly two data members.

I am providing a client program for you below.
You should copy and paste this and use it as your client program.
The output that should be produced when the provided client program
is run with your class is also given below, so that you can check your results. Since you are not writing the client program, you are not required to include comments in it.

Here is the client program.

#include <iostream>
#include "fraction.h"
using namespace std;

int main()
{
    Fraction f1(9,8);
    Fraction f2(2,3);
    Fraction result;

    cout << "The result starts off at ";
    result.print();
    cout << endl;

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

    const Fraction f3(12, 8);
    const Fraction f4(202, 303);
    result = f3.multipliedBy(f4);
    cout << "The product of ";
    f3.print();
    cout << " and ";
    f4.print();
    cout << " is ";
    result.print();
    cout << endl;
}
This client should produce the output shown here:

The result starts off at 0/1
The product of 9/8 and 2/3 is 3/4
The quotient of 9/8 and 2/3 is 27/16
The sum of 9/8 and 2/3 is 43/24
The difference of 9/8 and 2/3 is 11/24
The two Fractions are not equal.
The product of 3/2 and 2/3 is 1/1

You may not change the client program in any way.
Changing the client program will result in a grade of 0 on the project.

 */

#include <iostream>
#include <cassert>
using namespace std;

class Fraction {
    public:
        //void set(int inNumerator, int inDenominator);
        Fraction();
        Fraction( int inNumerator, int inDenominator );
        void print();
        Fraction addedTo( Fraction otherFraction );
        Fraction subtract( Fraction otherFraction );
        Fraction multipliedBy( Fraction otherFraction );
        Fraction dividedBy( Fraction otherFraction );
        bool isEqualTo( Fraction otherFraction );

    private:
        int numerator;
        int denominator;
        void simplify();
        Fraction addOrSubtract(bool isAddition, Fraction otherFraction);
};






/**
 * The default constructor, which assigns a default value of 0/1
 */
Fraction::Fraction() {
    numerator = 0;
    denominator = 1;
}






/**
 * The parameterized constructor that checks if the denominator is 0
 */
 Fraction::Fraction(int inNumerator, int inDenominator) {
     assert(inDenominator != 0);
     numerator = inNumerator;
     denominator = inDenominator;
     simplify();
 }







void Fraction::print() {
    cout << numerator << "/" << denominator;
}






/**
 * Simplifies this Fraction
 */
void Fraction::simplify() {
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
}






/**
 *
 * @param isAddition
 * @param otherFraction
 * @return
 */
Fraction Fraction::addOrSubtract(bool isAddition, Fraction otherFraction) {
    int crossMultiply1 = numerator * otherFraction.denominator;
    int crossMultiply2 = denominator * otherFraction.numerator;
    int commonDenominator = denominator * otherFraction.denominator;
    int results = (isAddition)? (crossMultiply1 + crossMultiply2) :
                                (crossMultiply1 - crossMultiply2);
    Fraction temp(results, commonDenominator);
    return temp;
}







Fraction Fraction::addedTo(Fraction otherFraction) {
    return addOrSubtract(true, otherFraction);
}







Fraction Fraction::subtract(Fraction otherFraction) {
    return addOrSubtract(false, otherFraction);
}







Fraction Fraction::multipliedBy(Fraction otherFraction) {
    Fraction temp((numerator * otherFraction.numerator),
                  (denominator * otherFraction.denominator));
    return temp;
}







Fraction Fraction::dividedBy(Fraction otherFraction) {
    Fraction temp((numerator * otherFraction.denominator),
                  (denominator * otherFraction.numerator));
    return temp;
}







bool Fraction::isEqualTo(Fraction otherFraction) {
    return (numerator * otherFraction.denominator ) ==
           (denominator * otherFraction.numerator);
}






int main() {
    Fraction f1(2,4);
    f1.print();
}




