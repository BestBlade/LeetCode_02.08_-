/* ------------------------------------------------------------------|
给定一个链表，如果它是有环链表，实现一个算法返回环路的开头节点。
有环链表的定义：在链表中某个节点的next元素指向在它前面出现过的节点，则表明该链表存在环路。

 

示例 1：

输入：head = [3,2,0,-4], pos = 1
输出：tail connects to node index 1
解释：链表中有一个环，其尾部连接到第二个节点。
 

示例 2：

输入：head = [1,2], pos = 0
输出：tail connects to node index 0
解释：链表中有一个环，其尾部连接到第一个节点。
 

示例 3：

输入：head = [1], pos = -1
输出：no cycle
解释：链表中没有环。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/linked-list-cycle-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
------------------------------------------------------------------*/

/*	快慢指针法
*
*	执行用时：4 ms, 在所有 C++ 提交中击败了99.94%的用户
*	内存消耗：7.3 MB, 在所有 C++ 提交中击败了93.95%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* detectCycle(ListNode* head) {
	//判断是否存在环路
	if (head == NULL || head->next == NULL) {
		return nullptr;
	}

	ListNode* slow = head;
	ListNode* fast = head->next;

	while (slow != fast) {
		if (fast->next == NULL || fast->next->next == NULL) {
			return nullptr;
		}
		else {
			slow = slow->next;
			fast = fast->next->next;
		}
	}
	//假设从head到环路入口的距离为x1
	//环路入口到两指针相遇的距离为x2
	//则slowLen = x1 + x2
	//fastLen = (x1 - 1) + x2 + n * cycle,因为初始fast比slow快一个节点
	//由于fast的速度是slow的两倍
	//所以2 * ( x1 + x2) = fastLen
	//所以x1 = cycle - (x2 + 1)
	//由于(x2 + 1)，所以fast要在相遇点再向后移动一次
	slow = head;
	fast = fast->next;

	//判断是否相遇
	while (slow != fast) {
		slow = slow->next;
		fast = fast->next;
	}
	//返回相遇节点
	return slow;
}
