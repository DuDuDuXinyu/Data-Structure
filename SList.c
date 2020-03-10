#include "SList.h"

//����һ���µĽڵ�

SLNode* BuySLNode(DateType data)
{
	SLNode* newNode = (SLNode*)malloc(sizeof(SLNode));
	if (NULL == newNode)
	{
		printf("����ڵ�ʧ�� ��");
		arrest(newNode);
	}
	newNode->data = data;
	newNode->next = NULL;

	return newNode;
}

//β��

void SLPushBack(SLNode** head, DateType data)
{
	//�ж������Ƿ����
	assert(head);

	SLNode* newNode = BuySLNode(data);
	
	//�����Ƿ�Ϊ��
	if (*head == NULL)
	{
		//��һ���ڵ�Ĳ��뷽ʽ
		*head = newNode;
	}
	else 
	{
		//˵���������Ѿ��нڵ���
		//����β��
		//��ȥ����������һ���ڵ㣨nextΪNULL��
		SLNode* tail = *head;
		//��ѭ���ҵ����Ľڵ�
		while (tail->next) 
		{
			//�����ǵ���������˳���
			//���Բ�������tail++
			tail = tail->next;
		}
		//���½ڵ����ӵ����һ���ڵ�֮��
		tail->next = newNode;
	}
}

//βɾ

void SLPopBack(SLNode** head)
{
	assert(head);

	//������
	if (NULL == *head)
	{
		return;
	}
	else if (NULL == (*head)->next)
	{
		free(*head);
		*head = NULL;
	}
	else
	{
		//�ж���ڵ�
		//��Ҫ����cur���ҵ����һ���ڵ�
		//���ұ���cur��ǰһ���ڵ�
		SLNode* cur = *head;
		SLNode* prev = NULL;
		while (cur->next)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = cur->next;
		free(cur);
	}
}

//ͷ��

void SLPushFront(SLNode** head, DateType data)
{
	assert(head);

	SLNode* newNode = BuySLNode(data);
	newNode->next = *head;
	*head = newNode;
}

// ͷɾ

void SLPopFront(SLNode** head)
{
	assert(head);

	SLNode* delNode = (*head);

	if (NULL == *head)
	{
		return;
	}

	*head = delNode->next;
	free(delNode);
}

//��posλ��֮�����data

void SLInseartAfter(SLNode* pos, DateType data)
{
	SLNode* newNode = NULL;

	//������

	if (NULL == pos)
	{
		return;
	}

	newNode = BuySLNode(data);
	newNode->next = pos->next;
	pos->next = newNode;

}

//ɾ��pos����Ľڵ�

void SLEraseAfter(SLNode* pos)
{
	SLNode* delNode = NULL;

	//�޷�ɾ����һ���ڵ�����һ���ڵ�
	
	if (NULL == pos || NULL == pos->next)
	{
		return;
	}
	delNode = pos->next;
	pos->next = delNode->next;
	free(delNode);
}

//����ĳ���

int SLSize(SLNode* head)
{
	int count = 0;
	SLNode* cur = head;
	while (cur) 
	{
		count++;
		cur = cur->next;
	}
	return count;
}

//�ҵ�����Ϊdata�Ľڵ�

SLNode* SLFind(SLNode* head, DateType data)
{
	SLNode* cur = head;
	while (cur)
	{
		if (cur->data == data)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//�ݻ�����

void SLDeatroy(SLNode** head)
{
	assert(head);
	SLNode* cur = *head;

	//��Ϊfreeֻ���ͷŵ�ǰһ���ڵ�
	//������Ҫһ������ȥ�ͷ�
	//��Ȼ������ڴ�й¶

	while (cur)
	{
		*head = cur->next;
		free(cur);
		cur = *head;
	}
}

//��ӡ����

void PrintSList(SLNode* head)
{
	SLNode* cur = head;
	while (cur) {
		printf("%d--->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}