
/*
*	@brief	����ť�� ���� �����
*	@date	2019.10.06
*	@author	��μ�
*/

#pragma once
#include <iostream>
#include <string>

#define maxQueue 30

template <typename T>
class CircularQueue
{
public:
	/**
	*	@brief	Allocate dynamic array whose size is maxQueue.
	*	@pre	The maxQueue is defined
	*	@post	Member of items points the allocated array.
	*/
	CircularQueue();

	/**
	*	@brief	Allocate dynamic array whose size is max.
	*	@pre	none.
	*	@post	Member of items points the allocated array.
	*/
	CircularQueue(int max);

	/**
	*	@brief	Destruct the object. Free the array dynamically allocated.
	*	@pre	Release memory for queue pointer.
	*	@post	none.
	*/
	~CircularQueue();


	/**
	*	@brief	Determines whether the queue is full.
	*	@pre	Queue has been initialized.
	*	@post	Function value = (queue is full)
	*/
	bool IsFull();

	/**
	*	@brief	Determines whether the queue is empty.
	*	@pre	Queue has been initialized.
	*	@post	Function value = (queue is empty)
	*/
	bool IsEmpty();

	/**
	*	@brief	Makes the queue empty.
	*	@pre	Queue has been initialized.
	*	@post	m_iFront�� m_iRear is set same value as Constructer.
	*/
	void MakeEmpty();

	/**
	*	@brief	Adds newItem to the last of the queue.
	*	@pre	Queue has been initialized.
	*	@post	If (queue is full), FullQueue exception is thrown; otherwise, newItem is at the last.
	*/
	bool EnQueue(T item);

	bool DeQueue();

	/**
	*	@brief	Removes first item from the queue.
	*	@pre	Queue has been initialized.
	*	@post	If (queue is empty), EmptyQueue exception is thrown; otherwise, first element has been removed from queue. item gets value of removed item.
	*/
	bool DeQueue(T& item);

	/**
	*	@brief	Print all the items in the queue on screen
	*	@pre	Queue has been initialized.
	*	@post	None.
	*/
	void Print();

private:
	int m_iFront;	//index of one infront of the first element.
	int m_iRear;	//index of the last element.
	int m_nMaxQueue;	//max size of the queue.
	T* m_pItems;	//pointer for dynamic allocation.
	int order; //�÷��̵� Ƚ�� ����
};

//Allocate dynamic array whose size is maxQueue.
template <typename T>
CircularQueue<T>::CircularQueue()
{
	m_pItems = new T[maxQueue];	//m_pItems�� ũ�Ⱑ maxQueue�� �迭�� �����.
	m_nMaxQueue = maxQueue;
	m_iFront = m_nMaxQueue - 1;
	m_iRear = m_nMaxQueue - 1;	//��� �������� �ʱ�ȭ�����ش�.

}

//Allocate dynamic array whose size is max.
template <typename T>
CircularQueue<T>::CircularQueue(int max)
{
	m_pItems = new T[max];	//m_pItems�� ũ�Ⱑ max�� �迭�� �����.
	m_nMaxQueue = max;
	m_iFront = m_nMaxQueue - 1;
	m_iRear = m_nMaxQueue - 1;	//��� �������� �ʱ�ȭ�����ش�.

}

//Destruct the object. Free the array dynamically allocated.
template <typename T>
CircularQueue<T>::~CircularQueue()
{
	delete[] m_pItems;	//�����Ҵ��ߴ� �޸𸮸� �������ش�.
}

//Determines whether the queue is full.
template <typename T>
bool CircularQueue<T>::IsFull()
{
	if (m_iFront - m_iRear == 1 || m_iRear - m_iFront == m_nMaxQueue - 1)
		return 1;	//m_iFront�� m_iRear���� 1 ���϶��� �� �����̹Ƿ� 1�� �����Ѵ�. m_iFront�� 0�϶��� m_iRear�� m_nMaxQueue-1�� ������ �� �����̴�.
	return 0;	//�� ���� �ʾ����� 0�� �����Ѵ�.
}

//Determines whether the queue is empty.
template <typename T>
bool CircularQueue<T>::IsEmpty()
{
	if (m_iFront == m_iRear)
		return 1;	//m_iFront�� m_iRear�� ���� ���� queue�� ����ִ� �����̹Ƿ� 1�� �����Ѵ�.
	return 0;	//������� ������ 0�� �����Ѵ�.
}

//Makes the queue empty.
template <typename T>
void CircularQueue<T>::MakeEmpty()
{
	m_iFront = m_nMaxQueue - 1;
	m_iRear = m_nMaxQueue - 1;	//�����ڿ� ���� ������ m_iFront�� m_iRear�� �������ش�.
}

//Adds newItem to the last of the queue.
template <typename T>
bool CircularQueue<T>::EnQueue(T item)
{
	if (IsFull())
		return false;	//�� á���� throw FullQueue

	m_iRear = (m_iRear + 1) % m_nMaxQueue;
	m_pItems[m_iRear] = item;	//m_iRear�� 1���������ְ� item���� �־��ش�.

	return true;
}

//Overloading..
template <typename T>
bool CircularQueue<T>::DeQueue()
{
	if (IsEmpty())
		return false;

	m_iFront = (m_iFront + 1) % m_nMaxQueue;

	//item = m_pItems[m_iFront];	//m_iFront�� 1 ���������ְ� ������ ���� item�� �������ش�.
	return true;
}

//Removes first item from the queue.
template <typename T>
bool CircularQueue<T>::DeQueue(T & item)
{
	if (IsEmpty())
		return false;

	m_iFront = (m_iFront + 1) % m_nMaxQueue;
	item = m_pItems[m_iFront];	//m_iFront�� 1 ���������ְ� ������ ���� item�� �������ش�.

	return true;
}

template <typename T>
void CircularQueue<T>::Print() {
	if (m_iFront > m_iRear) {
		for (int i = m_iFront + 1; i < m_nMaxQueue; i++) {
			m_pItems[i].DisPlayRecordOnScreen();
			cout << "===================================" << endl;
		}
		for (int i = 0; i <= m_iRear; i++) {
			m_pItems[i].DisPlayRecordOnScreen();
			cout << "===================================" << endl;
		}
	}
	else {
		for (int i = m_iFront + 1; i <= m_iRear; i++) {
			m_pItems[i].DisPlayRecordOnScreen();
			cout << "===================================" << endl;
		}
	}
	cout << endl;
}
