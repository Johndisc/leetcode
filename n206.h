//
// Created by CGCL on 2023/2/22.
//

#ifndef LEETCODE_N206_H
#define LEETCODE_N206_H
#include "global.h"

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (!head)
			return nullptr;
		ListNode *temp, *p, *q;
		p = head;
		q = p;
		while (q->next) {
			temp = q->next->next;
			q->next->next = p;
			p = q->next;
			q->next = temp;
		}
		return p;
	}
};
#endif //LEETCODE_N206_H
