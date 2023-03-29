#include "Calander.h"
#include <iostream>
#include <string.h>
using namespace std;

Calander::Calander() {

    for(int i=0; i<SIZE; i++){
        date[i]= nullptr;
    }
    fullDay=0;
}

bool Calander::isFree(int num) const{
    if(num-1<0 || num-1>SIZE){
        cout<<"Invalid number  ";
        return false;
    }
    if(date[num-1]==nullptr) {
        return false;
    }
    else
        return true;
}

int Calander::firsFree() const {
    for(int i=0; i<SIZE; i++){
        if(date[i]==nullptr)
            return i+1;
    }
    return -1;
}

Calander::Calander(const Calander &x) { //copy constructor
    for(int i=0; i<SIZE; i++){
        date[i]=x.date[i];
    }
    fullDay= x.fullDay;
}

void Calander::setDate(int num, MyDate x) {
    date[num-1] = new MyDate(x);
    fullDay++;
}

bool Calander::insert(MyDate x) {

    for(int i=0; i<SIZE; i++){
        if(date[i]==nullptr){
            date[i]=new MyDate(x);
            fullDay++;
            return true;
        }
    }
    return false;
}

int Calander::dateNum() const {
    return fullDay;
}

void Calander::deleteAll() {
    fullDay=0;
    for (int i = 0; i < SIZE; i++)
        delete[] date[i];

}

void Calander::deletDate(int num)  {

    if(num>=1 && num<=30) {
        if (date[num] != nullptr) {

            date[num] = nullptr;
        }
    }
    else
        cout<<"invalid input";
}

void Calander::print() const {

    for(int i=0; i<SIZE; i++){
        if(date[i]!= nullptr) {
            cout << "date [" << i + 1 << "] --> ";
            date[i]->print();
        }
        else
            cout<<"date["<<i+1<<"] is Empty "<<endl;
    }

    cout<<" number of total full day is: "<<fullDay;

}

int Calander::firsFull() const {
    for(int i=0; i<SIZE; i++){
        if(date[i]!=nullptr){
            return i;
        }
    }
    return -1;
}

int Calander::oldest() const {
    if(fullDay!=0){
        int x,minIndex=0;
        MyDate min;
        x = firsFull();
        if (x == -1) {
            x = 0;
        }
        for (int i = 0; i < SIZE; i++) {
            if (date[i] == nullptr)
                continue;
            if (!min.isBefore(*date[i])) {
                min = *date[i];
                minIndex=i;
            }
        }
        return minIndex;
    }
    else return -1;
}

void Calander::printFullDay() const{
    cout<<"the number of full days is:"<<fullDay;
    cout<<endl;
}

Calander::~Calander() {   //destructor
    for(int i=0; i<SIZE; i++){
        delete [] date[i];
    }
}


