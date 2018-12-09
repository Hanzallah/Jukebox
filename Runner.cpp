#include <iostream>
#include <string>
#include "TrackList.h"
#include "Track.h"
#include "Musician.h"
#include "JukeBox.h"
using namespace std;

int main() {
    string s = "West Virginia";
    string s1 = "Ironic";
    string s2 = "Going Down Under";

    JukeBox jk;

    jk.addTrack(s, 2009);
    jk.addTrack(s1, 2014);
    jk.addTrack(s2, 2017);

    jk.addMusician(s, "Niagra", "Josephine", "Guitarist");
    jk.addMusician(s, "Henry", "Jacob", "Lead");
    jk.addMusician(s, "Eddie", "Freestone", "Vocalist");

    jk.addMusician(s1, "Jimmy", "Anderson", "Drummer");
    jk.addMusician(s1, "Jordan", "Cullingham", "Lead");
    jk.addMusician(s1, "Selena", "Manocci", "Singer");
    jk.addMusician(s1, "Fred", "ElPaso", "Violin");

    jk.addMusician(s2, "Helen", "Adams", "Singer");
    jk.addMusician(s2, "Jake", "Nickelson", "Guitarist");
    jk.addMusician(s2, "Mathew", "McNile", "Drummer");
    jk.addMusician(s2, "Niagra", "Josephine", "Lead");
    jk.addMusician(s2, "Francesca", "Byrne", "Vocalist");


    jk.showAllTracks();
    jk.showTrack(s);
    jk.removeMusician(s, "Henry", "Jacob");
    jk.removeMusician(s2, "Helen", "Adams");
    jk.removeMusician(s1, "Fred", "ElPaso");
    jk.showAllTracks();
    jk.showMusicianRoles("Niagra", "Josephine");
    return 0;
}