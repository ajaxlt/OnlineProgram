#include <iostream>
#include <vector>
#include <string.h>
#include <map>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 字符串的排列
 *
 * 描述: 输入一个字符串,按字典序打印出该字符串中字符的所有排列
 * 例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba
 *
 * 思路：
 * 1.基于基本全排列方法，但是需要加一个排序以保证字典序
 * 2.基于回溯法
 *
*/

/**
 * 基于基本交换法
 */
class Solution1 {
public:
    void Permutation(string str, int index)
    {
        if (index == str.size()) rlt.push_back(str);
        else {
            sort(str.begin() + index, str.end()); //保证字典序的必要操作
            for (int j = index; j < str.size(); ++j){
                if (j != index && str[j] == str[index]) continue;
                swap(str[index], str[j]);
                Permutation(str, index + 1);
                swap(str[index], str[j]);
            }
        }
    }
    vector<string> Permutation(string str)
    {
        if(!str.empty()) Permutation(str, 0);
        return rlt;
    }
private:
    vector<string> rlt;
};
/**
 * 基于回溯法
 */
class Solution2 {
public:
    void Permutation(string str, int index, bool use[])
    {
        if (index == str.size()) rlt.push_back(tmp);
        else {
            map<char, bool> m;
            for (int j = 0; j < str.size(); ++j) {
                if (!m.count(str[j]) && !use[j]) {
                    tmp.push_back(str[j]);
                    use[j] = true;
                    Permutation(str, index + 1, use);
                    tmp.pop_back();
                    use[j] = false;
                } else m[str[j]] = true;
            }
        }
    }
    vector<string> Permutation(string str)
    {
        bool use[str.size()];
        memset(use, false, sizeof(use));
        Permutation(str, 0, use);
        return rlt;
    }
private:
    vector<string> rlt;
    string tmp = "";
};