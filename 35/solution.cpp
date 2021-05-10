#include "solution.h"

using namespace std;

Node* Solution::copyRandomList(Node* head) {
	return copyRandomListInLoop(head);
}

//�ݹ�ⷨ
Node* Solution::copyRandomListRecursion(Node* head) {
	if (head == nullptr) {
		return nullptr;
	}
	auto iter = visited.find(head);
	if (iter != visited.end()) {
		//��nextָ�븴��ʱ�������ٴη����Ѿ����Ľڵ�
		//һ���ٴη��ʣ���Ȼͨ��randomָ��
		return iter->second;
	}
	Node* p = new Node(head->val);
	visited.insert({ head,p });
	p->next = copyRandomListRecursion(head->next);
	p->random = copyRandomListRecursion(head->random);
	return p;
}

//�����ⷨ
//����nextָ���randomָ�����
//��nextָ��Ľڵ㲻�����򴴽�
//��ranndomָ��Ľڵ㲻������Ȼ����
Node* Solution::copyRandomListInLoop(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }
    //��������ͷ�ڵ�
    Node* dummy_head = new Node(-1);
    //����ԭ����ĸ���ָ��
    Node* p_origin = head;
    //����������ĸ���ָ��
    Node* p_copy = dummy_head;
    while (p_origin != nullptr) {
        //�������ڵ㲻���ڣ�����
        auto it_next = visited.find(p_origin);
        if (it_next == visited.end()) {
            p_copy->next = new Node(p_origin->val);
            visited.insert({ p_origin ,p_copy->next });
            p_copy = p_copy->next;
        } else {
            //�������ڵ��ѱ������������Ӽ���
            p_copy->next = it_next->second;
            p_copy = p_copy->next;
        }
        //����randomָ��ָ�� 
        if (p_origin->random != nullptr) {
            //�������ڵ㲻���ڣ�����
            auto it_random = visited.find(p_origin->random);
            if (it_random == visited.end()) {
                p_copy->random = new Node(p_origin->random->val);
                visited.insert({ p_origin->random,p_copy->random });
            } else {
                //�������ڵ��ѱ������������Ӽ���
                p_copy->random = it_random->second;
            }
        }
        p_origin = p_origin->next;
    }
    return dummy_head->next;
}
