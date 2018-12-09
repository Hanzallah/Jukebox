#pragma once
#include <iostream>
#include <string>
#include "MusicianList.h"
#include "Musician.h"
using namespace std;

class Track {
private:
    string title;
    int year;
    MusicianList *mList;

public:
    Track();
    Track(string title, int year, MusicianList *mList);
    Track(const Track & trackToCopy);
    void operator=(const Track & trackToCopy);
    ~Track();
    string getTitle() const;
    int getYear() const;
    bool addMusician(const Musician & musician);
    bool deleteMusician(string fName, string lName);
    void displayMusicians() const;
    int findMusician(string fName, string lName);
    string musicianRole(string fName, string lName);
    friend ostream & operator << (ostream &out, const Track &c);
};

inline ostream & operator<<(ostream & out, const Track & m)
{
    out << m.getTitle() << " " << m.getYear() << ": " << endl;
    m.displayMusicians();
    return out;
}