#pragma once
#include "HashNode.h"

class HashMap
{
private:
	//number of buckets
	int bucket;
	HashNode* table;
	int sizeoftable;

	//create a hash func to map the key to a value
	int hash(int x)
	{
		//x modulo bucket size
		return x % bucket;
	}
public:
	HashMap()
	{
		bucket = 100000;
		sizeoftable = 0;
		table = new HashNode[bucket];
	}
	void insert(int user_id,
		string movie_name,
		double rating)
	{
		HashNode* newNode = new HashNode(user_id, movie_name, rating);
		insertHelper(newNode);
	}
	void insertHelper(HashNode* object)
	{
		if (find(object) != true)
		{
			sizeoftable++;
			int index = hash(object->Rating);
			table[index] = *object;
		}
		else
		{
			return;
		}
	}

	bool find(HashNode* obj)
	{
		bool found = false;
		int index = (int)obj->Rating % bucket;

		for (int i = 0; i < sizeoftable; i++)
		{
			if (i == obj->Rating)
			{
				found = true;
				return found;
			}
			
		}
		if (found == false)
		{
			return false;
		}
	}

	void searchMovieUserRatings()
	{
		string input;
		std::cout << "Enter the movie title: " << endl;
		// Get the user's input
		getline(cin, input);

		bool found = false;

		for (int i = 0; i < input.length(); i++)
		{
			input[i] = tolower(input[i]);
		}

		for (int i = 0; i < sizeoftable; i++)
		{
			string name = table[i].MovieName;
			for (int i = 0; i < name.length(); i++)
			{
				name[i] = tolower(name[i]);
			}
			if (name.find(input) != string::npos)
			{
				found = true;
				std::cout << endl;
				std::cout << "User ID: " << table[i].UserId << endl;
				std::cout << "Rating: " << table[i].Rating << "/10" << endl;
			}
		}
		if (found == false)
		{
			std::cout << "No movies found in this genre :(" << endl;
		}
	}
};

