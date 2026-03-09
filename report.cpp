#include "report.h"
#include<bits/stdc++.h>
using namespace std;





void displaycustomers(){
    if(countCustomer==0){
        cout<<"No Customer Available.\n";
        return;
    }
    cout<<"\nAccount No.\tName\t    Type of account\t    ID of Customer\t   Mobile Number\tBalence\n";
    for(int i=0;i<countCustomer;i++){
        cout<<cus[i].account_num<<"      "<<"\t"<<cus[i].name<<"      "<<"\t"<<cus[i].type<<"          "<<"\t"<<cus[i].id<<"          "<<"\t"<<cus[i].mobile<<"      "<<"\t"<<cus[i].bal<<endl;
    }


}



void totalBankMoney(){
    if(countCustomer==0){
        cout<<"There is no customer in your bank";
        return;
    }
    int total=0;
    for(int i=0 ;i<countCustomer;i++){
        
        total=total+cus[i].bal ;

    }
    cout<<"The total balence avialble in your bank is: "<<total;
    return ;
}


void richestAccount(){

    if(countCustomer == 0){
        cout<<"No customers available\n";
        return;
    }

    int richestIndex = 0;

    for(int i = 1; i < countCustomer; i++){
        if(cus[i].bal > cus[richestIndex].bal){
            richestIndex = i;
        }
    }

    cout<<"\n--- Richest Customer ---\n";
    cout<<"Account Number: "<<cus[richestIndex].account_num<<endl;
    cout<<"Name: "<<cus[richestIndex].name<<endl;
    cout<<"Type of Account: "<<cus[richestIndex].type<<endl;
    cout<<"ID of Customer: "<<cus[richestIndex].id<<endl;
    cout<<"Mobile Number: "<<cus[richestIndex].mobile<<endl;
    cout<<"Balance: "<<cus[richestIndex].bal<<endl;
}
    