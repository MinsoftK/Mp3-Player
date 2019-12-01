/*
 *	@brief	���ø����̼� Ŭ������ ��� �Լ� �����
 *	@date	2019.10.06
 *	@author	��μ�
 */



#include "Application.h"
 //���� ���� ���
void Application::Run()
{
	while (1)
	{
		m_Command = GetCommand();

		switch (m_Command)
		{
		case 1:
			AddMusic();	// �� ������ �Է� �޾� ����Ʈ�� �߰�					AddMusic();
			break;
		case 2:
			DeleteMusic();
			// ���� ������ȣ�� �Է� �޾� ����Ʈ���� ����					DeleteMusic();
			break;
		case 3:
			RetrieveMusic();
			break;
			//RetrieveMusic();
			//������ �̸��̳� �帣�� �ش��ϴ� ��� ã��.				
		case 4:
			ReplaceMusic();// �� MusicNumber ������ �Է� �޾Ƽ� ����Ʈ���� �ش� �� ������ ����			ReplaceMusic();
			break;

		case 5:		// ����Ʈ�� ����� ��� ���� ȭ�鿡 ���
			DisPlayAllMusic();
			break;
		case 6:
			m_List.MakeEmpty();// ����Ʈ�� �Էµ� ��� ���� ����

			break;
		case 7:
			// load list data from a file.
			ReadDataFromFile();
			break;
		case 8:
			// save list data into a file.
			WriteDataToFile();
			break;
		case 9:
			AddToPlayList();
			break;

		case 10:
			PlayInsertOrder();//PlayList �� ��� �����ְ� ��� ASK
			break;

		case 11:
			DeletePlayList();
			break;

		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}


//���ο� ��ɾ� �޴� �κ� 
int Application::GetCommand() {
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Add Music" << endl;
	cout << "\t   2 : Delete Music" << endl;
	cout << "\t   3 : Retrieve Music" << endl;
	cout << "\t   4 : Replace Music list By Music Unique Number" << endl;
	cout << "\t   5 : Display All Music" << endl;
	cout << "\t   6 : Delete All Music list" << endl;
	cout << "\t   7 : load list data from a file" << endl;
	cout << "\t   8 : save list data into a file " << endl;
	cout << "\t   9 : Add Play List By ID " << endl;
	cout << "\t   10 :Display Play List And Play" << endl;
	cout << "\t   11 :Delete Play List" << endl;
	cout << "\t   0 : Quit" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;


	return command;
}

//���� ������ Sorted �ϰ� �Է�.
int Application::AddMusic() {

	ItemType item;
	item.SetRecordFromKB();
	m_List.Add(item);//Sorted ����
	DisPlayAllMusic();

	return 1;
}

//Sorted �� Delete �̿� Song Name ��
int Application::DeleteMusic() {
	int pre = m_List.GetLength();//���� item������ �޾ƿ´�.

	ItemType item;
	item.SetMusicNumberFromKB();
	m_List.Delete(item);

	if (pre > m_List.GetLength()) //���� item�������� ���� item������ �������� ���ż���
	{
		cout << "<========DELETE SUCCESS !===========>" << endl << endl;
		cout << "\t Current List" << endl;
		this->DisPlayAllMusic();
		return 1;
	}

	cout << "<========DELETE FAIL !=======>" << endl;
	return 0;
}

//�Է¹��� ������ �ش� ��� ��� ����ϱ�
int Application::RetrieveMusic() {
	int getN;
	string SingerName, genre;
	int MusicNumber;
	while (true) {
		cout << "\t\tPlease select which item you want to search for." << endl;
		cout << "\t\t1.Singer" << endl;
		cout << "\t\t2.Genre" << endl;
		//cout << "\t\t3.Music Number" << endl;  MusicNumbmer �ߺ�
		cout << "\t\t Choose one. (1~2) : ";
		cin >> getN;
		if (getN != 1 && getN != 2) { ///getN != 3 
			cout << "Wrong Input!" << endl;
			continue;
		}
		else break;
	}
	if (getN == 1) {//1:Singer�϶� ������ �����ε�
		cout << "Enter Singer Name what do you want to search: ";
		cin >> SingerName;
		ItemType item;
		item.SetSinger(SingerName);
		m_List.RetrieveBySinger(item);
		item.DisPlayRecordOnScreen();
		return 1;
	}
	else if (getN == 2) {//2:Genre�϶��� ������ �����ε�
		cout << "Enter genre what do you want to search: ";
		cin >> genre;
		ItemType item;
		item.Setgenre(genre);
		m_List.RetrieveBygenre(item);
		item.DisPlayRecordOnScreen();
		return 1;

	}
}

//Sorted �� replace �̿�
void Application::ReplaceMusic() {
	// ������ music ����
	/*cout << "=============== Enter the music with old informations ===============" << endl;
	ItemType item;
	item.SetMusicNumberFromKB();
	item.SetSongNameFromKB();
	item.SetSongMakerFromKB();
	item.SetSingerFromKB();
	item.SetgenreFromKB();


	// ������ music �߰�
	cout << "\n==============================" << endl;
	cout << "Enter the music with new informations " << endl;
	item.SetRecordFromKB();

	m_List.Add(item);
	this->DisPlayAllMusic();
	*/
	string repMusic;
	cout << "Please Enter the MusicNumber what you want to replace information : ";
	cin >> repMusic;
	ItemType data;
	data.SetRecordFromKB();

	m_List.ResetList();
	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);
	while (curIndex < length && curIndex != -1) {
		if (repMusic == data.GetMusicNumber()) {
			ItemType item;
			item.SetRecord(data.GetMusicNumber(), data.GetSongName(), data.GetSinger(), data.GetSongMaker(), data.Getgenre(), data.GetPlaynum(), data.GetInTime());
			m_List.Replace(item);
			break;
		}
		curIndex = m_List.GetNextItem(data);
	}
	DisPlayAllMusic();
}



//list�� ��� �����͸� ȭ�鿡 ���.
void Application::DisPlayAllMusic() {
	ItemType data;
	cout << "\t=========================" << endl;
	cout << "\n\tCurrent list" << endl;
	cout << "\t=========================" << endl;
	//�����͸���Ʈ ������ ����
	m_List.ResetList();
	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);
	for (int i = 0; i < length; i++) {
		m_List.GetNextItem(data);
		data.DisPlayRecordOnScreen();
		cout << "\t=========================" << endl;
	}
}

// Open a file by file descriptor as an input file.
int Application::OpenInFile(char* fileName) {
	m_InFile.open(fileName);
	if (!m_InFile) return 0;
	else return 1;
}

int Application::OpenOutFile(char* fileName) {
	m_OutFile.open(fileName);
	if (!m_OutFile) return 0;
	return 1;

}

int Application::ReadDataFromFile() {
	int index = 0;
	ItemType data;	// �б�� �ӽ� ����

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	// file open, open error�� �߻��ϸ� 0�� ����
	if (!OpenInFile(filename))
		return 0;

	// ������ ��� ������ �о� list�� �߰�
	while (!m_InFile.eof())
	{
		// array�� �л����� ������ ����ִ� structure ����
		data.ReadDataFromFile(m_InFile);
		m_List.Add(data);
	}

	m_InFile.close();	// file close

	// ���� list ���
	DisPlayAllMusic();

}

int Application::WriteDataToFile() {
	ItemType item;
	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name: ";
	cin >> filename;

	if (!OpenOutFile(filename))
		return 0;

	m_List.ResetList();
	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(item);
	while (curIndex < length && curIndex != -1)
	{
		item.WriteDataToFile(m_OutFile);
		curIndex = m_List.GetNextItem(item);
	}

	m_OutFile.close();	// file close

	return 1;
}





//Play List ��� Queue �̿�.
int Application::AddToPlayList() {
	//���� ������� ǥ��
	PlayItem play;
	ItemType item;
	play.SetMusicNumberFromKB();
	item.SetMusicNumber(play.GetMusicNumber());
	m_List.RetrieveByMusicNumber(item);

	play.SetRecord(item.GetMusicNumber(), item.GetPlaynum(), ++Order);

	if (!(m_PlayList.IsFull())) {
		//List�� Full�� �ƴҰ��

		if (m_List.RetrieveByMusicNumber(item)) {//Id�� Master�� �����Ҷ� return 1
			//item�� master ���� ����.

			m_PlayList.EnQueue(play);
			cout << endl << "\t=================================" << endl;
			cout << "\tAdd Music Number: " << play.GetMusicNumber() << " is in PlayList!" << endl;
			cout << "\t=================================" << endl;
			return 0;
		}
		else {

			cout << endl << "\t=================================" << endl;
			cout << "This Music Number is not exist in Master List!!" << endl;
			cout << "\t=================================" << endl;
			return 0;

		}
	}
	else { //List�� Full�ϰ��
		PlayItem check;
		m_PlayList.DeQueue(check);//check�� ������ ���� ����

		m_PlayList.EnQueue(play);

		cout << endl << "\t=================================" << endl;
		cout << "\tDeleted Music Number is: " << check.GetMusicNumber() << endl;
		cout << "\t=================================" << endl;

		cout << endl << "\t=================================" << endl;
		cout << "\tAdd Music Number: " << play.GetMusicNumber() << " is in PlayList!" << endl;
		cout << "\t=================================" << endl;
		return 0;
	}
}

void Application::PlayInsertOrder() {
	PlayItem play;
	ItemType item;
	int count = 0;
	while (1) {
		cout << "\tCurrent Play List : " << endl;
		m_PlayList.Print();
		cout << endl;
		string num;
		cout << endl;
		cout << "\t==============================================" << endl;
		cout << "\t Choose Music Number Do you want to play." << endl;
		cout << "\tif Press 0 is Exit PlayList." << endl;
		cout << "\t==============================================" << endl;
		cout << "\tNumber :";
		cin >> num;
		cout << endl << endl;
		if (num == "0")
			break;
		play.SetMusicNumber(num);//PlayItem ��ü�� MN ����
		item.SetMusicNumber(num);//masterList�� ���� key �Է�
		m_List.RetrieveByMusicNumber(item);
		item.SetPlaynum(++count);
		play.SetRecord(item.GetMusicNumber(), item.GetPlaynum(), item.GetInTime());
		//item���� MusicNumber ��ġ�ϴ� 
		//maseter ���� �ԷµǾ�����
		//�Է¹��� num�� Playcount++ ���ش�.
		cout << "\t==============================================" << endl;
		cout << "\t Choosen Music Information is:" << endl;
		//masterList�� ���� �Է�.
		item.DisPlayRecordOnScreen();//Master �������
		cout << "\t==============================================" << endl;
	}
}

void Application::DeletePlayList() {
	//�÷��̸���Ʈ�� ���� ����
	PlayItem play;//item ��ü�� MN ����
	ItemType item; //master List�� �񱳸� ���� ��ü ����
	play.SetMusicNumberFromKB();
	item.SetMusicNumber(play.GetMusicNumber());
	m_List.RetrieveByMusicNumber(item);

	if (!(m_PlayList.IsEmpty())) {
		//List�� empty�� �ƴҰ��
		m_PlayList.DeQueue(play);
		cout << endl << "\t=================================" << endl;
		cout << "\tDeleted Music Number is: " << endl;
		item.DisPlayRecordOnScreen();
		cout << "\t=================================" << endl;

	}
	else {

		cout << endl << "\t=================================" << endl;
		cout << "This Music Number is not exist in Master List!!" << endl;
		cout << "\t=================================" << endl;


	}
}
