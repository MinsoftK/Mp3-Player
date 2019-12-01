#pragma once
#include "CircularQueueDoublyLinkedList.h"

template<typename T>
struct DoublyNodeType;
template<typename T>
class CircularQueueDoublyLinkedList;

/**
*	연결리스트에서 쓰이는 Iterator의 클래스.
*/
template <typename T>
class CircularQueueDoublyIterator
{

private:
	const CircularQueueDoublyLinkedList<T>& m_List;//링크드리스트의 리스트
	DoublyNodeType<T>* m_pCurPointer;//노드타입의 포인터
	
public:
	/**
	*	디폴트 생성자.
	*/
	CircularQueueDoublyIterator(const CircularQueueDoublyLinkedList<T>& list) : m_List(list), m_pCurPointer(list.m_pFirst)
	{}; ///< DoublySortedLinkedList와 친구 클래스.


	bool NotNull();
	//m_curPointer 가 NULL이라면 fasle 반환
	//그외에 True 반환
	bool NextNotNull();//Next 가 NULL이라면 false 반환
	
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
