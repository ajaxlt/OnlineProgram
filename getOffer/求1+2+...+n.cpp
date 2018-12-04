#include <iostream>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 求 1 + 2 + ... + n
 *
 * 描述:
 * 求1 + 2 + ... + n + 要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）
 *
*/

/*              soluntion 1          */
/* 思路：
 * 1. 基于类的静态成员变量与构造函数
 *  1.1 类的所有对象都使用相同的静态成员变量，即公用的
 *  1.2 静态成员函数只能操作静态成员变量，类名可以直接调用静态成员函数，可以专门用静态成员函数对静态成员变量进行操作
 *  1.3 因此，可以利用创造一个类n个对象的方法，对一个类静态成员变量进行累加，但要需要置零
 */
class Sum {
public:
    Sum() {
        sum += (++n);
    }
    static int getSum() {
        return sum;
    }
    static void reSet() {
        n = 0;
        sum = 0;
    }
private:
    static int n;
    static int sum;
};
static int Sum::n = 0;
static int Sum::sum = 0;
class Solution1 {
public:
    int Sum_Solution(int n) {
        Sum::reSet();
        Sum s[n];
        return Sum::getSum();
    }
};
/*              soluntion 1            */

/*              soluntion 2            */
/* 思路：
 * 2. 基于虚函数的递归求解
 *  2.1 由于不能使用if, 因此需要另一个函数额外处理递归终止的情况；func1用于递归，func2用于限制边界
 *  2.2 由于限制，func1 和 func2 应该是同名的，因此可以自然联系到虚函数的使用
 *  2.3 当 n = 0 时到达终点， n > 0 时继续递归， 可以使用 !!n 实现
 *  2.4 修正递归为尾递归
 */
class A;
A* Tmp[2];

class A{
public:
    virtual int Sum(int n, int rlt){
        return rlt;
    }
};
class B: public A {
public:
    virtual int Sum(int n, int rlt) { //虚继承
        /*
        if (n == 0)
            return Tmp[0] -> Sum(n - 1) + n;
        else
            return Tmp[1] -> Sum(n - 1) + n;
            */
        return Tmp[!!n] -> Sum(n - 1, rlt + n);

    }
};
class Solution2 {
public:
    int Sum_Solution(int n) {
        A a;
        B b;
        Tmp[0] = &a;
        Tmp[1] = &b;
        return Tmp[1] -> Sum(n, 0);
    }
};
/*              soluntion 2            */

/*              soluntion 3            */
/* 思路：
 * 3. 基于函数指针(句柄)的递归求解
 *  思路与2.类似，也可以利用函数指针解决
 */
typedef int (*func) (int n, int rlt);
int Tem(int, int);
int Sum(int, int);
func f[2] = {Tem, Sum};

int Tem(int n, int rlt) {
    return rlt;
}
int Sum(int n, int rlt) {
    return f[!!n](n - 1, rlt + n);
}
class Solution3 {
public:
    int Sum_Solution(int n) {
        return Sum(n, 0);
    }
};
