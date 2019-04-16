//
//  3. 无重复的最长子串.swift
//
//  Copyright © 2019年 ajaxlt. All rights reserved.
//

import Foundation
// 一次遍历, map存储字母最右边的下标
class Solution {
    func lengthOfLongestSubstring(_ s: String) -> Int {
        let len = s.count
        guard len != 0 else {
            return 0
        }
        var ans : Int = 1, head : Int = 0
        var dict = [Character: Int]()
        let sChars = Array(s)
        for i in 0 ..< len {
            let c = sChars[i]
            if dict.keys.contains(c) && dict[c]! >= head{ // 如果已经前面已经出现过这个字符, 并且位于当前统计的区间内
                head = dict[c]! + 1
            }
            else {
                ans = max(ans, i - head + 1)
            }
            dict[c] = i // 无论如何，更新map
        }
        return ans
    }
}

