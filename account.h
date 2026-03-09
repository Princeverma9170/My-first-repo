#ifndef ACCOUNT_H
#define ACCOUNT_H
#include<bits/stdc++.h>
using namespace std;
struct Customer{
    int account_num;
    string name;
    string type;
    string id;
    int mobile;
    float bal;


};
extern Customer cus[1000];     
extern int countCustomer;

void addcustomer();
void searchcustomer();
void deletecustomer();
void updatecustomer();
void loadFromFile();
void saveToFile();


#endif