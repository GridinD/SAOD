#pragma once
#ifndef HEADER
#define HEADER
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Track
{
    string name = ""; // имя трека
};

struct Album
{
    string name = "";     // имя альбома
    string genre = "";    // жанр альбома
    int date;             //??
    Track track_list[64]; // треки в альбоме
    int TrackCounter = 0; // количество альбомов
};
struct Group
{
    string name = "";     // имя артиста
    Album diskograph[64]; // альбомы артиста
    int key;              // для хэша наверное
    int AlbumCounter = 0; // количество альбомов
    string genre = "";    // Жанр артиста
};
void getGenre(Group* Obj, const int SIZE);
void SavingData(Group* Obj, const int SIZE, int& count, string filename);
void ReadingData(Group* (&Obj), const int SIZE, int& count, string filename);
Group* addArtist(Group* Obj, const int SIZE, int* hash, int* count);
void findData(Group* Obj, int SIZE);
void getMenu();
Group* delData(Group* Obj, int SIZE, int* count);
void addTrack(Group* Obj, const int SIZE, int* hash);
void addTrack(Group* Obj, const int SIZE);
void getTracks_add(const Group* Obj, const int count, int choice1);
void getTracks(Group* Obj, const int SIZE, int index);
void addAlbum(Group* Obj, const int count, int* hash);
void addAlbum(Group* Obj, const int SIZE);
void getAlbums(Group* Obj, const int SIZE, int index);
void getArtists(const Group* Obj, const int SIZE);
int hashCalc(Group* Obj, const int SIZE);
int hashfunction_find(Group* Obj, char a, char b, int memory, string hname);
int hashfunction(Group* Obj, char a, char b, int memory);
int rehashfunction(int t, int memory);
int hash_summ(int a, int b, int memory);
int randDam(int min, int max);
#endif