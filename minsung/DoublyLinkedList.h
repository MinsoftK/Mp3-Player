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
class DoublyLinkedList
{ 
private:
	//DoublyNodeType<T> *Node;
	DoublyNodeType<T> *m_pLast;
	DoublyNodeType<T>* m_pFirst;
	int m_nLength;
public:
		DoublyLinkedList();
		~DoublyLinkedList();
		
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
		
		int Additem(const T& item); //playlist�� ������ �߰�
		
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

		friend class DoublyIterator<T>; 
		//Iterator�� ģ�� Ŭ����
};
template <typename T>
DoublyLinkedList<T> ::DoublyLinkedList(){
	m_pFirst = new DoublyNodeType<T>;
	m_pLast = new DoublyNodeType<T>;

	m_pFirst->next = m_pLast; // ���� ó���� ���θ� ����Ű�� �ʱ�ȭ.
	m_pFirst->prev = NULL; // ó��.

	m_pLast->next = NULL; // ��.
	m_pLast->prev = m_pFirst; // ���� ó���� ���θ� ����Ű�� �ʱ�ȭ.

	m_nLength = 0; // ���̴� 0.
}

// �Ҹ���.
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList(){
	delete m_pFirst;
	delete m_pLast;
}

// ����Ʈ�� ������� �˻��Ѵ�.
template <typename T>
bool DoublyLinkedList<T>::IsEmpty(){
	if (m_nLength == 0)
		return true;
	else
		return false;
}

// ����Ʈ�� �� ���ִ��� �˻��Ѵ�.
template <typename T>
bool DoublyLinkedList<T>::IsFull(){
	if (m_nLength == 10)
		return true;
	else
		return false;
}

// ����Ʈ�� ����.
template <typename T>
void DoublyLinkedList<T>::MakeEmpty(){
	DoublyNodeType<T>* pItem;
	DoublyIterator<T> itor(*this);
	itor.Next(); // �������� �̵�.

	while (itor.NextNotNull())
	{
		pItem = itor.m_pCurPointer;
		itor.Next(); // ���� �����͸� �������� �̵�.
		delete pItem;
	}

	m_pFirst->next = m_pLast;
	m_pFirst->prev = NULL;
	m_pLast->prev = m_pFirst;
	m_pLast->next = NULL;

	return;
}

// ����Ʈ�� ���̸� ��ȯ�Ѵ�.
template <typename T>
int DoublyLinkedList<T>::GetLength() const{
	return m_nLength;
}

// �������� �Է¹޾� ����Ʈ�� �´� �ڸ��� ã�� �����Ѵ�.
template <typename T>
int DoublyLinkedList<T>::Additem(const T& item){
	DoublyIterator<T> itor(*this);
	itor.Next(); // �������� �̵�.

	if (IsEmpty()) // ó�� ������ ��
	{
		DoublyNodeType<T>* pItem = new DoublyNodeType<T>;
		pItem->data = item;
		m_pFirst->next = pItem;
		pItem->prev = m_pFirst;
		pItem->next = m_pLast;
		m_pLast->prev = pItem; // ó���� �� ���̿� ����.
		m_nLength++;
		return 1;
	}
	else // ó���� �ƴ� ��
	{
		while (1)
		{
			if (item < itor.m_pCurPointer->data || !itor.NextNotNull()) // �´� �ڸ��� ã�´�. //�����������ƴ���
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
void DoublyLinkedList<T>::Delete(T item){
	DoublyIterator<T> itor(*this);
	itor.Next();	//�������� �̵�.

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
void DoublyLinkedList<T>::Replace(T item){
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
int DoublyLinkedList<T>::Get(T & item){
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
