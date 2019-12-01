#pragma once
#include<iostream>
#include<cstdio>
#include<cstdlib>

/**
*	���Ḯ��Ʈ���� ���̴� NodeType�� ����ü
*/
template <typename T>
struct DoublyNodeType {
	T data; // �� ����� ������
	DoublyNodeType* prev;
	DoublyNodeType* next;
};

template <typename T>
class CircularQueueDoublyLinkedList
{ 
private:
	DoublyNodeType<T>* m_pFirst;
	DoublyNodeType<T>* m_pLast;
	int m_nLength;
public:
		CircularQueueDoublyLinkedList();
		~CircularQueueDoublyLinkedList();
		
		/**
*	@brief	����Ʈ�� ���� á���� �ƴ��� �˻��Ѵ�.
*	@pre	m_nLength�� ���� ������ �־�� �Ѵ�.
*	@post	���� á���� �ƴ����� �˷��ش�.
*	@return	���� �������� true, �ƴϸ� false�� ��ȯ.
*/
		bool IsEmpty();

		/**
		*	@brief	����Ʈ�� ���� á���� �ƴ��� �˻��Ѵ�.
		*	@pre	m_nLength�� ���� ������ �־�� �Ѵ�.
		*	@post	���� á���� �ƴ����� �˷��ش�.
		*	@return	���� �������� true, �ƴϸ� false�� ��ȯ.
		*/
		bool IsFull();

		/**
		*	@brief	����Ʈ�� ����.
		*	@pre	����.
		*	@post	m_pFirst�� m_pLast�� ������ ��� �����͸� �����.
		*/
		void MakeEmpty();

		/**
		*	@brief	����Ʈ�� ���̸� ��ȯ�Ѵ�.
		*	@pre	����.
		*	@post	����Ʈ�� ���̸� ��ȯ.
		*	@return	m_nLength ����Ʈ�� ���� ��ȯ.
		*/
		int GetLength() const;

		/**
		*	@brief	���ο� �������� ����Ʈ�� �߰��Ѵ�.
		*	@pre	item�� �Է¹޴´�.
		*	@post	�������� ����Ʈ�� �߰��Ѵ�.
		*	@return	���� �������� ������ 0�� ��ȯ�ϰ�, �Է¿� �����ϸ� 1�� ��ȯ.
		*/

		bool CheckEnd();//queue�� ������ �ƴ��� Ȯ���ϴ� �Լ�
		
		void Additem(T& item); //playlist�� ������ �߰�
		
		void Delete(T item);

		/**
		*	@brief	�Է¹��� ���������� ������ �ٲ۴�.
		*	@pre	item�� �Է¹޴´�.
		*	@post	���ο� ������ ��ü�ȴ�.
		*/
		void Replace(T item);

		/**
		*	@brief	�Է¹��� �������� ������ ���Ͽ� ���� ����Ʈ�� �������� �����´�.
		*	@pre	item�� �Է¹޴´�.
		*	@post	�˻��� �����͸� �����ۿ� �ִ´�.
		*	@return	��ġ�ϴ� �����͸� ã���� 1, �׷��� ������ 0�� ��ȯ.
		*/
		int Get(T& item);

		friend class CircularQueueDoublyIterator<T>; 
		//Iterator�� ģ�� Ŭ����

};

template <typename T>
CircularQueueDoublyLinkedList<T>::CircularQueueDoublyLinkedList(){
	//�� ó���� ���� NodeType ���� 
	m_pFirst = new DoublyNodeType<T>;
	m_pLast = new DoublyNodeType<T>;

	m_pFirst->next = m_pLast;
	m_pFirst->prev = NULL;
	m_pLast->next = NULL;
	m_pLast->prev = m_pFirst;
	m_nLength = 0;
}

template <typename T>
CircularQueueDoublyLinkedList<T>::~CircularQueueDoublyLinkedList() {
	delete m_pFirst;
	delete m_pLast;

}
template <typename T>
bool CircularQueueDoublyLinkedList<T>::IsEmpty() {
	if (m_nLength == 0) { //���̰� 0�̸� true ��ȯ
		return true;
	}
	else return fasle;
}


template <typename T>
bool CircularQueueDoublyLinkedList<T>::IsFull() {
	if (m_nLength == 5) //100���̸� FULL
		return true;
	else return false;

}


template <typename T>
bool CircularQueueDoublyLinkedList<T> ::CheckEnd()
{
	if (m_nLength==5)
		return true;
	else
		return false;
}


template <typename T>
void CircularQueueDoublyLinkedList<T>::MakeEmpty() {
	DoublyNodeType<T>* pitem;
	CircularQueueDoublyIterator<T> itor(*this);
	
	while (itor.NextNotNull()) {
		pitem = itor.m_pCurPointer;
		itor.Next();
		delete pitem;
	}

	m_pFirst->next = m_pLast;
	m_pFirst->prev = NULL;
	m_pLast->prev = m_pFirst;
	m_pLast->next=NULL:
	
	return;
}

template <typename T>
int CircularQueueDoublyLinkedList<T>::GetLength() const {
	return m_nLength;
}


template <typename T>
void CircularQueueDoublyLinkedList<T>::Additem(T& item) {
	CircularQueueDoublyIterator itor(*this);
	itor.Next();
	if (IsEmpty()) {//ó�� �����Ҷ�
		DoublyNodeType<T>* pItem = new DoublyNodeType<T>;
		pItem->data = item;
		m_pFirst->next = pItem;
		pItem->prev = m_pFirst;
		pItem->next = m_pLast;
		m_pLast->prev = pItem; // ó���� �� ���̿� ����.
		m_nLength++;
		return 1;
	}/*
	else if (IsFull()) {
		DoublyNodeType<T>* pItem = new DoublyNodeType<T>;
		pItem->data = item;
		for (int i = 0; i < m_Length - 3; i++) {
			itor.Next();
		}

	}*/
	else // ó���� �ƴ� ��
	{
		while (1)
		{
			if (!itor.NextNotNull())//�����������ƴ���
				//item < itor.m_pCurPointer->data ||  ����// �´� �ڸ��� ã�´�. 
			{
				DoublyNodeType<T>* pItem = new DoublyNodeType<T>;
				pItem->data = item;
				pItem->prev = itor.m_pCurPointer->prev;
				pItem->next = itor.m_pCurPointer;
				itor.m_pCurPointer->prev->next = pItem;
				itor.m_pCurPointer->prev = pItem; // �������� ����.
				m_nLength++;
				return 1;
			}
			else if (item == itor.m_pCurPointer->data) // ���� ������ �������� ������
				return 0; // 0�� ��ȯ.
			else
				itor.Next(); // �������� �̵�.
		}
	}
}


// �Է¹��� �������� �����Ϳ��� ã�Ƴ��� �����Ѵ�.
template <typename T>
void CircularQueueDoublyLinkedList<T>::Delete(T item)
{
	DoublyIterator<T> itor(*this);
	itor.Next(); // �������� �̵�.

	while (itor.m_pCurPointer != m_pLast)
	{
		if (itor.m_pCurPointer->data == item) // ��ġ�ϴ� �����͸� ã�´�.
		{
			DoublyNodeType<T>* pItem = new DoublyNodeType<T>;
			pItem = itor.m_pCurPointer;
			itor.Next();
			pItem->prev->next = itor.m_pCurPointer;
			itor.m_pCurPointer->prev = pItem->prev; // �����ϴ� ����� �հ� �ڸ� ���� �̾��ش�.
			delete pItem; // ����.
			m_nLength--; // ���� ����.
			return;
		}
		else
			itor.Next();
	}
	return;
}

// �Է¹��� �������� ������ ��ü�Ѵ�.
template <typename T>
void CircularQueueDoublyLinkedList<T>::Replace(T item)
{
	DoublyIterator<T> itor(*this);
	itor.Next(); // �������� �̵�.

	while (itor.m_pCurPointer != m_pLast)
	{
		if (itor.m_pCurPointer->data == item)
		{
			itor.m_pCurPointer->data = item; // ������ ��ü.
			return;
		}
		else
			itor.Next();
	}

	return;
}

// �Է¹��� �����۰� ��ġ�ϴ� �������� ����Ʈ���� ã�� �����´�.
template <typename T>
int CircularQueueDoublyLinkedList<T>::Get(T& item)
{
	DoublyIterator<T> itor(*this);
	itor.Next();

	while (itor.m_pCurPointer != m_pLast)
	{
		if (itor.m_pCurPointer->data == item)
		{
			item = itor.m_pCurPointer->data;
			return 1; // ��ġ�ϸ� 1�� ��ȯ.
		}
		else
			itor.Next(); // �������� �̵�.
	}

	return 0; // ��ġ���� ������ 0�� ��ȯ.
}
