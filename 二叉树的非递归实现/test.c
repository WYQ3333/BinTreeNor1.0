#include"BinTreeNor.h"

void test()
{
	char *str = "ABD###CE##F";
	int size = strlen(str);
	Stack s;
	StackInit(&s);//��ʼ��ջ
	BinTreeNor *pRoot = NULL;
	int index = 0;
	CreateBinTreeNor(&pRoot,str, size, &index, '#');
	//////////////////////////////////////////////////
	//printf("�ݹ�ʵ�ֵ��������Ϊ��");
	//Preorder(pRoot);
	//printf("\n");
	//printf("�ݹ�ʵ�ֵ��������Ϊ��");
	//Inorder(pRoot);
	//printf("\n");
	//printf("�ݹ�ʵ�ֵĺ������Ϊ��");
	//Postorder(pRoot);
	//printf("\n");
	///////////////////////////////////////////////////////////
	printf("�ǵݹ�ʵ�ֵ��������Ϊ��");
	PreorderNor(&s,pRoot);
	printf("\n");
	/*printf("�ǵݹ�ʵ�ֵ��������Ϊ��");
	InorderNor(&s,pRoot);
	printf("\n");
	printf("�ǵݹ�ʵ�ֵĺ������Ϊ��");
	PostorderNor(&s,pRoot);
	printf("\n");*/
}

int main()
{
	test();
	system("pause");
	return 0;
}