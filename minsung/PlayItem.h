/*
 *	@brief	PlayItem Ŭ������ ��� �Լ� ���
 *	@date	2019.10.06
 *	@author	��μ�
 */


#pragma once
#include <string>
#include <iostream>

using namespace std;

// �� �÷��̿� ���� ������ ��� Ŭ���� (���� �÷��� Ƚ��, ���� ���� ��)
class PlayItem {

private:
	string SongName; // Primary Key �� �������� �����Ƿ� Master ���� ���´�.
	string Singer;
	int Playnum ;	//���Ƚ��
	string InTime; // ����ð�

public:

	PlayItem() {
		SongName = "";	//�뷡����
		Singer = "";	//����
		Playnum = 0;	//���Ƚ��
		InTime = "";	//����ð�
	}
	~PlayItem() {}

	string GetSongName();
	string GetSinger();
	string GetInTime();
	int GetPlaycount();
	
	void SetSongName(string inName);
	void SetSinger(string inSinger);
	void SetPlaynum(int inPlaynum);
	void SetInTime(string inInTime);

	void SetRecord(string inName, string inSinger, int inPlaynum, string inInTime) {
		SongName = inName;
		Singer = inSinger;
		Playnum = inPlaynum;
		InTime = inInTime;
	}

	void SetMusicNumberFromKB();


	void DisPlayMusicNumberOnScreen();
	void DisPlayPlayCountOnScreen();
	void DisPlayInTimeOnScreen();
	void DisPlayRecordOnScreen();


	bool operator ==(PlayItem& item);
	bool operator > (PlayItem& item);
	bool operator < (PlayItem& item);
	bool operator >= (PlayItem& item);
	bool operator <= (PlayItem& item);
};
