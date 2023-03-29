#ifndef EX1_CALANDER_H
#define EX1_CALANDER_H
#include <iostream>
#include <cstring>
#include "MyDate.h"
using namespace std;
#define SIZE 5


class Calander {

public:
    Calander(); // constructor
    Calander(const Calander &x ); // copy constructor
    void setDate(int num, MyDate x);
    bool isFree(int num) const;
    int firsFree() const;
    int firsFull() const;
    bool insert(MyDate x);
    int oldest() const;
    int dateNum() const;
    void deleteAll();
    void deletDate(int num);
    void print() const;
    void printFullDay()const;
    ~Calander();  //destructor

private:
    MyDate *date[SIZE];
    int fullDay=0;

};
#endif //EX1_CALANDER_H
