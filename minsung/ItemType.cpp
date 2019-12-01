/*
 *	@brief	ItemType Ŭ������ ��� �Լ� ���
 *	@date	2019.10.06
 *	@author	��μ�
 */


#include "ItemType.h"

ItemType::ItemType() {

	SongName = "";
	Singer = "";
	SongMaker = "";
	genre = "";
	MusicNumber = "";  //������ ���� ID
	InTime = 0;
	Playnum = 0;

}
ItemType::~ItemType() {
}


string ItemType::GetSongName() {
	return SongName;
}
string ItemType::GetSongMaker() {
	return SongMaker;
}
string ItemType::GetSinger() {
	return Singer;
}
string ItemType::Getgenre() {
	return genre;
}
string ItemType::GetMusicNumber() {
	return MusicNumber;
}
int ItemType::GetPlaynum() {
	return Playnum;
}
int ItemType::GetInTime() {
	return InTime;
}
void ItemType::SetSongName(string inName) {
	SongName = inName;
}

void ItemType::SetSongMaker(string inMaker) {
	SongMaker = inMaker;
}
void ItemType::SetSinger(string inSinger) {
	Singer = inSinger;
}
void ItemType::Setgenre(string ingenre) {
	genre = ingenre;
}
void ItemType::SetMusicNumber(string inMN) {
	MusicNumber = inMN;
}
void ItemType::SetPlaynum(int inPlaynum) {
	Playnum = inPlaynum;
}

void ItemType::SetInTime(int inInTime) {
	InTime = inInTime;
}



void ItemType::SetRecord(string inMN, string inName, string inMaker, string inSinger, string ingenre, int inPlaynum, int inInTime) {
	SetMusicNumber(inMN);
	SetSongName(inName);
	SetSongMaker(inMaker);
	SetSinger(inSinger);
	Setgenre(ingenre);
	SetPlaynum(inPlaynum);
	SetInTime(inInTime);
}

void ItemType::DisPlaySongNameOnScreen() {
	cout << "\tSongName: " << SongName << endl;
}

void ItemType::DisPlaySongMakerOnScreen() {
	cout << "\tSong Maker: " << SongMaker << endl;
}
void ItemType::DisPlaySingerOnScreen() {
	cout << "\tSinger: " << Singer << endl;
}
void ItemType::DisPlaygenreOnScreen() {
	cout << "\tGenre : " << genre << endl;
}
void ItemType::DisPlayMusicNumberOnScreen() {
	cout << "\tMusicNumber: " << MusicNumber << endl;
}

void ItemType::DisPlayPlaynumOnScreen() {
	cout << "\tPlaynum(���Ƚ��): " << Playnum << endl;
}
void ItemType::DisPlayInTimeOnScreen() {
	cout << "\t��ϵ� ����: " << InTime << endl;
}

void ItemType::DisPlayRecordOnScreen() {

	DisPlaySongNameOnScreen();
	DisPlaySongMakerOnScreen();
	DisPlaySingerOnScreen();
	DisPlaygenreOnScreen();
	DisPlayMusicNumberOnScreen();
	DisPlayPlaynumOnScreen();
	DisPlayInTimeOnScreen();
}

void ItemType::SetSongNameFromKB() {
	cout << "\tSong Name: ";

	cin >> SongName;

}

void ItemType::SetSongMakerFromKB() {
	cout << "\tSongMaker: ";
	cin >> SongMaker;
}
void ItemType::SetSingerFromKB() {
	cout << "\tSinger: ";
	cin >> Singer;
}
void ItemType::SetgenreFromKB() {
	cout << "\tGenre : ";
	cin >> genre;

}
void ItemType::SetMusicNumberFromKB() {
	cout << "\tMusic Number: ";
	cin >> MusicNumber;
}


void ItemType::SetRecordFromKB() {
	SetMusicNumberFromKB();
	SetSongNameFromKB();
	SetSingerFromKB();
	SetSongMakerFromKB();
	SetgenreFromKB();

}
//���Ͽ��� �ҷ����� ��
int ItemType::ReadDataFromFile(ifstream& fin) {

	fin >> SongName;
	fin >> Singer;
	fin >> SongMaker;
	fin >> genre;
	fin >> MusicNumber;

	return 1;
}
int ItemType::WriteDataToFile(ofstream& fout) {

	fout << setw(2) << SongName;
	fout << setw(2) << Singer;
	fout << setw(2) << SongMaker;
	fout << setw(2) << genre;
	fout << setw(2) << MusicNumber;

	return 1;
}


bool ItemType::operator==(ItemType& data) {//MusicNumber �񱳸� ���� ������ �����ε�
	if (data.GetMusicNumber() == MusicNumber) {
		//DisplayRecordOnScreen();
		return true;
	}
	else return false;

}

bool ItemType::operator+=(ItemType& data) {//genrer �񱳸� ���� ������ �����ε�
	if (data.Getgenre() == genre) {
		//DisplayRecordOnScreen();
		return true;
	}
	else return false;
}
bool ItemType::operator-=(ItemType& data) { //Singer �񱳸� ���� ������ �����ε�
	if (data.GetSinger() == Singer) {
		//DisplayRecordOnScreen();
		return true;
	}
	else return false;
}

bool ItemType::operator>(ItemType& data) {//�̸� ������ ���� ������ �����ε�
	if (data.GetMusicNumber() > MusicNumber) {
		return true;
	}
	else return false;
}
bool ItemType::operator<(ItemType& data) {//�̸� ������ ���� ������ �����ε�
	if (data.GetMusicNumber() < MusicNumber) {
		return true;
	}
	else return false;
}


/*
RelationType CompareByID(const ItemType& data) {

}
*/
