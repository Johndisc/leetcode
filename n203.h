//
// Created by CGCL on 2023/2/22.
//

#ifndef LEETCODE_N203_H
#define LEETCODE_N203_H
#include "global.h"

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		ListNode *dummy = new ListNode;
		dummy->next = head;
		ListNode *p;
		p = dummy;
		while (p->next) {
			if (p->next->val == val)
				p->next = p->next->next;
			else
				p = p->next;
		}
		return dummy->next;
	}
};
#endif //LEETCODE_N203_H
