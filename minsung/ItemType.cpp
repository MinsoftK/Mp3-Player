/*
 *	@brief	ItemType Ŭ������ ��� �Լ� ���
 *	@date	2019.10.06
 *	@author	��μ�
 */


#include "ItemType.h"

ItemType::ItemType() {

	SongName = "";//Primary Key
	Singer = "";
	Composer = "";
	genre = ""; 
	Lyric = "";
	MusicNumber = 0;  //������ ����
	InTime = "";
	Playnum = 0;

}
ItemType::~ItemType() {
}

string ItemType::GetSongName() {
	return SongName;
}

string ItemType::GetComposer() {
	return Composer;
}

string ItemType::GetSongWriter() {
	return SongWriter;
}

string ItemType::GetSinger() {
	return Singer;
}

string ItemType::Getgenre() {
	return genre;
}

int ItemType::GetMusicNumber() {
	return MusicNumber;
}

string ItemType::GetLyric() {
	return Lyric;
}


string ItemType::GetInTime() {
	return InTime;
}

int ItemType::GetPlaynum() {
	return Playnum;
}


void ItemType::SetMusicNumber(int inMN) {
	MusicNumber = inMN;
}

void ItemType::SetSongName(string inName) {
	SongName = inName;
}

void ItemType::SetSongWriter(string inSongWriter) {
	SongWriter = inSongWriter;
}

void ItemType::SetInTime(string inInTime) {
	InTime = inInTime;
}

void ItemType::SetComposer(string inComposer) {
	Composer = inComposer;
}

void ItemType::SetSinger(string inSinger) {
	Singer = inSinger;
}

void ItemType::Setgenre(string ingenre) {
	genre = ingenre;
}


void ItemType::SetLyric(string inLyric) {
	Lyric = inLyric;
}


void ItemType::SetInTime(string inInTime) {
	InTime = inInTime;
}

void ItemType::SetPlaynum(int inPlaynum) {
	Playnum = inPlaynum;
}

void ItemType::SetRecord(int inMN, string inName, string inComposer, string inSongWriter,string inSinger,string ingenre,string inLyric, string inInTime, int inPlaynum) {
	SetMusicNumber(inMN);
	SetSongName(inName);
	SetComposer(inComposer);
	SetSongWriter(inSongWriter);
	SetSinger(inSinger);
	Setgenre(ingenre);
	SetLyric(inLyric);
	SetInTime(inInTime);
	SetPlaynum(inPlaynum);
}

//////���
void ItemType::DisPlayMusicNumberOnScreen() {
	cout << "\t���ǹ�ȣ: " << MusicNumber << endl;
}


void ItemType::DisPlaySongNameOnScreen() {
	cout << "\t��������: " << SongName << endl;
}


void ItemType::DisPlayComposerOnScreen() {
	cout << "\t�۰: " << Composer<< endl;
}


void ItemType::DisPlaySongWriterOnScreen() {
	cout << "\t�ۻ簡: " << SongWriter<< endl;
}


void ItemType::DisPlaySingerOnScreen() {
	cout << "\t����: " << Singer << endl;
}

void ItemType::DisPlaygenreOnScreen() {
	cout << "\t�帣 : " << genre << endl;
}

void ItemType::DisPlayLyricOnScreen(){
	cout << "\t����: " << Lyric << endl; 
}

void ItemType::DisPlayInTimeOnScreen() {
	cout << "\t����ð� : " << InTime<< endl;
}

void ItemType::DisPlayPlaynumOnScreen() {
	cout << "\t���Ƚ�� : " << Playnum<< endl;
}

void ItemType::DisPlayRecordOnScreen() {
	
	DisPlaySongNameOnScreen();
	DisPlaySingerOnScreen();
	DisPlayComposerOnScreen();
	DisPlaySongWriterOnScreen();
	DisPlaygenreOnScreen();
	DisPlayLyricOnScreen();
	DisPlayInTimeOnScreen();
	DisPlayPlaynumOnScreen();
	DisPlayMusicNumberOnScreen();
}

void ItemType::SetSongNameFromKB() {
	cout << "\t�뷡����: ";
	cin >> SongName;
}

void ItemType::SetComposerFromKB() {
	cout << "\t�۰: ";
	cin >> Composer;
}
void ItemType::SetSongWriterFromKB() {
	cout << "\t�ۻ簡: ";
	cin >> SongWriter;
}
void ItemType::SetSingerFromKB() {
	cout << "\t����: ";
	cin >> Singer;
}
void ItemType::SetgenreFromKB() {
	cout << "\t�帣: ";
	cin >> genre;

}
void ItemType::SetMusicNumberFromKB() {
	cout << "\t���ǹ�ȣ: ";
	cin >> MusicNumber;
}
void ItemType::SetInTimeFromKB() {
	cout << "\t����ð�: ";
	cin >> InTime;
}

void ItemType::SetLyricFromKB() {
	cout << "\t����: ";
	cin >> Lyric;
}

void ItemType::SetPlaynumFromKB() {
	cout << "\t���Ƚ��: ";
	cin >> Playnum;
}

void ItemType::SetRecordFromKB() {
	SetSongNameFromKB();
	SetSingerFromKB();
	SetComposerFromKB();
	SetSongWriterFromKB();
	SetgenreFromKB();
	SetMusicNumberFromKB();
	SetInTimeFromKB();
	SetLyricFromKB();
	SetPlaynumFromKB();
}
//���Ͽ��� �ҷ����� ��
int ItemType::ReadDataFromFile(ifstream& fin){
	fin >> SongName;
	fin >> Singer;
	fin >> Composer;
	fin >> SongWriter;
	fin >> genre;
	fin >> MusicNumber;
	fin >> InTime;
	fin >> Lyric;
	fin >> Playnum;
	return 1;
}
int ItemType::WriteDataToFile(ofstream& fout) {

	fout << setw(2) << SongName;
	fout << setw(2) << Singer;
	fout << setw(2) << Composer;
	fout << setw(2) << genre;
	fout << setw(2) << MusicNumber;
	fout << setw(2) << InTime;
	fout << setw(2) << Lyric;
	fout << setw(2) << Playnum;
	return 1;
}

bool ItemType::operator==(ItemType& data) {//���� ���� �񱳸� ���� ������ �����ε�
	if (data.GetSongName() == SongName) {
		return true;
	}
	else return false;

}

bool ItemType::operator>=(ItemType& data) {//genrer �񱳸� ���� ������ �����ε�
	if (data.GetSongName() >= SongName) {
		return true;
	}
	else return false;
}
bool ItemType::operator<=(ItemType& data) { //Singer �񱳸� ���� ������ �����ε�
	if (data.GetSongName() <= SongName) {
		return true;
	}
	else return false;
}

bool ItemType::operator>(ItemType& data) {//�̸� ������ ���� ������ �����ε�
	if (data.GetSongName() > SongName) {
		return true;
	}
	else return false;
}
bool ItemType::operator<(ItemType& data) {//�̸� ������ ���� ������ �����ε�
	if (data.GetSongName() < SongName) {
		return true;
	}
	else return false;
}
