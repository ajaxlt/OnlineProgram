#include <iostream>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 替换空格
 *
 * 描述: 请实现一个函数，将一个字符串中的每个空格替换成“%20”
 * 例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy
 *
 * 思路:
 * 1.遍历一次数组，统计旧长度，空格数
 * 2.新长度 = 旧长度 + 2 * 空格数
 * 3.因为需要原地操作，所以必须从尾至头操作，否则在操作的过程中会改变暂未处理的部分
 */
class Solution {
public:
    /**
    * @param[in, out] str: 待修正字符串
    * @param[in] length: 预留长度
    */
    void replaceSpace(char *str,int length) {
        if (str == NULL) return;
        int i = 0, cntOfBlank = 0;
        for (; str[i] != '\0'; ++i)
            if (str[i] == ' ') ++cntOfBlank;
        // 若要将空格替换成 %20, 则长度变为 原长度 + 2 * 空格个数
        int newLen = i + 2 * cntOfBlank;
        int j = newLen;
        while(j >= 0) {
            if (str[i] == ' ') {
                str[j--] = '0';
                str[j--] = '2';
                str[j--] = '%';
            }
            else str[j--] = str[i];
            --i;
        }
    }
};