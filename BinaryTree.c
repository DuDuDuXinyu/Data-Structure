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

BTNode* GreatBinTree(int* array, int size)
{
	BTNode* root = BuyBinTreeNode(array[0]);

}

//先序（深度优先遍历）

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

void PostOrder(BTNode* root)
{
	if (root)
	{
		PostOrder(root->pleft);
		PostOrder(root->pright);
		printf("%d", root->val);
	}
}

//获取二叉树中节点的个数

//简单的算法

//int count = 0;
//int GetNodeCount(BTNode* root)
//{
//	if (root)
//	{
//		count++;
//		GetNodeCount(root->pleft);
//		GetNodeCount(root->pright);
//	}
//	return count;
//}

//复杂的算法

int GetNodeCount(BTNode* root)
{
	if (root)
	{
		//根+左子树的节点个数+右子树的节点个数

		return 1 + GetNodeCount(root->pleft) + GetNodeCount(root->pright);
	}
	else
	{
		return 0;
	}
}

//获取二叉树中叶子节点的个数

int GetLeafCount(BTNode* root)
{
	if (root)
	{
		if (root->pleft == NULL && root->pright == NULL)
		{
			return 1;
		}
		return GetLeafCount(root->pleft) + GetLeafCount(root->pright);
	}
	else
	{
		return 0;
	}
}

//获取二叉树的高度

int GetHight(BTNode* root)
{
	if (root)
	{
		int LeftHight = GetHight(root->pleft);
		int RightHight = GetHight(root->pright);
		return LeftHight > RightHight ? LeftHight + 1 : RightHight + 1;
	}
	else
	{
		return 0;
	}
}

//获取第k层中节点的个数

int GetLevelCount(BTNode* root, int k)
{
	if (NULL == root || k <= 0 || k > GetHight(root))
	{
		return 0;
	}
	if (1 == k)
	{
		return 1;
	}
	return GetLevelCount(root->pleft, k - 1) + GetLevelCount(root->pright, k - 1);
}


//返回x在数中多对应的节点
BTNode* Find(BTNode* root, BTDateType x)
{
	if (NULL == root)
	{
		return NULL;
	}
	if (root->val == x)
	{
		return root;
	}

	BTNode* PNode = NULL;
	if ((PNode = Find(root->pleft, x)) || (PNode = Find(root->pright, x)))
	{
		return PNode;
	}
	return NULL;
}

//获取Node的双亲

BTNode* GetParent(BTNode* proot, BTNode* pNode)
{
	if (NULL == proot || NULL == pNode || pNode == proot)
	{
		return NULL;
	}
	if (proot->pleft == pNode || proot->pright == pNode)
	{
		return proot;
	}

	BTNode* pParet = NULL;
	if ((GetParent(proot->pleft, pNode)) || (GetParent(proot->pright, pNode)))
	{
		return pParet;
	}
	return  NULL;
}

//层序遍历（广度优先遍历）
//用队列实现，所以需要引用队列的头文件

void BinaryTreeLevelOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty())
	{
		BTNode* cur = QueueFront(&q);
		QueuePop(&q);

		printf("%d", cur->val);

		if (cur->pleft)
		{
			QueuePush(&q, cur->pleft);
		}
		if (cur->pright)
		{
			QueuePush(&q, cur->pright);
		}
	}
	printf("\n");
}

//镜像二叉树

void MirrorBinTree(BTNode* root)
{
	if (root)
	{
		BTNode* temp = root->pleft;
		root->pleft = root->pright;
		root->pright = temp;

		MirrorBinTree(root->pleft);
		MirrorBinTree(root->pright);
	}
}

void MirrorBinTree(BTNode* root)
{
	Queue q;
	if (NULL == root)
		return;
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* cur = QueueFront(&q);
		QueuePop(&q);

		BTNode* temp = cur->pleft;
		cur->pleft = cur->pright;
		cur->pright = temp;

		if (cur->pleft)
			QueuePush(&q, cur->pleft);
		if (cur->pright)
			QueuePush(&q, cur->pright);
	}
}