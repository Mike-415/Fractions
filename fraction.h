//
// Created by Michael Gonzalez on 10/20/18.
//

#ifndef UNTITLED2_FRACTION_H
#define UNTITLED2_FRACTION_H


class fraction {
    public:
        //void set(int inNumerator, int inDenominator);
        fraction();
        fraction( int inNumerator, int inDenominator );
        void print();
        fraction addedTo( fraction otherFraction );
        fraction subtract( fraction otherFraction );
        fraction multipliedBy( fraction otherFraction );
        fraction dividedBy( fraction otherFraction );
        bool isEqualTo( fraction otherFraction );

    private:
        int numerator;
        int denominator;
        void simplify();
        bool fractionNegative();
        fraction addOrSubtract(bool isAddition, fraction otherFraction);
};


#endif //UNTITLED2_FRACTION_H
