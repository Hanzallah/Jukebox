#include "Track.h"
#include <string>
#include "MusicianList.h"
#include "Musician.h"
using namespace std;

Track::Track() : title(""), year(0000)
{
    mList = new MusicianList();
}

Track::Track(string title, int year, MusicianList *mList)
{
    this->title = title;
    this->year = year;
    if (mList == nullptr) {
        this->mList = new MusicianList();
    }
    else {
        this->mList = mList;
    }
}

Track::Track(const Track & trackToCopy)
{
    this->title = trackToCopy.title;
    this->year = trackToCopy.year;
    *(this->mList) = *trackToCopy.mList;
}

void Track::operator=(const Track & trackToCopy)
{
    if (this != &trackToCopy) {
        this->title = trackToCopy.title;
        this->year = trackToCopy.year;
        *(this->mList) = *trackToCopy.mList;
    }
}

Track::~Track()
{
    delete this->mList;
}

string Track::getTitle() const
{
    return title;
}

int Track::getYear() const
{
    return year;
}

bool Track::addMusician(const Musician & musician)
{
    if (mList->getLength() == 0)
        return mList->insert(musician, 1);
    return mList->insert(musician, mList->getLength() + 1);
}

bool Track::deleteMusician(string fName, string lName)
{
    int index = mList->findByName(fName, lName);
    if (index) {
        return mList->remove(index);
    }
    return false;
}

void Track::displayMusicians() const
{
    mList->display();
}

int Track::findMusician(string fName, string lName)
{
    return mList->findByName(fName, lName);
}

string Track::musicianRole(string fName, string lName)
{
    return mList->getRole(fName, lName);
}
