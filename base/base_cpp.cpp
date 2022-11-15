//
// Created by ShaoCHi on 2022/10/29.
//
#include "iostream"
using namespace std;

/// ++i和i++区别
///b=a+(i++);   在调用i之后，i++会进行+1操作，即b=2，i=2
///c=a+(++i);   在调用i之前，++i会进行+1操作，即i=3;c=a+3----->c=4;

/***
int main(){
    int i=1;
    int a=1;
    int b=a+(i++);
    int c=a+(++i);
    std::cout<<b<<":"<<c<<std::endl;
    return 0;
}*/


///C++引用和指针的区别
///C++引用相当于同一个变量进行操作，在getResult函数中，p即为外部的a，p与a在内存中对应同一个地址，即&a=&p；所以在函数中对p值进行修改，
/// 即是在与a相同的内存地址上进行了修改操作，所以外部a的值会随之变化
///C++指针，int *b;b所对应的值为内存中的一个地址，*b为解析b所对应地址上存储的值。
//在64位的机器上一个地址对应8个字节，同理，在32位的机器上一个地址对应4个字节----------->涉及内存对其的问题
/***
void getResult(int& p){};
void getResult2(int*& p){};
int main(){
    int a=9;
    int* b=&a;
    getResult(a);
    getResult2(b);
}*/


///动态开辟数组:C++涉及到动态操作内存的操作时，需要动态开辟内存空间，同时在使用完毕需要对之前开辟的空间进行释放操作
///1、malloc动态开辟空间--->需要开辟空间的大小与类型
///2、使用new来进行动态开辟
///3、删除操作均由delete完成

/***
struct LNode{};
LNode* L = (LNode*) malloc(sizeof(LNode));
delete L; */

/***
auto* L=new LNode;
//开辟一维数组
int* arr = new int[5];
delete[] a;
//开辟多维数组
int** arr = new int*[5];
for(i=0;i<5;i++){
    arr[i] = new int[5];
}
for(i=0;i<5;i++){
    delete[] arr[i];
}
delete[] arr;
*/

///通过指针访问结构中的某个子部分时，只能使用->访问其分量
///通过变量名访问结构中的某个子部分时，只能使用.访问其分量
