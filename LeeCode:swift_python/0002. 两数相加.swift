//
//  2. 两数相加.swift
//
//  Copyright © 2019年 ajaxlt. All rights reserved.
//

import Foundation

public class ListNode {
    public var val: Int
    public var next: ListNode?
    public init(_ val: Int) {
        self.val = val
        self.next = nil
    }
}

class Solution {
    func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        guard l1 != nil else {
            return l2
        }
        guard l2 != nil else {
            return l1
        }
        let dummy : ListNode! = ListNode(0)
        var lhs = l1, rhs = l2
        var l3 : ListNode? = dummy
        
        var carry : Int = 0
        while lhs != nil || rhs != nil {
            let a : Int = lhs == nil ? 0 : lhs!.val;
            let b : Int = rhs == nil ? 0 : rhs!.val;
            l3!.next = ListNode((a + b + carry) % 10)
            carry = (a + b + carry) / 10
            l3 = l3!.next
            if lhs != nil {
                lhs = lhs!.next
            }
            if rhs != nil {
                rhs = rhs!.next
            }
        }
        if carry > 0 {
            l3!.next = ListNode(carry)
        }
        return dummy.next
    }
}

