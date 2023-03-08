//
// Created by CGCL on 2023/3/8.
//

#ifndef LEETCODE_N234_H
#define LEETCODE_N234_H
#include "global.h"

class Solution {
public:
	bool isPalindrome(ListNode* head) {
		ListNode *fast, *slow;
		fast = slow = head;
		if (!fast->next)
			return true;
		while (fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (!fast->next)
				break;
		}
		slow = slow->next;
		stack<int> stk;
		while (slow) {
			stk.push(slow->val);
			slow = slow->next;
		}
		while (!stk.empty()) {
			if (head->val != stk.top())
				return false;
			head = head->next;
			stk.pop();
		}
		return true;
	}
};
#endif //LEETCODE_N234_H
