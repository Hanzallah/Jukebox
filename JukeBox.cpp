#include "JukeBox.h"

JukeBox::JukeBox() : tList(new TrackList())
{
}

JukeBox::~JukeBox()
{
    delete tList;
}

void JukeBox::addTrack(string trackTitle, int releaseYear)
{
    Track *track = new Track(trackTitle, releaseYear, nullptr);
    tList->insert(*track, tList->getLength() + 1);
    delete track;
}

void JukeBox::removeTrack(string trackTitle)
{
    int index = tList->findByName(trackTitle);
    if (index) {
        tList->remove(index);
    }
}

void JukeBox::addMusician(string trackTitle, string musicianFirstName, string musicianLastName, string musicianRole)
{
    Musician *temp = new Musician(musicianFirstName, musicianLastName, musicianRole);
    tList->addMusician(trackTitle, *temp);
    delete temp;
}

void JukeBox::removeMusician(string trackTitle, string musicianFirstName, string musicianLastName)
{
    tList->removeMusician(trackTitle, musicianFirstName, musicianLastName);
}

void JukeBox::showAllTracks()
{
    tList->display();
}

void JukeBox::showTrack(string trackTitle)
{
    int index = tList->findByName(trackTitle);
    if (index) {
        Track * t = new Track();
        tList->getEntry(*t, index);
        cout << *t;
        delete t;
    }
}

void JukeBox::showMusicianRoles(string musicianFirstName, string musicianLastName)
{
    tList->displayMusicianRoles(musicianFirstName, musicianLastName);
}