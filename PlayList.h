/*

Filename: PlayList.h
Name: Ethan Sam
Date: 10/17/2018 Fall 2018
Class: CSCI 235
Project: #3

This project keeps track of the number of songs in a playlist and allows for basic manipulation:
Adding; Removing; Clearing;
We utilize templates in this project. 

*/

#ifndef _PLAYLIST_H_
#define _PLAYLIST_H_
#include "LinkedSet.h"
#include "Node.h"

using namespace std;

class PlayList : public LinkedSet<Song>
{

public:
	PlayList();                     //default constructor 

    PlayList(const Song& a_song);   //parameterized constructor
    
    PlayList(const PlayList& a_play_list); // copy constructor
    
    ~PlayList();
    
    bool add(const Song& new_song) override;
    
    bool remove(const Song& a_song) override;
    
    // post: previous_ptr is null if target is not in PlayList or if target is the

    // first node, otherwise it points to the node preceding target

    // return: either a pointer to the node containing target

    // or the null pointer if the target is not in the PlayList.

    Node<Song>* getPointerTo(const Song& target, Node<Song>*& previous_ptr) const;
    
     void loop();    
    
     void unloop();

     void displayPlayList();

private:
	Node<Song>* tail_ptr_; // Pointer to last node
	Node<Song>* getPointerToLastNode() const;
};
#endif