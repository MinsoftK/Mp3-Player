#pragma once


#include <iostream>
using namespace std;
template<typename T>
struct DoublyNodeType;

template<typename T>
class DoublyLinkedList;

/**
*	���Ḯ��Ʈ���� ���̴� Iterator�� Ŭ����.
*/
template <typename T>
class DoublyIterator
{
	friend class DoublyLinkedList<T>;
private:
	const DoublyLinkedList<T>& m_List;//��ũ�帮��Ʈ�� ����Ʈ
	DoublyNodeType<T>* m_pCurPointer;//���Ÿ���� ������
	
public:
	/**
	*	����Ʈ ������.
	*/
	DoublyIterator(const DoublyLinkedList<T>& list) : m_List(list), m_pCurPointer(list.m_pFirst)
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
