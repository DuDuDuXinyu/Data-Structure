#pragma once

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

typedef int BTDateType;

typedef struct BinTreeNode
{
	struct BinTreeNode* pleft;
	struct BinTreeNode* pright;
	BTDateType val;
}BTNode;

//���ٿռ�

BTNode* BuyBinTreeNode(BTDateType val)
{
	BTNode* pNewNode = (BTNode*)malloc(sizeof(BTNode));

	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}

	pNewNode->pleft = NULL;
	pNewNode->pright = NULL;
	pNewNode->val = val;
}

//����

void PreOrder(BTNode* root)
{
	if (root)
	{
		printf("%d", root->val);
		PreOrder(root->pleft);
		PreOrder(root->pright);
	}
}

//����

void InOrder(BTNode* root)
{
	if (root)
	{
		InOrder(root->pleft);
		printf("%d", root->val);
		InOrder(root->pright);
	}
}

//����

void PostOrder(BTNode * root)
{
	if (root)
	{
		PostOrder(root->pleft);
		PostOrder(root->pright);
		printf("%d", root->val);
	}
}

//��ȡ�������нڵ�ĸ���

int GetNodeCount(BTNode* root);

//��ȡ��������Ҷ�ӽڵ�ĸ���

int GetLeafCount(BTNode* root);

//��ȡ��k���нڵ�ĸ���

int GetLevelCount(BTNode* root);

//��ȡ�������ĸ߶�

int GetHight(BTNode* root);	

//����x�����ж��Ӧ�Ľڵ�
BTNode* Find(BTNode* root, BTDateType x);

//��ȡNode��˫��

BTNode* GetParent(BTNode* proot, BTNode* pNode);