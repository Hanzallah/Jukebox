#include <iostream>
#include "MusicianList.h"
#include "Musician.h"
using namespace std;

// Head is actually the last element here

MusicianList::MusicianList() : size(0), head(nullptr)
{
}

MusicianList::MusicianList(const MusicianList & listToCopy) : size(listToCopy.size)
{
    if (listToCopy.head == nullptr) {
        this->head = nullptr;
    }
    else {
        head = new Node();
        head->item = listToCopy.head->item;
        Node *currPtr = head;
        for (Node *orig = listToCopy.head->next; orig != listToCopy.head; orig = orig->next) {
            currPtr->next = new Node;
            currPtr = currPtr->next;
            currPtr->item = orig->item;
        }
        currPtr->next = head;
    }
}

void MusicianList::operator=(const MusicianList & listToCopy)
{
    if (this != &listToCopy) {
        size = listToCopy.size;
        if (listToCopy.head == nullptr) {
            this->head = nullptr;
        }
        else {
            head = new Node();
            head->item = listToCopy.head->item;
            Node *currPtr = head;
            for (Node *orig = listToCopy.head->next; orig != listToCopy.head; orig = orig->next) {
                currPtr->next = new Node;
                currPtr = currPtr->next;
                currPtr->item = orig->item;
            }
            currPtr->next = head;
        }
    }
}

MusicianList::~MusicianList()
{
    while (!isEmpty()) {
        remove(1);
    }
}

bool MusicianList::isEmpty() const
{
    return size == 0;
}

int MusicianList::getLength() const
{
    return size;
}

bool MusicianList::insert(const ListItem & li, int index)
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

bool MusicianList::remove(int index)
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

bool MusicianList::getEntry(ListItem & li, int index) const
{
    Node *temp = find(index);
    if (temp != nullptr) {
        li = temp->item;
        return true;
    }
    return false;
}

void MusicianList::display() const
{
    if (head != nullptr) {
        Node *curr = head->next;
        do {
            cout << curr->item << " -> ";
            curr = curr->next;
        } while (curr != head->next);
        cout << "END" << endl;
    }
}

void MusicianList::displayHead() const
{
    if (head != nullptr)
        cout << head->item << endl;
}

int MusicianList::findByName(string fName, string lName)
{
    int index = 0;
    Node *curr = head;
    curr = curr->next;
    for (int i = 1; i < getLength() + 1; i++) {
        if (curr->item.getFirstName() == fName && curr->item.getLastName() == lName) {
            return i;
        }
        curr = curr->next;
    }
    return index;
}

string MusicianList::getRole(string fName, string lName)
{
    int index = findByName(fName, lName);
    if (index) {
        return this->find(index)->item.getRole();
    }
    return "";
}

MusicianList::Node * MusicianList::find(int index) const
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