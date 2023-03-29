#include <iostream>
#include "MyDate.h"
#include "Calander.h"
using namespace std;

int main()
{
    Calander calender;
    MyDate d, d2;
    MyDate *d3=nullptr;
    int day, month, year,day2, month2, year2,num,index,temp,size,count=0;
    char str[50];
    char ch;

    cout<<"default constructor"<<endl;
     MyDate(); //default constructor.
     d.print();
    cout<<"enter date:";
    cin>>day>>ch>>month>>ch>>year;
    cout<<endl<<"enter note:";
    cin>>str;
    MyDate (day,month,year,str);
    cout<<endl<<"d.setDate:"<<endl;
    d.setDate(day, month, year);
    d.print();
    cout<<"d.inc:"<<endl;
    d.inc(day, month, year);
    d.print();
    cout<<"d.init:"<<endl;
    d.init();
    d.print();

    cout<<"enter one more date:";
    cin>>day2>>ch>>month2>>ch>>year2;

    d2.setDate(day2, month2, year2);
    cout<<"d.isBefore(d2):"<<endl;
    if(d.isBefore(d2)){
        cout<<"date 2 is before date 1"<<endl;
    }
    else{
        cout<<"date 1 is before or equal date 2"<<endl;
    }

    cout<<"enter new note:";
    cin>>str;
    cout<<str<<endl;
    cout<<" d.changeComment(str):"<<endl;
    d.changeComment(str);

    cout<<endl;
    cout<<endl<<"part two:"<<endl;
    cout<<" calender.setDate(num,d):"<<endl;
    cout<<"Please enter a number of dates that you would like to reset[Maximum "<<SIZE<<"] :";
    cin>>num;
    cout<<endl;
    do{
        cout<<"enter index in calender of date["<<num<<"]:";
        cin>>index;
        cout<<"please enter date["<<num<<"]:";
        cin>>day>>ch>>month>>ch>>year;
        d.setDate(day, month, year);
        calender.setDate(index,d);
        num--;
    }while(num>0);

    cout<<"calender.isFree(num):"<<endl;
    cout<<"enter number to check if the date if free:";
    cin>>num;
    if(!calender.isFree(num)){
        cout<<"free pleas;"<<endl;
    } else cout<<"full date"<<endl;

    cout<<"calender.firsFree():"<<endl;
     temp=calender.firsFree();
     if(temp==-1)
         cout<<"the array is full";
     else cout<<"the firs free index is:"<<temp<<endl;;


    cout<<"calender.insert(d):"<<endl;
    cout<<"insert date to the calender:";
    cin>>day>>ch>>month>>ch>>year;
    d.setDate(day, month, year);
     if(!calender.insert(d))
         cout<<"Not enough space in array";
     else cout<<"The date has been entered successfully";
     cout<<endl;
     cout<<" calender.print():"<<endl;
     calender.print();

    cout<<" calender.deleteDate(index):"<<endl;
    calender.deletDate(3);
    calender.deleteAll();
    calender.print();

     temp=calender.oldest();
     if(temp==-1){
         cout<<"empty array"<<endl;
     }else cout<<"the index of the minimum date is: "<<temp<<endl;
    cout<<"calender.dateNum():"<<endl;
    temp= calender.dateNum();
    cout<<temp<<endl;

    return 0;
}


