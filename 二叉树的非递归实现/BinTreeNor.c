#include"BinTreeNor.h"

pBinTreeNor BuyNewNode(KeyType data)//�����½ڵ�
{
	pBinTreeNor NewNode = (pBinTreeNor)malloc(sizeof(BinTreeNor));
	if (NewNode == NULL)
		return NULL;
	NewNode->data = data;
	NewNode->left = NULL;
	NewNode->right = NULL;
}

void StackInit(pStack pS)//��ʼ��ջ
{
	pS->size = 0;
	pS-> top = -1;
	int i = 0;
	for (i = 0; i < MAX; i++)
	{
		pS->array[i] = NULL;
	}
}
void Pushstack(pStack pS, pBinTreeNor pRoot)//��ջ
{
	if (pS->size < MAX)
	{
		pS->top++;
		pS->array[pS->top] = pRoot->data;
		pS->size++;
		
	}
}
void PopStack(pStack pS)//��ջ
{
	if (pS->size == 0)
		return;
	pS->size--;
	pS->top--;
}
KeyType TopStack(pStack pS)//ȡջ��Ԫ��
{
	if ((pS->size > 0) && (pS->size < MAX))
	{
		return pS->array[pS->top];
	}
}
int IsEmptyStack(pStack pS)//�ж�ջ�Ƿ�Ϊ��
{
	return (pS->size == 0) ? 1 : 0;//��ջ����1
}
////////////////////////////////////////////////////////////////////////
////�ݹ�ʵ�ֶ������ı���

void Preorder(pBinTreeNor pRoot)//�ݹ�ʵ���������
{
	if (pRoot)
	{
		printf("%c", pRoot->data);
		Preorder(pRoot->left);
		Preorder(pRoot->right);
	}
}
void Inorder(pBinTreeNor pRoot)//�ݹ�ʵ���������
{
	if (pRoot)
	{
		Inorder(pRoot->left);
		printf("%c", pRoot->data);
		Inorder(pRoot->right);
	}
}
void Postorder(pBinTreeNor pRoot)//�ݹ�ʵ�ֺ������
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
////�ǵݹ�ʵ�ֶ������ı���
void PreorderNor(pStack pS, pBinTreeNor pRoot)//�ǵݹ�ʵ���������
{
	if (pRoot == NULL)
		return;//����
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
void InorderNor(pStack pS, pBinTreeNor pRoot);//�ǵݹ�ʵ���������
void PostorderNor(pStack pS, pBinTreeNor pRoot);//�ǵݹ�ʵ�ֺ������
/////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
////����������
void CreateBinTreeNor(pBinTreeNor *pRoot, char *str, int size, int *index, int invalid)//����������
{
	assert(pRoot != NULL);
	if (((*index) < size)&&(str[*index] != invalid))
	{
		*pRoot = BuyNewNode(str[*index]);
		if ((*pRoot) != NULL)
		{
			(*index)++;
			CreateBinTreeNor(&(*pRoot)->left, str, size, index, invalid);//����������
			(*index)++;
			CreateBinTreeNor(&(*pRoot)->right, str, size, index, invalid);//����������
		}
	}
}