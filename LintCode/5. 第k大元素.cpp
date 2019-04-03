/*
 * 来源: LintCode
 * 题目: 第k大元素
 *
 * 描述:
 * 在数组中找到第 k 大的元素
 *
 * 思路:
 * 部分快速排序 O(n)
 *
*/
class Solution {
public:
    /**
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    int partition(vector<int>& nums, int p, int r) {
        int x = nums[r];
        int i = p;
        for (int j = p; j < r; ++j)
            if (nums[j] <= x) swap(nums[j], nums[i++]);

        swap(nums[r], nums[i]);
        return i;
    }
    void binaryQuickSort(vector<int>& nums, int head, int tail, int n) {
        if (head < tail) {
            int mid = partition(nums, head, tail);
            if (mid - head == n) {
                ans = nums[mid];
                return;
            }
            else if (mid - head > n) binaryQuickSort(nums, head, mid - 1, n);
            else binaryQuickSort(nums, mid + 1, tail, n - (mid - head + 1));
        }
        else ans = nums[head];
    }
    int kthLargestElement(int n, vector<int>& nums) {
        binaryQuickSort(nums, 0, nums.size() - 1, nums.size() - n);
        return ans;
    }
private:
    int ans = -1;
};