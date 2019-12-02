/*
 *	@brief	ItemType 클래스의 멤버 함수 헤더
 *	@date	2019.10.06
 *	@author	김민성
 */


#include "ItemType.h"

ItemType::ItemType() {

	SongName = "";
	Singer = "";
	Composer = "";
	genre = "";
	MusicNumber = "";  //음악의 고유 ID
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

string ItemType::GetMusicNumber() {
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


void ItemType::SetMusicNumber(string inMN) {
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

void ItemType::SetRecord(string inMN, string inName, string inComposer, string inSongWriter,string inSinger,string ingenre,string inLyric, string inInTime, int inPlaynum) {
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

//////출력
void ItemType::DisPlayMusicNumberOnScreen() {
	cout << "\t음악번호: " << MusicNumber << endl;
}


void ItemType::DisPlaySongNameOnScreen() {
	cout << "\t음악제목: " << SongName << endl;
}


void ItemType::DisPlayComposerOnScreen() {
	cout << "\t작곡가: " << Composer<< endl;
}


void ItemType::DisPlaySongWriterOnScreen() {
	cout << "\t작사가: " << SongWriter<< endl;
}


void ItemType::DisPlaySingerOnScreen() {
	cout << "\t가수: " << Singer << endl;
}

void ItemType::DisPlaygenreOnScreen() {
	cout << "\t장르 : " << genre << endl;
}

void ItemType::DisPlayLyricOnScreen(){
	cout << "\t가사: " << Lyric << endl; 
}

void ItemType::DisPlayInTimeOnScreen() {
	cout << "\t재생시간 : " << InTime<< endl;
}

void ItemType::DisPlayPlaynumOnScreen() {
	cout << "\t재생횟수 : " << Playnum<< endl;
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
	cout << "\t노래제목: ";
	cin >> SongName;
}

void ItemType::SetComposerFromKB() {
	cout << "\t작곡가: ";
	cin >> Composer;
}
void ItemType::SetSingerFromKB() {
	cout << "\t가수: ";
	cin >> Singer;
}
void ItemType::SetgenreFromKB() {
	cout << "\t장르: ";
	cin >> genre;

}
void ItemType::SetMusicNumberFromKB() {
	cout << "\t음악번호: ";
	cin >> MusicNumber;
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
//파일에서 불러오는 것
int ItemType::ReadDataFromFile(ifstream& fin) {
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

bool ItemType::operator==(ItemType& data) {//MusicNumber 비교를 위한 연산자 오버로딩
	if (data.GetMusicNumber() == MusicNumber) {
		return true;
	}
	else return false;

}

bool ItemType::operator>=(ItemType& data) {//genrer 비교를 위한 연산자 오버로딩
	if (data.GetMusicNumber() >= MusicNumber) {
		return true;
	}
	else return false;
}
bool ItemType::operator<=(ItemType& data) { //Singer 비교를 위한 연산자 오버로딩
	if (data.GetMusicNumber() <= MusicNumber) {
		return true;
	}
	else return false;
}

bool ItemType::operator>(ItemType& data) {//이름 순서를 위한 연산자 오버로딩
	if (data.GetMusicNumber() > MusicNumber) {
		return true;
	}
	else return false;
}
bool ItemType::operator<(ItemType& data) {//이름 순서를 위한 연산자 오버로딩
	if (data.GetMusicNumber() < MusicNumber) {
		return true;
	}
	else return false;
}
