#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "HeapMovie.h"
#include "NodeHeapMovie.h"

using namespace std;

/* Code for min heap movie search */
inline void minHeapMovieSearch()
{
    HeapMovie movies;

    string DirectorName;
    int Duration;
    string Actor2Name;
    string Genres;
    string Actor1Name;
    string MovieTitle;
    int NumVotedUsers;
    string Actor3Name;
    string MovieImdbLink;
    int NumUserForReviews;
    string Language;
    string Country;
    int TitleYear;
    double ImdbScore;
    int Id;

    ifstream myFile;
    // Open the CSV file containing the data
    myFile.open("movie_data.csv");
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

            // Get the name of the movie's director
            getline(inputStream, DirectorName, ',');
            // Get the duration
            temporaryString = "";
            getline(inputStream, temporaryString, ',');
            Duration = atoi(temporaryString.c_str());
            // Get the 2nd actor's name
            getline(inputStream, Actor2Name, ',');
            // Get the movie's genre
            getline(inputStream, Genres, ',');
            // Get the 1st actor's name
            getline(inputStream, Actor1Name, ',');
            // Get the movie title
            getline(inputStream, MovieTitle, ',');
            // Get the number of users who voted
            temporaryString = "";
            getline(inputStream, temporaryString, ',');
            NumVotedUsers = atoi(temporaryString.c_str());
            // Get the 3rd actor's name
            getline(inputStream, Actor3Name, ',');
            // Get the link to the movie's IMDb page
            getline(inputStream, MovieImdbLink, ',');
            // Get the movie's number of reviews
            temporaryString = "";
            getline(inputStream, temporaryString, ',');
            NumUserForReviews = atoi(temporaryString.c_str());
            // Get the language
            getline(inputStream, Language, ',');
            // Get the country of origin
            getline(inputStream, Country, ',');
            // Get the movie's release date (in year)
            temporaryString = "";
            getline(inputStream, temporaryString, ',');
            TitleYear = atoi(temporaryString.c_str());
            // Get the movie's IMDb score
            temporaryString = "";
            getline(inputStream, temporaryString, ',');
            ImdbScore = atof(temporaryString.c_str());
            // Get its ID number
            temporaryString = "";
            getline(inputStream, temporaryString, ',');
            Id = atoi(temporaryString.c_str());

            // Insert the movie's information into the linked list 'movies'
            movies.insert(
                DirectorName,
                Duration,
                Actor2Name,
                Genres,
                Actor1Name,
                MovieTitle,
                NumVotedUsers,
                Actor3Name,
                MovieImdbLink,
                NumUserForReviews,
                Language,
                Country,
                TitleYear,
                ImdbScore,
                Id
            );

            line = "";
        }
    }


    string inputString;
    string inputString2;

    // Repeat new filtered movie searches as long as the user wants to by answering "yes" after the results have been displayed
    do {
        cout << endl << endl << "Search for a movie by giving a:" << endl;
        cout << "   1 -> Specific movie title" << endl;
        cout << "or search for movies by giving a(n):" << endl;
        cout << "   2 -> Movie genre" << endl;
        cout << "   3 -> Director" << endl;
        cout << "   4 -> Duration range" << endl;
        cout << "   5 -> Actor/Actress" << endl;
        cout << "   6 -> Language" << endl;
        cout << "   7 -> Country of origin" << endl;
        cout << "   8 -> Release date range (in year)" << endl << endl;


        cout << endl << endl << "Press a number between 1 & 8 to choose your filter option OR press 0 to end the program: ";
        // Get the user's input
        getline(cin, inputString);

        int input = stoi(inputString);

        switch (input) {
            case 1:
                // Displays the information of the movie searched for
                movies.searchMovieTitle();
                break;
            case 2:
                // Displays the movies in the genre searched for
                movies.searchByGenre();
                break;
            case 3:
                // Displays the movies made by a specific director searched for
                movies.searchByDirector();
                break;
           case 4:
                // Displays the movies in the duration range searched for (in ascending order)
                movies.searchByDuration();
                break;
            case 5:
                // Displays the movies with the actor searched for
                movies.searchByActor();
               break;
            case 6:
                // Displays the movies with the language searched for
                movies.searchByLanguage();
               break;
           case 7:
                // Displays the movies that come from the country searched for
                movies.searchByCountry();
                break;
            case 8:
                // Displays the movies that were released in the year range searched for (in ascending order)
                movies.searchByYear();
                break;
            default:
                cout << "You entered an incorrect value. Please re-enter a correct value:" << endl;
        }

        cout << endl << endl << endl << "Would you like to do a new movie search (Yes/No)? ";

        // Get the user's input
        getline(cin, inputString2);

    } while (inputString2 == "Yes" || inputString2 == "yes");
}