/*
 *	@brief	ItemType 클래스의 멤버 함수 헤더
 *	@date	2019.12.03
 *	@author	김민성
 */

#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

class ItemType
{
protected:
	int MusicNumber;  //음악순서
	string SongName;	//곡이름 
	string Singer;		//가수
	string Composer;	//작곡가
	string SongWriter; //작사가
	string genre;		//장르
	string Lyric;		//가사
	string InTime;		//play 시간
	int Playnum;		//play 횟수

public:
	ItemType();
	~ItemType();

	string GetSongName();	//노래제목
	string GetSinger();		//가수
	string GetComposer();	//작곡가
	string GetSongWriter();	//작사가
	string Getgenre();		//장르
	int GetMusicNumber(); //음악의 고유 ID
	string GetLyric();		//가사를 return
	string GetInTime();		//재생시간 return
	int GetPlaynum();		//play 횟수 return
	
	//Set 변수에 파리미터 값을 입력해줌
	void SetSongName(string inName);
	void SetSinger(string inSinger);
	void SetComposer(string inComposer);
	void SetSongWriter(string inSongWriter);
	void Setgenre(string ingenre);
	void SetMusicNumber(int inMN);
	void SetInTime(string inInTime);
	void SetLyric(string inLyric);
	void SetPlaynum(int inPlaynum);
	//전체 레코드 입력
	void SetRecord(int inMN, string inName, string inComposer, string inSongWriter, string inSinger, string ingenre, string inLyric, string inInTime, int inPlaynum);

		//변수 값을 출력해줌.

		void DisPlaySongNameOnScreen();
		void DisPlaySingerOnScreen();
		void DisPlayComposerOnScreen();
		void DisPlaySongWriterOnScreen();
		void DisPlaygenreOnScreen();
		void DisPlayLyricOnScreen();
		void DisPlayInTimeOnScreen();
		void DisPlayPlaynumOnScreen();
		void DisPlayMusicNumberOnScreen();

		void DisPlayRecordOnScreen();//전체출력

		//키보드로부터 입력받은 값 넣어줌.
		void SetSongNameFromKB();
		void SetSingerFromKB();
		void SetComposerFromKB();
		void SetSongWriterFromKB();
		void SetgenreFromKB();
		void SetMusicNumberFromKB();
		void SetInTimeFromKB();
		void SetLyricFromKB();
		void SetPlaynumFromKB();

		void SetRecordFromKB();

		int ReadDataFromFile(ifstream & fin);
		int WriteDataToFile(ofstream & fout);

		//연산자 오버로딩
		bool operator==(ItemType & data); //SongName 비교를 위한 연산자 오버로딩
		bool operator>=(ItemType & data);
		bool operator<=(ItemType & data);
		bool operator>(ItemType & data);
		bool operator<(ItemType & data);
	};