#ifndef UNTITLED2_FRACTION_H
#define UNTITLED2_FRACTION_H

/*
    Name:       Michael Gonzalez
    Class:      cs110b
    Instructor: Dave Harden
    File:       fraction.h

    The fraction class can be used to create objects that store a numerator and a denominator.
    The following functions are available:

    fraction();
      post: The calling object has been created and initialized to 0/1.

    fraction(int inNumerator, int inDenominator);
      post: The calling object has been created and initialized so that the month is inMonth, the
            day is inDay, and the year is inYear.

    void print() const;
      post: prints the data members to the console in the following format:
            <numerator> / <denominator>

    fraction addedTo( const fraction &otherFraction ) const;
      post: Returns the simplified sum of the
            calling object and the otherFraction object.

    fraction subtract( const fraction &otherFraction ) const;
      post: Returns the simplified difference of the
            calling object and the otherFraction object.

    fraction multipliedBy( const fraction &otherFraction ) const;
      post: Returns the simplified product of the
            calling object and the otherFraction object.

    fraction dividedBy( const fraction &otherFraction ) const;
      post: Returns the simplified quotient of the
            calling object and the otherFraction object.

    bool isEqualTo( const fraction &otherFraction ) const;
      post: Returns true if the calling object is equal
            to the otherFraction object.
*/
class fraction {
    public:
        fraction();
        fraction( int inNumerator, int inDenominator );
        void print() const;
        fraction addedTo( const fraction &otherFraction ) const;
        fraction subtract( const fraction &otherFraction ) const;
        fraction multipliedBy( const fraction &otherFraction ) const;
        fraction dividedBy( const fraction &otherFraction ) const;
        bool isEqualTo( const fraction &otherFraction ) const;

    private:
        int numerator;
        int denominator;
        void simplify();
        bool fractionNegative();
        fraction addOrSubtract(bool isAddition, const fraction &otherFraction) const;
};
#endif //UNTITLED2_FRACTION_H
