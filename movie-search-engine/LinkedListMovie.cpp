#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <chrono>
#include <cmath>
#include "LinkedListMovie.h"
#include "NodeMovie.h"
using namespace std;

LinkedListMovie::LinkedListMovie() {
	head = nullptr;
	tail = nullptr;
};

// Insert the movie's information into the linked list
void LinkedListMovie::insert(
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
	NodeMovie* newNode = new NodeMovie(
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
		id
	);

	// If the head is nonexistent, assign the new node to both the list's head (beginning of the list) and tail (end of the list)
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
	}
	// Otherwise set the new tail to the new node
	else {
		tail->next = newNode;
		tail = newNode;
	}
}

// Displays the information of the movie searched for
void LinkedListMovie::searchMovieTitle() {
	NodeMovie* temporaryNode;
	temporaryNode = head;
	string input;
	bool correctInput = false;

	std::cout << "Enter the movie title: " << endl;
	// Get the user's input
	getline(cin, input);

	// Get the start time
	auto start = chrono::steady_clock::now();

	// Traverse through the list to find the movie searched for
	while (temporaryNode != nullptr) {
		correctInput = false;

		// If the input's length is equal to that of the movie title, proceed
		if (input.length() == temporaryNode->MovieTitle.length()) {
			correctInput = true;

			// Convert the input and the movie title to lowercase & check if they are not equal
			for (int j = 0; j < input.length(); j++) {
				if (tolower(input[j]) != tolower(temporaryNode->MovieTitle[j])) {
					correctInput = false;
				}
			}
		}

		// If the inut matches the movie title, display the movie's information
		if (correctInput == true) {
			std::cout << endl;
			std::cout << temporaryNode->MovieTitle << endl;
			std::cout << temporaryNode->Duration << " minnutes" << endl;
			std::cout << temporaryNode->TitleYear << endl;
			std::cout << "ID: " << temporaryNode->Id << endl;
			std::cout << "Actors: " << temporaryNode->Actor1Name << ", " << temporaryNode->Actor2Name << ", " << temporaryNode->Actor3Name << endl;
			std::cout << "Director: " << temporaryNode->DirectorName << endl;
			std::cout << "Genre: " << temporaryNode->Genres << endl;
			std::cout << "Language: " << temporaryNode->Language << endl;
			std::cout << "IMDb score: " << temporaryNode->ImdbScore << "/10" << endl;
			std::cout << "IMDb link: " << temporaryNode->MovieImdbLink << endl;
			break;
		}

		// Go to the next node
		temporaryNode = temporaryNode->next;
	}

	// If the movie was not found, display an error message
	if (correctInput == false) {
		std::cout << "Movie not found :(" << endl;
	}

	// Get the end time
	auto end = std::chrono::steady_clock::now();

	// Find the difference
	double timeElapsed = double(chrono::duration_cast <chrono::microseconds> (end - start).count());

	// Output the time 
	cout << "\nElapsed time: " << timeElapsed / pow(1, 6) << " microseconds" << endl;
}

// Displays the movies in the genre searched for
void LinkedListMovie::searchByGenre() {
	NodeMovie* temporaryNode;
	temporaryNode = head;
	string input;
	bool movieFound = false;

	std::cout << "Enter the genre: " << endl;
	getline(cin, input);

	// Get the start time
	auto start = chrono::steady_clock::now();

	// Convert the input to lowercase
	for (int i = 0; i < input.length(); i++) {
		input[i] = tolower(input[i]);
	}

	// Traverse through the list to find movies in the genre searched for
	while (temporaryNode != nullptr) {
		// Convert the 'Genres' string to lowercase
		for (int j = 0; j < temporaryNode->Genres.length(); j++) {
			temporaryNode->Genres[j] = tolower(temporaryNode->Genres[j]);
		}

		// If the movie's genre corresponds to the user's input, display its information
		if (strstr(temporaryNode->Genres.c_str(), input.c_str())) {
			std::cout << endl;
			std::cout << temporaryNode->MovieTitle << endl;
			// Display the movie's duration if it is given
			if (temporaryNode->Duration > 0) {
				std::cout << temporaryNode->Duration << " minutes" << endl;
			}
			// Display the movie's release date (in year) if it is given
			if (temporaryNode->TitleYear > 0) {
				std::cout << temporaryNode->TitleYear << endl;
			}

			movieFound = true;
		}

		temporaryNode = temporaryNode->next;
	}

	// If no movie was found in this genre, display an error message
	if (movieFound == false) {
		std::cout << "No movies found in this genre :(" << endl;
	}

	// Get the end time
	auto end = std::chrono::steady_clock::now();

	// Find the difference
	double timeElapsed = double(chrono::duration_cast <chrono::microseconds> (end - start).count());

	// Output the time 
	cout << "\nElapsed time: " << timeElapsed / pow(1, 6) << " microseconds" << endl;
}

// Displays the movies made by a specific director searched for
void LinkedListMovie::searchByDirector() {
	NodeMovie* temporaryNode;
	temporaryNode = head;
	string input;
	bool movieFound = false;

	std::cout << "Enter the director: " << endl;
	getline(cin, input);

	// Get the start time
	auto start = chrono::steady_clock::now();

	// Convert the input to lowercase
	for (int i = 0; i < input.length(); i++) {
		input[i] = tolower(input[i]);
	}

	// Traverse through the list to find movies with the director searched for
	while (temporaryNode != nullptr) {
		// Convert the 'DirectorName' string to lowercase
		for (int j = 0; j < temporaryNode->DirectorName.length(); j++) {
			temporaryNode->DirectorName[j] = tolower(temporaryNode->DirectorName[j]);
		}

		// If the movie's director corresponds to the user's input, display its information
		if (strstr(temporaryNode->DirectorName.c_str(), input.c_str())) {
			std::cout << endl;
			std::cout << temporaryNode->MovieTitle << endl;
			if (temporaryNode->Duration > 0) {
				std::cout << temporaryNode->Duration << " minutes" << endl;
			}
			if (temporaryNode->TitleYear > 0) {
				std::cout << temporaryNode->TitleYear << endl;
			}

			// Set the boolean to true to signify that a movie with the director searched for was found
			movieFound = true;
		}

		temporaryNode = temporaryNode->next;
	}

	if (movieFound == false) {
		std::cout << "No movies found that are made by this director :(" << endl;
	}

	// Get the end time
	auto end = std::chrono::steady_clock::now();

	// Find the difference
	double timeElapsed = double(chrono::duration_cast <chrono::microseconds> (end - start).count());

	// Output the time 
	cout << "\nElapsed time: " << timeElapsed / pow(1, 6) << " microseconds" << endl;
}

// Displays the movies in the duration range searched for (in ascending order)
void LinkedListMovie::searchByDuration() {
	// Initialize the head node
	NodeMovie* temporaryNode = head;

	// Declare the input strings
	string inputMinDuration;
	string inputMaxDuration;

	// Declare the node's fields
	string temporaryDirectorName;
	int temporaryDuration ;
	string temporaryActor2Name;
	string temporaryGenres;
	string temporaryActor1Name;
	string temporaryMovieTitle;
	int temporaryNumVotedUsers;
	string temporaryActor3Name;
	string temporaryMovieImdbLink;
	int temporaryNumUserForReviews;
	string temporaryLanguage;
	string temporaryCountry;
	int temporaryTitleYear;
	double temporaryImdbScore;
	int temporaryId;
	double temporaryNorthAmericaUsersScore;
	double temporarySouthAmericaUsersScore;
	double temporaryEuropeUsersScore;
	double temporaryAsiaUsersScore;
	double temporaryAfricaUsersScore;
	double temporaryAustraliaUsersScore;

	int counter = 0;
	bool movieFound = false;

	// Ask for the minimum and maximum durations
	std::cout << "Enter the minimum movie duration (in minutes): " << endl;
	getline(cin, inputMinDuration);

	std::cout << "Enter the maximum movie duration (in minutes): " << endl;
	getline(cin, inputMaxDuration);

	// Get the start time
	auto start = chrono::steady_clock::now();

	// Convert the minimum and maximum durations to strings
	int minDuration = stoi(inputMinDuration);
	int maxDuration = stoi(inputMaxDuration);

	// Set the counter to the list's number of nodes
	while (temporaryNode)
	{
		temporaryNode = temporaryNode->next;
		counter++;
	}
	temporaryNode = head;

	// Display the projected approximate load time
	std::cout << "Loading result... (20-25 sec)" << endl;

	// Iterate through the list
	for (int j = 0; j < counter; j++)
	{
		while (temporaryNode->next)
		{
			// If the node's duration field is greater than that of the next node, switch the nodes' fields
			if (temporaryNode->Duration > temporaryNode->next->Duration)
			{
				// Switch the nodes' director name field
				temporaryDirectorName = temporaryNode->DirectorName;
				temporaryNode->DirectorName = temporaryNode->next->DirectorName;
				temporaryNode->next->DirectorName = temporaryDirectorName;

				// Switch the nodes' duration field
				temporaryDuration = temporaryNode->Duration;
				temporaryNode->Duration = temporaryNode->next->Duration;
				temporaryNode->next->Duration = temporaryDuration;

				// Switch the nodes' 2nd actor name field
				temporaryActor2Name = temporaryNode->Actor2Name;
				temporaryNode->Actor2Name = temporaryNode->next->Actor2Name;
				temporaryNode->next->Actor2Name = temporaryActor2Name;

				// Switch the nodes' genre field
				temporaryGenres = temporaryNode->Genres;
				temporaryNode->Genres = temporaryNode->next->Genres;
				temporaryNode->next->Genres = temporaryGenres;

				// Switch the nodes' 1st actor name field
				temporaryActor1Name = temporaryNode->Actor1Name;
				temporaryNode->Actor1Name = temporaryNode->next->Actor1Name;
				temporaryNode->next->Actor1Name = temporaryActor1Name;

				// Switch the nodes' movie title field
				temporaryMovieTitle = temporaryNode->MovieTitle;
				temporaryNode->MovieTitle = temporaryNode->next->MovieTitle;
				temporaryNode->next->MovieTitle = temporaryMovieTitle;

				// Switch the nodes' number of votes field
				temporaryNumVotedUsers = temporaryNode->NumVotedUsers;
				temporaryNode->NumVotedUsers = temporaryNode->next->NumVotedUsers;
				temporaryNode->next->NumVotedUsers = temporaryNumVotedUsers;

				// Switch the nodes' 3rd actor name field
				temporaryActor3Name = temporaryNode->Actor3Name;
				temporaryNode->Actor3Name = temporaryNode->next->Actor3Name;
				temporaryNode->next->Actor3Name = temporaryActor3Name;

				// Switch the nodes' IMDb movie link field
				temporaryMovieImdbLink = temporaryNode->MovieImdbLink;
				temporaryNode->MovieImdbLink = temporaryNode->next->MovieImdbLink;
				temporaryNode->next->MovieImdbLink = temporaryMovieImdbLink;

				// Switch the nodes' number of reviews field
				temporaryNumUserForReviews = temporaryNode->NumUserForReviews;
				temporaryNode->NumUserForReviews = temporaryNode->next->NumUserForReviews;
				temporaryNode->next->NumUserForReviews = temporaryNumUserForReviews;

				// Switch the nodes' language field
				temporaryLanguage = temporaryNode->Language;
				temporaryNode->Language = temporaryNode->next->Language;
				temporaryNode->next->Language = temporaryLanguage;

				// Switch the nodes' country field
				temporaryCountry = temporaryNode->Country;
				temporaryNode->Country = temporaryNode->next->Country;
				temporaryNode->next->Country = temporaryCountry;

				// Switch the nodes' release date (in year) field
				temporaryTitleYear = temporaryNode->TitleYear;
				temporaryNode->TitleYear = temporaryNode->next->TitleYear;
				temporaryNode->next->TitleYear = temporaryTitleYear;

				// Switch the nodes' IMDb score field
				temporaryImdbScore = temporaryNode->ImdbScore;
				temporaryNode->ImdbScore = temporaryNode->next->ImdbScore;
				temporaryNode->next->ImdbScore = temporaryImdbScore;

				// Switch the nodes' ID field
				temporaryId = temporaryNode->Id;
				temporaryNode->Id = temporaryNode->next->Id;
				temporaryNode->next->Id = temporaryId;
			}
			else {
				// Increment the node
				temporaryNode = temporaryNode->next;
			}
		}

		// Reset temporaryNode to the head
		temporaryNode = head;
	}

	// Traverse through the list to find movies that last in the time range given by the user
	while (temporaryNode != nullptr) {
		// If the movie's duration is between the minimum and maximum durations given by the user,
		// Display the movie's information
		if (temporaryNode->Duration >= minDuration && temporaryNode->Duration <= maxDuration) {
			std::cout << endl;
			std::cout << temporaryNode->MovieTitle << endl;
			std::cout << temporaryNode->Duration << " minutes" << endl;
			if (temporaryNode->TitleYear > 0) {
				std::cout << temporaryNode->TitleYear << endl;
			}

			movieFound = true;
		}
		temporaryNode = temporaryNode->next;
	}

	if (movieFound == false) {
		std::cout << "No movies found in this duration range :(" << endl;
	}

	// Get the end time
	auto end = std::chrono::steady_clock::now();

	// Find the difference
	double timeElapsed = double(chrono::duration_cast <chrono::milliseconds> (end - start).count());

	// Output the time 
	cout << "\nElapsed time: " << timeElapsed / pow(1, 3) << " milliseconds" << endl;
}

// Displays the movies with the actor searched for
void LinkedListMovie::searchByActor() {
	NodeMovie* temporaryNode;
	temporaryNode = head;
	string input;
	bool movieFound = false;

	// Get the user's input
	std::cout << "Enter the actor/actress: " << endl;
	getline(cin, input);

	// Get the start time
	auto start = chrono::steady_clock::now();

	// Convert the input to lowercase
	for (int i = 0; i < input.length(); i++) {
		input[i] = tolower(input[i]);
	}

	// Traverse through the list to find movies with the actor/actress searched for
	while (temporaryNode != nullptr) {
		// Convert the 'Actor1Name' string to lowercase
		for (int j = 0; j < temporaryNode->Actor1Name.length(); j++) {
			temporaryNode->Actor1Name[j] = tolower(temporaryNode->Actor1Name[j]);
		}
		// Convert the 'Actor2Name' string to lowercase
		for (int j = 0; j < temporaryNode->Actor2Name.length(); j++) {
			temporaryNode->Actor2Name[j] = tolower(temporaryNode->Actor2Name[j]);
		}// Convert the 'Actor3Name' string to lowercase
		for (int j = 0; j < temporaryNode->Actor3Name.length(); j++) {
			temporaryNode->Actor3Name[j] = tolower(temporaryNode->Actor3Name[j]);
		}

		// If the movie's 1st, 2nd or 3rd actor/actress corresponds to the user input, display the movie's information
		if (strstr(temporaryNode->Actor1Name.c_str(), input.c_str()) || strstr(temporaryNode->Actor2Name.c_str(), input.c_str()) 
		|| strstr(temporaryNode->Actor3Name.c_str(), input.c_str())) {	
			std::cout << endl;
			std::cout << temporaryNode->MovieTitle << endl;
			if (temporaryNode->Duration > 0) {
				std::cout << temporaryNode->Duration << " minutes" << endl;
			}
			if (temporaryNode->TitleYear > 0) {
				std::cout << temporaryNode->TitleYear << endl;
			}

			movieFound = true;
		}

		temporaryNode = temporaryNode->next;
	}

	if (movieFound == false) {
		std::cout << "No movies found with this actor/actress :(" << endl;
	}

	// Get the end time
	auto end = std::chrono::steady_clock::now();

	// Find the difference
	double timeElapsed = double(chrono::duration_cast <chrono::microseconds> (end - start).count());

	// Output the time 
	cout << "\nElapsed time: " << timeElapsed / pow(1, 6) << " microseconds" << endl;
}

// Displays the movies with the language searched for
void LinkedListMovie::searchByLanguage() {
	NodeMovie* temporaryNode;
	temporaryNode = head;
	string input;
	// Initialize the boolean that will determine whether a movie in the language 
	// searched for was found
	bool movieFound = false;

	std::cout << "Enter the language: " << endl;
	getline(cin, input);

	// Get the start time
	auto start = chrono::steady_clock::now();

	// Convert the input to lowercase
	for (int i = 0; i < input.length(); i++) {
		input[i] = tolower(input[i]);
	}

	// Traverse through the list to find movies with the genre searched for by the user
	while (temporaryNode != nullptr) {
		// Convert the 'Genres' string to lowercase
		for (int j = 0; j < temporaryNode->Language.length(); j++) {
			temporaryNode->Language[j] = tolower(temporaryNode->Language[j]);
		}

		// If the movie's language corresponds to the user input, display the movie's information
		if (strstr(temporaryNode->Language.c_str(), input.c_str())) {
			std::cout << endl;
			std::cout << temporaryNode->MovieTitle << endl;
			if (temporaryNode->Duration > 0) {
				std::cout << temporaryNode->Duration << " minutes" << endl;
			}
			if (temporaryNode->TitleYear > 0) {
				std::cout << temporaryNode->TitleYear << endl;
			}

			movieFound = true;
		}

		temporaryNode = temporaryNode->next;
	}

	if (movieFound == false) {
		std::cout << "No movies found in this language :(" << endl;
	}

	// Get the end time
	auto end = std::chrono::steady_clock::now();

	// Find the difference
	double timeElapsed = double(chrono::duration_cast <chrono::microseconds> (end - start).count());

	// Output the time 
	cout << "\nElapsed time: " << timeElapsed / pow(1, 6) << " microseconds" << endl;
}

// Displays the movies that come from the country searched for
void LinkedListMovie::searchByCountry() {
	NodeMovie* temporaryNode;
	temporaryNode = head;
	string input;
	bool movieFound = false;

	std::cout << "Enter the country of origin: " << endl;
	getline(cin, input);

	// Get the start time
	auto start = chrono::steady_clock::now();

	// Convert the input to lowercase
	for (int i = 0; i < input.length(); i++) {
		input[i] = tolower(input[i]);
	}

	// If the user inputs the United States with a spelling that is diferent from "usa", change the input to "usa"
	if (input == "united states" || input == "us" || input == "u.s." || input == "u.s.a." || input == "america") {
		input = "usa";
	}
	// If the user inputs the United Kingdom with a spelling that is diferent from "uk", change the input to "uk"
	else if (input == "united kingdom" || input == "u.k." || input == "england" || input == "wales" 
	|| input == "scotland" || input == "northern ireland") {
		input = "uk";
	}

	// Traverse the list to find movies with the same country of origin as the user input
	while (temporaryNode != nullptr) {
		// Convert the 'Genres' string to lowercase
		for (int j = 0; j < temporaryNode->Country.length(); j++) {
			temporaryNode->Country[j] = tolower(temporaryNode->Country[j]);
		}

		// If the movie's country of origin corresponds to the user input, display the movie's information
		if (strstr(temporaryNode->Country.c_str(), input.c_str())) {
			std::cout << endl;
			std::cout << temporaryNode->MovieTitle << endl;
			if (temporaryNode->Duration > 0) {
				std::cout << temporaryNode->Duration << " minutes" << endl;
			}
			if (temporaryNode->TitleYear > 0) {
				std::cout << temporaryNode->TitleYear << endl;
			}

			movieFound = true;
		}

		temporaryNode = temporaryNode->next;
	}

	if (movieFound == false) {
		std::cout << "No movies found that come from this country :(" << endl;
	}

	// Get the end time
	auto end = std::chrono::steady_clock::now();

	// Find the difference
	double timeElapsed = double(chrono::duration_cast <chrono::microseconds> (end - start).count());

	// Output the time 
	cout << "\nElapsed time: " << timeElapsed / pow(1, 6) << " microseconds" << endl;
}

// Displays the movies that were released in the year range searched for (in ascending order)
void LinkedListMovie::searchByYear() {
	// Declare the minimum and maximum movie duration inputs
	string inputMinDuration;
	string inputMaxDuration;

	bool movieFound = false;

	// Get the user's input for the minimum and maximum durations
	std::cout << "Enter the oldest release date (in year): " << endl;
	getline(cin, inputMinDuration);

	std::cout << "Enter the most recent release date (in year): " << endl;
	getline(cin, inputMaxDuration);

	// Get the start time
	auto start = chrono::steady_clock::now();

	// Convert the inputs to strings
	int minDuration = stoi(inputMinDuration);
	int maxDuration = stoi(inputMaxDuration);
	
	// Initialize the head node
	NodeMovie* temporaryNode = head;

	// Declare the node's fields
	string temporaryDirectorName;
	int temporaryDuration;
	string temporaryActor2Name;
	string temporaryGenres;
	string temporaryActor1Name;
	string temporaryMovieTitle;
	int temporaryNumVotedUsers;
	string temporaryActor3Name;
	string temporaryMovieImdbLink;
	int temporaryNumUserForReviews;
	string temporaryLanguage;
	string temporaryCountry;
	int temporaryTitleYear;
	double temporaryImdbScore;
	int temporaryId;

	int counter = 0;
	// Set the counter to the list's number of nodes
	while (temporaryNode)
	{
		temporaryNode = temporaryNode->next;
		counter++;
	}
	temporaryNode = head;

	// Display the projected approximate load time
	std::cout << "Loading result... (~20 sec)" << endl;

	// Iterate through the list
	for (int j = 0; j < counter; j++)
	{
		while (temporaryNode->next) 
		{
			// If the node's movie release date (in year) field is greater than that of the next node, switch the nodes' fields
			if (temporaryNode->TitleYear > temporaryNode->next->TitleYear)
			{
				// Switch the nodes' director name field
				temporaryDirectorName = temporaryNode->DirectorName;
				temporaryNode->DirectorName = temporaryNode->next->DirectorName;
				temporaryNode->next->DirectorName = temporaryDirectorName;

				// Switch the nodes' duration field
				temporaryDuration = temporaryNode->Duration;
				temporaryNode->Duration = temporaryNode->next->Duration;
				temporaryNode->next->Duration = temporaryDuration;

				// Switch the nodes' 2nd actor name field
				temporaryActor2Name = temporaryNode->Actor2Name;
				temporaryNode->Actor2Name = temporaryNode->next->Actor2Name;
				temporaryNode->next->Actor2Name = temporaryActor2Name;

				// Switch the nodes' genre field
				temporaryGenres = temporaryNode->Genres;
				temporaryNode->Genres = temporaryNode->next->Genres;
				temporaryNode->next->Genres = temporaryGenres;

				// Switch the nodes' 1st actor name field
				temporaryActor1Name = temporaryNode->Actor1Name;
				temporaryNode->Actor1Name = temporaryNode->next->Actor1Name;
				temporaryNode->next->Actor1Name = temporaryActor1Name;

				// Switch the nodes' movie title field
				temporaryMovieTitle = temporaryNode->MovieTitle;
				temporaryNode->MovieTitle = temporaryNode->next->MovieTitle;
				temporaryNode->next->MovieTitle = temporaryMovieTitle;

				// Switch the nodes' number of votes field
				temporaryNumVotedUsers = temporaryNode->NumVotedUsers;
				temporaryNode->NumVotedUsers = temporaryNode->next->NumVotedUsers;
				temporaryNode->next->NumVotedUsers = temporaryNumVotedUsers;

				// Switch the nodes' 3rd actor name field
				temporaryActor3Name = temporaryNode->Actor3Name;
				temporaryNode->Actor3Name = temporaryNode->next->Actor3Name;
				temporaryNode->next->Actor3Name = temporaryActor3Name;

				// Switch the nodes' IMDb movie link field
				temporaryMovieImdbLink = temporaryNode->MovieImdbLink;
				temporaryNode->MovieImdbLink = temporaryNode->next->MovieImdbLink;
				temporaryNode->next->MovieImdbLink = temporaryMovieImdbLink;

				// Switch the nodes' number of reviews field
				temporaryNumUserForReviews = temporaryNode->NumUserForReviews;
				temporaryNode->NumUserForReviews = temporaryNode->next->NumUserForReviews;
				temporaryNode->next->NumUserForReviews = temporaryNumUserForReviews;

				// Switch the nodes' language field
				temporaryLanguage = temporaryNode->Language;
				temporaryNode->Language = temporaryNode->next->Language;
				temporaryNode->next->Language = temporaryLanguage;

				// Switch the nodes' country field
				temporaryCountry = temporaryNode->Country;
				temporaryNode->Country = temporaryNode->next->Country;
				temporaryNode->next->Country = temporaryCountry;

				// Switch the nodes' release date (in year) field
				temporaryTitleYear = temporaryNode->TitleYear;
				temporaryNode->TitleYear = temporaryNode->next->TitleYear;
				temporaryNode->next->TitleYear = temporaryTitleYear;

				// Switch the nodes' IMDb score field
				temporaryImdbScore = temporaryNode->ImdbScore;
				temporaryNode->ImdbScore = temporaryNode->next->ImdbScore;
				temporaryNode->next->ImdbScore = temporaryImdbScore;

				// Switch the nodes' ID field
				temporaryId = temporaryNode->Id;
				temporaryNode->Id = temporaryNode->next->Id;
				temporaryNode->next->Id = temporaryId;
			}
			else {
				// Increment the node
				temporaryNode = temporaryNode->next;
			}
		}

		// Reset temporaryNode to the head
		temporaryNode = head;
	}

	// Traverse the list to find movies that last within the range given by the user
	while (temporaryNode != nullptr) {
		// If the movie lasts within the user input's range, output the movie's information
		if (temporaryNode->TitleYear >= minDuration && temporaryNode->TitleYear <= maxDuration) {
			std::cout << endl;
			std::cout << temporaryNode->MovieTitle << endl;
			if (temporaryNode->Duration > 0) {
				std::cout << temporaryNode->Duration << " minutes" << endl;
			}
			std::cout << temporaryNode->TitleYear << endl;
			movieFound = true;
		}
		temporaryNode = temporaryNode->next;
	}

	if (movieFound == false) {
		std::cout << "No movies found in this duration range :(" << endl;
	}

	// Get the end time
	auto end = std::chrono::steady_clock::now();

	// Find the difference
	double timeElapsed = double(chrono::duration_cast <chrono::milliseconds> (end - start).count());

	// Output the time 
	cout << "\nElapsed time: " << timeElapsed / pow(1, 3) << " milliseconds" << endl;
}

void LinkedListMovie::rankByNumberOfReviews() {
	// Get the start time
	auto start = chrono::steady_clock::now();

	// Initialize the head node
	NodeMovie* temporaryNode = head;

	// Declare the node's fields
	string temporaryDirectorName;
	int temporaryDuration;
	string temporaryActor2Name;
	string temporaryGenres;
	string temporaryActor1Name;
	string temporaryMovieTitle;
	int temporaryNumVotedUsers;
	string temporaryActor3Name;
	string temporaryMovieImdbLink;
	int temporaryNumUserForReviews;
	string temporaryLanguage;
	string temporaryCountry;
	int temporaryTitleYear;
	double temporaryImdbScore;
	int temporaryId;

	int counter = 0;
	// Set the counter to the list's number of nodes
	while (temporaryNode)
	{
		temporaryNode = temporaryNode->next;
		counter++;
	}
	temporaryNode = head;

	// Display the projected approximate load time
	std::cout << "Loading result... (~20 sec)" << endl;
	std::cout << endl;

	// Iterate through the list
	for (int j = 0; j < counter; j++)
	{
		while (temporaryNode->next)  
		{
			// If the node's number of reviews field is greater than that of the next node, switch the nodes' fields
			if (temporaryNode->NumUserForReviews < temporaryNode->next->NumUserForReviews)
			{
				// Switch the nodes' director name field
				temporaryDirectorName = temporaryNode->DirectorName;
				temporaryNode->DirectorName = temporaryNode->next->DirectorName;
				temporaryNode->next->DirectorName = temporaryDirectorName;

				// Switch the nodes' duration field
				temporaryDuration = temporaryNode->Duration;
				temporaryNode->Duration = temporaryNode->next->Duration;
				temporaryNode->next->Duration = temporaryDuration;

				// Switch the nodes' 2nd actor name field
				temporaryActor2Name = temporaryNode->Actor2Name;
				temporaryNode->Actor2Name = temporaryNode->next->Actor2Name;
				temporaryNode->next->Actor2Name = temporaryActor2Name;

				// Switch the nodes' genre field
				temporaryGenres = temporaryNode->Genres;
				temporaryNode->Genres = temporaryNode->next->Genres;
				temporaryNode->next->Genres = temporaryGenres;

				// Switch the nodes' 1st actor name field
				temporaryActor1Name = temporaryNode->Actor1Name;
				temporaryNode->Actor1Name = temporaryNode->next->Actor1Name;
				temporaryNode->next->Actor1Name = temporaryActor1Name;

				// Switch the nodes' movie title field
				temporaryMovieTitle = temporaryNode->MovieTitle;
				temporaryNode->MovieTitle = temporaryNode->next->MovieTitle;
				temporaryNode->next->MovieTitle = temporaryMovieTitle;

				// Switch the nodes' number of votes field
				temporaryNumVotedUsers = temporaryNode->NumVotedUsers;
				temporaryNode->NumVotedUsers = temporaryNode->next->NumVotedUsers;
				temporaryNode->next->NumVotedUsers = temporaryNumVotedUsers;

				// Switch the nodes' 3rd actor name field
				temporaryActor3Name = temporaryNode->Actor3Name;
				temporaryNode->Actor3Name = temporaryNode->next->Actor3Name;
				temporaryNode->next->Actor3Name = temporaryActor3Name;

				// Switch the nodes' IMDb movie link field
				temporaryMovieImdbLink = temporaryNode->MovieImdbLink;
				temporaryNode->MovieImdbLink = temporaryNode->next->MovieImdbLink;
				temporaryNode->next->MovieImdbLink = temporaryMovieImdbLink;

				// Switch the nodes' number of reviews field
				temporaryNumUserForReviews = temporaryNode->NumUserForReviews;
				temporaryNode->NumUserForReviews = temporaryNode->next->NumUserForReviews;
				temporaryNode->next->NumUserForReviews = temporaryNumUserForReviews;

				// Switch the nodes' language field
				temporaryLanguage = temporaryNode->Language;
				temporaryNode->Language = temporaryNode->next->Language;
				temporaryNode->next->Language = temporaryLanguage;

				// Switch the nodes' country field
				temporaryCountry = temporaryNode->Country;
				temporaryNode->Country = temporaryNode->next->Country;
				temporaryNode->next->Country = temporaryCountry;

				// Switch the nodes' release date (in year) field
				temporaryTitleYear = temporaryNode->TitleYear;
				temporaryNode->TitleYear = temporaryNode->next->TitleYear;
				temporaryNode->next->TitleYear = temporaryTitleYear;

				// Switch the nodes' IMDb score field
				temporaryImdbScore = temporaryNode->ImdbScore;
				temporaryNode->ImdbScore = temporaryNode->next->ImdbScore;
				temporaryNode->next->ImdbScore = temporaryImdbScore;

				// Switch the nodes' ID field
				temporaryId = temporaryNode->Id;
				temporaryNode->Id = temporaryNode->next->Id;
				temporaryNode->next->Id = temporaryId;
			}
			else {
				// Increment the node
				temporaryNode = temporaryNode->next;
			}
		}

		// Reset temporaryNode to the head
		temporaryNode = head;
	}

	// To give the movies a rank
	int rank = 1;

	// Output the 100 movies with the greatest number of reviews (in descending order)
	for (int i = 0; i < 100; i++) {
		string number = to_string(temporaryNode->NumUserForReviews);
		// Assigns the number of digits in 'number' to 'n'
		int n = number.length();

		// If there are more than 3 digits, output the number with a comma in the right place
		if (n > 3) {
			// Get the digits that will be after the comma
			string first_half = number.substr(0, n - 3);
			int n2 = first_half.length();
			// Get the 3 digits before the comma
			string second_half = number.substr(n2, 3);

			// Display the movie's rank with its number of reviews
			std::cout << rank << ": " << temporaryNode->MovieTitle << " (" << first_half << "," << second_half << " reviews)" << endl;
		}
		else {
			// Display the movie's rank with its number of reviews
			std::cout << rank << ": " << temporaryNode->MovieTitle << " (" << temporaryNode->NumUserForReviews << " reviews)" << endl;
		}
			
		rank++;
		temporaryNode = temporaryNode->next;
	}

	// Get the end time
	auto end = std::chrono::steady_clock::now();

	// Find the difference
	double timeElapsed = double(chrono::duration_cast <chrono::milliseconds> (end - start).count());

	// Output the time 
	cout << "\nElapsed time: " << timeElapsed / pow(1, 3) << " milliseconds" << endl;
}

void LinkedListMovie::rankByVotes() {
	// Get the start time
	auto start = chrono::steady_clock::now();

	// Initialize the head node
	NodeMovie* temporaryNode = head;

	// Declare the node's fields
	string temporaryDirectorName;
	int temporaryDuration;
	string temporaryActor2Name;
	string temporaryGenres;
	string temporaryActor1Name;
	string temporaryMovieTitle;
	int temporaryNumVotedUsers;
	string temporaryActor3Name;
	string temporaryMovieImdbLink;
	int temporaryNumUserForReviews;
	string temporaryLanguage;
	string temporaryCountry;
	int temporaryTitleYear;
	double temporaryImdbScore;
	int temporaryId;

	int counter = 0;
	while (temporaryNode)
	{
		temporaryNode = temporaryNode->next;
		counter++;
	}
	temporaryNode = head;

	std::cout << "Loading result... (~20 sec)" << endl;
	std::cout << endl;

	// Iterate through the list
	for (int j = 0; j < counter; j++)
	{
		while (temporaryNode->next)
		{
			// If the node's number of votes field is greater than that of the next node, switch the nodes' fields
			if (temporaryNode->NumVotedUsers < temporaryNode->next->NumVotedUsers)
			{
				// Switch the nodes' director name field
				temporaryDirectorName = temporaryNode->DirectorName;
				temporaryNode->DirectorName = temporaryNode->next->DirectorName;
				temporaryNode->next->DirectorName = temporaryDirectorName;

				// Switch the nodes' duration field
				temporaryDuration = temporaryNode->Duration;
				temporaryNode->Duration = temporaryNode->next->Duration;
				temporaryNode->next->Duration = temporaryDuration;

				// Switch the nodes' 2nd actor name field
				temporaryActor2Name = temporaryNode->Actor2Name;
				temporaryNode->Actor2Name = temporaryNode->next->Actor2Name;
				temporaryNode->next->Actor2Name = temporaryActor2Name;

				// Switch the nodes' genre field
				temporaryGenres = temporaryNode->Genres;
				temporaryNode->Genres = temporaryNode->next->Genres;
				temporaryNode->next->Genres = temporaryGenres;

				// Switch the nodes' 1st actor name field
				temporaryActor1Name = temporaryNode->Actor1Name;
				temporaryNode->Actor1Name = temporaryNode->next->Actor1Name;
				temporaryNode->next->Actor1Name = temporaryActor1Name;

				// Switch the nodes' movie title field
				temporaryMovieTitle = temporaryNode->MovieTitle;
				temporaryNode->MovieTitle = temporaryNode->next->MovieTitle;
				temporaryNode->next->MovieTitle = temporaryMovieTitle;

				// Switch the nodes' number of votes field
				temporaryNumVotedUsers = temporaryNode->NumVotedUsers;
				temporaryNode->NumVotedUsers = temporaryNode->next->NumVotedUsers;
				temporaryNode->next->NumVotedUsers = temporaryNumVotedUsers;

				// Switch the nodes' 3rd actor name field
				temporaryActor3Name = temporaryNode->Actor3Name;
				temporaryNode->Actor3Name = temporaryNode->next->Actor3Name;
				temporaryNode->next->Actor3Name = temporaryActor3Name;

				// Switch the nodes' IMDb movie link field
				temporaryMovieImdbLink = temporaryNode->MovieImdbLink;
				temporaryNode->MovieImdbLink = temporaryNode->next->MovieImdbLink;
				temporaryNode->next->MovieImdbLink = temporaryMovieImdbLink;

				// Switch the nodes' number of reviews field
				temporaryNumUserForReviews = temporaryNode->NumUserForReviews;
				temporaryNode->NumUserForReviews = temporaryNode->next->NumUserForReviews;
				temporaryNode->next->NumUserForReviews = temporaryNumUserForReviews;

				// Switch the nodes' language field
				temporaryLanguage = temporaryNode->Language;
				temporaryNode->Language = temporaryNode->next->Language;
				temporaryNode->next->Language = temporaryLanguage;

				// Switch the nodes' country field
				temporaryCountry = temporaryNode->Country;
				temporaryNode->Country = temporaryNode->next->Country;
				temporaryNode->next->Country = temporaryCountry;

				// Switch the nodes' release date (in year) field
				temporaryTitleYear = temporaryNode->TitleYear;
				temporaryNode->TitleYear = temporaryNode->next->TitleYear;
				temporaryNode->next->TitleYear = temporaryTitleYear;

				// Switch the nodes' IMDb score field
				temporaryImdbScore = temporaryNode->ImdbScore;
				temporaryNode->ImdbScore = temporaryNode->next->ImdbScore;
				temporaryNode->next->ImdbScore = temporaryImdbScore;

				// Switch the nodes' ID field
				temporaryId = temporaryNode->Id;
				temporaryNode->Id = temporaryNode->next->Id;
				temporaryNode->next->Id = temporaryId;
			}
			else {
				// Increment the node
				temporaryNode = temporaryNode->next;
			}
		}

		// Reset temporaryNode to the head
		temporaryNode = head;
	}

	int rank = 1;

	// Output the 100 movies with the greatest number of votes (in descending order)
	for (int i = 0; i < 100; i++) {
		string number = to_string(temporaryNode->NumVotedUsers);
		int n = number.length();

		// If there are more than 6 digits, output the number with 2 commas in the right place
		if (n > 6) {
			string first_half = number.substr(0, n - 6);
			int n2 = first_half.length();
			string second_half = number.substr(n2, 3);
			int n3 = first_half.length() + second_half.length();
			string third_half = number.substr(n3, 3);

			std::cout << rank << ": " << temporaryNode->MovieTitle << " (" << first_half << "," << second_half << "," << third_half << " votes)" << endl;
		}
		// Otherwise, output the number with a comma in the right place
		else {
			string first_half = number.substr(0, 3);
			int n2 = first_half.length();
			string second_half = number.substr(n2, 3);

			std::cout << rank << ": " << temporaryNode->MovieTitle << " (" << first_half << "," << second_half << " votes)" << endl;
		}

		// Increment the rank
		rank++;
		temporaryNode = temporaryNode->next;
	}

	// Get the end time
	auto end = std::chrono::steady_clock::now();

	// Find the difference
	double timeElapsed = double(chrono::duration_cast <chrono::milliseconds> (end - start).count());

	// Output the time 
	cout << "\nElapsed time: " << timeElapsed / pow(1, 3) << " milliseconds" << endl;
}

void LinkedListMovie::rankByImdb() {
	// Get the start time
	auto start = chrono::steady_clock::now();

	// Initialize the head node
	NodeMovie* temporaryNode = head;

	// Declare the node's fields
	string temporaryDirectorName;
	int temporaryDuration;
	string temporaryActor2Name;
	string temporaryGenres;
	string temporaryActor1Name;
	string temporaryMovieTitle;
	int temporaryNumVotedUsers;
	string temporaryActor3Name;
	string temporaryMovieImdbLink;
	int temporaryNumUserForReviews;
	string temporaryLanguage;
	string temporaryCountry;
	int temporaryTitleYear;
	double temporaryImdbScore;
	int temporaryId;

	int counter = 0;
	while (temporaryNode)
	{
		temporaryNode = temporaryNode->next;
		counter++;
	}
	temporaryNode = head;

	std::cout << "Loading result... (~20 sec)" << endl;
	std::cout << endl;

	// Iterate through the list
	for (int j = 0; j < counter; j++)
	{
		while (temporaryNode->next)
		{
			// If the node's IMDb score field is greater than that of the next node, switch the nodes' fields
			if (temporaryNode->ImdbScore < temporaryNode->next->ImdbScore)
			{
				// Switch the nodes' director name field
				temporaryDirectorName = temporaryNode->DirectorName;
				temporaryNode->DirectorName = temporaryNode->next->DirectorName;
				temporaryNode->next->DirectorName = temporaryDirectorName;

				// Switch the nodes' duration field
				temporaryDuration = temporaryNode->Duration;
				temporaryNode->Duration = temporaryNode->next->Duration;
				temporaryNode->next->Duration = temporaryDuration;

				// Switch the nodes' 2nd actor name field
				temporaryActor2Name = temporaryNode->Actor2Name;
				temporaryNode->Actor2Name = temporaryNode->next->Actor2Name;
				temporaryNode->next->Actor2Name = temporaryActor2Name;

				// Switch the nodes' genre field
				temporaryGenres = temporaryNode->Genres;
				temporaryNode->Genres = temporaryNode->next->Genres;
				temporaryNode->next->Genres = temporaryGenres;

				// Switch the nodes' 1st actor name field
				temporaryActor1Name = temporaryNode->Actor1Name;
				temporaryNode->Actor1Name = temporaryNode->next->Actor1Name;
				temporaryNode->next->Actor1Name = temporaryActor1Name;

				// Switch the nodes' movie title field
				temporaryMovieTitle = temporaryNode->MovieTitle;
				temporaryNode->MovieTitle = temporaryNode->next->MovieTitle;
				temporaryNode->next->MovieTitle = temporaryMovieTitle;

				// Switch the nodes' number of votes field
				temporaryNumVotedUsers = temporaryNode->NumVotedUsers;
				temporaryNode->NumVotedUsers = temporaryNode->next->NumVotedUsers;
				temporaryNode->next->NumVotedUsers = temporaryNumVotedUsers;

				// Switch the nodes' 3rd actor name field
				temporaryActor3Name = temporaryNode->Actor3Name;
				temporaryNode->Actor3Name = temporaryNode->next->Actor3Name;
				temporaryNode->next->Actor3Name = temporaryActor3Name;

				// Switch the nodes' IMDb movie link field
				temporaryMovieImdbLink = temporaryNode->MovieImdbLink;
				temporaryNode->MovieImdbLink = temporaryNode->next->MovieImdbLink;
				temporaryNode->next->MovieImdbLink = temporaryMovieImdbLink;

				// Switch the nodes' number of reviews field
				temporaryNumUserForReviews = temporaryNode->NumUserForReviews;
				temporaryNode->NumUserForReviews = temporaryNode->next->NumUserForReviews;
				temporaryNode->next->NumUserForReviews = temporaryNumUserForReviews;

				// Switch the nodes' language field
				temporaryLanguage = temporaryNode->Language;
				temporaryNode->Language = temporaryNode->next->Language;
				temporaryNode->next->Language = temporaryLanguage;

				// Switch the nodes' country field
				temporaryCountry = temporaryNode->Country;
				temporaryNode->Country = temporaryNode->next->Country;
				temporaryNode->next->Country = temporaryCountry;

				// Switch the nodes' release date (in year) field
				temporaryTitleYear = temporaryNode->TitleYear;
				temporaryNode->TitleYear = temporaryNode->next->TitleYear;
				temporaryNode->next->TitleYear = temporaryTitleYear;

				// Switch the nodes' IMDb score field
				temporaryImdbScore = temporaryNode->ImdbScore;
				temporaryNode->ImdbScore = temporaryNode->next->ImdbScore;
				temporaryNode->next->ImdbScore = temporaryImdbScore;

				// Switch the nodes' ID field
				temporaryId = temporaryNode->Id;
				temporaryNode->Id = temporaryNode->next->Id;
				temporaryNode->next->Id = temporaryId;
			}
			else {
				// Increment the node
				temporaryNode = temporaryNode->next;
			}
		}

		// Reset temporaryNode to the head
		temporaryNode = head;
	}

	int rank = 1;

	// Display the 100 highest IMDb rated movies
	while (rank <= 100) {
		// Make sure the movie's IMDb score is between 0 and 10
		if (temporaryNode->ImdbScore >= 0 && temporaryNode->ImdbScore <= 10) {
			std::cout << rank << ". " << temporaryNode->MovieTitle << endl;
			std::cout << "IMDb score: " << temporaryNode->ImdbScore << "/10" << endl << endl;
			rank++;
		}

		temporaryNode = temporaryNode->next;
	}

	// Get the end time
	auto end = std::chrono::steady_clock::now();

	// Find the difference
	double timeElapsed = double(chrono::duration_cast <chrono::milliseconds> (end - start).count());

	// Output the time 
	cout << "\nElapsed time: " << timeElapsed / pow(1, 3) << " milliseconds" << endl;
}