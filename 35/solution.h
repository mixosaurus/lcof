#pragma once
#include <vector>
#include <iostream>
#include <unordered_map> 
#include <algorithm>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random; 
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
private:
    //key表示已访问（复制）过的原链表节，value表示其拷贝
    unordered_map<Node*,Node*> visited;
public:
    Node* copyRandomList(Node* head);
    Node* copyRandomListRecursion(Node* head);
    Node* copyRandomListInLoop(Node* node);
};