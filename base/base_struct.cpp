//
// Created by ShaoCHi on 2022/10/29.
//
#include<iostream>
#include <utility>
using namespace std;
///关于typedef的使用
///1、使用typedef后在初始化结构体时可以不用声明struct关键字
///2、不使用typedef在初始化结构体时需要声明struct关键字(经测试好像也不用声明struct关键字）
///加上typedef可以这样声明变量，即在struct的末尾进行结构体的命名：
///     typedef struct{
///         string name;
///         int age;
///     }student;
///     student* stu = new student;
///这样命名不能在结构体内部进行同结构体的声明--------->链表结点

//所以按照这种写比较好
struct student{
    string name;
    int age{};
    //默认结构体构造函数
    student()= default;
    //自定义构造函数
    //在定义自定义构造函数后将覆盖默认构造函数，即若未再次进行默认构造函数的声明将无法使用
    ///student(string _name,int _age):name(_name),age(_age){};
    ///这种方式相较于下面的方式多了一次将_name复制到name的操作
    student(string _name,int _age):name(std::move(_name)),age(_age){};
};

struct room{
    int class_num;
    student* stu;
    room() = default;
    ///explicit关键字声明：使该构造函数不能被隐式调用
    explicit room(int _num):class_num(_num),stu(nullptr){};
};

struct Node{
    int value;
    ///注意这里仅仅只能在同名结构体中声明同名指针
    ///这是因为C++在声明一个变量时需要为其分配其对应大小的空间
    ///指针在64位机器上占用8个字节，有明确大小
    ///非指针则为一个变量，想象一个构造函数的递归过程，那么这个变量没有确定的大小
    Node* next;
};
/***
 * 测试代码
 * @return 0
int main(){
    student stu1={"1",20};
    student stu2={"2",18};
    student stu[]={stu1,stu2};
    room first = room(1);
    first.stu=stu;
    cout<<first.stu[1].name<<endl<<first.stu[0].name<<endl;
    return 0;
}
***/
