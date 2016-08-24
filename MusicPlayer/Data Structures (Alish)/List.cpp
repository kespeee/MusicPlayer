#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Song {
public:
	string songTitle, songArtist;
	int songYear, songPrice;

	void calculateSongPrice(){
		if (songYear >= 2016) {
			songPrice = 1;
		}
		else {
			songPrice = 0;
		}
	}

	Song(){
		calculateSongPrice();
	}

	Song(string songTitle, string songArtist, int songYear){
		this->songTitle = songTitle;
		this->songArtist = songArtist;
		this->songYear = songYear;
		calculateSongPrice();
	}
};

struct NodeType {
	Song *song;
	NodeType *next;
};

class PlayList {
public:

	int playlistSize;
	NodeType *start;

	PlayList() {
		this->start = NULL;
		this->playlistSize = 0;
	}

	Song* getSongByID(int position) {
		NodeType* current = start;
		if (playlistSize != 0){
			if (position>0 && position <= playlistSize) {
				for (int i = 0; i<position - 1; i++) {
					current = current->next;
				}
				return current->song;
			}
			else {
				return NULL;
			}
		}
		else {
			return NULL;
		}
	}

	void viewAllSongs(){

		cout << endl;

		NodeType *current = start;

		for (int i = 0; i<playlistSize; i++) {
			cout << i + 1 << " - " << current->song->songArtist << " - " << current->song->songTitle << " " << current->song->songYear << " ";

			if (current->song->songPrice != 0) {
				cout << "$1" << endl;
			}
			else {
				cout << "$0" << endl;
			}

			current = current->next;
		}

		if (playlistSize != 0) {
			cout << endl;
		}
	}

	void addNewSong(Song* song) {
		NodeType* newNodeType = new NodeType;
		newNodeType->song = song;
		newNodeType->next = NULL;

		if (start == NULL) {
			start = newNodeType;
		}
		else {
			NodeType *last = start;
			while (last->next != NULL) {
				last = last->next;
			}
			last->next = newNodeType;
		}
		playlistSize++;

		cout << "The song has been added!" << endl;
		cout << endl;
	}

	void removeSongByID(int position){
		if (playlistSize != 0) {
			if (position <= playlistSize) {
				if (position == 1) {
					if (playlistSize > 0) {
						NodeType *toBeDeleted = start;
						start = start->next;
						delete toBeDeleted;
						playlistSize--;

						cout << "The song has been deleted!" << endl;
						cout << endl;
					}
				}
				else if (position == 0) {
					cout << "Error! Incorrect ID" << endl;
					cout << endl;
				}

				else {
					NodeType *prev = NULL, *toDelete = start;
					for (int i = 0; i < position - 1; i++) {
						prev = toDelete;
						toDelete = toDelete->next;
					}
					prev->next = toDelete->next;
					delete toDelete;
					playlistSize--;

					cout << "The song has been deleted!" << endl;
					cout << endl;
				}
			}
			else {
				cout << "Incorrect ID" << endl;
				cout << endl;
			}
		}
		else {
			cout << "Error! No songs available" << endl;
			cout << endl;
		}
	}
};

class QueueList {
public:

	int playlistSize;
	NodeType *start;

	QueueList(){
		this->start = NULL;
		this->playlistSize = 0;
	}

	void viewAllSongs(){
		cout << " ***** QUEUE PLAYLIST PAGE ***** " << endl;

		cout << endl;

		NodeType *current = start;

		for (int i = 0; i<playlistSize; i++) {
			cout << i + 1 << " - " << current->song->songArtist
				 << " - " << current->song->songTitle
				 << " " << current->song->songYear << " ";

			if (current->song->songPrice != 0) {
				cout << "$1" << endl;
			}
			else {
				cout << "$0" << endl;
			}

			current = current->next;
		}

		if (playlistSize != 0) {
			cout << endl;
		}
	}

	void addSongAtEnd(Song* song) {
		NodeType* newNodeType = new NodeType;
		newNodeType->song = song;
		newNodeType->next = NULL;

		if (start == NULL) {
			start = newNodeType;
		}
		else {
			NodeType *last = start;
			while (last->next != NULL) {
				last = last->next;
			}
			last->next = newNodeType;
		}
		playlistSize++;
	}

	void removeSongByID(int position){
		if (playlistSize != 0) {
			if (position <= playlistSize) {
				if (position == 1) {
					if (playlistSize > 0) {
						NodeType *toBeDeleted = start;
						start = start->next;
						delete toBeDeleted;
						playlistSize--;
					}
				}
				else if (position == 0) {
					cout << "Error! Incorrect ID!" << endl;
					cout << endl;
				}

				else {
					NodeType *prev = NULL, *toDelete = start;
					for (int i = 0; i < position - 1; i++) {
						prev = toDelete;
						toDelete = toDelete->next;
					}
					prev->next = toDelete->next;
					delete toDelete;
					playlistSize--;
				}
			}
			else {
				cout << "Error! Incorrect ID" << endl;
				cout << endl;
			}
		}
		else {
			cout << "0 songs available" << endl;
			cout << endl;
		}
	}
};

class StackList {
public:

	int playlistSize;
	NodeType *start;

	StackList(){
		this->start = NULL;
		this->playlistSize = 0;
	}

	void viewAllSongs(){
		cout << " ***** STACK PLAYLIST PAGE ***** " << endl;

		cout << endl;

		NodeType *current = start;

		for (int i = 0; i<playlistSize; i++) {
			cout << i + 1 << " - " << current->song->songArtist << " - " << current->song->songTitle << " " << current->song->songYear << " ";

			if (current->song->songPrice != 0) {
				cout << "$1" << endl;
			}
			else {
				cout << "$0" << endl;
			}

			current = current->next;
		}

		if (playlistSize != 0) {
			cout << endl;
		}
	}

	void pushSong(Song* song){
		NodeType* newNodeType = new NodeType;
		newNodeType->song = song;
		newNodeType->next = start;
		start = newNodeType;
		playlistSize++;
	}

	void removeSongByID(int position){
		if (playlistSize != 0) {
			if (position <= playlistSize) {
				if (position == 1) {
					if (playlistSize > 0) {
						NodeType *toBeDeleted = start;
						start = start->next;
						delete toBeDeleted;
						playlistSize--;

					}
				}
				else if (position == 0) {
					cout << "Error! Incorrect ID" << endl;
					cout << endl;
				}

				else {
					NodeType *prev = NULL, *toDelete = start;
					for (int i = 0; i < position - 1; i++) {
						prev = toDelete;
						toDelete = toDelete->next;
					}
					prev->next = toDelete->next;
					delete toDelete;
					playlistSize--;

				}
			}
			else {
				cout << "Error! Incorrect ID" << endl;
				cout << endl;
			}
		}
		else {
			cout << "0 songs Available!" << endl;
			cout << endl;
		}
	}
};