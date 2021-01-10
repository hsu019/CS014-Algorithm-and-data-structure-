#include <iostream>
#include <string>
#include "Playlist.h"

using namespace std;

	PlaylistNode::PlaylistNode() {
        uniqueID = "none";
        songName = "none";
        artistName = "none";
        songLength = 0;
        nextNodePtr = nullptr;
    }

    PlaylistNode::PlaylistNode(string ID, string sname, string aname, int slength) {
        uniqueID = ID;
        songName = sname;
        artistName = aname;
        songLength = slength;
    }

    void PlaylistNode::InsertAfter(PlaylistNode *node) {
        node -> nextNodePtr = this -> nextNodePtr;
        this -> nextNodePtr = node;
    }
    void PlaylistNode::SetNext(PlaylistNode *node) {
        this -> nextNodePtr = node;
    }

    string PlaylistNode::GetID()const {
        return uniqueID;
    }

    string PlaylistNode::GetSongName()const {
        return songName;
    }

    string PlaylistNode::GetArtistName()const {
        return artistName;
    }

    int PlaylistNode::GetSongLength()const {
        return songLength;
    }

    PlaylistNode* PlaylistNode::GetNext() {
        return nextNodePtr;
    }

    void PlaylistNode::PrintPlaylistNode() {
        cout << "Unique ID: " << uniqueID << endl;
        cout << "Song Name: " << songName << endl;
        cout << "Artist Name: " << artistName << endl;
        cout << "Song Length (in seconds): " << songLength << endl;
    }






