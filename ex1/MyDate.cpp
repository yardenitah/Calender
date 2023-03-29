#include "MyDate.h"

MyDate::MyDate() { //default constructor
    char tmp[]="First date" ;
    day=1;month=1;year=2013;
    note=new char[50]; //Dynamic allocation
    strcpy(note,tmp);
}

MyDate::MyDate(int day, int month, int year, char* str) {
    this->day=day;
    this->month=month;
    this->year=year;
    note=new char[strlen(str)+1];
    strcpy(note,str);
}

bool MyDate::setDay(int d) {
    if(d<0) {
        cout<<"invalid day"<<endl;
        return false;
    }

    if(getMonth()==2 && d>28) {
        cout<<"invalid day"<<endl;
        return false;
    }
    if((getMonth()==4 || getMonth()==6 || getMonth()==9 || getMonth()==11) && d>30){
        cout<<"invalid day"<<endl;
        return false;
    }
        if((getMonth()==1 || getMonth()==3 || getMonth()==5 || getMonth()==7 || getMonth()==10 || getMonth()==12)&& (d>31) ) {
            cout<<"invalid day"<<endl;
        return false;
    }
        else{
            day=d;
            return true;
        }
}

bool MyDate::setMonth(int m) {

    if(m<0 || m>12) {
        cout<<"invalid month";
        return false;
    }
    else{
        month=m;
        return true;
    }
}

bool MyDate::setYear(int y) {

    if(y<=0) {
        cout<<"invalid year";
        return false;
    }
    else{
        year=y;
        return true;
    }
}

void MyDate::setDate(int d, int m, int y) {

    int newDay=1, newMonth=1, newYear=1900;

    if(!setYear(y)){
        y=newYear;
        year=y;
    }
    if(!setMonth(m)){
        m=newMonth;
        month=m;
    }
    if(!setDay(d)){
        d=newDay;
        day=d;
    }
}

int MyDate::getDay() const {
    return day;
}

int MyDate::getMonth() const {
    return month;
}

int MyDate::getYear() const {
    return year;
}

void MyDate::inc(int d, int m, int y) {

    int newDay=d+1, newMonth=m+1, newYear=y+1;

    if(newMonth==13){
        newDay=1;newMonth=1;
    }

    if((newMonth==1 || newMonth==3 || newMonth==5 || newMonth==7 || newMonth==10 || newMonth==12)&& (newDay==32) ) {
        if(newMonth==12 && newDay==32){
            newDay=1;newMonth=1;
        }

    }

   else if((newMonth==4 || newMonth==6 || newMonth==9 || newMonth==11) && (newDay==31) ) {
        newDay=1;
        newMonth++;
    }

   else if(newMonth==2 && newDay==29){
        newDay=1;
        newMonth++;
   }

    day=newDay; month=newMonth; year=newYear;
}

void MyDate::print() const {

    cout<<"the date is: ";
    cout<<day<<"/"<<month<<"/"<<year<<endl;
    cout<<endl;
}

bool MyDate::isBefore(const MyDate &date)  const{

    if(this->year < date.year){
        return true;
    }

    else if(date.year == this->year && this->month < date.month){
        return true;
    }

    else if (date.year == this->year && date.month == this->month  && this->day < date.day){
        return true;
    }

    else{
        return false;
    }

}

MyDate::MyDate(const MyDate &x) {
    this->day=x.day;
    this->month=x.month;
    this->year=x.year;
    this->note=new char[strlen(x.note)+1];
    strcpy(this->note, x.note);
}

void MyDate::changeComment(char *str) {

    note=new char[strlen(str)+1];
    strcpy(note,str);
    cout<<"the new note is:";
    cout<<note;
}

void MyDate::init() {
    this->day=16;
    this->month=12;
    this->year=2022;
}

MyDate::~MyDate() {
    delete[] note;
}

MyDate &MyDate::operator=(const MyDate &x) {
    this->day=x.day;
    this->month=x.month;
    this->year=x.year;
    this->note=new char[strlen(x.note)+1];
    strcpy(this->note, x.note);
    return *this;
}