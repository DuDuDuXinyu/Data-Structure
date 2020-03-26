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

//开辟空间

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

//先序

void PreOrder(BTNode* root)
{
	if (root)
	{
		printf("%d", root->val);
		PreOrder(root->pleft);
		PreOrder(root->pright);
	}
}

//中序

void InOrder(BTNode* root)
{
	if (root)
	{
		InOrder(root->pleft);
		printf("%d", root->val);
		InOrder(root->pright);
	}
}

//后序

void PostOrder(BTNode * root)
{
	if (root)
	{
		PostOrder(root->pleft);
		PostOrder(root->pright);
		printf("%d", root->val);
	}
}

//获取二叉树中节点的个数

int GetNodeCount(BTNode* root);

//获取二叉树中叶子节点的个数

int GetLeafCount(BTNode* root);

//获取第k层中节点的个数

int GetLevelCount(BTNode* root);

//获取二叉树的高度

int GetHight(BTNode* root);	

//返回x在数中多对应的节点
BTNode* Find(BTNode* root, BTDateType x);

//获取Node的双亲

BTNode* GetParent(BTNode* proot, BTNode* pNode);