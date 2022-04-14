//
//  Template.h
//  Spider_Search
//
//  Created by $ on 4/11/22.
//
/* void setNews(N *d, int i){
     if(i<0 || i>Size-1){
         throw "Error: ";
     }
     N *p;
     p=d;
     Data[i]= *p;
     p++;
     Data[++i]= *p;
     
     cout<<"-> "<<*p<<"->>" <<Data[1];
   }*/

#ifndef Template_h
#define Template_h
#include <iostream>
#include <map>
#include <cstring>
using namespace std;
//template <typename  N, int Size>
//extern int SIZE;
template <class  N, int Size=50>
struct TData {
private:
    N *p;
    N Data[Size];
    N value;
public:
    N *getData();
    N getValue();
    N &operator[] (int i);
    ~TData();
   // News(N *n);
    TData(N n);
    TData();
};
/*template<class N, int Size>
void News<N,Size>::setData(N *n){
    p=n;
}*/

template<class N, int Size>
TData<N,Size>::TData(N v){
    value=v;
}
template<class N, int Size>
TData<N,Size>::TData(){}

template<class N, int Size>
N *TData<N,Size>::getData(){
    for(int i=0;*p;i++){
        Data[i]=*p;
        p++;
    }
    return Data;
}

template<class N, int Size>
N TData<N,Size>::getValue(){
  //  cout<<"getV"<<value<<"\n";
    return value;
}
template<class N, int Size>
N &TData<N, Size>::operator[](int i)
{
    if(i<0 || i>Size-1){
        throw "Error: ";
    }
    return Data[i];
}
template<class N, int Size>
TData<N,Size>::~TData(){
  //  cout<<"Destructing"<<"\n";
}





template <class C1, class C2>
struct Country {
private:
    C1 anyKeyType1, anyKeyType2;
    C2 T;
    map<Country<string, string>,TData<string>> d;
    map<Country<string, string>,TData<int>> d1;
    
public:
    // member functions
    C1 getKeyType1(){
        return anyKeyType1;
    }
    C1 getKeyType2(){
        return anyKeyType2;
    }
    ~Country();
    Country(C1 _ad1);
    Country(C1 _ad1,C1 _ad2);
   // Country(C1 _ad1,C1 _ad2,C1 ad3);
    void setValueString(string v);
    void setValueInt(int v);
    string isTypeStr();// return value if str
    int isTypeInt();// return value if int, save me copy code
    
    C2 getStrBy1Key(C1 _ad1);
    C2 getStrBy2Key(C1 _ad1,C1 _ad2);
    
    C2 getIntBy1Key(C1 _ad1);
    C2 getIntBy2Key(C1 _ad1,C1 _ad2);
  //  C2 getValueBy3Key(C1 _ad1,C1 _ad2,C1 _ad3);

};


//template <class C1,class C2> <-dont declared here!
bool operator<(Country<string, string>  a,Country<string, string> b){
    return a.getKeyType1()<b.getKeyType1();
}



// by one key
template <class C1,class C2>
Country<C1, C2>::Country(C1 _ad1){
    if(_ad1==C1{}){//if null
        throw "Error";
    }
    anyKeyType1=_ad1;
    cout<<"key: "<<anyKeyType1<<"\n";
}
//by two key
template <class C1,class C2>
Country<C1, C2>::Country(C1 _ad1, C1 _ad2){
    if(_ad1==C1{}||_ad2==C1{}){//if null
        throw "Error";
    }
    anyKeyType1=_ad1+_ad2;
}


template <class C1,class C2>
void Country<C1, C2>::setValueString(string __v){
    T=__v;
    d.insert(pair<Country<string , string>,TData<string>>
             (Country<string, string>(anyKeyType1),TData<string>(T)));
       
}

template <class C1,class C2>
void Country<C1, C2>::setValueInt(int __v){
    T=__v;
    d1.insert(pair<Country<string , string>,TData<int>>
             (Country<string, string>(anyKeyType1),TData<int>(T)));
     
}


/* <key, value> if we declared the value
as int we must set int and return int
return the value <type1,type2> by key*/
template <class C1,class C2>
C2 Country<C1, C2>::getStrBy1Key(C1 _ad1){
    T=  isTypeStr();
     return (C2)T;
}
template <class C1,class C2>
C2 Country<C1, C2>::getStrBy2Key(C1 _ad1,C1 _ad2){
       T=  isTypeStr();
        return (C2)T;
}
template <class C1,class C2>
C2 Country<C1, C2>::getIntBy1Key(C1 _ad1){
    T=  isTypeInt();
     return (C2)T;
}
template <class C1,class C2>
C2 Country<C1, C2>::getIntBy2Key(C1 _ad1,C1 _ad2){
    T=  isTypeInt();
     return (C2)T;
}



template <class C1,class C2>
string Country<C1, C2>::isTypeStr(){
    map<Country<string, string>,TData<string>>::iterator r;
   r= d.find(Country<string, string>(anyKeyType1));//_ad1+_ad2
    if(r!=d.end()){
        return  r->second.getValue();
    }
    return "";
}
template <class C1,class C2>
int Country<C1, C2>::isTypeInt(){
    map<Country<string, string>,TData<int>>::iterator r1;
    r1= d1.find(Country<string, string>(anyKeyType1));
     if(r1!=d1.end()){
         return r1->second.getValue();
     }
    return 0;
}
template <class C1,class C2>
Country<C1, C2>::~Country(){}









/*template<typename type1,typename type2>
struct MapAt{
private:
    type1 key;
    type2 value;
          // key                //value
    map<Country<type1, type2>, News<type2>> d;
   typename map<Country<type1, type2>,News<type2>>::iterator r;
public:
   bool setKeyAndValue(type1 k,type2 v);
    type2 getValue(type1 k);
};

template<typename type1,typename type2>
bool MapAt<type1, type2>::setKeyAndValue(type1 k, type2 v)
{
    d.insert(pair<Country<type1 , type2>,News<type2>>(
              Country<type1 ,type2 >(k),News<type2>(v)));
    return false;
}

template<typename type1,typename type2>
type2 MapAt<type1, type2>::getValue(type1 k){
    

      r= d.find(Country<type1, type2>(k));
      if(r!=d.end()){
          return r->second.getData();
         // cout<<r->second.getData()<<"\n";
      }
    return false;
}*/



/*#if _LIBCPP_STD_VER > 11
template <class C1=void,class C2=void>
#else
template <class C1, class C2>
#endif*/









#endif /* Template_h */
