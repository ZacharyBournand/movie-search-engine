#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include "HeapMovie.h"
#include "NodeHeapMovie.h"
#include <vector>
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

		while (newparent != NULL && newparent->TitleYear > newNode->TitleYear) 
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

void HeapMovie::searchMovieTitle()
{
	string input;
	std::cout << "Enter the movie title: " << endl;
	getline(cin, input);
	bool correctInput = false;

	NodeHeapMovie* temp = root;
	while (temp->left != nullptr && temp->right != nullptr) 
	{
		correctInput = false;

		// If the input's length is equal to that of the movie title, proceed
		if (input.length() == temp->MovieTitle.length()) {
			correctInput = true;

			// Convert the input and the movie title to lowercase & check if they are not equal
			for (int j = 0; j < input.length(); j++) {
				if (tolower(input[j]) != tolower(temp->MovieTitle[j])) {
					correctInput = false;
				}
			}
		}

		// If the inut matches the movie title, display the movie's information
		if (correctInput == true) {
			std::cout << endl;
			std::cout << temp->MovieTitle << endl;
			std::cout << temp->Duration << " minnutes" << endl;
			std::cout << temp->TitleYear << endl;
			std::cout << "ID: " << temp->Id << endl;
			std::cout << "Actors: " << temp->Actor1Name << ", " << temp->Actor2Name << ", " << temp->Actor3Name << endl;
			std::cout << "Director: " << temp->DirectorName << endl;
			std::cout << "Genre: " << temp->Genres << endl;
			std::cout << "Language: " << temp->Language << endl;
			std::cout << "IMDb score: " << temp->ImdbScore << "/10" << endl;
			std::cout << "IMDb link: " << temp->MovieImdbLink << endl;
			break;
		}

		//traverse the tree

}