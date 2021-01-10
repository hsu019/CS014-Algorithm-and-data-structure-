#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include <string>
using namespace std;


class PlaylistNode {
 private:
    string uniqueID;
    string songName;
    string artistName;
    int songLength;
    PlaylistNode* nextNodePtr;
 public:
	PlaylistNode();
    PlaylistNode(string ID, string sname, string aname, int slength);
    void InsertAfter(PlaylistNode* node);
    void SetNext(PlaylistNode* node);
    string GetID()const;
    string GetSongName()const;
    string GetArtistName()const;
    int GetSongLength()const;
    PlaylistNode* GetNext();
    void PrintPlaylistNode();
};

#endif

