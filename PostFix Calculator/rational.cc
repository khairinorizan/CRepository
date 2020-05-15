/* 
* Author: Muhammad Khairi Norizan (Khairi)
* Purpose: HW7 Rational Class
* Language: C,C++
*/

#include <iostream>
#include "string.h"
#include "rational.hh"
using namespace std;

/* Find the simplified fraction */
int gcd(int n, int m){
    int gcd, remainder;

    while(n != 0){
        remainder = m % n;
        m = n;
        n = remainder;
    }

    gcd = m;

    return gcd;
}

/* << overloading operator */
ostream& operator<<(ostream& out, rational ratNum){
    long int ratNumNominator = ratNum.getNominator();
    long int ratNumDenominator = ratNum.getDominator();
    if(ratNumDenominator == 1){
        out << ratNumNominator << endl;
        
        return out;
    }else{
        long int cpyratNumNominator = ratNumNominator;
        ratNumNominator = ratNumNominator / gcd(ratNumNominator, ratNumDenominator);
        ratNumDenominator = ratNumDenominator / gcd(cpyratNumNominator, ratNumDenominator);
        out << ratNumNominator << "/" << ratNumDenominator << "\n" << endl;
        
        return out;
    }
}

/* + overloading operator */
rational rational::operator+ (rational &ratNum2){
    if(denominator == 1 && ratNum2.denominator == 1){
        long int newVal = 0;
        newVal = nominator + ratNum2.nominator;
        
        rational retRational(newVal, 1);
        return retRational;
        
    }else if(denominator == 1 && ratNum2.denominator > 1){
        //Ex: 2 + 1/2 = 5/2
        /* Give new fraction to this.rational */
        denominator = denominator * ratNum2.denominator;
        nominator = nominator * ratNum2.denominator;
        /* New return value */
        rational retRational(nominator + ratNum2.nominator, ratNum2.denominator);
        return retRational;

    }else if(denominator > 1 && ratNum2.denominator == 1){
        //Ex: 1/2 + 2 = 5/2
        /* Give new fraction to ratNum2 */
        ratNum2.denominator = ratNum2.denominator * denominator;
        ratNum2.nominator = ratNum2.nominator * nominator;
        /* New return value */
        rational retRational(ratNum2.nominator + nominator, denominator);
        return retRational;

    }else{
        //Ex: 1/2 + 3/4 = 4/8 = 1/2
        if(ratNum2.denominator % denominator == 0){
            long int multipleVal = ratNum2.denominator / denominator;

            /* Give new fraction to this.rational */
            nominator = nominator * multipleVal;
            denominator = denominator * multipleVal;

            /* New return value */
            rational retRational(nominator + ratNum2.nominator, denominator);
            return retRational;

        }else if(denominator % ratNum2.denominator== 0){
            long int multipleVal = denominator / ratNum2.denominator;

            /* Give new fraction to ratNum2 */
            ratNum2.nominator = ratNum2.nominator * multipleVal;
            ratNum2.denominator = ratNum2.denominator * multipleVal;

            /* New return value */
            rational retRational(nominator + ratNum2.nominator, ratNum2.denominator);
            return retRational;

        }else{
            long int cpyDenominator = denominator;
            long int ratNumCpyDenominator = ratNum2.denominator;

            /* Give new fraction to this.rational */
            nominator = nominator * ratNumCpyDenominator;
            denominator = denominator * ratNumCpyDenominator;

            /* Give new fraction to ratNum2 */
            ratNum2.nominator = ratNum2.nominator * cpyDenominator;
            ratNum2.denominator = ratNum2.denominator * cpyDenominator;

            /* New return value */
            rational retRational(nominator + ratNum2.nominator, denominator);
            return retRational;

        }
    }
}

rational rational::operator- (rational &ratNum2){
    if(denominator == 1 && ratNum2.denominator == 1){
        long int newVal = 0;
        newVal = nominator - ratNum2.nominator;

        rational retRational(newVal);
        return retRational;

    }else if(denominator == 1 && ratNum2.denominator > 1){
        //Ex: 2 + 1/2 = 5/2
        /* Give new fraction to this.rational */
        denominator = denominator * ratNum2.denominator;
        nominator = nominator * ratNum2.denominator;
        /* New return value */
        rational retRational(nominator - ratNum2.nominator, ratNum2.denominator);
        return retRational;

    }else if(denominator > 1 && ratNum2.denominator == 1){
        //Ex: 1/2 + 2 = 5/2
        /* Give new fraction to ratNum2 */
        ratNum2.denominator = ratNum2.denominator * denominator;
        ratNum2.nominator = ratNum2.nominator * nominator;
        /* New return value */
        rational retRational(ratNum2.nominator - nominator, denominator);
        return retRational;

    }else{
        //Ex: 1/2 + 3/4 = 4/8 = 1/2
        if(ratNum2.denominator % denominator == 0){
            long int multipleVal = ratNum2.denominator / denominator;

            /* Give new fraction to this.rational */
            nominator = nominator * multipleVal;
            denominator = denominator * multipleVal;

            /* New return value */
            rational retRational(nominator - ratNum2.nominator, denominator);
            return retRational;

        }else if(denominator % ratNum2.denominator== 0){
            long int multipleVal = denominator / ratNum2.denominator;

            /* Give new fraction to ratNum2 */
            ratNum2.nominator = ratNum2.nominator * multipleVal;
            ratNum2.denominator = ratNum2.denominator * multipleVal;

            /* New return value */
            rational retRational(nominator - ratNum2.nominator, ratNum2.denominator);
            return retRational;

        }else{
            long int cpyDenominator = denominator;
            long int ratNumCpyDenominator = ratNum2.denominator;

            /* Give new fraction to this.rational */
            nominator = nominator * ratNumCpyDenominator;
            denominator = denominator * ratNumCpyDenominator;

            /* Give new fraction to ratNum2 */
            ratNum2.nominator = ratNum2.nominator * cpyDenominator;
            ratNum2.denominator = ratNum2.denominator * cpyDenominator;

            /* New return value */
            rational retRational(nominator - ratNum2.nominator, denominator);
            return retRational;

        }
    }
}

rational rational::operator/ (rational &ratNum2){
    
    if(denominator == 1 && ratNum2.denominator == 1){
        /* Divisible */
        if(nominator % ratNum2.nominator == 0){
            //Ex: 9 / 3 = 3
            rational retRational(nominator / ratNum2.nominator);
            return retRational;

        }else{
            /* Not divisible */
            //Ex: 3 / 5
            rational retRational(nominator, ratNum2.nominator);
            return retRational;
        }
    }else{
        long int tempNominator = ratNum2.nominator;
        ratNum2.nominator = ratNum2.denominator;
        ratNum2.denominator = tempNominator;

        rational newRational;
        newRational = rational::operator*(ratNum2);
        return newRational;
    }
}

rational rational::operator* (rational &ratNum2){
    rational newRational;
    if(denominator == 1 && ratNum2.denominator == 1){
        long int newVal = 0;
        newVal = nominator * ratNum2.nominator;

        rational retRational(newVal);
        return retRational;

    }else if(denominator == 1 && ratNum2.denominator > 1){
        //Ex: 2 * 1/2 = 2/2 = 1
        /* New return value */
        rational retRational(nominator * ratNum2.nominator, denominator * ratNum2.denominator);
        return retRational;

    }else if(denominator > 1 && ratNum2.denominator == 1){
        //Ex: 1/2 * 2 = 2/2 = 1
        /* New return value */
        rational retRational(ratNum2.nominator * nominator, ratNum2.denominator * denominator);
        return retRational;

    }else{
        //Ex: 1/2 * 3/4 = 3/8
        /* New return value */
        rational retRational(ratNum2.nominator * nominator, ratNum2.denominator * denominator);
        return retRational;

    }
}