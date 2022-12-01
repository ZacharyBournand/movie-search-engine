#pragma once
#include <iostream>
#include <string>
#include "NodeUserRating.h"
using namespace std;

// Constructor
NodeUserRating::NodeUserRating(
	int user_id,
	string movie_name,
	double rating
) {
	UserId = user_id;
	MovieName = movie_name;
	Rating = rating;
}