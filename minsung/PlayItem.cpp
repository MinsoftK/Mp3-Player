/*
 *	@brief	PlayItem Ŭ������ ��� �Լ� �����
 *	@date	2019.10.06
 *	@author	��μ�
 */


#include "PlayItem.h"


void PlayItem::SetMusicNumber(string MN) {
	MusicNumber = MN;
}
void PlayItem::SetPlaycount(int play) {
	Playcount = play;
}// ť�� ���� ���´�


void PlayItem::SetInTime(int Time) {
	InTime = Time;
}
string PlayItem::GetMusicNumber() {
	return MusicNumber;
}
int PlayItem::GetPlaycount() {
	return Playcount;
}
int PlayItem::GetInTime() {
	return InTime;
}

void PlayItem::SetMusicNumberFromKB() {
	cout << "\tMusic Number: ";
	cin >> MusicNumber;

}




void PlayItem::DisPlayMusicNumberOnScreen() {
	cout << "\tMusic Number: " << MusicNumber << endl;
}
void PlayItem::DisPlayPlayCountOnScreen() {
	cout << "\tPlay Count(����� Ƚ��): " << Playcount << endl;
}
void PlayItem::DisPlayInTimeOnScreen() {
	cout << "\tInTime (���¼���): " << InTime << endl;
}
void PlayItem::DisPlayRecordOnScreen() {
	DisPlayMusicNumberOnScreen();
	//DisPlayPlayCountOnScreen();
	DisPlayInTimeOnScreen();
}



bool PlayItem::operator ==(PlayItem& item) {
	if (item.GetMusicNumber() == MusicNumber) {
		return 1;
	}

	else return 0;
}

bool PlayItem::operator > (PlayItem& item) {
	if (item.GetMusicNumber() > MusicNumber)
		return 1;
	else
		return 0;
}
bool PlayItem::operator < (PlayItem& item) {
	if (item.GetMusicNumber() > MusicNumber)
		return 1;
	else
		return 0;
}
bool PlayItem::operator >= (PlayItem& item) {
	if (item.GetMusicNumber() > MusicNumber)
		return 1;
	else
		return 0;
}
bool PlayItem::operator <= (PlayItem& item) {
	if (item.GetMusicNumber() > MusicNumber)
		return 1;
	else
		return 0;
}
