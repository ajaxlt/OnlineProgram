'''
4. 寻找两个有序数组的中位数
'''
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums3 = sorted(nums1 + nums2)
        return float(nums3[len(nums3)//2]) if len(nums3) % 2 == 1 \
            else (nums3[len(nums3)//2 - 1] + nums3[len(nums3)//2]) / 2

