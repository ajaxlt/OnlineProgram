//
//  1. 两数之和.swift
//
//  Created by ajaxlt on 2017/9/22.
//  Copyright © 2017年 ajaxlt. All rights reserved.
//

import Foundation

class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var dict = [Int: Int]()
        for i in 0..<nums.count {
            if dict.keys.contains(target - nums[i]) {
                return [dict[target - nums[i]]! ,i];
            }
            else {
                dict[nums[i]] = i
            }
        }
        return []
    }
}

