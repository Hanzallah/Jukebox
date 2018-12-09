#pragma once
#include <cstring>
#include "Musician.h"
using namespace std;

typedef Musician ListItem;
class MusicianList {
private:
    struct Node {
        ListItem item;
        Node *next;
    };

    Node *head;
    int size;
    Node * find(int index) const;

public:
    MusicianList();
    MusicianList(const MusicianList &listToCopy);
    void operator=(const MusicianList &listToCopy);
    ~MusicianList();

    bool isEmpty() const;
    int getLength() const;
    bool insert(const ListItem & li, int index);
    bool remove(int index);
    bool getEntry(ListItem & li, int index) const;
    void display() const;
    void displayHead() const;
    int findByName(string fName, string lName);
    string getRole(string fName, string lName);
};