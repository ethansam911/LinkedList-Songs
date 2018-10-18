/**
Filename: Song.cpp
Name: Ethan Sam
Date: 10/17/2018 Fall 2018
Class: CSCI 235
Project: #3

This project keeps track of the number of songs in a playlist and allows for basic manipulation:
Adding; Removing; Clearing;
We utilize templates in this project. 

*/
#include "Song.h"
#include <iostream>

using namespace std;


/*
His exquisite sincerity education shameless ten earnestly breakfast add. So we me unknown as improve hastily sitting forming. Especially favourable compliment but thoroughly unreserved saw she themselves. Sufficient impossible him may ten insensible put continuing. Oppose exeter income simple few joy cousin but twenty. Scale began quiet up short wrong in in. Sportsmen shy forfeited engrossed may can. 

Lose eyes get fat shew. Winter can indeed letter oppose way change tended now. So is improve my charmed picture exposed adapted demands. Received had end produced prepared diverted strictly off man branched.own ye money so large decay voice there to. Preserved be mr cordially incommode as an. He doors quick child an point at. Had share vexed front least style off why him. 

*/

Song::Song(){}

Song::Song(const string& title, const string& author, const string& album){
	title_ = title;
	author_ = author;
	album_ = album;
}
void Song::setTitle(string title)
{
	title_ = title;
}
/*His exquisite sincerity education shameless ten earnestly breakfast add. */

void Song::setAuthor(string author){
	author_ = author;
}
/*His exquisite sincerity education shameless ten earnestly breakfast add. */
void Song::setAlbum(string album){
	album_ = album;
}
/*His exquisite sincerity education shameless ten earnestly breakfast add. */
string Song::getTitle() const{
	return title_;
}
/*His exquisite sincerity education shameless ten earnestly breakfast add. */
string Song::getAuthor() const{
	return author_;
}
/*His exquisite sincerity education shameless ten earnestly breakfast add. */
string Song::getAlbum() const{
	return album_;
}
/*His exquisite sincerity education shameless ten earnestly breakfast add. */

bool operator==(const Song& lhs, const Song& rhs) {
   if(lhs.getTitle() == rhs.getTitle() && lhs.getAuthor() == rhs.getAuthor() && rhs.getAlbum() == lhs.getAlbum()){
   	return true;
   }
   return false;
}
/*His exquisite sincerity education shameless ten earnestly breakfast add. */

