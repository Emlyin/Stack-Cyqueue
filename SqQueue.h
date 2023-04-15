template <class DT>
struct SqQueue							// 顺序队定义
{
	DT* base;							// 队列首址
	int front;							// 队头指针
	int rear;							// 队尾指针
	int queuesize;						// 队容量
};

//基本操作的实现
//【算法3.14】							
template <class DT>
bool InitQueue(SqQueue<DT>& Q, int m)	// 创建一栈容量为m的空队
{
	Q.base = new DT[m];					//申请队列空间
	if (!Q.base)
	{
		cout << "未创建成功！";
		exit(1);
	}
	Q.front = Q.rear = 0;					// 空队属性
	Q.queuesize = m;
	return true;
}


//算法3.15】
template <class DT>
void DestroyQueue(SqQueue<DT>& Q)			// 释放队列空间
{
	delete[] Q.base;
	Q.front = Q.rear = 0;
	Q.queuesize = 0;
}


//【算法3.16】
template<class DT>
bool EnQueue(SqQueue<DT>& Q, DT e)
{
	if ((Q.rear + 1) % Q.queuesize == Q.front)     // 队满
		return false;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % Q.queuesize;
	return true;							// 插入成功，返回true
}

//【算法3.17】
template<class DT>
bool DeQueue(SqQueue<DT>& Q, DT& e)
{
	if (Q.front == Q.rear)						// 队空
		return false;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % Q.queuesize;
	return true;							// 删除成功，返回true
}


//【算法3.18】
template<class DT>
bool GetHead(SqQueue<DT> Q, DT& e)
{
	if (Q.front == Q.rear)						// 队空
		return false;
	e = Q.base[Q.front];
	return true;							// 返回true
}


template<class DT>
bool GetTail(SqQueue<DT> Q, DT& e)			// 取队尾元素
{
	if (Q.front == Q.rear)						// 队空
		return false;						// 返回false
	e = Q.base[Q.rear - 1];						// 取队尾元素
	return true;							// 返回true
}

template<class DT>
void ClearQueue(SqQueue<DT>& Q)
{
	Q.front = Q.rear = 0;
}


template<class DT>
bool QueueEmpty(SqQueue<DT> Q)				// 测队空
{
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}


template<class DT>
bool QueueFull(SqQueue<DT> Q)				// 测队满
{
	if ((Q.rear + 1) % Q.queuesize == Q.front)     //队满
		return true;
	else
		return false;
}


template<class DT>
void DispQueue(SqQueue<DT> Q)				//显示队列内容
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
