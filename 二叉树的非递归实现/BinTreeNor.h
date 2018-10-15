#pragma once

#include<Windows.h>
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

#define MAX 20

typedef char KeyType;
typedef struct BinTreeNor
{
	KeyType data;
	struct BinTreeNor *left;
	struct BinTreeNor *right;
}BinTreeNor, *pBinTreeNor;

typedef struct Stack
{
	KeyType array[MAX];
	int size;
	int top;
}Stack,*pStack;



void StackInit(pStack pS);//初始化栈
void Pushstack(pStack pS, KeyType data);//入栈
void PopStack(pStack pS);//出栈
KeyType TopStack(pStack pS);//取栈顶元素
int IsEmptyStack(pStack pS);//判断栈是否为空
void CreateBinTreeNor(pBinTreeNor *pRoot, char *str, int size, int *index, int invalid);//创建二叉树
pBinTreeNor BuyNewNode(KeyType data);//购买新节点
///////////////////////////////////////////////////////////////////
////递归实现
void Preorder(pBinTreeNor pRoot);//递归实现先序遍历
void Inorder(pBinTreeNor pRoot);//递归实现中序遍历
void Postorder(pBinTreeNor pRoot);//递归实现后序遍历
//////////////////////////////////////////////////////////////////
////非递归实现

void PreorderNor(pStack pS,pBinTreeNor pRoot);//非递归实现先序遍历
void InorderNor(pStack pS, pBinTreeNor pRoot);//非递归实现中序遍历
void PostorderNor(pStack pS, pBinTreeNor pRoot);//非递归实现后序遍历