#include <iostream>
#include <vector>
#include <map>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 二叉搜索树和双向链表
 *
 * 描述: 数入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
 * 要求不能创建任何新的结点，只能调整树中结点指针的指向
 *
 * 思路：
 * 只要按照中序遍历，即 左 -> 根 -> 右的顺序进行遍历，一定能保证有序
 * 假设，前面已经排完的末尾结点是 tail，则对于当前遍历的结点 pNode
 * 1. 访问其左儿子
 * 2. 处理自己，即与tail建立双向关系
 * 3. 访问其右儿子
 *
*/
class Solution {
public:
    void ConvertNode(TreeNode* pNode)
    {
        if (!pNode) return;
        ConvertNode(pNode -> left);     
        
        pNode -> left = tail;
        if (tail) tail -> right = pNode;
        else head = pNode; // 当head为null时，此是刚遇到头
        tail = pNode;
        
        ConvertNode(pNode -> right); 
    }
    TreeNode* Convert(TreeNode* pRoot)
    {
        ConvertNode(pRoot);
        return head;
    }
private:
    TreeNode* head = nullptr;
    TreeNode* tail = nullptr;
};