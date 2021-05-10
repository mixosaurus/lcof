#include <iostream>
#include <vector>
#include "solution.h"

using namespace std;

void traverseLinkedList(Node* node) {
    while (node != nullptr) {
        if (node->random != nullptr) {
            cout << "val: " << node->val << ", random: "<<node->random->val << endl;
        } else {
            cout << "val: " << node->val << ", random: nullptr"<< endl;
        }
        node = node->next;
    }
}

//������������
Node* createLinkedList(vector<vector<int>> samples) {
    if (samples.empty()) {
        return nullptr;
    }
    Node* head = nullptr;
    Node* r = nullptr;
    Node* p = nullptr;
    //β�巨����������ʱ����random
    for (auto line : samples) {
        if (head == nullptr) {
            head = new Node(line[0]);
            r = head;
        } else {
            p = new Node(line[0]);
            r->next = p;
            r = r->next;
        }
    }
    //����ָ��p
    p = head;
    Node* random_target = nullptr;
    for (auto line : samples) {
        if (line[1] == numeric_limits<int>::min()) {
            p->random = nullptr;
        } else {
            random_target = head;
            for (int i = 0; i< line[1]; i++) {
                random_target = random_target->next;
            }
            p->random = random_target;
        }
        p = p->next;
    }   
    return head;
}

int main() {
    Solution solution;
    //��int�½��ʾnullptr
    vector<vector<int>> samples = {
        {7,numeric_limits<int>::min()},
        {13,0},
        {11,4},
        {10,2},
        {1,0}
    };
    Node* head = createLinkedList(samples);
    traverseLinkedList(head);    
    cout << endl;
    traverseLinkedList(solution.copyRandomList(head));

    return 0;
}