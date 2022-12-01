#pragma once
#include <iostream>
#include <string>
#include "NodeUserRating.h"
using namespace std;

// Linked List containing individual user ratings for specific movies
class LinkedListUserRating
{
private:
	NodeUserRating* head;
	NodeUserRating* tail;

public:
	LinkedListUserRating();
	// Insert the user rating's information into the linked list
	void insert(
		int user_id,
		string movie_name,
		double rating
	);
	// Displays individual user ratings of the movie searched for
	void searchMovieUserRatings();
};
