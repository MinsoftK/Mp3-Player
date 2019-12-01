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
		void insert_end();		//�������� ���� �߰�
		void insert_pos();		//���ϴ� �����Ͽ� �߰�
		void delete_pos();		//���ϴ� ��ġ�� �� ����
		void search();			//primary key�� ���� �˻�
		void update();			//����
		void display();			//�����÷��̾��� ���
		void reverse();			//����Ʈ �Ųٷ� �����
	
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
	if (m_nLength == 100) //100���̸� FULL
		return true;
	else return false;

}

template <typename T>
bool CircularQueueDoublyLinkedList<T> ::CheckEnd()
{
	if (m_pFirst->next->next==m_pLast)
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

}

template <typename T>
int CircularQueueDoublyLinkedList<T>::GetLength() const {
	return m_nLength;
}

template <typename T>
void CircularQueueDoublyLinkedList<T>::Additem(T& item) {
	CircularQueueDoublyIterator itor(*this);
	itor.Next();
	if (m_pFirst ->next== m_pLast && m_pFirst == NULL) {

	}

		m_nLength++;
}

template <typename T>
void CircularQueueDoublyLinkedList<T>::insert_end() {
	int v;
	cout << endl << "Enter the element to be inserted: ";
	cin >> v;
	struct nod* t;
	t = create_node(v);
	if (start == last && start == NULL) {
		cout << "Element inserted in empty list" << endl;
		start = last = t;
		start->n = last->n = NULL;
		start->p = last->p = NULL;
	}
	else {
		last->n = t;
		t->p = last;
		last = t;
		start->p = last;
		last->n = start;
	}
}

template <typename T>
void CircularQueueDoublyLinkedList<T>::insert_pos() {
	int v, pos, i;
	cout << endl << "Enter the element to be inserted: ";
	cin >> v;
	cout << endl << "Enter the position of element inserted: ";
	cin >> pos;
	struct nod* t, * s, * ptr;
	t = create_node(v);
	if (start == last && start == NULL) {
		if (pos == 1) {
			start = last = t;
			start->n = last->n = NULL;
			start->p = last->p = NULL;
		}
		else {
			cout << "Position out of range" << endl;
			count--;
			return;
		}
	}
	else {
		if (count < pos) {
			cout << "Position out of range" << endl;
			count--;
			return;
		}
		s = start;
		for (i = 1; i <= count; i++) {
			ptr = s;
			s = s->n;
			if (i == pos - 1) {
				ptr->n = t;
				t->p = ptr;
				t->n = s;
				s->p = t;
				cout << "Element inserted" << endl;
				break;
			}
		}
	}
}

template <typename T>
void CircularQueueDoublyLinkedList<T>::delete_pos() {
	int pos, i;
	nod* ptr, * s;
	if (start == last && start == NULL) {
		cout << "List is empty, nothing to delete" << endl;
		return;
	}
	cout << endl << "Enter the position of element to be deleted: ";
	cin >> pos;
	if (count < pos) {
		cout << "Position out of range" << endl;
		return;
	}
	s = start;
	if (pos == 1) {
		count--;
		last->n = s->n;
		s->n->p = last;
		start = s->n;
		free(s);
		cout << "Element Deleted" << endl;
		return;
	}
	for (i = 0; i < pos - 1; i++) {
		s = s->n;
		ptr = s->p;
	}
	ptr->n = s->n;
	s->n->p = ptr;
	if (pos == count) {
		last = ptr;
	}
	count--;
	free(s);
	cout << "Element Deleted" << endl;
}

template <typename T>
void CircularQueueDoublyLinkedList<T>::update() {
	int v, i, pos;
	if (start == last && start == NULL) {
		cout << "The List is empty, nothing to update" << endl;
		return;
	}
	cout << endl << "Enter the position of node to be updated: ";
	cin >> pos;
	cout << "Enter the new value: ";
	cin >> v;
	struct nod* s;
	if (count < pos) {
		cout << "Position out of range" << endl;
		return;
	}
	s = start;
	if (pos == 1) {
		s->info = v;
		cout << "Node Updated" << endl;
		return;
	}
	for (i = 0; i < pos - 1; i++) {
		s = s->n;
	}
	s->info = v;
	cout << "Node Updated" << endl;
}

template <typename T>
void CircularQueueDoublyLinkedList<T>::search() {
	int pos = 0, v, i;
	bool flag = false;
	struct nod* s;
	if (start == last && start == NULL) {
		cout << "The List is empty, nothing to search" << endl;
		return;
	}
	cout << endl << "Enter the value to be searched: ";
	cin >> v;
	s = start;
	for (i = 0; i < count; i++) {
		pos++;
		if (s->info == v) {
			cout << "Element " << v << " found at position: " << pos << endl;
			flag = true;
		}
		s = s->n;
	}
	if (!flag)
		cout << "Element not found in the list" << endl;
}

template <typename T>
void CircularQueueDoublyLinkedList<T>::display() {
	int i;
	struct nod* s;
	if (start == last && start == NULL) {
		cout << "The List is empty, nothing to display" << endl;
		return;
	}
	s = start;
	for (i = 0; i < count - 1; i++) {
		cout << s->info << "<->";
		s = s->n;
	}
	cout << s->info << endl;
}

template <typename T>
void CircularQueueDoublyLinkedList<T>::reverse() {
	if (start == last && start == NULL) {
		cout << "The List is empty, nothing to reverse" << endl;
		return;
	}
	struct nod* p1, * p2;
	p1 = start;
	p2 = p1->n;
	p1->n = NULL;
	p1->p = p2;
	while (p2 != start) {
		p2->p = p2->n;
		p2->n = p1;
		p1 = p2;
		p2 = p2->p;
	}
	last = start;
	start = p1;
	cout << "List Reversed" << endl;
}

