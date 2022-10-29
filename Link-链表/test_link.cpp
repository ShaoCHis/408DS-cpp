//
// Created by ShaoCHi on 2022/10/29.
//

#include "single_link.h"
#include<iostream>
using namespace std;

int main(){
    cout<<"single_link_test START================"<<endl;
    test_link link = test_link(nullptr);
    cout<<"the head point is "<<link.getHead()<<endl;
    link.show();
    for(int i=0;i<8;i++){
        link.insert_last(i*i);
    }
    link.show();
    if (link.search_value(5)== nullptr)
        cout<<"sorry!We can't find the value;"<<endl;
    else
        cout<<"Congratulations!We  find the value;"<<endl;
    if (link.search_value(49)== nullptr)
        cout<<"sorry!We can't find the value;"<<endl;
    else
        cout<<"Congratulations!We  find the value;"<<endl;
    link.delete_value(49);
    link.show();
    cout<<"single_link_test END================"<<endl;
    return 0;
}