/*
 * 来源: LintCode
 * 题目: 旋转字符串
 *
 * 描述:
 * 给定一个字符串（以字符数组的形式给出）和一个偏移量，根据偏移量原地旋转字符串(从左向右旋转)
 *
 * 思路:
 * 简单题，注意特殊输入
*/

class Solution {
public:
    /**
     * @param str: An array of char
     * @param offset: An integer
     * @return: nothing
     */
    void rotateString(string &str, int offset) {
        // write your code here
        if (str.empty()) return;
        offset %= str.size();
        str = str.substr(str.size() - offset) + str.substr(0, str.size() - offset);

    }
};