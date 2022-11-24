#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "MovieInformation.h"
using namespace std;

int main()
{
    ifstream myFile;
    myFile.open("movie_data.csv"); 

    if (myFile.fail()) {
        cout << "Fail" << endl;
    }

    vector<MovieInformation> movies;

    string line = "";

    while (getline(myFile, line)) {
        stringstream inputStream(line);

        string director_name;
        int duration;
        string actor_2_name;
        string genres;
        string actor_1_name;
        string movie_title;
        int num_voted_users;
        string actor_3_name;
        string movie_imdb_link;
        int num_user_for_reviews;
        string language;
        string country;
        int title_year;
        double imdb_score;
        int id;
        int north_america_users_score;
        int south_america_users_score;
        int europe_users_score;
        int asia_users_score;
        int africa_users_score;
        int australia_users_score;
        string temporaryString;

        // Get the director_name
        getline(inputStream, director_name, ',');
        // Get the duration
        temporaryString = "";
        getline(inputStream, temporaryString, ',');
        duration = atoi(temporaryString.c_str());
        // Get the actor_2_name
        getline(inputStream, actor_2_name, ',');
        // Get the genres
        getline(inputStream, genres, ',');
        // Get the actor_1_name
        getline(inputStream, actor_1_name, ',');
        // Get the movie_title
        getline(inputStream, movie_title, ',');
        // Get the num_voted_users
        temporaryString = "";
        getline(inputStream, temporaryString, ',');
        num_voted_users = atoi(temporaryString.c_str());
        // Get the actor_3_name
        getline(inputStream, actor_3_name, ',');
        // Get the movie_imdb_link
        getline(inputStream, movie_imdb_link, ',');
        // Get the num_user_for_reviews
        temporaryString = ""; 
        getline(inputStream, temporaryString, ',');
        num_user_for_reviews = atoi(temporaryString.c_str());
        // Get the language
        getline(inputStream, language, ',');
        // Get the country
        getline(inputStream, country, ',');
        // Get the title_year
        temporaryString = "";
        getline(inputStream, temporaryString, ',');
        title_year = atoi(temporaryString.c_str());
        // Get the imdb_score
        temporaryString = "";
        getline(inputStream, temporaryString, ',');
        imdb_score = atof(temporaryString.c_str());
        // Get the id
        temporaryString = "";
        getline(inputStream, temporaryString, ',');
        id = atoi(temporaryString.c_str());
        // Get the north_america_users_score
        temporaryString = "";
        getline(inputStream, temporaryString, ',');
        north_america_users_score = atoi(temporaryString.c_str());
        // Get the south_america_users_score
        temporaryString = "";
        getline(inputStream, temporaryString, ',');
        south_america_users_score = atoi(temporaryString.c_str());
        // Get the europe_users_score
        temporaryString = "";
        getline(inputStream, temporaryString, ',');
        europe_users_score = atoi(temporaryString.c_str());
        // Get the asia_users_score
        temporaryString = "";
        getline(inputStream, temporaryString, ',');
        asia_users_score = atoi(temporaryString.c_str());
        // Get the africa_users_score
        temporaryString = "";
        getline(inputStream, temporaryString, ',');
        africa_users_score = atoi(temporaryString.c_str());
        // Get the australia_users_score
        temporaryString = "";
        getline(inputStream, temporaryString, ',');
        australia_users_score = atoi(temporaryString.c_str());

        MovieInformation movie(
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
            australia_users_score
        );

        movies.push_back(movie);

        line = "";
    }

    for (auto movie : movies) {
        cout << endl;
        movie.display();
    }

    return 0;
}
