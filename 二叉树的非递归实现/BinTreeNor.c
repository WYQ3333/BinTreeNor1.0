#include"BinTreeNor.h"

pBinTreeNor BuyNewNode(KeyType data)//购买新节点
{
	pBinTreeNor NewNode = (pBinTreeNor)malloc(sizeof(BinTreeNor));
	if (NewNode == NULL)
		return NULL;
	NewNode->data = data;
	NewNode->left = NULL;
	NewNode->right = NULL;
}

void StackInit(pStack pS)//初始化栈
{
	pS->size = 0;
	pS-> top = -1;
	int i = 0;
	for (i = 0; i < MAX; i++)
	{
		pS->array[i] = NULL;
	}
}
void Pushstack(pStack pS, pBinTreeNor pRoot)//入栈
{
	if (pS->size < MAX)
	{
		pS->top++;
		pS->array[pS->top] = pRoot->data;
		pS->size++;
		
	}
}
void PopStack(pStack pS)//出栈
{
	if (pS->size == 0)
		return;
	pS->size--;
	pS->top--;
}
KeyType TopStack(pStack pS)//取栈顶元素
{
	if ((pS->size > 0) && (pS->size < MAX))
	{
		return pS->array[pS->top];
	}
}
int IsEmptyStack(pStack pS)//判断栈是否为空
{
	return (pS->size == 0) ? 1 : 0;//空栈返回1
}
////////////////////////////////////////////////////////////////////////
////递归实现二叉树的遍历

void Preorder(pBinTreeNor pRoot)//递归实现先序遍历
{
	if (pRoot)
	{
		printf("%c", pRoot->data);
		Preorder(pRoot->left);
		Preorder(pRoot->right);
	}
}
void Inorder(pBinTreeNor pRoot)//递归实现中序遍历
{
	if (pRoot)
	{
		Inorder(pRoot->left);
		printf("%c", pRoot->data);
		Inorder(pRoot->right);
	}
}
void Postorder(pBinTreeNor pRoot)//递归实现后序遍历
{
	if (pRoot)
	{
		Postorder(pRoot->left);
		Postorder(pRoot->right);
		printf("%c", pRoot->data);
	}
}
//////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
////非递归实现二叉树的遍历
void PreorderNor(pStack pS, pBinTreeNor pRoot)//非递归实现先序遍历
{
	if (pRoot == NULL)
		return;//空树
	Pushstack(pS, pRoot);
	while (!IsEmptyStack(pS))
	{
		KeyType cur = TopStack(pS);
		printf("%c", cur);
		PopStack(pS);
		if (pRoot->right)
		{
			Pushstack(pS, pRoot->right);
		}
		if (pRoot->left)
		{
			Pushstack(pS, pRoot->left);
		}
	}
}
void InorderNor(pStack pS, pBinTreeNor pRoot);//非递归实现中序遍历
void PostorderNor(pStack pS, pBinTreeNor pRoot);//非递归实现后序遍历
/////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
////创建二叉树
void CreateBinTreeNor(pBinTreeNor *pRoot, char *str, int size, int *index, int invalid)//创建二叉树
{
	assert(pRoot != NULL);
	if (((*index) < size)&&(str[*index] != invalid))
	{
		*pRoot = BuyNewNode(str[*index]);
		if ((*pRoot) != NULL)
		{
			(*index)++;
			CreateBinTreeNor(&(*pRoot)->left, str, size, index, invalid);//创建左子树
			(*index)++;
			CreateBinTreeNor(&(*pRoot)->right, str, size, index, invalid);//创建左子树
		}
	}
}