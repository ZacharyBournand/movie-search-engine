#pragma once
#include <iostream>
#include <string>
#include "NodeHeapMovie.h"
using namespace std;

//Default Constructor

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
	int id,
	double north_america_users_score,
	double south_america_users_score,
	double europe_users_score,
	double asia_users_score,
	double africa_users_score,
	double australia_users_score
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
	NorthAmericaUsersScore = north_america_users_score;
	SouthAmericaUsersScore = south_america_users_score;
	EuropeUsersScore = europe_users_score;
	AsiaUsersScore = asia_users_score;
	AfricaUsersScore = africa_users_score;
	AustraliaUsersScore = australia_users_score;
	left = nullptr;
	right = nullptr;
	
}