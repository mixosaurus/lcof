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
    //key��ʾ�ѷ��ʣ����ƣ�����ԭ����ڣ�value��ʾ�俽��
    unordered_map<Node*,Node*> visited;
public:
    Node* copyRandomList(Node* head);
    Node* copyRandomListRecursion(Node* head);
    Node* copyRandomListInLoop(Node* node);
};