#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
//#include "LinkedListMovie.h"
//#include "NodeMovie.h"
//#include "LinkedListUserRating.h"
//#include "NodeUserRating.h"
//#include "HeapMovie.h"
//#include "NodeHeapMovie.h"
//#include "HeapMovieRating.h"
//#include "NodeHeapMovieRating.h"
//#include "Graph.h"
//#include "Node.h"

using namespace std;

/*int main()
{
    // Create an instance of the linked list that contains movies and information associated to them
    //test change
    LinkedListMovie movies;

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
    double NorthAmericaUsersScore;
    double SouthAmericaUsersScore;
    double EuropeUsersScore;
    double AsiaUsersScore;
    double AfricaUsersScore;
    double AustraliaUsersScore;

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
            // Get the movie's rating in North America
            temporaryString = "";
            getline(inputStream, temporaryString, ',');
            NorthAmericaUsersScore = atof(temporaryString.c_str());
            // Get the movie's rating in South America
            temporaryString = "";
            getline(inputStream, temporaryString, ',');
            SouthAmericaUsersScore = atof(temporaryString.c_str());
            // Get the movie's rating in Europe
            temporaryString = "";
            getline(inputStream, temporaryString, ',');
            EuropeUsersScore = atof(temporaryString.c_str());
            // Get the movie's rating in Asia
            temporaryString = "";
            getline(inputStream, temporaryString, ',');
            AsiaUsersScore = atof(temporaryString.c_str());
            // Get the movie's rating in Africa
            temporaryString = "";
            getline(inputStream, temporaryString, ',');
            AfricaUsersScore = atof(temporaryString.c_str());
            // Get the movie's rating in Australia
            temporaryString = "";
            getline(inputStream, temporaryString, ',');
            AustraliaUsersScore = atof(temporaryString.c_str());

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
                Id,
                NorthAmericaUsersScore,
                SouthAmericaUsersScore,
                EuropeUsersScore,
                AsiaUsersScore,
                AfricaUsersScore,
                AustraliaUsersScore
            );

            line = "";
        }
    }


    // Create an instance of the linked list that contains user ratings of movies
    LinkedListUserRating userRating;

    int UserId;
    string MovieName;
    double Rating;

    ifstream myFile2;
    // Open the CSV file containing the data
    myFile2.open("ratings.csv");
    int counter2 = 0;

    // If the program is unable to open the CSV file, output an error message
    if (myFile2.fail()) {
        cout << "Fail" << endl;
    }

    string line2 = "";

    while (getline(myFile2, line2)) {
        string temporaryString;

        if (counter2 == 0) {
            getline(myFile2, temporaryString);
            counter2 = 1;
        }
        else {
            stringstream inputStream(line2);

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

            // Insert the user rating's information into the linked list 'userRating'
            userRating.insert(
                UserId,
                MovieName,
                Rating
            );

            line2 = "";
        }
    }



    string inputString;
    string inputString2;

    cout << "Welcome to the Movie Search Engine!" << endl;

    // Repeat new filtered movie searches as long as the user wants to by answering "yes" after the results have been displayed
    do {
        cout << endl << "Search for a movie by giving a:" << endl;
        cout << "   1 -> Specific movie title" << endl;
        cout << "or search for movies by giving a(n):" << endl;
        cout << "   2 -> Movie genre" << endl;
        cout << "   3 -> Director" << endl;
        cout << "   4 -> Duration range" << endl;
        cout << "   5 -> Actor/Actress" << endl;
        cout << "   6 -> Language" << endl;
        cout << "   7 -> Country of origin" << endl;
        cout << "   8 -> Release date range (in year)" << endl << endl;

        cout << "or search for the 100 movies with the:" << endl;
        cout << "   9 -> Greatest number of reviews" << endl;
        cout << "   10 -> Greatest number of votes" << endl;
        cout << "   11 -> Highest IMDb ratings" << endl;
        cout << "   12 -> Highest ratings in North America" << endl;
        cout << "   13 -> Highest ratings in South America" << endl;
        cout << "   14 -> Highest ratings in Europe" << endl;
        cout << "   15 -> Highest ratings in Asia" << endl;
        cout << "   16 -> Highest ratings in Africa" << endl;
        cout << "   17 -> Highest ratings in Australia" << endl << endl;

        cout << "or search for a:" << endl;
        cout << "   18 -> Movie's list of individual user ratings" << endl;

        cout << endl << endl << "Press a number between 1 & 18 to choose your filter option OR press 0 to end the program: ";
        // Get the user's input
        getline(cin, inputString);

        int input = stoi(inputString);

        switch (input) {
            case 0:
                cout << "Ending the program" << endl;
                break;
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
            case 9:
                // Ranks the 100 movies with the greatest number of reviews (in descending order)
                movies.rankByNumberOfReviews();
                break;
            case 10:
                // Ranks the 100 movies with the greatest number of votes (in descending order)
                movies.rankByVotes();
                break;
            case 11:
                // Ranks the 100 movies with the highest IMDb ratings (in descending order)
                movies.rankByImdb();
                break;
            case 12:
                // Ranks the 100 movies with the highest ratings in North America (in descending order)
                movies.rankByNorthAmericanRatings();
                break;
            case 13:
                // Ranks the 100 movies with the highest ratings in South America (in descending order)
                movies.rankBySouthAmericanRatings();
                break;
            case 14:
                // Ranks the 100 movies with the highest ratings in Europe (in descending order)
                movies.rankByEuropeanRatings();
                break;
            case 15:
                // Ranks the 100 movies with the highest ratings in Asia (in descending order)
                movies.rankByAsianRatings();
                break;
            case 16:
                // Ranks the 100 movies with the highest ratings in Africa (in descending order)
                movies.rankByAfricanRatings();
                break;
            case 17:
                // Ranks the 100 movies with the highest ratings in Australia (in descending order)
                movies.rankByAustralianRatings();
                break;
            case 18:
                // Ranks the 100 movies with the highest ratings in Australia (in descending order)
                userRating.searchMovieUserRatings();
                break;
            default:
                cout << "You entered an incorrect value. Please re-enter a correct value:" << endl;
        }

        cout << endl << endl << endl << "Would you like to do a new movie search (Yes/No)? ";

        // Get the user's input
        getline(cin, inputString2);

    } while (inputString2 == "Yes" || inputString2 == "yes");
}*/


/******************************************************************************************************************/
/******************************************************************************************************************/
/************************CODE ***********************************************************************************/
/***********************************************FOR***********************************************************/
/************************************************************************HEAP******************************/
/******************************************************************************************************************/

/******************************************************************************************************************/


    int main()
    {

    /*HeapMovie movies;

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
    double NorthAmericaUsersScore;
    double SouthAmericaUsersScore;
    double EuropeUsersScore;
    double AsiaUsersScore;
    double AfricaUsersScore;
    double AustraliaUsersScore;

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
            // Get the movie's rating in North America
            temporaryString = "";
            getline(inputStream, temporaryString, ',');
            NorthAmericaUsersScore = atof(temporaryString.c_str());
            // Get the movie's rating in South America
            temporaryString = "";
            getline(inputStream, temporaryString, ',');
            SouthAmericaUsersScore = atof(temporaryString.c_str());
            // Get the movie's rating in Europe
            temporaryString = "";
            getline(inputStream, temporaryString, ',');
            EuropeUsersScore = atof(temporaryString.c_str());
            // Get the movie's rating in Asia
            temporaryString = "";
            getline(inputStream, temporaryString, ',');
            AsiaUsersScore = atof(temporaryString.c_str());
            // Get the movie's rating in Africa
            temporaryString = "";
            getline(inputStream, temporaryString, ',');
            AfricaUsersScore = atof(temporaryString.c_str());
            // Get the movie's rating in Australia
            temporaryString = "";
            getline(inputStream, temporaryString, ',');
            AustraliaUsersScore = atof(temporaryString.c_str());

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
                Id,
                NorthAmericaUsersScore,
                SouthAmericaUsersScore,
                EuropeUsersScore,
                AsiaUsersScore,
                AfricaUsersScore,
                AustraliaUsersScore
            );

            line = "";
        }
    }*/

    /*HeapMovieRating userRating;

    int UserId;
    string MovieName;
    double Rating;

    ifstream myFile2;
    // Open the CSV file containing the data
    myFile2.open("ratings.csv");
    int counter2 = 0;

    // If the program is unable to open the CSV file, output an error message
    if (myFile2.fail()) {
        cout << "Fail" << endl;
    }

    string line2 = "";

    while (getline(myFile2, line2)) {
        string temporaryString;

        if (counter2 == 0) {
            getline(myFile2, temporaryString);
            counter2 = 1;
        }
        else {
            stringstream inputStream(line2);

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

            line2 = "";
        }
    }*/


    string inputString;
    string inputString2;

    cout << "Welcome to the Movie Search Engine!" << endl;

    // Repeat new filtered movie searches as long as the user wants to by answering "yes" after the results have been displayed
    do {
        cout << endl << "Search for a movie by giving a:" << endl;
        cout << "   1 -> Specific movie title" << endl;
        cout << "or search for movies by giving a(n):" << endl;
        cout << "   2 -> Movie genre" << endl;
        cout << "   3 -> Director" << endl;
        cout << "   4 -> Duration range" << endl;
        cout << "   5 -> Actor/Actress" << endl;
        cout << "   6 -> Language" << endl;
        cout << "   7 -> Country of origin" << endl;
        cout << "   8 -> Release date range (in year)" << endl << endl;

        //cout << "or search for the 100 movies with the:" << endl;
        //cout << "   9 -> Greatest number of reviews" << endl;
        //cout << "   10 -> Greatest number of votes" << endl;
        //cout << "   11 -> Highest IMDb ratings" << endl;
        //cout << "   12 -> Highest ratings in North America" << endl;
        //cout << "   13 -> Highest ratings in South America" << endl;
        //cout << "   14 -> Highest ratings in Europe" << endl;
        //cout << "   15 -> Highest ratings in Asia" << endl;
       // cout << "   16 -> Highest ratings in Africa" << endl;
        //cout << "   17 -> Highest ratings in Australia" << endl << endl;

        cout << "or search for a:" << endl;
        cout << "   9 -> Movie's list of individual user ratings" << endl;

        cout << endl << endl << "Press a number between 1 & 9 to choose your filter option OR press 0 to end the program: ";
        // Get the user's input
        getline(cin, inputString);

        int input = stoi(inputString);

        switch (input) {
            //case 0:
                //cout << "Ending the program" << endl;
                //break;
            //case 1:
                // Displays the information of the movie searched for
                //movies.searchMovieTitle();
                //break;
           // case 2:
                //Displays the movies in the genre searched for
                //movies.searchByGenre();
                //break;
            //case 3:
                 //Displays the movies made by a specific director searched for
               // movies.searchByDirector();
                //break;
           //case 4:
                // Displays the movies in the duration range searched for (in ascending order)
                //movies.searchByDuration();
                //break;
            //case 5:
                // Displays the movies with the actor searched for
                //movies.searchByActor();
              // break;
           // case 6:
                // Displays the movies with the language searched for
               // movies.searchByLanguage();
              // break;
          // case 7:
                // Displays the movies that come from the country searched for
                //movies.searchByCountry();
                //break;
           // case 8:
                // Displays the movies that were released in the year range searched for (in ascending order)
                //movies.searchByYear();
                //break;
            //case 9:
                // Ranks the 100 movies with the greatest number of reviews (in descending order)
                //movies.rankByNumberOfReviews();
                //break;
            //case 10:
                // Ranks the 100 movies with the greatest number of votes (in descending order)
                //movies.rankByVotes();
                //break;
            //case 9:
                // Ranks the 100 movies with the highest IMDb ratings (in descending order)
                //userRating.searchMovieUserRatings();
                //break;
            default:
                cout << "You entered an incorrect value. Please re-enter a correct value:" << endl;
        }

        cout << endl << endl << endl << "Would you like to do a new movie search (Yes/No)? ";

        // Get the user's input
        getline(cin, inputString2);

    } while (inputString2 == "Yes" || inputString2 == "yes");
   }


   /******************************************************************************************************************/
/******************************************************************************************************************/
/************************CODE ***********************************************************************************/
/***********************************************FOR***********************************************************/
/************************************************************************GRAPH******************************/
/******************************************************************************************************************/

/******************************************************************************************************************/


int main()
{
    Graph userRating;

    int UserId;
    string MovieName;
    double Rating;

    ifstream myFile2;
    // Open the CSV file containing the data
    myFile2.open("ratings.csv");
    int counter2 = 0;

    // If the program is unable to open the CSV file, output an error message
    if (myFile2.fail()) {
        cout << "Fail" << endl;
    }

    string line2 = "";

    while (getline(myFile2, line2)) {
        string temporaryString;

        if (counter2 == 0) {
            getline(myFile2, temporaryString);
            counter2 = 1;
        }
        else {
            stringstream inputStream(line2);

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
            userRating.insertRating(
                UserId,
                MovieName,
                Rating
            );

            line2 = "";
        }
    }


    string inputString;
    string inputString2;

    cout << "Welcome to the Movie Search Engine!" << endl;

    // Repeat new filtered movie searches as long as the user wants to by answering "yes" after the results have been displayed
    do {
        cout << endl << "Search for a movie by giving a:" << endl;
        
        cout << "   1 -> Movie's list of individual user ratings" << endl;

        cout << endl << endl << "Press a number between 1 & 9 to choose your filter option OR press 0 to end the program: ";
        // Get the user's input
        getline(cin, inputString);

        int input = stoi(inputString);

        switch (input) {
        
        case 1:
            // Ranks the 100 movies with the highest IMDb ratings (in descending order)
            userRating.searchMovieUserRatings();
            break;
        default:
            cout << "You entered an incorrect value. Please re-enter a correct value:" << endl;
        }

        cout << endl << endl << endl << "Would you like to do a new movie search (Yes/No)? ";

        // Get the user's input
        getline(cin, inputString2);

    } while (inputString2 == "Yes" || inputString2 == "yes");

    return 0;
}*/

    
