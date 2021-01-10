#include <iostream>
#include <string>
#include "Playlist.h"

using namespace std;

void PrintMenu(string title);

int main(){
    string title;
    cout << "Enter playlist's title:" << endl;
    cout << endl;
    getline(cin,title);
    PrintMenu(title);
    return 0;
}

void PrintMenu(string title) {
    PlaylistNode* head = nullptr;
    PlaylistNode* tail = nullptr;
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
    while (option != 'q') {
        if (option == 'a'){
            string ID;
            string sname;
            string aname;
            int slength;
            cin.ignore();
            cout << "ADD SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            getline(cin,ID);
            cout << "Enter song's name:" << endl;
            getline(cin,sname);
            cout << "Enter artist's name:" << endl;
            getline(cin,aname);
            cout << "Enter song's length (in seconds):" << endl;
            cout << endl;
            cin >> slength;
            PlaylistNode* temp = new PlaylistNode(ID, sname, aname, slength);
            if (head == nullptr) {
                head = temp;
                tail = temp;
            }
            else {
                tail -> InsertAfter(temp);
                tail = temp;
            }
        }
        if(option == 'd') {
            string ID;
            cout << "REMOVE SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            cin >> ID;
            PlaylistNode* prep = head;
            PlaylistNode* curr = head -> GetNext();
            if (head == nullptr){
                return;
            }
            if(prep -> GetID() == ID){
                head = curr;
                cout << "\"" << prep -> GetSongName() << "\" removed." << endl;
                cout << endl;
                delete prep;
            }
            while (curr != nullptr) {
                if(curr -> GetID() == ID){
                    if(curr != tail){
                        prep -> SetNext(curr -> GetNext());
                        cout << "\"" << curr -> GetSongName() << "\" removed." << endl;
                        cout << endl;
                        delete curr;
                    }
                    else {
                        tail = prep;
                        prep -> SetNext(curr -> GetNext());
                        cout << "\"" << curr -> GetSongName() << "\" removed." << endl;
                        cout << endl;
                        delete curr;
                    }
                }
                curr = curr -> GetNext();
                prep = prep -> GetNext();
            }
        }
        if (option == 'c') {
            int newnum;
            int oldnum;
            cout << "CHANGE POSITION OF SONG" << endl;
            cout << "Enter song's current position:" << endl;
            cin >> oldnum;
            cout << "Enter new position for song:" << endl;
            cin >> newnum;
            PlaylistNode* oldnode = head;
            PlaylistNode* newnode = head;
            PlaylistNode* temp;
            temp = head;
            int nodenum = 0;
            while (temp != nullptr){
                ++nodenum;
                temp = temp -> GetNext();
            }
            if (newnum < 1) {
                newnum = 1;
            }
            if (newnum > nodenum) {
                newnum = nodenum;
            }
            int position = 1;
            while (position != oldnum && oldnode != nullptr) {
                oldnode = oldnode -> GetNext();
                ++position;
            }
            position = 1;
            while (position != newnum && newnode != nullptr) {
                newnode = newnode -> GetNext();
                ++position;
            }
            PlaylistNode* prep = head;
            PlaylistNode* curr = head -> GetNext();
            if(oldnode == head) {
                head = curr;
            }
            else {
            while (curr != nullptr) {
                if(curr == oldnode) {
                    if(curr == tail) {
                        tail = prep;
                        prep -> SetNext(curr -> GetNext());
                    }
                    else {
                        prep -> SetNext(curr -> GetNext());
                    }
                    break;
                }
                curr = curr -> GetNext();
                prep = prep -> GetNext();
            }
            }
            if(newnum == 1) {
                oldnode -> SetNext(head);
                head = oldnode;
            }
            else if(newnum == nodenum) {
                newnode -> InsertAfter(oldnode);
                tail = oldnode;
            }
            else if (oldnum < newnum) {
                newnode -> InsertAfter(oldnode);
            }
            else if (oldnum > newnum) {
                temp = head;
                while (temp -> GetNext() != newnode) {
                    temp = temp -> GetNext();
                }
                temp -> InsertAfter(oldnode);
            }
            cout << "\"" << oldnode -> GetSongName() << "\" moved to position " << newnum << endl;
            cout << endl;
        }
        if (option == 's') {
            string aname;
            cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
            cout << "Enter artist's name:" << endl;
            cin.ignore();// why uese ignore?
            getline(cin,aname);
            cout << endl;

            int num = 1;
            PlaylistNode* temp = head;
            while (temp != nullptr) {
                if(temp -> GetArtistName() == aname) {
                    cout << num << "." << endl;
                    temp -> PrintPlaylistNode();
                    cout << endl;
                }
                num = num + 1;
                temp = temp -> GetNext();
            }
        }
        if (option == 't') {
            cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
            int sum = 0;
            PlaylistNode* temp = head;
            while (temp != nullptr) {
                sum = sum + temp -> GetSongLength();
                temp = temp -> GetNext();
            }
            cout << "Total time: " << sum << " seconds" << endl;
            cout << endl;
        }
        if (option == 'o') {
            cout << title << " - OUTPUT FULL PLAYLIST" << endl;
            if (head == nullptr) {
                cout << "Playlist is empty" << endl;
                cout << endl;
            }
            else {
                int num = 1;
                PlaylistNode* temp = head;
                while (temp != nullptr) {
                    cout << num << "." << endl;
                    temp -> PrintPlaylistNode();
                    cout << endl;
                    ++num;
                    temp = temp -> GetNext();
                }
        }
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
