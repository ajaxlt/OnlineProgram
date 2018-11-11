#include <iostream>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 数组中重复的数字
 *
 * 描述: 在一个长度为n的数组里的所有数字都在0到n-1的范围内
 * 数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次
 * 请找出数组中任意一个重复的数字。
 * 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2
 *
 * 思路:
 * 遍历一次数组，使 nums[i] 位于 idx = nums[i] 处
 * 例如， nums[0] = 2， 那么交换num[0] 和 nums[2]，直到 nums[i] = nums[nums[i]]
 * 如果在交换之前发现已经有nums[nums[i]] == nums[i] -> return i 即可
 */
class Solution {
public:
    bool duplicate(int numbers[], int length, int* duplication) {
        for (int i = 0; i < length; ++i) {
            while(numbers[i] != i) {
                if (numbers[numbers[i]] == numbers[i]) {
                    *duplication = numbers[i];
                    //cout << *duplication << endl;
                    return true;
                } else {
                    swap(numbers[numbers[i]],numbers[i]);
                }
            }
        }
        return false;
    }
};