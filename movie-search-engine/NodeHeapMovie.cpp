#pragma once
#include <iostream>
#include <string>
#include "NodeHeapMovie.h"
using namespace std;

//Default Constructor
NodeHeapMovie::NodeHeapMovie()
{

};
// Constructor
NodeHeapMovie::NodeHeapMovie(
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
) {
	DirectorName = director_name;
	Duration = duration;
	Actor2Name = actor_2_name;
	Genres = genres;
	Actor1Name = actor_1_name;
	MovieTitle = movie_title;
	NumVotedUsers = num_voted_users;
	Actor3Name = actor_3_name;
	MovieImdbLink = movie_imdb_link;
	NumUserForReviews = num_user_for_reviews;
	Language = language;
	Country = country;
	TitleYear = title_year;
	ImdbScore = imdb_score;
	Id = id;
}