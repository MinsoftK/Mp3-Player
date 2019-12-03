/*
 *	@brief	ItemType Ŭ������ ��� �Լ� ���
 *	@date	2019.12.03
 *	@author	��μ�
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
	int MusicNumber;  //���Ǽ���
	string SongName;	//���̸� 
	string Singer;		//����
	string Composer;	//�۰
	string SongWriter; //�ۻ簡
	string genre;		//�帣
	string Lyric;		//����
	string InTime;		//play �ð�
	int Playnum;		//play Ƚ��

public:
	ItemType();
	~ItemType();

	string GetSongName();	//�뷡����
	string GetSinger();		//����
	string GetComposer();	//�۰
	string GetSongWriter();	//�ۻ簡
	string Getgenre();		//�帣
	int GetMusicNumber(); //������ ���� ID
	string GetLyric();		//���縦 return
	string GetInTime();		//����ð� return
	int GetPlaynum();		//play Ƚ�� return
	
	//Set ������ �ĸ����� ���� �Է�����
	void SetSongName(string inName);
	void SetSinger(string inSinger);
	void SetComposer(string inComposer);
	void SetSongWriter(string inSongWriter);
	void Setgenre(string ingenre);
	void SetMusicNumber(int inMN);
	void SetInTime(string inInTime);
	void SetLyric(string inLyric);
	void SetPlaynum(int inPlaynum);
	//��ü ���ڵ� �Է�
	void SetRecord(int inMN, string inName, string inComposer, string inSongWriter, string inSinger, string ingenre, string inLyric, string inInTime, int inPlaynum);

		//���� ���� �������.

		void DisPlaySongNameOnScreen();
		void DisPlaySingerOnScreen();
		void DisPlayComposerOnScreen();
		void DisPlaySongWriterOnScreen();
		void DisPlaygenreOnScreen();
		void DisPlayLyricOnScreen();
		void DisPlayInTimeOnScreen();
		void DisPlayPlaynumOnScreen();
		void DisPlayMusicNumberOnScreen();

		void DisPlayRecordOnScreen();//��ü���

		//Ű����κ��� �Է¹��� �� �־���.
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

		//������ �����ε�
		bool operator==(ItemType & data); //SongName �񱳸� ���� ������ �����ε�
		bool operator>=(ItemType & data);
		bool operator<=(ItemType & data);
		bool operator>(ItemType & data);
		bool operator<(ItemType & data);
	};