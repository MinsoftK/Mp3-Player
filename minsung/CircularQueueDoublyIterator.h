#pragma once
#include "CircularQueueDoublyLinkedList.h"

template<typename T>
struct DoublyNodeType;
template<typename T>
class CircularQueueDoublyLinkedList;

/**
*	���Ḯ��Ʈ���� ���̴� Iterator�� Ŭ����.
*/
template <typename T>
class CircularQueueDoublyIterator
{

private:
	const CircularQueueDoublyLinkedList<T>& m_List;//��ũ�帮��Ʈ�� ����Ʈ
	DoublyNodeType<T>* m_pCurPointer;//���Ÿ���� ������
	
public:
	/**
	*	����Ʈ ������.
	*/
	CircularQueueDoublyIterator(const CircularQueueDoublyLinkedList<T>& list) : m_List(list), m_pCurPointer(list.m_pFirst)
	{}; ///< DoublySortedLinkedList�� ģ�� Ŭ����.


	bool NotNull();
	//m_curPointer �� NULL�̶�� fasle ��ȯ
	//�׿ܿ� True ��ȯ
	bool NextNotNull();//Next �� NULL�̶�� false ��ȯ
	
	T First();
	T Next();
	T Prev();
	
	T Getdata();
	void Reset();
	DoublyNodeType<T> GetCurrentNode();
	const DoublySortedLinkedList<T>& m_List;
	DoublyNodeType<T>* m_pCurPointer;
	friend class CircularQueueDoublyLinkedList<T>;
};

//
template <typename T>
bool CircularQueueDoublyIterator<T> ::NotNull()
{
	if (m_pCurPointer == NULL)
		return false;
	else
		return true;
}

template <typename T>
bool CircularQueueDoublyIterator<T> ::NextNotNull()
{
	if (m_pCurPointer->next == NULL)
		return false;
	else
		return true;
}




template <typename T>
T CircularQueueDoublyIterator<T> ::First()
{
	return m_List.m_pFirst->data;
}

template <typename T>
T CircularQueueDoublyIterator<T> ::Prev()
{
	m_pCurPointer = m_pCurPointer->prev;
	return m_pCurPointer->data;
}




template <typename T>
T CircularQueueDoublyIterator<T> ::Next()
{
	m_pCurPointer = m_pCurPointer->next;
	return m_pCurPointer->data;
}

template<typename T>
T CircularQueueDoublyIterator<T>::Getdata()
{
	return m_pCurPointer->data;

}

template<typename T>
void CircularQueueDoublyIterator<T>::Reset()
{
	m_pCurPointer = m_List.m_pLast;
}

template <typename T>
DoublyNodeType<T> CircularQueueDoublyIterator<T>::GetCurrentNode()
{
	return *m_pCurPointer;
}
