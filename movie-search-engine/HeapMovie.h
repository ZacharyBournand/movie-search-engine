#pragma once
#include <iostream>
#include <string>
#include <map>
#include "NodeHeapMovie.h"
using namespace std;

//Heap that contains all the movies sorted from oldest to newest (min heap)
class HeapMovie
{
public:
	map<string, NodeHeapMovie*> mapmovies;
	NodeHeapMovie* arraypointer;
	int capacity;
	int sizearray;
	HeapMovie();
	// Insert the movie's information into the heap
	void insert(string director_name,
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

	void insertHelper(NodeHeapMovie* object);
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
	//void rankByNumberOfReviews();

	//void rankByVotes();
};