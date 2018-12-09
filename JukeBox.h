#pragma once
#include <iostream>
#include <string>
#include "TrackList.h"
#include "Track.h"
#include "Musician.h"
using namespace std;

class JukeBox {
private:
    TrackList *tList;
public:
    JukeBox();
    ~JukeBox();
    void addTrack(string trackTitle, int releaseYear);
    void removeTrack(string trackTitle);
    void addMusician(string trackTitle, string musicianFirstName, string musicianLastName, string musicianRole);
    void removeMusician(string trackTitle, string musicianFirstName, string musicianLastName);
    void showAllTracks();
    void showTrack(string trackTitle);
    void showMusicianRoles(string musicianFirstName, string musicianLastName);

};