/*
 *	@brief	SOrtedList Ŭ������ ��� �Լ� ���
 *	@date	2019.10.06
 *	@author	��μ�
 */



#pragma once
#include <iostream>
#include <fstream>
#include <string>

#define MAXSIZE 100

using namespace std;

template<class T>
class SortedList
{
private:
	T* m_Array;
	int m_ArraySize;
	int m_Length;
	int m_CurPointer;

public:
	SortedList() {
		m_Array = new T[MAXSIZE];
		m_Length = 0;
		m_ArraySize = 0;
		m_CurPointer = 0;
		ResetList();
	}
	SortedList(int size);
	~SortedList() {
		delete[] m_Array;
	}
	void MakeEmpty();
	int GetLength();
	bool IsFull();
	int Add(T data);
	int Retrieve_SeqS(T& target);
	int Delete(T& target);
	int GetNextItem(T& data);
	void ResetList();
	bool IsEmpty();
	//������ ���� �Է��ϴ� �Լ�, m_Array �� �������� �Է�
	int Replace(T data);
	//Singer Name�� ��ġ�ϴ� ���� ã�Ƽ� ��� ������ return ���ش�. -> Application RetrieveMusic�� ����.
	int RetrieveBySinger(T& target);//������ �˻�
	int RetrieveBygenre(T& target);//genre ���� �˻���� ã�� �Լ�
	int RetrieveByMusicNumber(T& target);//MusicNumber�� ��
	////Binary Search
	int RetrieveByBS(T& target);

};
//cpp


template<typename T>
SortedList<T>::SortedList(int size) {
	m_Array = new T[size];
	m_Length = 0;
	m_ArraySize = 0;
	m_CurPointer = 0;
	ResetList();
}

template<typename T>
void SortedList<T>::MakeEmpty() {
	m_Length = 0;
}
template<typename T>
int SortedList<T>::GetLength() {
	return m_Length;
}
template<typename T>
bool SortedList<T>::IsFull() {
	if (m_Length > MAXSIZE - 1)
		return true;
	else return false;
}
//data

//Sorted List Add
template<typename T>
int SortedList<T>::Add(T data) {
	int index = GetLength() - 1;
	if (m_Length == 0) { //����ִٸ�
		m_Array[m_Length] = data;
		m_Length++;
	}
	//list�� ��� ó������ �Է�
	   //list�� ��ġ�� �ľ��ϰ� �� ��ġ�� �Է�
	else {

		for (int i = 0; i <= index; i++) {
			if (data == m_Array[i]) {
				cout << endl << "ERROR: Same list exist. " << endl;
				return 0;
			}

			else if (data < m_Array[i]) {
				for (int k = index; k >= i; k--) {
					m_Array[k + 1] = m_Array[k];
				}
				m_Array[i] = data;
				m_Length++;
				return 1;
			}
			else if (data > m_Array[index]) {
				m_Array[index + 1] = data;
				m_Length++;
				return 1;
			}

		}
	}

	return 1;
}

//Music Number�� ��ġ�Ѵٸ� 1�� ��ȯ�Ѵ�.


template<typename T>
int SortedList<T>::Retrieve_SeqS(T & target) {

	int index = m_Length - 1;
	ResetList();
	for (int i = 0; i <= index; i++) {
		m_CurPointer++;
		if (target == m_Array[i]) {
			target = m_Array[i];
			return 1;
		}

	}
	return 0;
	;//ID ��ġ�� ���ϸ� 0�� ��ȯ
}



//Retrieve_SeqS �� ��ȯ�ϴ� 1 �� �̿� �ؼ� ���� ����
template<typename T>
int SortedList<T>::Delete(T & target)
{
	if (Retrieve_SeqS(target))//Retrieve_SeqS(target)	//Primary key�� ��ġ�ϴ� item�� �߰��Ѵٸ�(1)
	{

		for (int i = m_CurPointer; i < m_Length; i++)	//���� �����ͺ��� �Էµ� �迭 ������ �ݺ�
			m_Array[i] = m_Array[i + 1];	//�迭 �ڿ��� ������ �ϳ��� ����
		m_Length--;	//������ ������ �ϳ� ����
		return 1;	//����(1)�� ����
	}
	else {
		cout << endl << "There is no match item." << endl << endl;
		return 0;	//Primary key��ġ�ϴ� item�� ã�� ���Ѵٸ� ����(0)�� ����
	}
}
/* ����
int SortedList::Delete(ItemType data) {
	while (m_CurPointer < MAXSIZE - 1) {
		data = m_Array[m_CurPointer + 1];
		m_Array[m_CurPointer] = data;
		m_CurPointer++;
	}
	m_Length--;
	cout << "record is deleted. " << endl;
	return 0;
}
*/


//���� ��ġ ��ȯ �Լ�
template<typename T>
int SortedList<T>::GetNextItem(T & data) {
	m_CurPointer++;
	if (m_CurPointer == MAXSIZE) {
		return -1;
	}
	data = m_Array[m_CurPointer];

	return m_CurPointer;
}

template<typename T>
void SortedList<T>::ResetList() {
	m_CurPointer = -1;
}

template<typename T>
bool SortedList<T>::IsEmpty() {
	if (m_Length == 0) {
		cout << "List is empty." << endl;
		return true;
	}
	else {
		cout << "List is remain. " << endl;
		return false;
	}
}




//������ ���� �Է��ϴ� �Լ�, m_Array �� �������� �Է�
template<typename T>
int SortedList<T>::Replace(T data) {

	m_Array[m_CurPointer] = data;
	return 0;

}


//Singer Name�� ��ġ�ϴ� ���� ã�Ƽ� ��� ������ return ���ش�. -> Application RetrieveMusic�� ����.
template<typename T>
int SortedList<T>::RetrieveBySinger(T & target) {

	int index = m_Length - 1;
	if (m_Length == 0) {//list�� ����ٸ�
		cout << "There is no List" << endl;
		return 0;
	}
	else {//List �� �����Ѵٸ�.

		for (int i = 0; i <= index; i++) {
			if (target -= m_Array[i]) {//Singer Name ������� taeget�� ����!
				target = m_Array[i];
				return 1;
			}
		}
		return 0;
	}
}


template<typename T>
int SortedList<T>::RetrieveBygenre(T & target) {//genre ���� �˻���� ã�� �Լ�

	int index = m_Length - 1;
	if (m_Length == 0) {//list�� ����ٸ�
		cout << "There is no List" << endl;
		return 0;
	}
	else {//List �� �����Ѵٸ�.

		for (int i = 0; i <= index; i++) {
			if (target += m_Array[i]) {//Name ������� target�� ���� ����!
				target = m_Array[i];
				return 1;
			}
		}
		return 0;
	}
}

template<typename T>
int SortedList<T>::RetrieveByMusicNumber(T & target) {//Music Number���� �˻���� ã�� �Լ�: PrimaryKey
	int index = m_Length - 1;
	if (m_Length == 0) {//
		cout << "=============================" << endl;
		cout << "There is no List" << endl;
		cout << "=============================" << endl;
		return 0;
	}
	else {

		for (int i = 0; i <= index; i++) {
			if (target == m_Array[i]) {
				target = m_Array[i];
				return 1;
			}
		}
	}
}






/*  @@@@@@@@@@@@ ���߿� Singer �� genre �� search �ϴ� �˰���.
int RetrieveBySinger(ItemType& target) {

	for (int i = 0; i <= index; i++) {
		if (target == m_Array[i]) {// ������� ���!
			m_Array[i].DisplayRecordOnScreen();
			return 0;
		}
		if (index == 9 || target < m_Array[i])//index �� 9�̰ų� m_Array ID�� �� ũ�ٸ�
			return 0;
	}
	return 0;
}


}
int RetrieveBygenre(ItemType& target){


}

*/

////Binary Search
template<typename T>
int SortedList<T>::RetrieveByBS(T & target) {
	//�����ڵ� �˻� ���
	int index = m_Length - 1;// �Էµ� ����Ʈ������ �°� index �� ����
	int mid = 5;//�߰� index
	int point = 1;//index �缳���� ���� ����
	while (true) {
		point = index / 2;
		if (target < m_Array[point]) {//Array�� Name�� �� ũ�ٸ�
			point = point / 2;
			continue;
		}
		else if (target > m_Array[point]) { //target�� Name�� �� ũ�ٸ�
			index = index + point;  //index�� point�� �̿��� ������ �°� Search ����
			continue;
		}
		else if (target == m_Array[point]) { //Name ���� ���� ��� ����� break;
			m_Array[point].DisplayRecordOnScreen();
			break;
		}

	}
	return 0;
}