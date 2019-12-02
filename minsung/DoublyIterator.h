#pragma once


#include <iostream>
using namespace std;
template<typename T>
struct DoublyNodeType;

template<typename T>
class DoublyLinkedList;

/**
*	연결리스트에서 쓰이는 Iterator의 클래스.
*/
template <typename T>
class DoublyIterator
{
	friend class DoublyLinkedList<T>;
private:
	const DoublyLinkedList<T>& m_List;//링크드리스트의 리스트
	DoublyNodeType<T>* m_pCurPointer;//노드타입의 포인터
	
public:
	/**
	*	디폴트 생성자.
	*/
	DoublyIterator(const DoublyLinkedList<T>& list) : m_List(list), m_pCurPointer(list.m_pFirst)
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

	
};

template <typename T>
bool DoublyIterator<T>::NotNull(){
	if (m_pCurPointer == NULL)
		return false;
	else
		return true;
}

template <typename T>
bool DoublyIterator<T>::NextNotNull(){
	if (m_pCurPointer->next == NULL)
		return false;
	else
		return true;
}




template <typename T>
T DoublyIterator<T>::First(){
	return m_List.m_pFirst->data;
}

template <typename T>
T DoublyIterator<T>::Prev(){
	m_pCurPointer = m_pCurPointer->prev;
	return m_pCurPointer->data;
}




template <typename T>
T DoublyIterator<T>::Next(){
	m_pCurPointer = m_pCurPointer->next;
	return m_pCurPointer->data;
}

template<typename T>
T DoublyIterator<T>::Getdata(){
	return m_pCurPointer->data;

}

template<typename T>
void DoublyIterator<T>::Reset(){
	m_pCurPointer = m_List.m_pLast;
}

template <typename T>
DoublyNodeType<T> DoublyIterator<T>::GetCurrentNode(){
	return *m_pCurPointer;
}
