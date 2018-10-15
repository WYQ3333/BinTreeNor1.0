#include"BinTreeNor.h"

void test()
{
	char *str = "ABD###CE##F";
	int size = strlen(str);
	Stack s;
	StackInit(&s);//初始化栈
	BinTreeNor *pRoot = NULL;
	int index = 0;
	CreateBinTreeNor(&pRoot,str, size, &index, '#');
	//////////////////////////////////////////////////
	//printf("递归实现的先序遍历为：");
	//Preorder(pRoot);
	//printf("\n");
	//printf("递归实现的中序遍历为：");
	//Inorder(pRoot);
	//printf("\n");
	//printf("递归实现的后序遍历为：");
	//Postorder(pRoot);
	//printf("\n");
	///////////////////////////////////////////////////////////
	printf("非递归实现的先序遍历为：");
	PreorderNor(&s,pRoot);
	printf("\n");
	/*printf("非递归实现的中序遍历为：");
	InorderNor(&s,pRoot);
	printf("\n");
	printf("非递归实现的后序遍历为：");
	PostorderNor(&s,pRoot);
	printf("\n");*/
}

int main()
{
	test();
	system("pause");
	return 0;
}