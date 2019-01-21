#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: LRU缓存机制(LRU Cache)
 *
 * 描述:
 * 运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put
 * 获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1
 * 写入数据 put(key, value) - 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，它应该在写入新数据之前删除最近最少使用的数据值，从而为新的数据值留出空间
 *
 *
 * 思路:
 * 哈希 + 双向链表
 * 每次操作时，将操作的结点放置于头结点上
 */



struct Node{
    int key, val;
    Node *prev, *next;
    Node(int _key, int _val) : key(_key), val(_val), prev(nullptr), next(nullptr) {}
};
class LRUCache {
public:
    LRUCache(int capacity) {
        size = capacity;
        len = 0;

        head = new Node(0, 0);
        tail = new Node(0, 0);

        head -> next = tail;
        head -> prev = nullptr;
        tail -> prev = head;
        tail -> next = nullptr;
    }

    int get(int key) {
        if(hash.find(key) == hash.end()) return -1;

        Node *p = hash[key]; //取出来

        //1. p 要走了，所以先善后
        p -> next -> prev = p -> prev;
        p -> prev -> next = p -> next;

        //2. 和本来的头建立双向关系
        p -> next = head -> next;
        p -> next -> prev = p;

        //3. 和伪头建立双向关系
        p -> prev = head;
        head -> next = p;

        return p -> val;
    }

    void put(int key, int value) {
        Node *p = nullptr;

        if (hash.find(key) != hash.end()) {
            p = hash[key];
            p -> val = value;

            p -> next -> prev = p -> prev;
            p -> prev -> next = p -> next;


            p -> next = head -> next;
            p -> next -> prev = p;

            head -> next = p;
            p -> prev = head;

        }
        else {
            p = new Node(key, value);
            p -> next = head -> next;
            p -> next -> prev = p;

            head -> next = p;
            p -> prev = head;

            hash[key] = p;
            ++len;
        }
        if (len > size) {
            p = tail -> prev;

            hash.erase(hash.find(p -> key));

            p -> next -> prev = p -> prev;
            p -> prev -> next = p -> next;
            delete p;
            --len;
        }
    }
private:
    int len, size;
    Node *head = nullptr, *tail = nullptr;
    unordered_map<int, Node*> hash;
};