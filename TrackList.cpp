#include <iostream>
#include "TrackList.h"
using namespace std;

// Head is actually the last element here

TrackList::TrackList() : size(0), head(nullptr)
{
}

TrackList::TrackList(const TrackList & listToCopy) : size(listToCopy.size)
{
    if (listToCopy.head == nullptr) {
        this->head = nullptr;
    }
    else {
        head = new Node();
        head->item = listToCopy.head->item;
        Node *currPtr = head;
        for (Node *orig = listToCopy.head->next; orig != nullptr; orig = orig->next) {
            currPtr->next = new Node;
            currPtr = currPtr->next;
            currPtr->item = orig->item;
        }
        currPtr->next = head;
    }
}

TrackList::~TrackList()
{
    while (!isEmpty()) {
        remove(1);
    }
}

bool TrackList::isEmpty() const
{
    return size == 0;
}

int TrackList::getLength() const
{
    return size;
}

bool TrackList::insert(const Item & li, int index)
{
    int newLen = size + 1;
    if ((index >= 1) && (index <= newLen)) {
        size = newLen;

        Node *newNode = new Node;
        newNode->item = li;

        if (index == 1) {
            if (head == nullptr) {
                head = newNode;
                newNode->next = newNode;
            }
            else {
                newNode->next = head->next;
                head->next = newNode;
            }
        }
        else if (index == newLen) {
            newNode->next = head->next;
            head->next = newNode;
            head = newNode;
        }
        else {
            Node *prev = find(index - 1);
            newNode->next = prev->next;
            prev->next = newNode;
        }
        return true;
    }

    return false;
}

bool TrackList::remove(int index)
{
    if ((index >= 1) && (index <= size)) {
        Node *prev = find(index - 1);
        if (index == size) {
            head = prev;
        }
        --size;
        Node *curr = prev->next;
        prev->next = curr->next;

        curr->next = nullptr;
        delete curr;
        curr = nullptr;

        return true;
    }

    return false;
}

bool TrackList::getEntry(Item & li, int index) const
{
    Node *temp = find(index);
    if (temp != nullptr) {
        li = temp->item;
        return true;
    }
    return false;
}

void TrackList::display() const
{
    if (head != nullptr) {
        Node *curr = head->next;
        do {
            cout << curr->item << endl;
            curr = curr->next;
        } while (curr != head->next);
        cout << "=====================================================================" << endl;
    }
    else {
        cout << "----NONE----" << endl;
    }
}

void TrackList::displayHead() const
{
    if (head != nullptr)
        cout << head->item << endl;
}

int TrackList::findByName(string title)
{
    int index = 0;
    Node *curr = head;
    curr = curr->next;
    for (int i = 1; i < getLength() + 1; i++) {
        if (curr->item.getTitle() == title) {
            return i;
        }
        curr = curr->next;
    }
    return index;
}

bool TrackList::addMusician(string title, const Musician & musician)
{
    int index = findByName(title);
    if (index) {
        Node *temp = find(index);
        temp->item.addMusician(musician);
        return true;
    }
    return false;
}

bool TrackList::removeMusician(string trackTitle, string fName, string lName)
{
    int index = findByName(trackTitle);
    if (index) {
        Node *temp = find(index);
        temp->item.deleteMusician(fName, lName);
        return true;
    }
    return false;
}

void TrackList::displayMusicianRoles(string fName, string lName)
{
    if (head != nullptr) {
        Node *curr = head->next;
        do {
            if (curr->item.findMusician(fName, lName)) {
                cout << curr->item.getTitle() << " " << curr->item.getYear() << " " << curr->item.musicianRole(fName, lName) << endl;
            }
            curr = curr->next;
        } while (curr != head->next);
    }
}

TrackList::Node * TrackList::find(int index) const
{
    if (index == 0) {
        index = size;
    }

    bool success = (index >= 1) && (index <= size);

    if (success) {
        Node *curr = head;
        if (index == size) {
            return curr;
        }
        if (index == 1) {
            return curr->next;
        }
        else {
            curr = curr->next;
            for (int i = 1; i < index; i++) {
                curr = curr->next;
            }
            return curr;
        }

    }

    return nullptr;
}