#include <iostream>
#include <string.h>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 赋值运算符函数
 *
 * 描述: 如下为类型CMyString的声明，请为该类型添加赋值运算符函数
 *
 * 思路:
 * 1. 返回值是引用的，才能连续赋值
 * 2. 形参为常量引用，减少无谓调用复制构造函数
 * 3. 释放自身内存
 * 4. 判断是否就是自身
 */
class CMyString {
public:
    CMyString(char* pData = nullptr);
    CMyString(const CMyString& str);
    ~CMyString();

    CMyString& operator=(const CMyString& str);
private:
    char* m_pData;
};
CMyString& CMyString::operator=(const CMyString& str) {
    if(this == &str) return *this;

    delete []this -> m_pData;
    this -> m_pData = nullptr;

    m_pData = new char[strlen(str.m_pData) + 1];
    strcpy(m_pData, str.m_pData);
    return *this;
}