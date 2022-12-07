#pragma once
#include <iostream>
#include <string>
#include "NodeMovie.h"
using namespace std;

// Linked list that contains movies and information about them
class LinkedListMovie
{
private:
	NodeMovie* head;
	NodeMovie* tail;

public:
	LinkedListMovie();
	// Insert the movie's information into the linked list
	void insert(
		string director_name,
		int duration,
		string actor_2_name,
		string genres,
		string actor_1_name,
		string movie_title,
		int num_voted_users,
		string actor_3_name,
		string movie_imdb_link,
		int num_user_for_reviews,
		string language,
		string country,
		int title_year,
		double imdb_score,
		int id
	);
	// Displays the information of the movie searched for
	void searchMovieTitle();
	// Displays the movies in the genre searched for
	void searchByGenre();
	// Displays the movies made by a specific director searched for
	void searchByDirector();
	// Displays the movies in the duration range searched for (in ascending order)
	void searchByDuration();
	// Displays the movies with the actor searched for
	void searchByActor();
	// Displays the movies with the language searched for
	void searchByLanguage();
	// Displays the movies that come from the country searched for
	void searchByCountry();
	// Displays the movies that were released in the year range searched for (in ascending order)
	void searchByYear();
	// Ranks the 100 movies with the greatest number of reviews (in descending order)
	void rankByNumberOfReviews();
	// Ranks the 100 movies with the greatest number of votes (in descending order)
	void rankByVotes();
	// Ranks the 100 movies with the highest IMDb ratings (in descending order)
	void rankByImdb();
};