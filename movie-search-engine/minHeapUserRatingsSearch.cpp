#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "HeapMovie.h"
#include "NodeHeapMovie.h"
#include "HeapMovieRating.h"
#include "NodeHeapMovieRating.h"

/* Code for min heap user ratings search */
inline void minHeapUserRatingsSearch() 
{
    HeapMovieRating userRating;

    int UserId;
    string MovieName;
    double Rating;

    ifstream myFile;
    // Open the CSV file containing the data
    myFile.open("ratings.csv");
    int counter = 0;

    // If the program is unable to open the CSV file, output an error message
    if (myFile.fail()) {
        cout << "Fail" << endl;
    }

    string line = "";

    while (getline(myFile, line)) {
        string temporaryString;

        if (counter == 0) {
            getline(myFile, temporaryString);
            counter = 1;
        }
        else {
            stringstream inputStream(line);

            // Get the user ID
            temporaryString = "";
            getline(inputStream, temporaryString, ',');
            UserId = atoi(temporaryString.c_str());
            // Get the movie title
            getline(inputStream, MovieName, ',');
            // Get the user's rating
            temporaryString = "";
            getline(inputStream, temporaryString, ',');
            Rating = atof(temporaryString.c_str());

            // Insert the user rating's information into the Heap 'userRating'
            userRating.insert(
                UserId,
                MovieName,
                Rating
            );

            line = "";
        }
    }


    string inputString;
    string inputString2;

    // Repeat new filtered movie searches as long as the user wants to by answering "yes" after the results have been displayed
    do {
        cout << endl << endl << "Search for a Movie's list of individual user ratings" << endl;
        userRating.searchMovieUserRatings();

        cout << endl << endl << endl << "Would you like to do a new movie search (Yes/No)? ";

        // Get the user's input
        getline(cin, inputString2);

      } while (inputString2 == "Yes" || inputString2 == "yes");
}