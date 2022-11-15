//
// Created by ShaoCHi on 2022/11/14.
//
#include<iostream>
#include<cstdio>
#ifndef INC_408DS_CPP_STATICLINK_H
#define INC_408DS_CPP_STATICLINK_H

#define MAX_SIZE 100

/***
 * 该实现仿造链表实现：
 * 即在进行插入操作时，默认为尾部插入
 * 实际上可以直接进行头部插入，节省遍历的效率；
 * 同时，在删除操作完成后，进行备用链的更新时也可以直接使用头部更新
 */

typedef struct SLNode {
    int value;
    int cur;

    SLNode() {};

    SLNode(int _value, int _cur) : value(_value), cur(_cur) {};
};

class static_link {
    SLNode *l = new SLNode[MAX_SIZE];
    unsigned int length;

public:
//初始化静态链表
//首尾结点保持特殊初始化,-1表示截止和空值
    static_link() {
        length = 0;
        for (int i = 1; i < (MAX_SIZE - 1); i++) {
            l[i] = SLNode(-1, i + 1);
        }
        l[MAX_SIZE - 2] = SLNode(-1, -1);
        l[0] = SLNode(-1, -1);
        l[MAX_SIZE - 1] = SLNode(-1, 1);
    }

    void show_static_link() {
        std::cout << "max size is " << MAX_SIZE <<";the length of used link is "<<length<<"."<< std::endl;
        std::cout << "used link:" << std::endl;
        if (l[0].cur == -1)
            std::cout<<std::endl << "used link is null!" << std::endl;
        else {
            SLNode temp = l[l[0].cur];
            std::cout << "start->" << "index:"<<l[0].cur<<";value:";
            while (temp.cur != -1) {
                std::cout<<temp.value;
                std::cout << "->" <<"index:"<< temp.cur<<";value:";
                temp = l[temp.cur];
            }
            std::cout<<temp.value;
        }
        std::cout <<std::endl<< "unused link:" << std::endl;
        if (l[MAX_SIZE - 1].cur == -1)
            std::cout << "unused link is null!" << std::endl;
        else {
            SLNode temp = l[l[MAX_SIZE - 1].cur];
            std::cout << "start->"  << "index:"<<l[MAX_SIZE-1].cur<<";value:";
            while (temp.cur != -1) {
                std::cout<<temp.value;
                std::cout << "->" <<"index:"<< temp.cur<<";value:";
                temp = l[temp.cur];
            }
            std::cout<<temp.value;
        }
        std::cout<<std::endl;
    }

    void init_value(){
        for(int i=0;i<20;i++) {
            length+=1;
            int _value = rand()%100;
            SLNode* temp = &l[0];
            while(temp->cur!=-1)
                temp = &l[temp->cur];
            temp->cur = l[MAX_SIZE-1].cur;
            l[MAX_SIZE-1].cur = l[l[MAX_SIZE-1].cur].cur;
            l[temp->cur].value = _value;
            l[temp->cur].cur = -1;
        }
    }

    void insert(int _value){
        if(length==MAX_SIZE-2){
            std::cout<<"link is full;Can't insert new item"<<std::endl;
            return;
        }
//找到静态链表的最后一个结点
        SLNode* temp = &l[0];
        while(temp->cur!=-1)
            temp = &l[temp->cur];
        length+=1;
        temp->cur = l[MAX_SIZE-1].cur;
        l[temp->cur].value=_value;
        l[MAX_SIZE-1].cur = l[temp->cur].cur;
        l[temp->cur].cur=-1;
        std::cout<<std::endl<<"insert new item success!"<<"Now the length of the used link is "<<length<<std::endl;
        show_static_link();
    }

    void delete_value(int _value){
        if(length==0){
            std::cout<<"link is null!Can't delete item"<<std::endl;
            return;
        }
        SLNode* temp = &l[0];
        while(temp->cur!=-1 and l[temp->cur].value!=_value)
            temp = &l[temp->cur];
        if(l[temp->cur].value==_value){
            if (l[temp->cur].cur==-1){
                l[temp->cur].value = -1;
                l[temp->cur].cur = l[MAX_SIZE-1].cur;
                l[MAX_SIZE-1].cur = temp->cur;
                temp->cur = -1;
            }
            else{
                int location = temp->cur;
                temp->cur = l[temp->cur].cur;
                l[location].value = -1;
                l[location].cur = l[MAX_SIZE-1].cur;
                l[MAX_SIZE-1].cur=location;
            }
            length-=1;
            show_static_link();
        }
        else{
            std::cout<<"the value not in static link"<<std::endl;
        }
    }
};


#endif //INC_408DS_CPP_STATICLINK_H
