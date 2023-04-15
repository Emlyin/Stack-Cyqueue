#include<iostream>
using namespace std;
#include"SqQueue.h"
void YHTriangle(int n)
{
	SqQueue<int> Q;
	InitQueue(Q, n+3);                               //创建队列
	EnQueue(Q, 0);                                 //0，1入队
	EnQueue(Q, 1);
	int k,e1,e2,e;                                      //k计数，e1，e2分别为出队元素和队头元素
	cout << 1 << endl;
	for (int i = 2; i <= n; i++)                  //每一行
	{
		EnQueue(Q, 0);                            //0入队
		k = 1;                                    //计数
		while (k <= i)
		{
			if (DeQueue(Q, e1) && GetHead(Q, e2))//出队，取对头
			{
				k++;
				e = e1 + e2;
				cout << e << '\t';
				EnQueue(Q, e);
			}
			else
				cout << "出队异常";
		}
		cout << endl;
	}
	DestroyQueue(Q);
}
void dismenue()
{                                              //显示菜单
	cout << endl;
	cout << "0--结束\n1--开始\n";
}
int main()
{
	bool choice;
	int n;
	do 
	{
		dismenue();
		cout << "Enter choice:";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Please input n(正整数):\n";
			cin >> n;
			cout << "n阶杨辉三角：\n";
			YHTriangle(n);                                               //调用N10to16
			break;
		case 0:														// 退出
			cout << "结束运行 Bye-bye!" << endl;
			break;
		default:													// 无效选择
			cout << "无效选择!\n";
			break;
		}
		system("pause");
		system("cls");
	} while (choice);
	return 0;
}