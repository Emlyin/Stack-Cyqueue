#include<iostream>
using namespace std;
#include"SqQueue.h"
void YHTriangle(int n)
{
	SqQueue<int> Q;
	InitQueue(Q, n+3);                               //��������
	EnQueue(Q, 0);                                 //0��1���
	EnQueue(Q, 1);
	int k,e1,e2,e;                                      //k������e1��e2�ֱ�Ϊ����Ԫ�غͶ�ͷԪ��
	cout << 1 << endl;
	for (int i = 2; i <= n; i++)                  //ÿһ��
	{
		EnQueue(Q, 0);                            //0���
		k = 1;                                    //����
		while (k <= i)
		{
			if (DeQueue(Q, e1) && GetHead(Q, e2))//���ӣ�ȡ��ͷ
			{
				k++;
				e = e1 + e2;
				cout << e << '\t';
				EnQueue(Q, e);
			}
			else
				cout << "�����쳣";
		}
		cout << endl;
	}
	DestroyQueue(Q);
}
void dismenue()
{                                              //��ʾ�˵�
	cout << endl;
	cout << "0--����\n1--��ʼ\n";
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
			cout << "Please input n(������):\n";
			cin >> n;
			cout << "n��������ǣ�\n";
			YHTriangle(n);                                               //����N10to16
			break;
		case 0:														// �˳�
			cout << "�������� Bye-bye!" << endl;
			break;
		default:													// ��Чѡ��
			cout << "��Чѡ��!\n";
			break;
		}
		system("pause");
		system("cls");
	} while (choice);
	return 0;
}