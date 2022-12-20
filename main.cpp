#include "Header.h"

using namespace std;
int main() {

	system("mode con cols=126 lines=59");

	const int SIZE = 500;
	Group* Artist = new Group[SIZE];			// �������� ��������
	int count = 0;				// ������� ��������
	int choice;
	int hash = 0;
	string hname;
	string filename;

	getMenu();	// ������� ������ ����

	cout << "Enter the command:" << endl;
	cin >> choice;
	system("cls");

	while (choice != 0) {
		switch (choice) {
		case 1: // �������� �������
			system("cls");
			Artist = addArtist(Artist, SIZE, &hash, &count);
			break;
		case 2:	//������� ������� (������, ������, ����)
			system("cls");
			Artist = delData(Artist, SIZE, &count);
			break;
		case 3: //����� ��������
			getArtists(Artist, SIZE);
			system("pause");
			break;
		case 4: //�������� ������
			system("cls");
			addAlbum(Artist, SIZE);
			break;
		case 5: //�������� ����
			getArtists(Artist, SIZE);
			addTrack(Artist, SIZE);
			break;
		case 6: //������� �������
			getArtists(Artist, SIZE);
			hash = hashCalc(Artist, SIZE);
			getAlbums(Artist, SIZE, hash);
			system("pause");
			break;
		case 7: //������ �����
			system("cls");
			getArtists(Artist, SIZE);
			hash = hashCalc(Artist, SIZE);
			getAlbums(Artist, SIZE, hash);
			getTracks(Artist, SIZE, hash);
			system("pause");
			break;
		case 8: //����� (�������, �������, �����)
			findData(Artist, SIZE);
			break;
		case 9:
			system("cls");
			if (count != 0) {
				cout << "Enter file name: " << endl;
				cin.get();
				getline(cin, filename);
				SavingData(Artist, SIZE, count, filename);
			}
			else
				cout << "Database is empty" << endl;
			system("pause");
			break;
		case 10:
			cout << "Enter file name: " << endl;
			cin.get();
			getline(cin, filename);
			ReadingData(Artist, SIZE, count, filename);
			cout << "\nReading completed successfully\n";
			system("pause");
			break;
		case 11:
			getGenre(Artist, SIZE);
			system("pause");
			break;
		default: // ���� ����������� �������
			cout << "Unknown command!" << endl;
			break;
		}

		if (cin.fail()) { //��� �� ������ ��� �����
			cin.clear();
			cin.ignore(32767, '\n');
			system("cls");
			getMenu();
			cout << "Enter the command: " << endl;
			cin >> choice;
		}
		else {
			system("cls");
			getMenu();
			cout << "Enter the command: " << endl;
			cin >> choice;
		}
	}
	if (choice == 0) {//����� �� ���������
		cout << "Thanks for using our program!" << endl;
	}
	return 0;
}