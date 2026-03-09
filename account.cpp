#include<bits/stdc++.h>
using namespace std;
#include "account.h"

Customer cus[1000];
int countCustomer=0;


void loadFromFile() {
    ifstream fin("customer.txt");

    if (!fin) return; // file not found first time

    countCustomer = 0;
    while (fin >> cus[countCustomer].account_num
               >> cus[countCustomer].name
               >> cus[countCustomer].type
               >> cus[countCustomer].id
               >> cus[countCustomer].mobile
               >> cus[countCustomer].bal) {
        countCustomer++;
    }

    fin.close();
}



void saveToFile() {
    ofstream fout("customer.txt");

    for (int i = 0; i < countCustomer; i++) {
        fout << cus[i].account_num<< " "
             << cus[i].name << " "
             << cus[i].type<<" "
             << cus[i].id<<" "
             << cus[i].mobile<<" "
             << cus[i].bal << " "<<endl;
    }

    fout.close();
}


void addcustomer(){
    int acc_num;
    if(countCustomer==0) acc_num=1001;
    else acc_num=cus[countCustomer-1].account_num+1;

    cus[countCustomer].account_num=acc_num;
    cout<<"Enter Name of Customer: ";
    cin>>cus[countCustomer].name;
    cout << "Enter Account Type (Savings/Current): ";
    cin >> cus[countCustomer].type;
    cout<<"Enter ID of Customer: ";
    cin>> cus[countCustomer].id;
    cout<<"Emter Mobile Number of Customer: ";
    cin>> cus[countCustomer].mobile;
    cout<<"Enter Balence: ";
    cin>>cus[countCustomer].bal;
    countCustomer++;
    saveToFile();
    cout<<"Customer account Number is: "<<acc_num<<endl;
    cout<<"Customer details added succssfully!\n";

}



void searchcustomer(){
    cout<<"Enter Account Number of Customer: ";
    int account_no;
    cin>>account_no;
    for(int i=0;i<countCustomer;i++){
        if(cus[i].account_num==account_no){
            cout<<"Account Number: "<<cus[i].account_num<<endl;
            cout<<"Name of Customer: "<<cus[i].name<<endl;
            cout<<"Type of Account: "<<cus[i].type<<endl;
            cout<<"ID of Customer: "<<cus[i].id<<endl;
            cout<<"Mobile Number of Customer: "<<cus[i].mobile<<endl;
            cout<<"balence: "<<cus[i].bal<<endl;
        }
    }
}



void deletecustomer(){
    if(countCustomer==0){
        cout<<"There is no customer to delete";
        return ;
    }
    int account_num;
    cout<<"Enter Account number to delete account: ";
    cin>> account_num;
    for(int i=0 ; i<countCustomer;i++){
        if(cus[i].account_num== account_num){
            for(int j=i;j<countCustomer-1;j++){
                cus[j]=cus[j+1];

                
            }
            countCustomer--;
            saveToFile();
            cout<<"Customer account deleted succssfully!\n";
            return ;
        }

    }
    return;
    

}



void updatecustomer(){

    int acc;

    cout<<"Enter Account Number: ";
    cin>>acc;

    for(int i=0;i<countCustomer;i++){

        if(cus[i].account_num == acc){

            cout<<"Enter New Name: ";
            cin>>cus[i].name;
            cout<<"Enter New Account Type(Savings/Current): ";
            cin>>cus[i].type;
            cout<<"Enter New ID of Customer: ";
            cin>>cus[i].id;
            cout<<"Enter New Mobile Number: ";
            cin>>cus[i].mobile;
            
            saveToFile();


            

            cout<<"Customer updated successfully\n";

            return;
        }
    }

    cout<<"Customer not found\n";
}




