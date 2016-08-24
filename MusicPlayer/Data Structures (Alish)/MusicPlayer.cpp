#include "stdafx.h"
#include "List.cpp"
#include <iostream>
#include <string>

using namespace std;

class MusicPlayer {
public:
	MusicPlayer(){
		showMenu();
	}

private:
	QueueList queuePl;
	StackList stackPl;
	PlayList songsL;

	void showMenu(){
		cout << " ***** MAIN MENU ***** " << endl;

		int selection = 0;

		cout << "  1) View Playlist" << endl;
		cout << "  2) View Songs" << endl;
		cout << "  3) Exit" << endl;
		cout << "  Enter Option: ";

		cin >> selection;
		cout << endl;

		switch (selection)
		{
			case 1:
				viewSongList();
				break;
			case 2:
				viewAllSongs();
				break;
			case 3:
				cout << " Good Bye and Please Come Again! " << endl;
				break;
			default:
				cout << " ** Error! Please Try Again ** " << endl;
				showMenu();
		}

	}

	void viewSongList(){
		cout << "    ***** PLAYLIST ***** " << endl;
		cout << endl;

		stackPl.viewAllSongs();
		queuePl.viewAllSongs();

		int selection;

		cout << " 1) Add song" << endl;
		cout << " 2) Remove song" << endl;
		cout << " 3) Home" << endl;
		cout << " Enter Option: ";

		cin >> selection;
		cout << endl;

		if (selection == 1) {
			int id;

			cout << "Enter the Song ID Number: ";
			cin >> id;

			Song *song = NULL;

			song = songsL.getSongByID(id);

			if (song != NULL){
				stackPl.pushSong(song);
				queuePl.addSongAtEnd(song);

			}
			else {
				cout << "Error! Song does not exist" << endl;
				cout << endl;
			}

			viewSongList();
		}
		else if (selection == 2) {
			int id;
			int id2;

			cout << "Enter the Song number in the queue: ";
			cin >> id;
			cout << "Enter the Song number in the stack: ";
			cin >> id2;
			

			if (id != 0 && id <= queuePl.playlistSize) {
				queuePl.removeSongByID(id);
				stackPl.removeSongByID(id2);

				cout << "Songs have been deleted!" << endl;
				cout << endl;
			}
			else {
				cout << "Error! Songs with selected number does not exist" << endl;
				cout << endl;
			}

			viewSongList();
		}
		else if (selection == 3) {
			showMenu();
		}
		else {
			cout << "Error! Please Try Again" << endl;
			cout << endl;

			viewSongList();
		}
	}

	void viewAllSongs() {
		cout << " ***** SONGS PAGE ***** " << endl;

		songsL.viewAllSongs();

		int selection;

		cout << " 1) Add song" << endl;
		cout << " 2) Delete song" << endl;
		cout << " 3) Main menu" << endl;
		cout << " Enter Option: ";

		cin >> selection;
		cout << endl;

		if (selection == 1) {
			string songTitle, songArtist;
			int songYear;

			cout << "Song Title: ";
			cin >> songTitle;

			cout << "Song Artist: ";
			cin >> songArtist;

			cout << "Song Year: ";
			cin >> songYear;

			Song* song = new Song(songTitle, songArtist, songYear);

			songsL.addNewSong(song);

			viewAllSongs();
		}
		else if (selection == 2) {
			if (songsL.playlistSize == 0){

				cout << "No Songs Available" << endl;
				cout << endl;

				viewAllSongs();
			}
			else {

				int id;

				cout << "Enter Song ID to delete: ";
				cin >> id;

				songsL.removeSongByID(id);
				viewAllSongs();
			}
		}
		else if (selection == 3) {
			showMenu();
		}
		else {
			cout << "Error! Please try again" << endl;
			cout << endl;

			viewAllSongs();
		}
	}
};