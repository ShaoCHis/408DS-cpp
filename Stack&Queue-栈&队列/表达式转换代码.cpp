//
// Created by 沈韬 on 2022/11/18.
//

#include "translate_stack.h"
#include "iostream"

using namespace std;

//中缀表达式转后缀表达式
string translate_back(string input) {
    string result = "";
    stack_link stack = stack_link();
    //需要对输入表达式中的每个字符进行判断
/***中缀表达式转后缀表达式的步骤为：
 * 从前向后扫描输入字符串对字符串的每个字符进行判断
 * 若字符为非运算符（不包括括号），那么直接进行输出
 * 若字符为运算符：
 * ===》若栈为空，则直接将该运算符入栈
 * ===》若栈非空，那么需要将其与栈顶运算符进行比较，
 * ====》若该运算符的优先级低于或等于栈顶运算符的优先级，那么需要将栈顶运算符进行出栈写入结果中
 * ====》若该运算符的优先级高于栈顶运算符的优先级，那么将该运算符入栈
 * 若字符为左括号，那么直接入栈
 * 若字符为右括号，那么需要将栈中左括号之前的运算符全部出栈写入结果中
 * 直到扫描到输入表达式的最后一位，将栈中残留元素全部出栈写入结果中
 */
    // (<+==-<*==/
    // 即当运算符为+、-时，需要将栈中运算符出栈，直到栈为空或者栈顶元素为(
    // 当运算符为*、/时，若栈顶不为*、/那么直接入栈即可，否则出栈，直到栈顶不为*、/
    // 左括号直接入栈
    // 右括号进行出栈操作，直到遇到左括号停止
    for (int i = 0; i < input.length(); i++) {
        switch (input[i]) {
            case '+': {
                while (!stack.is_empty() and stack.get_pop_item() != '(') {
                    result.push_back(stack.get_pop_item());
                    stack.pop();
                }
                stack.push(input[i]);
                break;
            }
            case '-': {
                while (!stack.is_empty() and stack.get_pop_item() != '(') {
                    result.push_back(stack.get_pop_item());
                    stack.pop();
                }
                stack.push(input[i]);
                break;
            }
            case '*': {
                while (stack.get_pop_item() == '*' or stack.get_pop_item() == '/') {
                    result.push_back(stack.get_pop_item());
                    stack.pop();
                }
                stack.push(input[i]);
                break;
            }
            case '/': {
                while (stack.get_pop_item() == '*' or stack.get_pop_item() == '/') {
                    result.push_back(stack.get_pop_item());
                    stack.pop();
                }
                stack.push(input[i]);
                break;
            }
            case '(': {
                stack.push(input[i]);
                break;
            }
            case ')': {
                while (stack.get_pop_item() != '(') {
                    result.push_back(stack.get_pop_item());
                    stack.pop();
                }
                stack.pop();
                break;
            }
            default: {
                result.push_back(input[i]);
                break;
            }
        }
    }
    while (!stack.is_empty()) {
        result.push_back(stack.get_pop_item());
        stack.pop();
    }
    return result;
}

//中缀表达式转前缀表达式
string translate_front(string input) {
    string result = "";
    stack_link stack = stack_link();
/***
 * 从后往前扫描输入的表达式
 * 若字符不为运算符，直接输入到结果中
 * 若字符为运算符，那么需要将其与运算符栈栈顶元素进行比较
 * ====》若栈为空，那么直接入栈即可
 * ====》若该运算符的优先级低于栈顶运算符优先级，那么将栈顶元素出栈并写入结果中，直到将该运算符写入栈中
 * ====》若该运算符优先级等于或者高于栈顶运算符优先级，那么将该运算符直接入栈
 * 若字符为右括号，则直接入栈
 * 若字符为左括号，那么需要将栈中元素出栈，直到右括号括号为止
 * 一直循环直到扫描完毕
 */
    //)<+==-<*==/
    //即若运算符为+、-时，需要将*、/出栈
    //若运算符为*、/时，直接入栈
    for (int i = (input.length() - 1); i >= 0; i--) {
        switch (input[i]) {
            case '+': {
                while (!stack.is_empty() and (stack.get_pop_item() == '*' or stack.get_pop_item() == '/')) {
                    result.push_back(stack.get_pop_item());
                    stack.pop();
                }
                stack.push(input[i]);
                break;
            }
            case '-': {
                while (!stack.is_empty() and (stack.get_pop_item() == '*' or stack.get_pop_item() == '/')) {
                    result.push_back(stack.get_pop_item());
                    stack.pop();
                }
                stack.push(input[i]);
                break;
            }
            case '*': {
                stack.push(input[i]);
                break;
            }
            case '/': {
                stack.push(input[i]);
                break;
            }
            case '(': {
                while (stack.get_pop_item() != ')') {
                    result.push_back(stack.get_pop_item());
                    stack.pop();
                }
                stack.pop();
                break;
            }
            case ')': {
                stack.push(input[i]);
                break;
            }
            default: {
                result.push_back(input[i]);
                break;
            }
        }
    }
    while (!stack.is_empty()) {
        result.push_back(stack.get_pop_item());
        stack.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string input = "";
    //cin输入流无法接受空格字符的输入，空格字符的输入将中断字符流的输入
    //确保所有输入表达式合法，并未进行输入式是否合法的判断
    cin >> input;
    cout << "translate back::" << translate_back(input) << endl;
    cout << "translate front:" << translate_front(input) << endl;
    return 0;
}

