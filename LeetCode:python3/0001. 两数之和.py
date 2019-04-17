'''
1. 两数之和
'''
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        book = dict()
        for i in range(len(nums)):
            if target - nums[i] in book:
                return [book[target - nums[i]], i]
            else:
                book[nums[i]] = i

        return None
