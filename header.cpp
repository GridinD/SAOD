#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Track
{
    string name = ""; // ��� �����
};

struct Album
{
    string name = "";     // ��� �������
    string genre = "";    // ���� �������
    int date;
    Track track_list[64]; // ����� � �������
    int TrackCounter = 0; // ���������� ������
};

struct Group
{
    string name = "";     // ��� �������
    Album diskograph[64]; // ������� �������
    int key;              // ��� ����
    int AlbumCounter = 0; // ���������� ��������
    string genre = "";    // ���� �������
};

// ��������!
int randDam(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
int hash_summ(int a, int b, int memory)
{
    int t = a + b;
    return t % memory;
}
int rehashfunction(int t, int memory)
{
    int u = randDam(1, memory / 2);
    int f = t + u;
    return f % memory;
}
int hashfunction(Group* Obj, char a, char b, int memory)
{
    int g = hash_summ((int)a, (int)b, memory);
    if (Obj[g].name == "")
    {
        return g;
    }
    else
    {
        while (Obj[g].name != "")
        {
            g = rehashfunction(g, memory);
        }
        if (Obj[g].name == "")
        {
            return g;
        }
    }
    return -1;
}
int hashfunction_find(Group* Obj, char a, char b, int memory, string hname)
{
    int g = hash_summ((int)a, (int)b, memory);
    if (Obj[g].name == hname)
    {
        return 1, g;
    }
    else
    {
        while (Obj[g].name == "")
        {
            g = rehashfunction(g, memory);
        }
        if (Obj[g].name == hname)
        {
            return 1, g;
        }
    }
    return 0, 0;
}
int hashCalc(Group* Obj, const int SIZE)
{
    int k = 0;
    int hash = 0;
    string hname;
    cout << "Enter the name author: " << endl;
    cin.get();
    getline(cin, hname);
    k = hname.length();
    hash = hashfunction_find(Obj, (int)hname[0], (int)hname[k - 1], SIZE, hname);

    return hash;
}
//! ��������

// ��������
void getArtists(const Group* Obj, const int SIZE)
{
    system("cls"); // ������� �������
    cout << "Groups and musicians: " << endl;
    cout << "================================" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        if (Obj[i].name == "")
            continue;
        else
            cout << Obj[i].name << endl;
    }
}

// ��������
void getAlbums(Group* Obj, const int SIZE, int index)
{
    if (index >= SIZE)
    { // �������� ����� �������
        getArtists(Obj, SIZE);
        cout << endl
            << "There is no author with this serial number!" << endl
            << endl;
        return;
    }
    else
    { // �� ��

        cout << "Albums of the " << Obj[index].name << endl;
        cout << "================================" << endl;

        for (int i = 0; i < Obj[index].AlbumCounter; i++)
        {
            cout << i + 1 << ". " << Obj[index].diskograph[i].name << endl;
        }
    }
}

// ��������
void addAlbum(Group* Obj, const int SIZE)
{
    getArtists(Obj, SIZE);

    int index = hashCalc(Obj, SIZE);

    if (Obj[index].name == "")
    { // �������� �� ������
        system("cls");
        getArtists(Obj, SIZE);
        cout << endl
            << endl
            << "There is no musician with this name!" << endl
            << endl;
        return;
    }
    else
    {
        Obj[index].AlbumCounter++;

        cout << "Enter the name of the album: " << endl;
        getline(cin, (Obj[index].diskograph[(Obj[index].AlbumCounter) - 1].name));

        cout << "Album added succesfully" << endl;

        cout << endl;
        getAlbums(Obj, SIZE, index);
        system("pause");
    }
}

// ��������
void addAlbum(Group* Obj, const int count, int* hash)
{ // ������������� ������� � ��� ������� ��������� ������������

    Obj[*hash].AlbumCounter++;

    cout << "Enter the name of the album: " << endl;
    cin.get();
    getline(cin, (Obj[*hash].diskograph[(Obj[*hash].AlbumCounter) - 1].name));

    cout << "Album added succesfully" << endl;
}

// ��������
void getTracks(Group* Obj, const int SIZE, int index)
{ // ����� ������ ��� ����� �������
    int album;
    cout << "Enter the serial number of album: " << endl;
    cin >> album;
    album--;

    if (index >= SIZE || index < 0)
    {
        cout << "There is no musician with this serial number!" << endl
            << endl;
        getArtists(Obj, SIZE);
        return;
    }
    else
    {
        if (album > Obj[index].AlbumCounter || album < 0)
        {
            cout << "There is no album with this serial number!" << endl
                << endl;
            getAlbums(Obj, SIZE, index);
            return;
        }
        else
        {
            cout << "Tracks" << endl;
            cout << "================================" << endl;
            for (int i = 0; i < Obj[index].diskograph[album].TrackCounter; i++)
                cout << i + 1 << ". " << Obj[index].diskograph[album].track_list[i].name << endl;
        }
    }
}

// ��������
void getTracks_add(const Group* Obj, const int count, int choice1)
{ // ����� ������ ��������� �����������
    int choice2 = Obj[choice1].AlbumCounter - 1;
    cout << "Tracks:" << endl;
    cout << "================================" << endl;
    for (int i = 0; i < Obj[choice1].diskograph[choice2].TrackCounter; i++)
        cout << i + 1 << ". " << Obj[choice1].diskograph[choice2].track_list[i].name << endl;
}

// ��������
void addTrack(Group* Obj, const int SIZE)
{
    int y;

    int index = hashCalc(Obj, SIZE);

    if (Obj[index].name == "")
    {
        getArtists(Obj, SIZE);
        cout << endl
            << endl
            << "There are no such musicians!" << endl
            << endl;
        return;
    }
    else
    {
        getAlbums(Obj, SIZE, index);
        cout << "Enter the serial number of album: " << endl;
        cin >> y;
        y--; // ������

        if (y >= Obj[index].AlbumCounter || y < 0 || Obj[index].diskograph[y].name == "")
        {
            getAlbums(Obj, SIZE, index);
            cout << endl
                << endl
                << "There is no album with this serial number!" << endl
                << endl;
            return;
        }
        else
        {
            cout << "Enter the name of the track: " << endl;
            cin.get();
            int z = Obj[index].diskograph[y].TrackCounter; // ���������� ������ � ������� �����������
            getline(cin, Obj[index].diskograph[y].track_list[z].name);
            Obj[index].diskograph[y].TrackCounter++;
            cout << "Track added succesfully" << endl;
        }
    }

    cout << endl;
    getTracks_add(Obj, SIZE, index);
    system("pause");
}

// ��������
void addTrack(Group* Obj, const int SIZE, int* hash)
{
    int temp = *hash;                   // ������
    int y = Obj[temp].AlbumCounter - 1; // � ��������� ������ (���� ������������ ��� ����� ������� ����� ������ ��� � ������)
    cout << "Enter the name of the track: " << endl;
    cin.get();
    int z = Obj[temp].diskograph[y].TrackCounter; // ���������� ������ � ������� �����������
    getline(cin, Obj[temp].diskograph[y].track_list[z].name);
    Obj[temp].diskograph[y].TrackCounter++;
    cout << "Track added succesfully" << endl;
}

// ��������
Group* delData(Group* Obj, int SIZE, int* count)
{ // �������� ��������
    int choice;

    cout << "What do you want to delete: " << endl;
    cout << "1 - author" << endl;
    cout << "2 - album" << endl;
    cout << "3 - track" << endl;
    cout << "0 - exit" << endl;
    cin >> choice;

    if (*count == 0)
    {
        cout << "Database is empty" << endl;
        return Obj;
    }
    int y;
    int index = 0;
    switch (choice)
    {
    case 1: // ������� �����������
        getArtists(Obj, SIZE);
        index = hashCalc(Obj, SIZE);
        if (Obj[index].name == "")
        {
            cout << endl
                << "There is no musician !" << endl
                << endl;
            break;
        }
        else
        {

            Obj[index].name = "";

            system("cls");
            cout << "Author deleted!" << endl;
            getArtists(Obj, SIZE);
            system("pause");
            return Obj;
        }

    case 2: // ������� ������
        getArtists(Obj, SIZE);

        index = hashCalc(Obj, SIZE);
        if (Obj[index].name == "")
        {
            cout << endl
                << "There is no musician!" << endl
                << endl;
            break;
        }
        else
        {
            getAlbums(Obj, SIZE, index);

            cout << endl
                << endl
                << "Enter the serial number of album: " << endl;
            cin >> y;
            y--;

            if (y < 0 || y >= Obj[index].AlbumCounter || Obj[index].diskograph[y].name[0] == 0)
            {
                cout << "There is no album with this serial number!" << endl
                    << endl;
                break;
            }
            else
            {
                for (int i = y; i < Obj[index].AlbumCounter; i++)
                {
                    Obj[index].diskograph[y] = Obj[index].diskograph[y + 1];
                }

                Obj[index].AlbumCounter--;
                cout << "Album deleted!" << endl;

                getAlbums(Obj, SIZE, index);
                system("pause");
                return Obj;
            }
        }
    case 3: // ������� ����
        getArtists(Obj, SIZE);
        index = hashCalc(Obj, SIZE);
        if (Obj[index].name == "")
        {
            cout << endl
                << "There is no musician!" << endl
                << endl;
            break;
        }
        else
        {
            getAlbums(Obj, SIZE, index);

            cout << endl
                << endl
                << "Enter the serial number of album: " << endl;
            cin >> y;
            y--;
            if (y < 0 || y >= Obj[index].AlbumCounter || Obj[index].diskograph[y].name[0] == 0)
            {
                cout << "There is no album with this serial number!" << endl
                    << endl;
                break;
            }
            getTracks_add(Obj, SIZE, index);
            cout << "Enter the serial number of track: " << endl;
            int z;
            cin >> z;
            z--;

            if (z < 0 || z >= Obj[index].diskograph[y].TrackCounter || Obj[index].diskograph[y].track_list[z].name[0] == 0)
            {
                cout << "There is no track with this serial number!" << endl
                    << endl;
                break;
            }
            else
            {
                for (int i = z; i < Obj[index].diskograph[y].TrackCounter; i++)
                {
                    Obj[index].diskograph[y].track_list[z] = Obj[index].diskograph[y].track_list[z + 1];
                }
                Obj[index].diskograph[y].TrackCounter--;

                cout << "Track deleted!" << endl;
                system("pause");
                return Obj;
            }
        }
    case 0:
        break;
    default:
        cout << "Unknown command!" << endl;
        system("pause");
        break;
    }

    if (choice == 1)
        (*count)--;

    return Obj;
}

// ��������
void getMenu()
{
    cout << "Menu: " << endl
        << endl;
    cout << "1. - add musician or band" << endl;
    cout << "2. - delete element" << endl;
    cout << "3. - get musicians" << endl;
    cout << "4. - add album" << endl;
    cout << "5. - add track" << endl;
    cout << "6. - get albums" << endl;
    cout << "7. - get tracks" << endl;
    cout << "8. - find" << endl;
    cout << "9. - save data in file" << endl;
    cout << "10. - reading data from file" << endl;
    cout << "11. - genre sorting" << endl;
    cout << "0. - exit" << endl;
}

// ��������
void findData(Group* Obj, int SIZE)
{
    system("cls");
    cout << "What do you want to find?\n 1 - author\n 2 - album\n 3 - track\n 0 - exit\n";
    int choice, sensor = -1;
    string hname;
    int index = 0;
    cin >> choice;
    while (1)
    {
        if (choice != 1 && choice != 2 && choice != 3 && choice != 0)
        {
            cout << "Unknown command� plese re-enter\n";
            cin >> choice;
        }
        else
        {
            switch (choice)
            {
            case 1: // ����� �������
                index = hashCalc(Obj, SIZE);
                if (Obj[index].name == "")
                {
                    cout << "Author not found!\n";
                }
                else
                {
                    cout << endl
                        << "\nAuthor found!\n";
                    getAlbums(Obj, SIZE, index);
                    sensor = 0;
                    break;
                }
                break;
            case 2: // ����� �������
                cout << "Enter the album title:\n";
                cin.get();
                getline(cin, hname);
                for (int i = 0; i < SIZE; i++)
                {
                    if (Obj[i].name == "")
                    {
                        continue;
                    }
                    for (int j = 0; j < Obj[i].AlbumCounter; j++)
                    {
                        if (hname == Obj[i].diskograph[j].name)
                        {
                            cout << "\nAlbum found!\n";
                            cout << "Author: " << Obj[i].name << endl;
                            cout << "Its serial number is " << j + 1 << endl;
                            getAlbums(Obj, SIZE, i);
                            sensor = 0;
                            break;
                        }
                    }
                }
                if (sensor == -1)
                { // �� ������
                    cout << "Album not found!\n";
                }
                break;
            case 3: // ����� �����
                cout << "Enter the name of the track:\n";
                cin.get();
                getline(cin, hname);
                for (int i = 0; i < SIZE; i++)
                {
                    if (Obj[i].name == "")
                    {
                        continue;
                    }
                    for (int j = 0; j < Obj[i].AlbumCounter; j++)
                    {
                        for (int c = 0; c < Obj[i].diskograph[j].TrackCounter; c++)
                        {
                            if (hname == Obj[i].diskograph[j].track_list[c].name)
                            {
                                cout << "\nTrack found!\n";
                                cout << "Author: " << Obj[i].name << endl;
                                cout << "Album: " << Obj[i].diskograph[j].name << endl;
                                cout << "Its serial number is " << c + 1 << endl;
                                // getTracks_add(Obj, SIZE, i); // ������
                                sensor = 0;
                                break;
                            }
                        }
                    }
                }
                if (sensor == -1)
                { // �� ������
                    cout << "\nTrack not found!\n";
                }
                break;
            case 0: // ����� �� �������
                break;
            }
            system("pause");
            break;
        }
    }
}

// ��������
Group* addArtist(Group* Obj, const int SIZE, int* hash, int* count)
{
    char x;
    if (*count == 0)
    {
        Obj = new Group[SIZE];
    }
    cin.get();
    cout << "Enter the name of the band or musician: ";
    string hname;
    int index = -1;
    getline(cin, hname);
    int k = hname.length();
    index = hashfunction(Obj, (int)hname[0], (int)hname[k - 1], SIZE);
    if (index != -1)
    {
        Obj[index].name = hname;
        Obj[index].key = index;
        *hash = index;
    }
    else
    {
        cout << "Out of memory\n";
        return Obj;
    }
    cout << endl;
    cout << "Input genre of this artist: ";
    cin >> Obj[index].genre; // ���������� ����� � �������
    system("cls");
    getArtists(Obj, SIZE);
    cout << endl;

    (*count)++;

    cout << "Add albums to this author? y/n" << endl; // �������� �� �������� ���������� �������
    cin >> x;
    while (x == 'y' || x == 'Y')
    {
        system("cls");
        getAlbums(Obj, SIZE, index);               // ����� �������� ������� �������
        addAlbum(Obj, SIZE, &index);               // �������� ������
        cout << "Add tracks to this album? y/n: "; // �������� �� ����� � ��������� ������ ������� �������
        cin >> x;
        while (x == 'y' || x == 'Y')
        {
            system("cls");
            getTracks_add(Obj, SIZE, index); // ������� �����
            addTrack(Obj, SIZE, &index);     // �������� ����
            cout << "\nAdd more tracks? y/n: ";
            cin >> x;
            cout << endl;
        }
        cout << "\nAdd more albums? y/n: ";
        cin >> x;
        cout << endl;
    }

    return Obj;
}

void ReadingData(Group* (&Obj), const int SIZE, int& count, string filename)
{
    system("cls");
    int index, k;
    string temp;
    ifstream reading(filename);
    if (reading)
    {
        reading >> count;
        Obj = new Group[SIZE];
        reading.seekg(2, ios::cur);
        for (int i = 0; i < SIZE; i++)
        {
            // reading.getline(Obj[i].name, '\n');
            getline(reading, temp);
            if (temp == "")
                break;
            k = temp.length();
            index = hashfunction(Obj, (int)temp[0], (int)temp[k - 1], SIZE);
            // reading >> Obj[i].name;
            Obj[index].name = temp;
            getline(reading, Obj[index].genre);
            // reading.seekg(2, ios::cur);
            reading >> Obj[index].AlbumCounter;
            reading.seekg(2, ios::cur);
            for (int j = 0; j < Obj[index].AlbumCounter; j++)
            {
                // reading.getline(Obj[i].diskograph[j].genre, 64, '\n'); // ��������� ����
                // reading >> Obj[i].diskograph[j].date; // ��������� ���� �������
                // reading.seekg(2, ios::cur);
                // reading.getline(Obj[i].diskograph[j].name, 64, '\n');
                getline(reading, Obj[index].diskograph[j].name);
                reading >> Obj[index].diskograph[j].TrackCounter;
                reading.seekg(2, ios::cur);
                for (int k = 0; k < Obj[index].diskograph[j].TrackCounter; k++)
                {
                    // reading >> Obj[i].diskograph[j].track_list[k].name;
                    // reading.getline(Obj[i].diskograph[j].track_list[k].name, 64, '\n');
                    getline(reading, Obj[index].diskograph[j].track_list[k].name);
                }
            }
        }
    }
    else
        cout << "error reading data";
}

void SavingData(Group* Obj, const int SIZE, int& count, string filename)
{
    ofstream record(filename, ios::out);
    if (record)
    {
        record << count << endl;

        for (int i = 0; i < SIZE; i++)
        {
            if (Obj[i].name == "")
            {
                continue;
            }
            record << Obj[i].name << endl;
            record << Obj[i].genre << endl;
            record << Obj[i].AlbumCounter << endl;
            for (int j = 0; j < Obj[i].AlbumCounter; j++)
            {
                // record << Obj[i].diskograph[j].genre << endl; // ���������� ����
                // record << Obj[i].diskograph[j].date << endl;  // ���������� ���� �������
                record << Obj[i].diskograph[j].name << endl;
                record << Obj[i].diskograph[j].TrackCounter << endl;
                for (int k = 0; k < Obj[i].diskograph[j].TrackCounter; k++)
                {
                    if (Obj[i].diskograph[j].TrackCounter - k == 1)
                        record << Obj[i].diskograph[j].track_list[k].name;
                    else
                        record << Obj[i].diskograph[j].track_list[k].name << endl;
                }
                record << endl;
            }
        }
    }
    else
        cout << "error saving data";
}

void getGenre(Group* Obj, const int SIZE)
{
    system("cls");
    string chGenre;
    cout << "Enter genre: ";
    cin >> chGenre;
    int counter = 0;
    system("cls");
    cout << "There is list of artits with " << chGenre << " genre: " << endl;
    for (int i = 0; i < SIZE; i++)
    {
        if (Obj[i].genre == chGenre)
        {
            counter++;
            cout << counter << ". " << Obj[i].name << endl;
        }
    }
}