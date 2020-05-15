/*
Author: Muhammad Khairi Norizan
Language: C, C++
Purpose: HW9 Integers Container
*/

#include <iostream>
using namespace std;

class intbox {
    private:
    int integerNum;

    public:
    intbox();
    intbox(int intnum);

    ~intbox(){};

    virtual bool contains(int a);
    virtual void show(ostream &s);

};

class singleton: public intbox {
    private:
    int value;

    public:
    singleton();
    singleton(int setValue);

    ~singleton(){};

    bool contains(int val);
    void show(ostream &s);
};

class interval: public intbox {
    private:
    int low;
    int high;

    public:
    interval();
    interval(int lower, int upper);

    ~interval(){};

    bool contains(int val);
    void show(ostream &s);
};

class collection: public intbox {
    private:
    unsigned int size;
    intbox **classptr;

    public:
    collection(unsigned int arrSize);

    ~collection(){};

    void set_item(unsigned i, intbox* item);
    bool contains(int val);
    void show(ostream &s);
};