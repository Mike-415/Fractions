#ifndef UNTITLED2_FRACTION_H
#define UNTITLED2_FRACTION_H

/*

    The Fraction class can be used to create objects that store a numerator and a denominator.
    The following functions are available:

    Fraction();
      post: The calling object has been created and initialized to 0/1.

    Fraction(int inNumerator, int inDenominator);
      post: The calling object has been created and initialized so that the month is inMonth, the
            day is inDay, and the year is inYear.

    void print() const;
      post: prints the data members to the console in the following format:
            <numerator> / <denominator>

    Fraction addedTo( const Fraction &otherFraction ) const;
      post: Returns the simplified sum of the
            calling object and the otherFraction object.

    Fraction subtract( const Fraction &otherFraction ) const;
      post: Returns the simplified difference of the
            calling object and the otherFraction object.

    Fraction multipliedBy( const Fraction &otherFraction ) const;
      post: Returns the simplified product of the
            calling object and the otherFraction object.

    Fraction dividedBy( const Fraction &otherFraction ) const;
      post: Returns the simplified quotient of the
            calling object and the otherFraction object.

    bool isEqualTo( const Fraction &otherFraction ) const;
      post: Returns true if the calling object is equal
            to the otherFraction object.
*/

class Fraction {
    public:
        Fraction();
        Fraction( int inNumerator, int inDenominator );
        void print() const;
        Fraction addedTo( const Fraction &otherFraction ) const;
        Fraction subtract( const Fraction &otherFraction ) const;
        Fraction multipliedBy( const Fraction &otherFraction ) const;
        Fraction dividedBy( const Fraction &otherFraction ) const;
        bool isEqualTo( const Fraction &otherFraction ) const;

    private:
        int numerator;
        int denominator;
        void simplify();
        bool fractionNegative();
        Fraction addOrSubtract(bool isAddition, const Fraction &otherFraction) const;
};


#endif //UNTITLED2_FRACTION_H
