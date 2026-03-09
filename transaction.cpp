#include<bits/stdc++.h>
using namespace std;
#include "transaction.h"



string getCurrentDate()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);

    stringstream ss;

    ss << 1900 + ltm->tm_year << "-"
       << setw(2) << setfill('0') << 1 + ltm->tm_mon << "-"
       << setw(2) << setfill('0') << ltm->tm_mday;

    return ss.str();
}



string getCurrentTime()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);

    stringstream ss;

    ss << setw(2) << setfill('0') << ltm->tm_hour << ":"
       << setw(2) << setfill('0') << ltm->tm_min << ":"
       << setw(2) << setfill('0') << ltm->tm_sec;

    return ss.str();
}



void saveTransaction(int account_num,string id ,string type, float amount) {
    ofstream fout("transaction.txt",ios::app);

    
    fout << account_num<< " "
         << id<<" "
         << type << " "
         << amount << " "
         << getCurrentDate()<<" "
         << getCurrentTime()<<endl;







    

    fout.close();
}


void deposit(){
    int account_num;
    string id;
    cout<<"Please enter account number of Customer: ";
    cin>>account_num;
    cout<<"Please enter ID of Customer: ";
    cin>>id;
    float dep_money;
    cout<<"Please enter amount to deposit: ";
    cin>>dep_money;
    for(int i=0; i<countCustomer;i++){
        if(cus[i].account_num== account_num && cus[i].id==id){
            cus[i].bal=cus[i].bal+dep_money;
            saveTransaction(account_num,id,"Deposit",dep_money);
            saveToFile();
            cout<<"Money deposited succssfully!\n";
            break;
        }
        
    }
    return;


}



void withdraw(){
    string id;
    int account_num;
    cout<<"Please enter account number of Customer: ";
    cin>>account_num;
    cout<<"Please enter ID of Customer: ";
    cin>>id;
    float w_money;
    cout<<"Please enter amount to withdraw: ";
    cin>>w_money;
    
    for(int i=0; i<countCustomer;i++){
        if(cus[i].account_num== account_num && cus[i].bal>=w_money && cus[i].id==id){
            cus[i].bal=cus[i].bal-w_money;
            saveTransaction(account_num,id, "Withdraw",w_money);
            saveToFile();
            cout<<"Money withdraw succssfully!\n";
            break;
        }
        else if(cus[i].account_num==account_num){
            cout<<"Insufficient balence\n";
        }
        
    }
    return;


}



void checkbal(){

    int acc;
    cout<<"Enter Account Number: ";
    cin>>acc;

    for(int i=0;i<countCustomer;i++){

        if(cus[i].account_num == acc){

            cout<<"Account Number: "<<cus[i].account_num<<endl;
            cout<<"Name: "<<cus[i].name<<endl;
            cout<<"Type of Account: "<<cus[i].type<<endl;
            cout<<"ID of Customer: "<<cus[i].id<<endl;
            cout<<"Mobile Number of Customer: "<<cus[i].mobile<<endl;
            cout<<"Current Balance: "<<cus[i].bal<<endl;

            return;
        }
    }

    cout<<"Account not found\n";
}




void transactionhistory(){
    int acc;
    string startDate, endDate;
    string id;
    cout<<"Enter Account Number: ";
    cin>>acc;
    
    cout<<"Enter ID of Customer: ";
    cin>>id;
    cout<<"Enter Start Date (YYYY-MM-DD): ";
    cin>>startDate;

    cout<<"Enter End Date (YYYY-MM-DD): ";
    cin>>endDate;

    ifstream fin("transaction.txt");

    int accNo;
    string type, date, time,Id;
    float amount;

    cout<<"\n---- Transaction History ----\n";
    cout<<"Account Number: "<<acc<<endl;
    cout<<"ID of Customer: "<<id<<endl;
    cout<<"Transaction History From "<<startDate<<" To "<<endDate<<endl;
    cout<<"\tType\t     Amount\t    Date\t     Time\n";
    bool found = false;

    while(fin >> accNo >>Id>> type >> amount >> date >> time){
        
        if(accNo == acc && date >= startDate && date <= endDate && Id==id){
            
            cout<<"        "<<type<<"       "<<amount<<"          "<<date<<"         "<<time<<endl;
            found = true;
        }
    }

    if(!found)
    cout<<"No transactions in this date range\n";



    fin.close();
}


