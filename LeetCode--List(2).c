#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

//������

typedef struct ListNode {
	int val;
	struct ListNode* next;
}Node;

//�����ָ��ĵ�����

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

// �ָ�����

struct ListNode* partition(struct ListNode* head, int x)
{
	//��ջ�ϴ��������յ�����

	Node lessNode = { 0,NULL };
	Node moreNode = { 0,NULL };

	//��ָ��ָ�������
	//�γɴ�ͷ�ڵ������

	Node* lessTail = &lessNode;
	Node* moreTail = &moreNode;

	//��headΪ��ֱ�ӷ���


	if (NULL == head)
	{
		return NULL;
	}

	//��������

	while (head)
	{

		//����Ĵ����ֺ�ϸ�ڣ�Ҫע��

		if (head->val < x)
		{
			//������head����lessTail��
			//��������λ�û�����lessTail��ȷ����

			lessTail->next = head;
			lessTail = head;
		}
		else
		{
			moreTail->next = head;
			moreTail = head;
		}
		head = head->next;
	}

	//����������ϳ�һ������
	//ע�������ϸ��
	//moreNode��next��ǰ�����������
	//��Ϊ�Ǹ���ͷ�ڵ������

	lessTail->next = moreNode.next;

	//ע�⣺�����moreTail֮����Ҫ����һ��NULL������
	//��Ϊ��һ���������þ���NULL��Ҳ�п�����head�ڴ˽ڵ�֮���һ���ڵ�ֱ��NULL

	moreTail->next = NULL;

	//��ͷ�ڵ����������ͷ�ڵ����һ���ڵ㼴��

	return lessNode.next;
}

//�ҵ���������Ļ����

struct ListNode* detectCycle(struct ListNode* head) {
	Node* fast = head;
	Node* low = head;

	//ͨ������ָ�����ж������Ƿ����
	//isCircycle����������ʾ�����Ƿ�����ı�־

	bool isCircycle = false;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		low = low->next;
		if (low == fast)
		{
			isCircycle = true;
			break;
		}
	}

	//��������ֱ�ӷ���NULL

	if (!isCircycle)
	{
		return NULL;
	}

	//fastΪ����ָ�������ĵ�һ��������
	//���ڿ���ָ������Կ��Ե�֪��������ָ������ʱ����ָ�벢δ����һȦ
	//��ʱ��head��ͷ��ʼ��fast��headͬʱ��һ��һ���Ŀ�ʼ����
	//��fast����head��ʱ����ǻ������
	//head������������ΪL
	//������㵽fast�ľ���ΪX
	//����ΪR
	//fast���뻷���ľ���ΪR-X
	//��fast��low�Ĺ�ϵ��֪��2L+2X=L+X+nR(ǰ���2����low��·�̣�������fast��·��)
	//L=nR-X->{n=1,L=R-X}{n=2,L=R-X+R}
	//���Ե�֪����nΪ���٣���head����Lʱ��fastҲ�պ�����nR-X
	//��ó�head==fastʱ�ǻ������

	while (fast != head)
	{
		fast = fast->next;
		head = head->next;
	}

	return head;
}

//���ƴ����ָ�������
//����nextָ��ָ����һ���ڵ��⻹��һ��random��ָ�����ָ������ڵ����NULL

//����һ������һ���µ�����newHead������headʹnewHead��head��nextһ��
//Ȼ����head����ÿһ���ڵ��random��ָ���λ�ã��̶���newHead��randomָ���Լ��������Ӧ��λ��
//�����¿��ٵ�����newHead

class Solution {
public:

	//�Զ���һ�����ٿռ䲢��ʼ���ĺ���

	Node* buyNode(int val)
	{
		Node* newNode = (Node*)malloc(sizeof(Node));
		
		//�жϿռ��Ƿ񿪱ٳɹ�

		if (NULL == newNode)
		{
			return NULL;
		}

		//��ֵ��ʼ��

		newNode->val = val;
		newNode->next = NULL;
		newNode->random = NULL;

		return newNode;
	}

	Node* copyRandomList(Node* head) 
	{
		//���headΪNULLֱ�ӷ���

		if (NULL == head)
		{
			return NULL;
		}

		Node* newHead = NULL;
		Node* newNode = NULL;
		Node* cur = head;

		//����β�巨��cope����head
		//��Ϊһ��ʼ��newHead��NULL
		//������Ҫ����ѭ���������һ����ֵ�����ſ��Խ���ѭ��

		newHead = buyNode(cur->val);
		Node* tail = newHead;
		cur = cur->next;
		while (cur)
		{
			newNode = buyNode(cur->val);
			tail->next = newNode;
			tail = newNode;
			cur = cur->next;
		}

		//��ʼ����head�ҵ�ÿһ���ڵ��random��ָ��

		cur = head;
		Node* newAdd = newHead;
		while (cur)
		{
			//����Ѱ��random��ָ��

			Node* search = head;

			//������newHead����ڵ㸳randomֵ��ָ��

			Node* addRandom = newHead;

			//����ȷ��random��λ�õ�����

			int count = 0;

			//head��randomΪNULL����ֱ�Ӹ�newHead��random��ֵ

			if (cur->random == NULL)
			{
				newAdd->random = NULL;

				//������һ�εĲ���

				cur = cur->next;
				newAdd = newAdd->next;
				continue;
			}

			//Ѱ��random��ָ��

			while (cur->random != search)
			{
				count++;
				search = search->next;
			}

			//ָ���һ���ڵ�����

			if (count == 0)
			{
				newAdd->random = newHead;
			}

			//ָ��ǵ�һ���ڵ�����

			while (count--)
			{
				newAdd->random = addRandom->next;
				addRandom = addRandom->next;
			}

			//ÿһ�εĵ���

			cur = cur->next;
			newAdd = newAdd->next;
		}

		return newHead;
	}
};

//����������ԭ�����ÿһ���ڵ�ĺ������һ������valһ���Ľڵ�
//Ȼ��ԭ��������ĳһ�ڵ��randomָ���λ�õ���һ�����Ǹýڵ���һ���ڵ��random��λ��
//��������𿪼���

class Solution {
public:

	//�Զ���һ�����ٿռ䲢��ʼ���ĺ���

	 Node* buyNode(int val)
	 {
	     Node* newNode=(Node*)malloc(sizeof(Node));

		 //�жϿռ��Ƿ񿪱ٳɹ�

	     if(NULL==newNode)
	     {
	         return NULL;
	     }

		 //��ֵ��ʼ��

	     newNode->val=val;
	     newNode->next=NULL;
	     newNode->random=NULL;

	     return newNode;
	 }

	 Node* copyRandomList(Node* head) 
	 {
		 //���headΪNULL�������ֱ�ӷ���NULL

	     if(NULL==head)
	     {
	         return NULL;
	     }

		 //��ԭ�����в����µĽڵ�

	     Node* cur=head;
	     Node* newNode=NULL;
	     while(cur)
	     {
	         newNode=buyNode(cur->val);
	         newNode->next=cur->next;
	         cur->next=newNode;
	         cur=newNode->next;
	     }

		 //���½ڵ��random��ֵ

	     cur=head;
	     while(cur)
	     {
	         newNode=cur->next;
	         if(cur->random)
	         {
	             newNode->random=cur->random->next;
	         }
	         cur=newNode->next;
	     }

		 //�Ͽ��¾���������

	     Node* newHead=head->next;
	     cur=head;

	     while(cur->next)
	     {
	         newNode=cur->next;
	         cur->next=newNode->next;
	         cur=newNode;
	     }

	     return newHead;
	 }
};

//��������в�������

//����һ������������һ�����Ľ��в���

struct ListNode* insertionSortList(struct ListNode* head) 
{
	Node* newHead = NULL;
	Node* cur = head;

	while (cur)
	{
		//��cur��ԭ�������Ƴ�--->ͷɾ

		head = cur->next;

		//��newHead����cur�Ĳ���λ��

		Node* pos = newHead;

		//�������λ�õ�ǰһ���ڵ�

		Node* prev = NULL;

		//����Ѱ�Ҳ���λ��

		while (pos)
		{
			if (cur->val < pos->val)
			{
				break;
			}
			prev = pos;
			pos = pos->next;
		}

		//cur��λ�����ҵ�
		//����λ����ͷ��㴦

		if (pos == newHead)
		{
			cur->next = newHead;
			newHead = cur;
		}

		//����λ�ò���ͷ���

		else
		{
			cur->next = pos;
			prev->next = cur;
		}
		cur = head;
	}

	return newHead;
}

//��������ת��Ϊ���飬Ȼ���������ת��Ϊ������

 struct ListNode* insertionSortList(struct ListNode* head){
     int  a[5000],i=0,k=0;
     Node* cur=head;

	 //��������

     while(cur)
     {
         a[i++]=cur->val;
         cur=cur->next;
     }

	 //ð������

     for(int j=0;j<i-1;j++){
         for(k=0;k<i-1-j;k++){
             if(a[k]>a[k+1]){
                 int temp=a[k];
                 a[k]=a[k+1];
                 a[k+1]=temp;
             }
         }
     }

	 //תΪ����

     cur=head;
     k=0;
     while(k<i)
     {
         cur->val=a[k++];
         cur=cur->next;
     }

     return head;
 }

 //��������---l1->l2->l3->l4
 //������֮��---l1->l4->l3->l4

 void reorderList(struct ListNode* head) {

	 //����Ҫ�ƶ������

	 if (head == NULL || head->next == NULL || head->next->next == NULL)
	 {
		 return head;
	 }

	 //�ҵ��м�ֵ

	 Node* fast = head;
	 Node* slow = head;
	 while (fast && fast->next)
	 {
		 slow = slow->next;
		 fast = fast->next->next;
	 }

	 //���ú�벿��


	 Node* cur = slow->next;
	 slow->next = NULL;
	 Node* newNode = NULL;
	 while (cur)
	 {
		 Node* next = cur->next;
		 cur->next = newNode;
		 newNode = cur;
		 cur = next;
	 }

	 //��ʼ����

	 cur = head;
	 while (newNode)
	 {
		 Node* newNext = newNode->next;
		 Node* curNext = cur->next;

		 //����

		 cur->next = newNode;
		 newNode->next = curNext;
		 cur = curNext;
		 newNode = newNext;
	 }
 }