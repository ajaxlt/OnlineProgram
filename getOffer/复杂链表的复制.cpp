#include <iostream>
#include <vector>
#include <map>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 复杂链表的复制
 *
 * 描述: 输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head
 *
 * 思路:
 * 一. 两遍遍历法 + map
 * 1. 首次遍历，只正常复制，但是还要用Map记录原链与新链的配对
 * 2. 再次遍历，根据映射关系，建立random指针关系
 *
 * 二.
 * 1. 首次遍历，把新结点跟在旧结点之后
 * 2. 二次遍历，加上random指针关系
 * 3. 三次遍历，解离
 *
*/


struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
/*
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (!pHead) return nullptr;
        map<RandomListNode*, RandomListNode*> m;//配对表
        RandomListNode* dummy = new RandomListNode(0);
        RandomListNode* p = pHead;
        RandomListNode* q = new RandomListNode(p -> label);
        dummy -> next = q;
        m[p] = q;
        while(p -> next) {
            p = p -> next;
            q -> next = new RandomListNode(p -> label);
            q = q -> next;
            m[p] = q;
        }
        p = pHead;
        while(p) {
            if(p -> random) m[p] -> random = m[p -> random];
            p = p -> next;
        }
        return dummy -> next;
    }
};
 */

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (!pHead) return nullptr;
        RandomListNode* p = pHead;
        //1. 首次遍历
        while(p) {
            RandomListNode* q = new RandomListNode(p -> label);
            q -> next = p -> next;
            p -> next = q;
            p = p -> next -> next;
        }
        //2. 二次遍历
        p = pHead;
        while(p) {
            RandomListNode* q = p -> next;
            if (p -> random) q -> random = p -> random -> next;
            p = p -> next -> next;
        }

        //3. 三次遍历，解离
        //注意必须完全解离
        RandomListNode* dummy = pHead -> next;
        RandomListNode* tmp;
        RandomListNode* crtNode = pHead;
        while(crtNode -> next){
            tmp = crtNode -> next;
            crtNode -> next = tmp -> next;
            crtNode = tmp;
        }
        return dummy;
    }
};