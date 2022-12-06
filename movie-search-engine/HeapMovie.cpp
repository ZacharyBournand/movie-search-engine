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
		swap(arraypointer[parent], arraypointer[index]);
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
}
void HeapMovie::searchByDirector()
{
	string input;
	std::cout << "Enter the director name: " << endl;
	getline(cin, input);
	string key;

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

}

void HeapMovie::searchByDuration()
{
	
}



//void HeapMovie::searchByActor()
//{

//}

/*void HeapMovie::searchByLanguage()
{
	string input;
	std::cout << "Enter the language: " << endl;
	getline(cin, input);
	string key;
	for (int i = 0; i < input.length(); i++)
	{
		input[i] = tolower(input[i]);
	}

	for (auto it = mapmovies.begin(); it != mapmovies.end(); it++)
	{
		string director = it->second->Language;
		for (int i = 0; i < director.length(); i++)
		{
			director[i] = tolower(director[i]);
		}


		if (director == input)
		{
			key = it->first;
			break;
		}
	}

	NodeHeapMovie* found = searchHelper(root, mapmovies[key]->TitleYear);

	if (found == nullptr)
	{
		std::cout << "No movies found in this language :(" << endl;
	}
	else
	{
		std::cout << endl;
		std::cout << found->MovieTitle << endl;
		// Display the movie's duration if it is given
		if (found->Duration > 0)
		{
			std::cout << found->Duration << " minutes" << endl;
		}
		// Display the movie's release date (in year) if it is given
		if (found->TitleYear > 0)
		{
			std::cout << found->TitleYear << endl;
		}
	}
}

//void HeapMovie::searchByCountry()
//{
//
//}

//void HeapMovie::searchByYear()
//{

//}*/