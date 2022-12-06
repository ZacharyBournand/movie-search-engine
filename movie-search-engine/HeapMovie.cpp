#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include "HeapMovie.h"
#include "NodeHeapMovie.h"
#include <vector>
#include <queue>
#include <cstdlib>
using namespace std;

HeapMovie::HeapMovie() 
{
	sizearray = 0;
	capacity = 5000;
	arraypointer = new NodeHeapMovie[capacity];
};

void HeapMovie::insert(string director_name,
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
	double australia_users_score)
{
	NodeHeapMovie* newNode = new NodeHeapMovie(
		director_name,
		duration,
		actor_2_name,
		genres,
		actor_1_name,
		movie_title,
		num_voted_users,
		actor_3_name,
		movie_imdb_link,
		num_user_for_reviews,
		language,
		country,
		title_year,
		imdb_score,
		id,
		north_america_users_score,
		south_america_users_score,
		europe_users_score,
		asia_users_score,
		africa_users_score,
		australia_users_score);

	insertHelper(newNode);
}

void HeapMovie::insertHelper(NodeHeapMovie* newNode)
{
	
	if (sizearray == 5000)
	{
		return;
	}
	//for map of moives
	string name = newNode->MovieTitle;
	for (int i = 0; i < name.length(); i++) 
		{
			name[i] = tolower(name[i]);
		}
	
	//for tree based heap
	mapmovies[name] = newNode;

	sizearray++;

	int index = sizearray - 1;
	arraypointer[index] = *newNode;

	

	int left = 2 * index + 1; // left = 2 * i + 1  
	int right = 2 * index + 2; // right = 2 * i + 2  
	
	int parent = (index - 1) / 2; 

	while (index != 0 && arraypointer[parent].TitleYear > arraypointer[index].TitleYear)
	{
		swap(arraypointer[index], arraypointer[parent]);
		parent = index;
	}
	
	
}



void HeapMovie::searchMovieTitle()
{
	string input;
	std::cout << "Enter the movie title: " << endl;
	getline(cin, input);
	string key;
	bool yes = false;
	for (int i = 0; i < input.length(); i++)
	{
		input[i] = tolower(input[i]);
	}
	
	NodeHeapMovie* found = mapmovies[input];
	
	for (int i = 0; i < sizearray; i++)
	{
		if (arraypointer[i].TitleYear = found->TitleYear)
		{
			yes = true;
		}
	}

	if (yes == false) 
	{
		std::cout << "Movie not found :(" << endl;
	}
	else
	{
		std::cout << endl;
		std::cout << found->MovieTitle << endl;
		std::cout << found->Duration << " minutes" << endl;
		std::cout << found->TitleYear << endl;
		std::cout << "ID: " << found->Id << endl;
		std::cout << "Actors: " << found->Actor1Name << ", " << found->Actor2Name << ", " << found->Actor3Name << endl;
		std::cout << "Director: " << found->DirectorName << endl;
		std::cout << "Genre: " << found->Genres << endl;
		std::cout << "Language: " << found->Language << endl;
		std::cout << "IMDb score: " << found->ImdbScore << "/10" << endl;
		std::cout << "IMDb link: " << found->MovieImdbLink << endl;
		
	}

}

void HeapMovie::searchByGenre()
{
	
	string input;
	std::cout << "Enter the genre: " << endl;
	getline(cin, input);
	string key;
	bool found = false;
	
	for (int i = 0; i < input.length(); i++)
	{
		input[i] = tolower(input[i]);
	}
	
	
	for (int i = 0; i < sizearray; i++)
	{
		string genre = arraypointer[i].Genres;
		for (int i = 0; i < genre.length(); i++)
		{
			genre[i] = tolower(genre[i]);
		}
		if (genre.find(input) != string::npos)
		{
			found = true;
				std::cout << endl;
				std::cout << arraypointer[i].MovieTitle << endl;
				// Display the movie's duration if it is given
				if (arraypointer[i].Duration > 0)
				{
					std::cout << arraypointer[i].Duration << " minutes" << endl;
				}
				// Display the movie's release date (in year) if it is given
				if (arraypointer[i].TitleYear > 0)
				{
					std::cout << arraypointer[i].TitleYear << endl;
				}
		}
	}
	if (found == false)
	{
		std::cout << "No movies found in this genre :(" << endl;
	}
}
void HeapMovie::searchByDirector()
{
	string input;
	std::cout << "Enter the director name: " << endl;
	getline(cin, input);
	string key;
	bool found = false;

	for (int i = 0; i < input.length(); i++)
	{
		input[i] = tolower(input[i]);
	}


	for (int i = 0; i < sizearray; i++)
	{
		string director = arraypointer[i].DirectorName;
		for (int i = 0; i < director.length(); i++)
		{
			director[i] = tolower(director[i]);
		}
		if (director.find(input) != string::npos)
		{
			found = true;
			std::cout << endl;
			std::cout << arraypointer[i].MovieTitle << endl;
			// Display the movie's duration if it is given
			if (arraypointer[i].Duration > 0)
			{
				std::cout << arraypointer[i].Duration << " minutes" << endl;
			}
			// Display the movie's release date (in year) if it is given
			if (arraypointer[i].TitleYear > 0)
			{
				std::cout << arraypointer[i].TitleYear << endl;
			}
		}
	}
	if (found == false)
	{
		std::cout << "No movies found that are made by this director :(" << endl;
	}

}

void HeapMovie::searchByDuration()
{
	string inputMaxDuration;
	string inputMinDuration;
	int maxDuration;
	int minDuration;
	bool found = false;

	std::cout << "Enter the minimum movie duration (in minutes): " << endl;
	getline(cin, inputMinDuration);

	std::cout << "Enter the maximum movie duration (in minutes): " << endl;
	getline(cin, inputMaxDuration);

	minDuration = stoi(inputMinDuration);
	maxDuration = stoi(inputMaxDuration);

	for (unsigned int i = 0; i < sizearray; i++)
	{
		if ((i + 1) == sizearray)
		{
			break;
		}
		else
		{
			if (arraypointer[i].Duration > arraypointer[i + 1].Duration)
			{
				NodeHeapMovie temp = arraypointer[i];
				arraypointer[i] = arraypointer[i + 1];
				arraypointer[i + 1] = temp;
			}
		}
		
	}

	for (unsigned int j = 0; j < sizearray; j++)
	{
		if (arraypointer[j].Duration > minDuration && arraypointer[j].Duration < maxDuration)
		{
			found = true;
			std::cout << endl;
			std::cout << arraypointer[j].MovieTitle << endl;
			// Display the movie's duration if it is given
			if (arraypointer[j].Duration > 0)
			{
				std::cout << arraypointer[j].Duration << " minutes" << endl;
			}
			// Display the movie's release date (in year) if it is given
			if (arraypointer[j].TitleYear > 0)
			{
				std::cout << arraypointer[j].TitleYear << endl;
			}
		}
		
	}
	if (found == false)
	{
		std::cout << "No movies found in this duration range :(" << endl;
	}
}



void HeapMovie::searchByActor()
{
	string input;
	std::cout << "Enter the actor/actress: " << endl;
	getline(cin, input);
	bool found = false;

	for (int i = 0; i < input.length(); i++)
	{
		input[i] = tolower(input[i]);
	}

	for (unsigned int i = 0; i < sizearray; i++)
	{
		for (int j = 0; j < arraypointer[i].Actor1Name.length(); j++) {
			arraypointer[i].Actor1Name[j] = tolower(arraypointer[i].Actor1Name[j]);
		}
		// Convert the 'Actor2Name' string to lowercase
		for (int j = 0; j < arraypointer[i].Actor2Name.length(); j++) {
			arraypointer[i].Actor2Name[j] = tolower(arraypointer[i].Actor2Name[j]);
		}// Convert the 'Actor3Name' string to lowercase
		for (int j = 0; j < arraypointer[i].Actor3Name.length(); j++) {
			arraypointer[i].Actor3Name[j] = tolower(arraypointer[i].Actor3Name[j]);
		}

		if (arraypointer[i].Actor1Name.find(input) != string::npos || arraypointer[i].Actor2Name.find(input) != string::npos || arraypointer[i].Actor3Name.find(input) != string::npos)
		{
			found = true;
			std::cout << endl;
			std::cout << arraypointer[i].MovieTitle << endl;
			// Display the movie's duration if it is given
			if (arraypointer[i].Duration > 0)
			{
				std::cout << arraypointer[i].Duration << " minutes" << endl;
			}
			// Display the movie's release date (in year) if it is given
			if (arraypointer[i].TitleYear > 0)
			{
				std::cout << arraypointer[i].TitleYear << endl;
			}
		}
	}
	if (found = false)
	{
		std::cout << "No movies found with this actor/actress :(" << endl;
	}
}

void HeapMovie::searchByLanguage()
{
	string input;
	std::cout << "Enter the language: " << endl;
	getline(cin, input);
	string key;
	bool found = false;
	for (int i = 0; i < input.length(); i++)
	{
		input[i] = tolower(input[i]);
	}


	for (int i = 0; i < sizearray; i++)
	{
		string language = arraypointer[i].Language;
		for (int i = 0; i < language.length(); i++)
		{
			language[i] = tolower(language[i]);
		}
		if (language.find(input) != string::npos)
		{
			found = true;
			std::cout << endl;
			std::cout << arraypointer[i].MovieTitle << endl;
			// Display the movie's duration if it is given
			if (arraypointer[i].Duration > 0)
			{
				std::cout << arraypointer[i].Duration << " minutes" << endl;
			}
			// Display the movie's release date (in year) if it is given
			if (arraypointer[i].TitleYear > 0)
			{
				std::cout << arraypointer[i].TitleYear << endl;
			}
		}
		
	}
	if (found == false)
	{
		std::cout << "No movies found in this language :(" << endl;
	}
}

void HeapMovie::searchByCountry()
{
	string input;
	std::cout << "Enter the country: " << endl;
	getline(cin, input);
	string key;
	bool found = false;

	for (int i = 0; i < input.length(); i++)
	{
		input[i] = tolower(input[i]);
	}

	if (input == "united states" || input == "us" || input == "u.s." || input == "u.s.a." || input == "america") {
		input = "usa";
	}
	// If the user inputs the United Kingdom with a spelling that is diferent from "uk", change the input to "uk"
	else if (input == "united kingdom" || input == "u.k." || input == "england" || input == "wales"
		|| input == "scotland" || input == "northern ireland") {
		input = "uk";
	}


	for (int i = 0; i < sizearray; i++)
	{
		string country = arraypointer[i].Country;
		for (int i = 0; i < country.length(); i++)
		{
			country[i] = tolower(country[i]);
		}
		if (country.find(input) != string::npos)
		{
			found = true;
			std::cout << endl;
			std::cout << arraypointer[i].MovieTitle << endl;
			// Display the movie's duration if it is given
			if (arraypointer[i].Duration > 0)
			{
				std::cout << arraypointer[i].Duration << " minutes" << endl;
			}
			// Display the movie's release date (in year) if it is given
			if (arraypointer[i].TitleYear > 0)
			{
				std::cout << arraypointer[i].TitleYear << endl;
			}
		}
		
	}
	if (found == false)
	{
		std::cout << "No movies found that come from this country :(" << endl;
	}
}

void HeapMovie::searchByYear()
{
	bool found = false;
	string inputMinDuration;
	string inputMaxDuration;
	std::cout << "Enter the oldest release date (in year): " << endl;
	getline(cin, inputMinDuration);

	std::cout << "Enter the most recent release date (in year): " << endl;
	getline(cin, inputMaxDuration);

	// Convert the inputs to strings
	int minDuration = stoi(inputMinDuration);
	int maxDuration = stoi(inputMaxDuration);

	for (unsigned int j = 0; j < sizearray; j++)
	{
		if (arraypointer[j].TitleYear > minDuration && arraypointer[j].TitleYear < maxDuration)
		{
			found = true;
			std::cout << endl;
			std::cout << arraypointer[j].MovieTitle << endl;
			// Display the movie's duration if it is given
			if (arraypointer[j].Duration > 0)
			{
				std::cout << arraypointer[j].Duration << " minutes" << endl;
			}
			// Display the movie's release date (in year) if it is given
			if (arraypointer[j].TitleYear > 0)
			{
				std::cout << arraypointer[j].TitleYear << endl;
			}
		}

	}
	if (found == false)
	{
		std::cout << "No movies found in this duration range :(" << endl;
	}
}

