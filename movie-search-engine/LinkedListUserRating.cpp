#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include "LinkedListMovie.h"
#include "LinkedListUserRating.h"
#include "NodeMovie.h"
#include "NodeUserRating.h"
using namespace std;

// Constructor
LinkedListUserRating::LinkedListUserRating() {
	head = nullptr;
	tail = nullptr;
};

// Insert the user rating's information into the linked list
void LinkedListUserRating::insert(
	int user_id,
	string movie_name,
	double rating
) {
	NodeUserRating* newNode = new NodeUserRating(
		user_id,
		movie_name,
		rating
	);

	// If the head is nonexistent, assign the new node to both the list's head (beginning of the list) and tail (end of the list)
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
	}
	// Otherwise set the new tail to the new node
	else {
		tail->next = newNode;
		tail = newNode;
	}
}

// Displays individual user ratings of the movie searched for
void LinkedListUserRating::searchMovieUserRatings() {
	// Initialize the head node
	NodeUserRating* temporaryNode;
	temporaryNode = head;

	// Declare the input string
	string input;
	
	// Boolean to check if the user's input matches a movie title stored in the dataset
	bool correctInput = false;
	// Boolean to check if a user rating was found for the movie searched by the user
	bool ratingFound = false;

	std::cout << "Enter the movie title: " << endl;
	// Get the user's input
	getline(cin, input);

	// Traverse through the list to find the movie searched for
	while (temporaryNode != nullptr) {
		correctInput = false;

		// If the input's length is equal to that of the movie title, proceed through
		if (input.length() == temporaryNode->MovieName.length()) {
			correctInput = true;

			// Convert the input and the movie title to lowercase & check if they are not equal
			for (int j = 0; j < input.length(); j++) {
				if (tolower(input[j]) != tolower(temporaryNode->MovieName[j])) {
					correctInput = false;
				}
			}
		}

		// If the inut matches the movie title, display the movie's individual user ratings
		if (correctInput == true) {
			std::cout << endl;
			std::cout << "User ID: " << temporaryNode->UserId << endl;
			std::cout << "Rating: " << temporaryNode->Rating << "/10" << endl;

			ratingFound = true;
		}

		// Go to the next node
		temporaryNode = temporaryNode->next;
	}

	// If the movie was not found, display an error message
	if (ratingFound == false) {
		std::cout << "No individual rating found for this movie :(" << endl;
	}
}
