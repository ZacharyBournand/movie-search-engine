#pragma once
#include "Node.h"
#include <list>
#include <vector>
#include<map>

class Graph
{
private:
	map <string, vector<pair<string, int>>> user;
	int vertices;

public:
	Graph()
	{
		vertices = 0;
	}
	
	void insertRating(int user_id,
		string movie_name,
		double rating)
	{
		Node* newNode = new Node(user_id, movie_name, rating);
		insertLink(newNode, newNode->UserId, newNode->MovieName);
	}
	void insertLink(Node* object, int userid, string movie)
	{
		string userfrom = to_string(userid);
		user[movie].push_back(make_pair(userfrom, object->Rating));

		
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

		for (auto it = user.begin(); it != user.end(); it++)
		{
			for (int i = 0; i < user[it->first].size(); i++)
			{
				string name = it->first;
				for (int i = 0; i < name.length(); i++)
				{
					name[i] = tolower(name[i]);
				}
				if (name.find(input) != string::npos)
				{
					found = true;
					std::cout << endl;
					std::cout << "User ID: " << it->second.at(i).first << endl;
					std::cout << "Rating: " << it->second.at(i).second << "/10" << endl;
				}
			}
			
		}
			
		
		if (found == false)
		{
			std::cout << "No movies found in this genre :(" << endl;
		}
	}

	
};

