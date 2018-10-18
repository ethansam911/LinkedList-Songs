/**
Filename: PlayList.cpp
Name: Ethan Sam
Date: 10/17/2018 Fall 2018
Class: CSCI 235
Project: #3

This project keeps track of the number of songs in a playlist and allows for basic manipulation:
Adding; Removing; Clearing;
We utilize templates in this project. 

*/
#include "PlayList.h"
#include <iostream>
using namespace std;

PlayList::PlayList(): tail_ptr_(nullptr) {}

PlayList::PlayList(const Song& a_song){
	add(a_song);
}

PlayList::PlayList(const PlayList& a_play_list) : LinkedSet<Song>(a_play_list)
{//at least one node if this is true
			tail_ptr_ = getPointerToLastNode();
	
}


//LinkedSet<ItemType>::clear() = new PLaylist::clear();

bool PlayList::remove(const Song& a_song) {
	
//We use this syntax	
	Node<Song> * previous_ptr = nullptr;
	Node<Song> * node_to_delete_ptr = getPointerTo(a_song, previous_ptr);


 //    // node not present , simply return false
	if (node_to_delete_ptr == NULL){
	    return false;
	}
	else{
		// if a_song is the first node....previous is null
		if(previous_ptr == NULL){
			// make headptr point to the next item
			head_ptr_ = node_to_delete_ptr->getNext();
			
			//make noddetodel point to nullptr
			node_to_delete_ptr ->setNext(nullptr);
			
			//delete asong
			delete node_to_delete_ptr;
			
			//node to delptr = nullptr
			
			node_to_delete_ptr = nullptr;
			item_count_--;
			return true;
		}
		else{
			
			
			if(node_to_delete_ptr->getNext() == NULL){
				tail_ptr_=previous_ptr;
				//previous_ptr->setNext(nullptr);
				previous_ptr -> setNext(node_to_delete_ptr->getNext());
				//make node to del point to nullptr
				node_to_delete_ptr ->setNext(nullptr);
				//delete the node
				delete node_to_delete_ptr;
				//nodetodel = nullptr
				node_to_delete_ptr = nullptr;
				item_count_--;
				return true;
			}
			else{
				//set the previous node to the node after node todel
				previous_ptr -> setNext(node_to_delete_ptr->getNext());
				//make node to del point to nullptr
				node_to_delete_ptr ->setNext(nullptr);
				//delete the node
				delete node_to_delete_ptr;
				//nodetodel = nullptr
				node_to_delete_ptr = nullptr;
				item_count_--;
				return true;
			}
		}
	}
}



bool PlayList::add(const Song& new_song) {

	if(!contains(new_song)){
		Node<Song>* next_node_ptr = new Node<Song>();
    	next_node_ptr->setItem(new_song);
    	//next_node_ptr->setNext(tail_ptr_);
    	if(tail_ptr_ != nullptr){
	      	// get the last node and make it point to new node
	    	tail_ptr_->setNext(next_node_ptr);
    	}
    	else{
    			head_ptr_ = next_node_ptr;
    		}

       	// make new no0de point to nullptr
    	next_node_ptr->setNext(nullptr);
       	// update tailptr
    	tail_ptr_ = next_node_ptr;          
    	item_count_++;
	
		return true;
	}

	return false;
}

Node<Song>* PlayList::getPointerTo(const Song& target, Node<Song>*& previous_ptr) const{
	bool found = false;
   Node<Song>* current_ptr = head_ptr_;
   
   
   while (!found && (current_ptr != nullptr))
   {
      if (target == current_ptr->getItem()){
         found = true;
      
     	return current_ptr;
     }
      else
      	previous_ptr = current_ptr;
         current_ptr = current_ptr->getNext();
   } // end while
   
   return nullptr;
  
}

Node<Song>* PlayList::getPointerToLastNode() const{
	bool found = false;
	Node<Song>* traveling_ptr = head_ptr_;
	while (!found){
		if(traveling_ptr -> getNext() == nullptr){
			found = true;
			return traveling_ptr;
		}
		else{
			traveling_ptr = traveling_ptr->getNext();
		}
	}
	return traveling_ptr;
}
void PlayList::loop(){
	Node<Song>* last_ptr = getPointerToLastNode();
    last_ptr->setNext(head_ptr_);
}

//The tail_ptr_ points to setNext(nullptr)
void PlayList::unloop(){
	tail_ptr_ -> setNext(nullptr);
}

void PlayList::displayPlayList(){
	//LinkedSet<Song> vec = toVector();
	for(int i = 0; i < item_count_; i++){
		cout << "* Title:" << " " << toVector()[i].getTitle() << " " <<"*" <<   " Author:" << " "
		<< toVector()[i].getAuthor() << " "<< "* Album:" << " " << toVector()[i].getAlbum() << " *" << endl;
	}
	cout << "End of playlist" << endl;
}


PlayList::~PlayList(){
	unloop();
}






