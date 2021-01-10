#include <iostream>
#include <string>
#include "Playlist.h"

using namespace std;

void PrintMenu(string title);

int main(){
    string title;
    cout << "Enter playlist's title:" << endl;
    getline(cin,title);
    PrintMenu(title);
    return 0;
}

void PrintMenu(string title) {
    cout << title << " PLAYLIST MENU" << endl;
    cout << "a - Add song" << endl;
    cout << "d - Remove song" << endl;
    cout << "c - Change position of song" << endl;
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit" << endl;
    cout << endl;
    cout << "Choose an option:" << endl;
    char option;
    cin >> option;
    Playlist playlist;
    while (option != 'q') {
        if (option == 'a'){
            string ID;
            string sname;
            string aname;
            int slength;
            cout << "ADD SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            getline(cin,ID);
            cout << "Enter song's name:" << endl;
            getline(cin,sname);
            cout << "Enter artist's name:" << endl;
            getline(cin,aname);
            cout << "Enter song's length (in seconds):" << endl;
            cin >> slength;
            playlist.add(ID, sname, aname, slength);
        }
        if(option == 'd') {
            string ID;
            cout << "REMOVE SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            getline(cin,ID);
            playlist.remove(ID);
        }
        if (option == 'c') {
            int newnum;
            int oldnum;
            cout << "CHANGE POSITION OF SONG" << endl;
            cout << "Enter song's current position:" << endl;
            cin >> oldnum;
            cout << "Enter new position for song:" << endl;
            cin >> newnum;
            playlist.changePosition(oldnum, newnum);
        }
        if (option == 's') {
            string aname;
            cout << "OUT SONG BY SPECIFIC ARTIST" << endl;
            cout << "Enter artist's name:" << endl;
            getline(cin,aname);
            cout << aname;
            playlist.outputsongs(aname);
        }
        if (option == 't') {
            cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
            playlist.outputtime();
        }
        if (option == 'o') {
            cout << title << " - OUTPUT FULL PLAYLIST" << endl;
            playlist.outputfulllist();
        }
        cout << title << " PLAYLIST MENU" << endl;
        cout << "a - Add song" << endl;
        cout << "d - Remove song" << endl;
        cout << "c - Change position of song" << endl;
        cout << "s - Output songs by specific artist" << endl;
        cout << "t - Output total time of playlist (in seconds)" << endl;
        cout << "o - Output full playlist" << endl;
        cout << "q - Quit" << endl;
        cout << endl;
        cout << "Choose an option:" << endl;
        cin >> option;
    }
}
