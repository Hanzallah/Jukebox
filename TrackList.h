#pragma once
#include <cstring>
#include "Track.h"
using namespace std;

typedef Track Item;
class TrackList {
private:
    struct Node {
        Item item;
        Node *next;
    };

    Node *head;
    int size;
    Node * find(int index) const;

public:
    TrackList();
    TrackList(const TrackList &listToCopy);
    ~TrackList();

    bool isEmpty() const;
    int getLength() const;
    bool insert(const Item & li, int index);
    bool remove(int index);
    bool getEntry(Item & li, int index) const;
    void display() const;
    void displayHead() const;
    int findByName(string title);
    bool addMusician(string trackTitle, const Musician & musician);
    bool removeMusician(string trackTitle, string fName, string lName);
    void displayMusicianRoles(string fName, string lName);
};