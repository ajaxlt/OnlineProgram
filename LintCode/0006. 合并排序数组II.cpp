/*
 * 来源: LintCode
 * 题目: 合并排序数组 II
 *
 * 描述:
 * 合并两个有序升序的整数数组A和B变成一个新的数组。新数组也要有序
 *
 * 思路:
 * 简单题
 *
*/
class Solution {
public:
    /**
     * @param A: sorted integer array A
     * @param B: sorted integer array B
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        int len1 = A.size(), len2 = B.size();
        vector<int> C(len1 + len2);
        int i = 0, j = 0, k = 0;
        while (i < len1 || j < len2) {
            int a = i == len1 ? INT32_MAX : A[i];
            int b = j == len2 ? INT32_MAX : B[j];

            if (a < b) C[k++] = A[i++];
            else C[k++] = B[j++];
        }
        return C;
    }
};