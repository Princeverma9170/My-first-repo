//This is my first project 
#include<bits/stdc++.h>
using namespace std;

#include "account.h"
#include "transaction.h"
#include "report.h"

bool login() {
    string username, password;
    int attempts = 0;

    while (attempts < 3) {
        cout << "\n--- SECURITY LOGIN ---\n";
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;

        // Simple hardcoded credentials for now
        if (username == "Admin" && password == "hello") {
            cout << "Login Successful!\n";
            return true;
        } else {
            attempts++;
            cout << "Invalid credentials. Attempts remaining: " << (3 - attempts) << endl;
        }
    }
    return false;
}


int main(){
    if (!login()) {
        cout << "Too many failed attempts. Exiting program...\n";
        return 0;
    }
    loadFromFile();
    int mainChoice;

    while(true){

        cout<<"\n===== BANK SYSTEM =====\n";
        cout<<"1. Account Management\n";
        cout<<"2. Transactions\n";
        cout<<"3. Reports\n";
        cout<<"4. Exit\n";
        cout<<"Enter choice: ";
        cin>>mainChoice;

        switch(mainChoice){

            case 1:{
                int accChoice;

                while(true){
                    cout<<"\n--- Account Management ---\n";
                    cout<<"1. Add Customer\n";
                    cout<<"2. Update Customer\n";
                    cout<<"3. Delete Customer\n";
                    cout<<"4. Search Customer\n";
                    cout<<"5. Back\n";
                    cout<<"Enter choice: ";
                    cin>>accChoice;

                    if(accChoice==1) addcustomer();
                    else if(accChoice==2) updatecustomer();
                    else if(accChoice==3) deletecustomer();
                    else if(accChoice==4) searchcustomer();
                    else if(accChoice==5) break;
                    else cout<<"Invalid choice\n";
                }

                break;
            }

            case 2:{
                int tranChoice;

                while(true){
                    cout<<"\n--- Transactions ---\n";
                    cout<<"1. Deposit\n";
                    cout<<"2. Withdraw\n";
                    cout<<"3. Balance Check\n";
                    cout<<"4. Transaction History\n";
                    cout<<"5. Back\n";
                    cout<<"Enter choice: ";
                    cin>>tranChoice;

                    if(tranChoice==1) deposit();
                    else if(tranChoice==2) withdraw();
                    else if(tranChoice==3) checkbal();
                    else if(tranChoice==4) transactionhistory();
                    else if(tranChoice==5) break;
                    else cout<<"Invalid choice\n";
                }

                break;
            }

            case 3:
                int repChoice;

                while(true){
                    cout<<"\n--- Reports ---\n";
                    cout<<"1. Display Customer Details\n";
                    cout<<"2. Total bank Money\n";
                    cout<<"3. Richest Account in Bank\n";
                    cout<<"4.back\n";
                    cout<<"Enter choice: ";
                    cin>>repChoice;

                    if(repChoice==1) displaycustomers();
                    else if(repChoice==2) totalBankMoney();
                    else if(repChoice==3) richestAccount();
                    else if(repChoice==4) break;
                    else cout<<"Invalid choice\n";
                }

                break;

            case 4:
                saveToFile();
                cout<<"Exiting program...\n";
                
                return 0;

            default:
                cout<<"Invalid choice\n";
        }
    }

    return 0;
}