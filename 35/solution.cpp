#include "solution.h"

using namespace std;

Node* Solution::copyRandomList(Node* head) {
	return copyRandomListInLoop(head);
}

//递归解法
Node* Solution::copyRandomListRecursion(Node* head) {
	if (head == nullptr) {
		return nullptr;
	}
	auto iter = visited.find(head);
	if (iter != visited.end()) {
		//沿next指针复制时，不会再次访问已经过的节点
		//一旦再次访问，必然通过random指针
		return iter->second;
	}
	Node* p = new Node(head->val);
	visited.insert({ head,p });
	p->next = copyRandomListRecursion(head->next);
	p->random = copyRandomListRecursion(head->random);
	return p;
}

//迭代解法
//沿着next指针或random指针遍历
//若next指向的节点不存在则创建
//若ranndom指向的节点不存在依然创建
Node* Solution::copyRandomListInLoop(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }
    //创建辅助头节点
    Node* dummy_head = new Node(-1);
    //操作原链表的辅助指针
    Node* p_origin = head;
    //操作新链表的辅助指针
    Node* p_copy = dummy_head;
    while (p_origin != nullptr) {
        //待拷贝节点不存在，创建
        auto it_next = visited.find(p_origin);
        if (it_next == visited.end()) {
            p_copy->next = new Node(p_origin->val);
            visited.insert({ p_origin ,p_copy->next });
            p_copy = p_copy->next;
        } else {
            //待拷贝节点已被创建过，连接即可
            p_copy->next = it_next->second;
            p_copy = p_copy->next;
        }
        //设置random指针指向 
        if (p_origin->random != nullptr) {
            //待拷贝节点不存在，创建
            auto it_random = visited.find(p_origin->random);
            if (it_random == visited.end()) {
                p_copy->random = new Node(p_origin->random->val);
                visited.insert({ p_origin->random,p_copy->random });
            } else {
                //待拷贝节点已被创建过，连接即可
                p_copy->random = it_random->second;
            }
        }
        p_origin = p_origin->next;
    }
    return dummy_head->next;
}
