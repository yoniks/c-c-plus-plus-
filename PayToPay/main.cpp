//
//  main.cpp
//  PayToPay
//
//  Created by $ on 4/21/22.
//
#include <typeinfo>
#include <iostream>
using namespace std;
#include "PayToPay.h"
//Virtual Functions and Polymorphism
int main(int argc, const char * argv[]) {
    // insert code here...
    string email="yoni@icloud.com";
    string idUser="123445677";
    CreditCard pubObj;
    pubObj.nameCard="MasterCard";
    pubObj.date[0]=01;
    pubObj.date[1]=26;
    cout<<"number card\n";
   
    BaseUser *p=NULL;
  unsigned short int *p_value_card=NULL;
    try {
        p=new BaseUser();
    p_value_card= new unsigned short int[pubObj.SIZE];
    } catch (bad_alloc a) {
        return  1;
    }
    EncryptionCreditCard ecc;
    p=&ecc;//now pointer of BaseUser pointing
    p_value_card= pubObj.numberCard;//move the first adress of arry
    
    for(int i=0;i<pubObj.SIZE;i++){
        p_value_card[i]=1234*(i+1);//initialize card
        cout<<" "<<p_value_card[i]<<" ";
        
    }
    cout<<"__"<<p_value_card<<"\n ";

    if(p!=NULL){
    p->encryptionCard(&pubObj);
    p->decryptionCard(&pubObj);
    p_value_card= p->dynamicGrowArray(p_value_card, &pubObj.SIZE);
        // initialize a parameter of type 'unsigned short
        cout<<"size: "<<pubObj.SIZE<<  p_value_card[3] <<"\n";
       
    }
 
    Store ps;
   // ecc.nameCard=""; private member
    //p=&store;// now pointer of BaseUser pointing to object Store
    delete [] p_value_card;
    p=NULL;
    return 0;
}
/*
 long arrSize = *(&pubObj.numberCard +1) - pubObj.numberCard;
   cout << "The size of the array is: " << arrSize;
 */