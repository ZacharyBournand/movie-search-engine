#pragma once
#include <iostream>
#include <string>
#include <chrono>
#include <cmath>
#include "NodeHeapMovieRating.h"
using namespace std;

// Linked List containing individual user ratings for specific movies
class HeapMovieRating
{
public:
	NodeHeapMovieRating* arraypointer;
	int capacity;
	int sizearray;
	

	HeapMovieRating()
	{
		sizearray = 0;
		capacity = 100000;
		arraypointer = new NodeHeapMovieRating[capacity];
	}
	// Insert the movie's information into the heap
	void insert(int user_id,
		string movie_name,
		double rating)
	{
		NodeHeapMovieRating* newNode = new NodeHeapMovieRating(user_id, movie_name, rating);
		insertHelper(newNode);
	}


	void insertHelper(NodeHeapMovieRating* object)
	{
		// Get the start time
		

		if (sizearray == 100000)
		{
			return;
		}
		

		sizearray++;

		int index = sizearray - 1;
		arraypointer[index] = *object;



		int left = 2 * index + 1; // left = 2 * i + 1  
		int right = 2 * index + 2; // right = 2 * i + 2  

		int parent = (index - 1) / 2;

		while (index != 0 && arraypointer[parent].Rating > arraypointer[index].Rating)
		{
			swap(arraypointer[index], arraypointer[parent]);
			parent = index;
		}
	}
	// Displays individual user ratings of the movie searched for
	void searchMovieUserRatings()
	{

		string input;
		std::cout << "Enter the movie title: " << endl;
		// Get the user's input

		getline(cin, input);
		auto start = chrono::steady_clock::now();

		// Get the start time
		auto start = chrono::steady_clock::now();

		bool found = false;

		for (int i = 0; i < input.length(); i++)
		{
			input[i] = tolower(input[i]);
		}

		for (int i = 0; i < sizearray; i++)
		{
			string name = arraypointer[i].MovieName;
			for (int i = 0; i < name.length(); i++)
			{
				name[i] = tolower(name[i]);
			}
			if (name.find(input) != string::npos)
			{
				found = true;
				std::cout << endl;
				std::cout << "User ID: " << arraypointer[i].UserId << endl;
				std::cout << "Rating: " << arraypointer[i].Rating << "/10" << endl;
			}
		}
		if (found == false)
		{
			std::cout << "No movies found in this genre :(" << endl;
		}

		// Get the end time
		auto end = std::chrono::steady_clock::now();

		// Find the difference
		double timeElapsed = double(chrono::duration_cast <chrono::microseconds> (end - start).count());

		// Output the time 
		cout << "Elapsed time: " << timeElapsed / pow(1, 6) << " microseconds" << endl;
	}

	
};

