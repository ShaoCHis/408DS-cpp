//
// Created by 沈韬 on 2022/11/20.
//

#include "iostream"
#include "translate_stack.h"
using namespace std;
/***
 * 本代码实现利用栈求解表达式的值，仅作演示使用，所以这里仅仅使用个位数的数值进行运算操作
 * 同时，确保所有输入表达式合法
 */

//求解中缀表达式的计算结果，
/***
 * 步骤如下：
 * 利用两个栈来求解表达式的最终计算结果，操作数栈S1，运算符栈S2
 * 1、从左往右扫描中缀表达式
 * 2、遇到操作数，则直接入栈S1
 * 3、遇到左括号，直接入栈S2
 * 4、遇到运算符
 * ===》S2栈为空或S2栈顶元素为左括号，则该运算符直接入栈
 * ===》S2栈非空且栈顶元素不为左括号，则将该运算符优先级与S2栈顶元素优先级进行比较，
 * =====》若该运算符优先级大于栈顶运算符优先级，则直接将该运算符入栈S2
 * =====》若该运算符优先级小于或等于栈顶元素优先级，那么将栈顶元素弹出，并从S1中弹出两个操作数进行运算，注意，S1中第一个弹出的操作数在运算符的右侧，并将运算结果入栈S1，重复，直至该运算符入栈
 * 5、遇到右括号，则将S2中元素弹出，一直遇到左括号为止，并对S2中弹出的每一个元素进行一次运算操作，注意第一次弹出的操作数在运算符的左侧
 * 6、重复扫描直到表达式扫描完毕，若S2栈中还存在运算符，则依次弹出进行计算最终S1中留下的最后一个元素即为该表达式的最终答案
 * @param input
 * @return
 */
 // (<<+==-<<*==/
int compute_mid(string input){
    stack_link s1 = stack_link();
    stack_link s2 = stack_link();
    for(int i =0;i<input.length();i++){
        switch (input[i]) {
            case '+':{
                if (s2.is_empty() or s2.get_pop_item()=='(')
                    s2.push(input[i]);
                else{
                    int num2 = (int)s1.get_pop_item() - 48;
                    s1.pop();
                    int num1 = (int)s1.get_pop_item() - 48;
                    int result = num1+num2;
                    s1.push((char)(result+48));
                }
                break;
            }
            case '-':{
                break;
            }
            case '*':{
                break;
            }
            case '/':{
                break;
            }
            case '(':{
                break;
            }
            case ')':{
                break;
            }
            default:{
                break;
            }
        }
    }
}

int compute_front(string input){
    stack_link s1 = stack_link();
    stack_link s2 = stack_link();
    for(int i =0;i<input.length();i++){
        switch (input[i]) {
            case '+':{
                break;
            }
            case '-':{
                break;
            }
            case '*':{
                break;
            }
            case '/':{
                break;
            }
            case '(':{
                break;
            }
            case ')':{
                break;
            }
            default:{
                break;
            }
        }
    }
}


int compute_back(string input){
    stack_link s1 = stack_link();
    stack_link s2 = stack_link();
    for(int i =0;i<input.length();i++){
        switch (input[i]) {
            case '+':{
                break;
            }
            case '-':{
                break;
            }
            case '*':{
                break;
            }
            case '/':{
                break;
            }
            case '(':{
                break;
            }
            case ')':{
                break;
            }
            default:{
                break;
            }
        }
    }
}

int main(){

}

