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
	count = 0;
	root = nullptr;
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

	//for map of moives
	string name = newNode->MovieTitle;
	for (int i = 0; i < name.length(); i++) 
		{
			name[i] = tolower(name[i]);
		}
	mapmovies[name] = newNode;
	//for tree based heap
	
	if (root == nullptr)
	{
		root = newNode;
		root->left = nullptr;
		root->right = nullptr;
		root->parent = nullptr;
	}
	else if (root != nullptr)
	{
		NodeHeapMovie* newparent = root;
	

		while (newparent->left != nullptr && newparent->right != nullptr)
		{
			int random = rand();
			if (random % 2 != 0)
			{
				newparent = newparent->right;
			}
			else if (random % 2 == 0)
			{
				newparent = newparent->left;
			}
		}

		//with new parent variable we can now insert the newnode as a child of the parent

		if (newparent->left != nullptr)
		{
			newparent->right = newNode;
		}
		else if (newparent->right != nullptr)
		{
			newparent->left = newNode;
		}

		newNode->parent = newparent;

		//once parent is set, we need to do swaps for making this heap a min heap
		int year;

		while (newparent != nullptr && newparent->TitleYear > newNode->TitleYear) 
		{
			year = newparent->TitleYear;

			//swap year for the nodes
			newparent->TitleYear = newNode->TitleYear;
			newNode->TitleYear = year;
			
			//swap the parents
			//new node will swithc with new parent and new parent will be equal to new nodes parent
			newNode = newparent;
			newparent = newNode->parent;
		}

	}
}

NodeHeapMovie* HeapMovie::searchHelper(NodeHeapMovie* root, int year)
	{
		queue<NodeHeapMovie*> q;
		q.push(root);
		bool found = false;
		//if level = 0, then the root is the level i need and i just return that
		if (root == nullptr)
		{
			cout << "unsuccessful" << endl;
		}
		else
		{
			while (!q.empty())
			{
				//hold a sum variable for the sums of each level, then find the size of the queue based on how many objects are in it

				int size = q.size();

				//iterate through the size of the queue, once i finish the size of the queue itll add up the values on each of the levels by going to
				//nodes->right and nodes->left conditionally if it is not nullptr
				for (unsigned int i = 0; i < size; i++)
				{

					NodeHeapMovie* current = q.front();
					q.pop();

					//if current->val is the value i need then print out theior name
					if (current->TitleYear == year)
					{
						found = true;
						return current;
					}
					else
					{
						if (current->left != nullptr)
							q.push(current->left);
						if (current->right != nullptr)
							q.push(current->right);
					}
				}
			}
			if (found == false)
			{
				
				return nullptr;
			}

		}
	}

void HeapMovie::searchMovieTitle()
{
	string input;
	std::cout << "Enter the movie title: " << endl;
	getline(cin, input);
	for (int i = 0; i < input.length(); i++)
	{
		input[i] = tolower(input[i]);
	}
	
	NodeHeapMovie* found = searchHelper(root, mapmovies[input]->TitleYear);

	if (found == nullptr) 
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
	for (auto it = mapmovies.begin(); it != mapmovies.end(); it++)
	{
		string genre = it->second->Genres;
		for (int i = 0; i < genre.length(); i++)
		{
			genre[i] = tolower(genre[i]);
		}


		if (genre == input)
		{
			key = it->first;
			break;
		}
	}

	NodeHeapMovie* found = searchHelper(root, mapmovies[key]->TitleYear);

	if (found == nullptr)
	{
		std::cout << "Genre not found :(" << endl;
	}
	// Traverse through the list to find movies in the genre searched for
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