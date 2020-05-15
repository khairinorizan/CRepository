/*
Author: Muhammad Khairi Norizan
Language: C, C++
Purpose: HW9 Integers Container
*/

#include <iostream>
#include "intbox.hh"
#include <array>
using namespace std;

intbox::intbox(){
    integerNum = 0;
}

intbox::intbox(int intnum){
    integerNum = intnum;
}

void intbox::show(ostream &s){
    s << integerNum;
}

bool intbox::contains(int a){
    if(integerNum == a){
        return true;
    }else{
        return false;
    }
}
singleton::singleton(){
    value = 0;
}

singleton::singleton(int setValue){
    value = setValue;
}

bool singleton::contains(int val){
    if(value == val){
        return true;
    }else{
        return false;
    }
}

void singleton::show(ostream &s){
    s << value;
}

interval::interval(){
    low = 0;
    high = 0;
}

interval::interval(int lower, int upper){
    if(lower > upper){
        throw "Invalid lower bound!";
    }else{
        low = lower;
        high = upper;
    }   
}

bool interval::contains(int val){
    if(val >= low && val <= high ){
        return true;
    }else{
        return false;
    }
}

void interval::show(ostream &s){
    s << "[" << low << "," << high << "]";
}

collection::collection(unsigned int arrSize){
    size = arrSize;
    classptr = new intbox*[size];

    for(int i=0; i < size; i++){
        classptr[i] = 0;
    }
}

void collection::set_item(unsigned int i, intbox* item){
    if(i > size-1){
        throw "Index out of bound!";
    }else{
        classptr[i] = (intbox *)malloc(1 * sizeof(intbox));
        classptr[i] = item;
    }
}

bool collection::contains(int val){
    if(classptr == 0){
        throw "Collection empty!";
    }else{
        for(int i=0; i < size; i++){
            if(classptr[i]->contains(val) == true){
                return true;
            }
        }
        return false;
    }
}

void collection::show(ostream &s){
    if(classptr == 0){
        throw "Collection empty!";
    }else{
        for(int i=0; i < size; i++){
            classptr[i]->show(cout);
        }
    }
}