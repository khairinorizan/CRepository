/* 
* Author: Muhammad Khairi Norizan (Khairi)
* Purpose: HW7 Rational Class
* Language: C,C++
*/

#include <iostream>
#include "string.h"
using namespace std;

class rational {
    private:
    long int nominator;
    long int denominator;

    public:
    rational(){
        nominator = 0;
        denominator = 1;
    };
    rational(long int num1){
        nominator = num1;
        denominator = 1;
    };
    rational(long int num1, long int num2){
        if(num1 % num2 == 0){
            nominator = num1 / num2;
            denominator = 1;
        }else{
            nominator = num1;
            denominator = num2;
        }
    };

    long int getDominator(){
        return denominator;
    }

    long int getNominator(){
        return nominator;
    }

    public:
    rational operator+ (rational &ratNum2);
    rational operator- (rational &ratNum2);
    rational operator* (rational &ratNum2);
    rational operator/ (rational &ratNum2);
};
ostream& operator<<(ostream& out,rational ratNum);