template <class DT>
struct SqQueue							// ˳��Ӷ���
{
	DT* base;							// ������ַ
	int front;							// ��ͷָ��
	int rear;							// ��βָ��
	int queuesize;						// ������
};

//����������ʵ��
//���㷨3.14��							
template <class DT>
bool InitQueue(SqQueue<DT>& Q, int m)	// ����һջ����Ϊm�Ŀն�
{
	Q.base = new DT[m];					//������пռ�
	if (!Q.base)
	{
		cout << "δ�����ɹ���";
		exit(1);
	}
	Q.front = Q.rear = 0;					// �ն�����
	Q.queuesize = m;
	return true;
}


//�㷨3.15��
template <class DT>
void DestroyQueue(SqQueue<DT>& Q)			// �ͷŶ��пռ�
{
	delete[] Q.base;
	Q.front = Q.rear = 0;
	Q.queuesize = 0;
}


//���㷨3.16��
template<class DT>
bool EnQueue(SqQueue<DT>& Q, DT e)
{
	if ((Q.rear + 1) % Q.queuesize == Q.front)     // ����
		return false;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % Q.queuesize;
	return true;							// ����ɹ�������true
}

//���㷨3.17��
template<class DT>
bool DeQueue(SqQueue<DT>& Q, DT& e)
{
	if (Q.front == Q.rear)						// �ӿ�
		return false;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % Q.queuesize;
	return true;							// ɾ���ɹ�������true
}


//���㷨3.18��
template<class DT>
bool GetHead(SqQueue<DT> Q, DT& e)
{
	if (Q.front == Q.rear)						// �ӿ�
		return false;
	e = Q.base[Q.front];
	return true;							// ����true
}


template<class DT>
bool GetTail(SqQueue<DT> Q, DT& e)			// ȡ��βԪ��
{
	if (Q.front == Q.rear)						// �ӿ�
		return false;						// ����false
	e = Q.base[Q.rear - 1];						// ȡ��βԪ��
	return true;							// ����true
}

template<class DT>
void ClearQueue(SqQueue<DT>& Q)
{
	Q.front = Q.rear = 0;
}


template<class DT>
bool QueueEmpty(SqQueue<DT> Q)				// ��ӿ�
{
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}


template<class DT>
bool QueueFull(SqQueue<DT> Q)				// �����
{
	if ((Q.rear + 1) % Q.queuesize == Q.front)     //����
		return true;
	else
		return false;
}


template<class DT>
void DispQueue(SqQueue<DT> Q)				//��ʾ��������
{
	int i = Q.front;
	while (i != Q.rear)
	{
		cout << Q.base[i] << "\t";
		i = (i + 1) % Q.queuesize;
	}
	cout << endl;
}

#pragma once
