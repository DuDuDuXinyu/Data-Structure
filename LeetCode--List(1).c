#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

//�������Ĵ���

 typedef struct ListNode {
	int val;
	struct ListNode *next;
 }Node;

 //�Ƴ�����Ԫ��

struct ListNode* removeElements(struct ListNode* head, int val) {
	Node* cur = head;
	Node* prev = NULL;

	while (cur)
	{
		if (cur->val == val)
		{
			//�жϸ���Ҫɾ����λ��������

			if (cur == head)
			{
				//��ͷ�ڵ�����
				//ͷɾ

				head = head->next;
				free(cur);
				cur = head;
			}
			else
			{
				//����ͷ�ڵ�����

				prev->next = cur->next;
				free(cur);
				cur = prev->next;
			}
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}

	return head;
}

//��ת����

//�ı�next��ָ������ת

 struct ListNode* reverseList(struct ListNode* head){
     Node* prev=NULL;
     Node* cur=head;
     Node* next=NULL;

     while(cur)
     {
         assert(cur);

         next=cur->next;
         cur->next=prev;
         prev=cur;
         cur=next;
     }
     return prev;
 }

//����ͷ��ķ�������ת

struct ListNode* reverseList(struct ListNode* head) {
	Node* cur = head;
	Node* newNode = NULL;

	while (cur)
	{
		//����������һ���ڵ�
		head = cur->next;
		//ͷ��
		//��head�ĵ�һ���ڵ����newNode��
		cur->next = newNode;
		newNode = cur;
		cur = head;
	}
	return newNode;
}

//�ж��Ƿ���ڻ�������
//bool��ͷ�ļ���<stdbool.h>

bool hasCycle(struct ListNode* head) {
	Node* low = head;
	Node* fast = head;

	//while���������Ҫע��
	//fast��˫��������
	//fast->next�ǵ���������

	while (fast && fast->next)
	{
		//����һ����һ��

		low = low->next;

		//���һ��������

		fast = fast->next->next;

		//����л��Ļ�fast�ͻ�׷��low

		if (low == fast)
		{
			return true;
		}
	}
	return false;
}

//�ҵ��������м�ڵ�
//Ҫ��ʱ�临�Ӷ�0��1��

struct ListNode* middleNode(struct ListNode* head) {
	Node* low = head;
	Node* fast = head;

	//fastһ���������ڵ�
	//lowһ����һ���ڵ�
	//��fast����NULL��ʱ��
	//low���Ƿ��ص�һ��Ľڵ�

	while (fast && fast->next)
	{
		low = low->next;
		fast = fast->next->next;
	}
	return low;
}

//�ж�һ�������Ƿ�Ϊ��������

//����һ������ȫ�������������Ļ�����û�жԱ������ˣ������У�
//���������ÿ���ָ���ҵ��м�ڵ㣬Ȼ��Ѻ�벿�����ñȽ�

bool isPalindrome(struct ListNode* head) {
	SLNode* low = head;
	SLNode* fast = head;
	SLNode* prev = NULL;
	SLNode* newNode = NULL;

	//��Ϊ����ĵĺ������޷��ж�����Ϊ�պ�ֻ��һ�����ݵ����

	if (head == NULL || head->next == NULL) 
	{
		//������Ϊ�ջ���ֻ��һ�����ݵ�ʱ��ֱ���ж�Ϊtrue

		return true;
	}

	//����жϵ��ǵ��������������ݵ����
	//��ε�if�����Բ�Ҫ
	//����ֻ��д�Ļ����Խ��ͺ�����ʱ�临�Ӷ�
	//����ֻ��Ҫһ�αȽϼ�������ж�

	if (head->next->next == NULL) {

		//����ֻ��Ҫ�Ƚϵ�һ���͵ڶ��������ǲ�����ͬ�ļ���

		if (head->val == head->next->val)
		{
			return true;
		}
		return false;
	}

	//while���������Ҫע��
	//fast��˫��������
	//fast->next�ǵ���������

	while (fast && fast->next)
	{
		//����low��ǰһ��ֵ
		//��Ϊ˫����ʱ��prev����ǰһ���ֵ����һ��
		prev = low;

		//����һ����һ��

		low = low->next;

		//���һ��������
		//����Ŀ�������ȷ������fast��λ��
		//fast = fast->next ? fast->next->next : fast->next;
		//����Ϊ���Ժ�Ĳ���δ�������ַ���

		fast = fast->next->next;
	}

	//ż����

	if (fast == NULL)
	{
		//��head���������һ��ĵط��ͽ���

		prev->next = NULL;

		//���ú�벿�ֵ�����

		fast = low;
		while (fast)
		{
			fast = low->next;
			low->next = newNode;
			newNode = low;
			low = fast;
		}

		//���������������ж��Ƿ�Ϊ���ĺ���

		while (newNode && head)
		{
			if (newNode->val == head->val)
			{
				newNode = newNode->next;
				head = head->next;
			}
			else {
				return false;
			}
		}
		return true;
	}

	//������

	else
	{
		//��λ����벿�������Ŀ�ʼλ��

		fast = low->next;

		//�ͷŴ������м��λ�õ�����

		free(low);

		//���ú�벿������

		low = fast;
		prev->next = NULL;
		while (fast)
		{
			fast = low->next;
			low->next = newNode;
			newNode = low;
			low = fast;
		}

		//���������������ж��Ƿ�Ϊ���ĺ���

		while (newNode && head)
		{
			if (newNode->val == head->val)
			{
				newNode = newNode->next;
				head = head->next;
			}
			else {
				return false;
			}
		}
		return true;
	}
}

//�������������������ݴ���������Ȼ���ж�
//��Ȼ�����ܱ�������˼ά�ܼ򵥣���������ʱ���
//ȱ�����ռ���˶�����ڴ�

bool isPalindrome(struct ListNode* head) {
	Node* cur = head;

	//����δ֪�����ĳ��ȣ����������������Ҫ����

	int a[50000];

	//��������

	int i = 0;
	while (cur)
	{
		a[i++] = cur->val;
		cur = cur->next;
	}

	//������ķ������ж��Ƿ�Ϊ����

	int left = 0, right = i - 1;
	while (left < right)
	{
		if (a[left] == a[right])
		{
			left++;
			right--;
		}
		else {
			return false;
		}
	}

	return true;
}

//����һ���ڵ㣬��������ɾ���ýڵ�

void deleteNode(struct ListNode* node) 
{
	//cur�������ͷ�node������Ľڵ��
	//Ϊ�˷�ֹ����ڴ�й¶

	Node* cur = node->next;
	node->val = node->next->val;
	node->next = node->next->next;
	free(cur);
}

// ����������ת����
//������ÿ������ֵ���� 0 ���� 1

int getDecimalValue(struct ListNode* head) {

	//

	int bit[32], i = 0, sum = 0, count = 0;

	//�����������ݰ�˳��ķ���������

	while (head)
	{
		bit[i++] = head->val;
		head = head->next;
	}
	count = i;

	//������ת��Ϊ����

	while (i)
	{
		if (bit[i - 1] == 1)
		{
			sum += pow(2, count - i);
		}
		i--;
	}

	return sum;
}

//�ϲ����������������

//����һ�������˵ݹ�ķ����������������
//�ô����ǲ�û�п����¿ռ�
//���ô����ǵ������������������ܴ󣩵�ʱ�򣬵ݹ�����Ҫ��ջ�ռ��ʱ������ıȽϴ�

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	if (l1 == NULL) {
		return l2;
	}
	if (l2 == NULL) {
		return  l1;
	}
	if (l1->val < l2->val) {
		l1->next = mergeTwoLists(l1->next, l2);
		return l1;
	}
	else {
		l2->next = mergeTwoLists(l1, l2->next);
		return l2;
	}
}

//������������һ���µ��������洢������������������

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	Node* newNode = NULL;

	//ͷ�巨����С������ѹ��newNode��

	while (l1 && l2)
	{
		if (l1->val > l2->val)
		{
			Node* cur = l2->next;
			l2->next = newNode;
			newNode = l2;
			l2 = cur;
		}
		else
		{
			Node* cur = l1->next;
			l1->next = newNode;
			newNode = l1;
			l1 = cur;
		}
	}

	//ע�����ﲻ����ֱ�Ӱ�δ����������ӵ�newNode�ĺ�
	//��Ϊ֮ǰ����������н���С�����ָ�������newNode�Ŀ�ʼ
	//���Ժ��������Ҳ��Ҫ��֮ǰ��ͷ���ȥ

	while (l1)
	{
		Node* cur = l1->next;
		l1->next = newNode;
		newNode = l1;
		l1 = cur;
	}
	while (l2)
	{
		Node* cur = l2->next;
		l2->next = newNode;
		newNode = l2;
		l2 = cur;
	}

	//��������������newNode�������������
	//�������ñ��ĺ���reverseList������һ��

	return reverseList(newNode);
}

//��������ֱ��������������

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	if (NULL == l1)
	{
		return l2;
	}
	if (NULL == l2)
	{
		return l1;
	}

	//��newNode��ָ���������е�һ���ڵ�

	Node* newNode = NULL;

	//ָ�������������һ���ڵ�

	Node* tail = NULL;

	if (l1->val <= l2->val)
	{
		newNode = l1;
		l1 = l1->next;
	}
	else
	{
		newNode = l2;
		l2 = l2->next;
	}

	//��Ϊ����newNodeֻ��һ������
	//����tail�ͺ�newNode��ͬһ��λ��

	tail = newNode;

	//�Ƚ�ƴ��

	while (l1 && l2)
	{
		//С������������tail�ĺ���

		if (l1->val <= l2->val)
		{
			tail->next = l1;
			l1 = l1->next;
		}
		else
		{
			tail->next = l2;
			l2 = l2->next;
		}
		tail = tail->next;
	}

	//while����֮��϶���һ������Ϊ��
	//����ֱ�Ӱ�Ϊ�������ֱ�ӽ���tail�ĺ���

	if (l1)
	{
		tail->next = l1;
	}
	else
	{
		tail->next = l2;
	}

	return newNode;
}

//�����ģ����������Ż��汾
//���õ��Ǵ�ͷ�ڵ������

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	if (NULL == l1)
	{
		return l2;
	}
	if (NULL == l2)
	{
		return l1;
	}

	//��ջ�Ͽ��ٵ�һ��newNode

	Node newNode;

	//ָ�������������һ���ڵ�

	Node* tail = &newNode;
	while (l1 && l2)
	{
		if (l1->val <= l2->val)
		{
			tail->next = l1;
			l1 = l1->next;
		}
		else
		{
			tail->next = l2;
			l2 = l2->next;
		}
		tail = tail->next;
	}
	if (l1)
	{
		tail->next = l1;
	}
	else
	{
		tail->next = l2;
	}

	//���ص�ʱ�򷵻�newNode����һ���ڵ�

	return newNode.next;
}

//��β��ͷ��ӡ����,Ҫ�������鷵��

//����һ���Ƚ��������

int* reversePrint(struct ListNode* head, int* returnSize) {

	//ʹ��malloc����һ���ռ�

	int* res = (int*)malloc(sizeof(int) * 10000);

	//�����������ݴ��ڿ��ٵ�res��

	int i = 0;
	while (head)
	{
		res[i++] = head->val;
		head = head->next;
	}

	int left = 0, right = i - 1;
	
	//��������

	while (left < right)
	{
		int temp = res[left];
		res[left] = res[right];
		res[right] = temp;
		left++;
		right--;
	}

	//*returnSize��ֵ���Ǹı��ⲿ���ֵı�������ȷ��һ���м�������

	*returnSize = i;

	return res;
}

//�������������������ڴ洢

int* reversePrint(struct ListNode* head, int* returnSize) {
	int* res = (int*)malloc(sizeof(int) * 10000);

	//�ı�������ָ��������

	Node* cur = head;
	Node* prev = NULL;

	while (cur)
	{
		head = cur->next;
		cur->next = prev;
		prev = cur;
		cur = head;
	}

	//��������

	int i = 0;
	head = prev;
	while (head)
	{
		res[i++] = head->val;
		head = head->next;
	}
	*returnSize = i;

	return res;
}

//��������е�����k���ڵ�

//����һ��������֮��Ȼ��������k����㼴��

struct ListNode* getKthFromEnd(struct ListNode* head, int k) {
	//�����ñ�����������

	Node* cur = head;
	Node* prev = NULL;

	while (cur)
	{
		head = cur->next;
		cur->next = prev;
		prev = cur;
		cur = head;
	}

	//��ʼ����k����㣬���õ����������Ƿ��ص�����

	head = prev;
	cur = head;
	prev = NULL;
	while (k--)
	{
		head = cur->next;
		cur->next = prev;
		prev = cur;
		cur = head;
	}

	return prev;
}

//������������˫ָ�������

struct ListNode* getKthFromEnd(struct ListNode* head, int k) {
	Node* latter = head;
	Node* former = head;

	//����former��k���ֽ�

	while (k--)
	{
		former = former->next;
	}

	//latter��formerһ����
	//��former�ߵ�ĩβ��ʱ��
	//��ʱlatter���ڵ�λ�þ��ǵ�����k���ڵ�
	//latter��ֱ�ӵĲ�����k���ֽ�

	while (former)
	{
		latter = latter->next;
		former = former->next;
	}

	return latter;
}

//�ཻ����
//�ж����������Ƿ��ཻ
//�ָཻ���Ǵ�ĳһ���ڵ�֮������нڵ㶼��ͬ

struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) 
{
	//����һ������Ϊ�յ�ʱ����ô���������Ͳ����ཻ

	if (NULL == headA || NULL == headB)
	{
		return NULL;
	}

	Node* curA = headA;
	Node* curB = headB;

	int along = 0, blong = 0;

	//�����������ߵ����
	//�������ó����������ĳ���

	while (curA)
	{
		along++;
		curA = curA->next;
	}
	while (curB)
	{
		blong++;
		curB = curB->next;
	}

	//������������ཻ�Ļ�����ô�������Ľڵ�һ������ͬ��
	//��������ֻ��Ҫ�ж��������������һ���ڵ��Ƿ���ͬ���ɵ�֪���������Ƿ���ͬ

	if (curA != curB)
	{
		return NULL;
	}

	//��Ϊ���������п��ܲ���һ���ĳ��ȣ����Ǵ��ཻ�ڵ�֮������ͬ��
	//����������Ҫ�ó��������ӺͶ̵������ĵȳ��ĵط���ʼ
	//�������������ٿ�ʼͬʱ������
	//��ʱ��������������ͬ�Ľڵ�����ཻ�Ľڵ�

	int num = along - blong;
	curA = headA;
	curB = headB;
	if (num > 0)
	{
		while (num--)
		{
			curA = curA->next;
		}
	}
	else
	{
		while (num++)
		{
			curB = curB->next;
		}
	}

	while (curA != curB)
	{
		curA = curA->next;
		curB = curB->next;
	}

	return curA;
}