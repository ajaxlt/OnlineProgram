//
//  4. 寻找两个有序数组的中位数.swift
//
//  Copyright © 2019年 ajaxlt. All rights reserved.
//

import Foundation
class Solution {
    func findMedianSortedArrays(_ nums1: [Int], _ nums2: [Int]) -> Double {
        let len1 = nums1.count, len2 = nums2.count
        var ans = [Int](repeating: 0, count: len1 + len2)
        var i = 0, j = 0, k = 0
        repeat {
            let a = i == len1 ? Int.max : nums1[i]
            let b = j == len2 ? Int.max : nums2[j]
            if (a < b) {
                ans[k] = a
                i += 1
            }
            else {
                ans[k] = b
                j += 1
            }
            k += 1
        } while i < len1 || j < len2
        let mid = (len1 + len2) / 2
        if ((len1 + len2) & 1 == 1) { // 奇数
            return Double(ans[mid])
        }
        else {
            return Double((ans[mid - 1] + ans[mid])) / 2
        }
    }
}

