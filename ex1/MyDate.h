#ifndef EX1_MYDATE_H
#define EX1_MYDATE_H
#include <iostream>
#include <cstring>
using namespace std;

class MyDate {
public:
    MyDate(); //default constructor
    MyDate(int day, int month, int year, char* str); // constructor
    MyDate(const MyDate &x); // copy constructor
    bool isBefore(const MyDate &date) const;
    bool setDay(int d);
    bool setMonth(int m);
    bool setYear(int y);
    void setDate(int d, int m, int y);
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    void inc(int d, int m, int y);
    void print() const;
    void changeComment(char str[50]);
    void init();
     MyDate &operator=(const MyDate &x);
     ~MyDate(); //destructor

private:
    int day, month, year;
    char *note;
};


#endif //EX1_MYDATE_H
