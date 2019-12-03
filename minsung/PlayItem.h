/*
 *	@brief	PlayItem 클래스의 멤버 함수 헤더
 *	@date	2019.10.06
 *	@author	김민성
 */


#pragma once
#include <string>
#include <iostream>

using namespace std;

// 곡 플레이에 관한 정보만 담는 클래스 (곡의 플레이 횟수, 곡의 순서 등)
class PlayItem {

private:
	string SongName; // Primary Key 는 공통으로 가지므로 Master 에서 얻어온다.
	string Singer;
	int Playnum ;	//재생횟수
	string InTime; // 재생시간

public:

	PlayItem() {
		SongName = "";	//노래제목
		Singer = "";	//가수
		Playnum = 0;	//재생횟수
		InTime = "";	//재생시간
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
