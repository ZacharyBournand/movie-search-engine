#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MovieInformation {
public:
    // Constructor
    MovieInformation(
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
        int id,
        int north_america_users_score,
        int south_america_users_score,
        int europe_users_score,
        int asia_users_score,
        int africa_users_score,
        int australia_users_score
    ) {
        DirectorName = director_name;
        Duration = duration;
        Actor2Name = actor_2_name;
        Genres = genres;
        Actor1Name = actor_1_name;
        MovieTitle = movie_title;
        NumVotedUsers = num_voted_users;
        Actor3Name = actor_3_name;
        MovieImdbLink = movie_imdb_link;
        NumUserForReviews = num_user_for_reviews;
        Language = language;
        Country = country;
        TitleYear = title_year;
        ImdbScore = imdb_score;
        Id = id;
        NorthAmericaUsersScore = north_america_users_score;
        SouthAmericaUsersScore = south_america_users_score;
        EuropeUsersScore = europe_users_score;
        AsiaUsersScore = asia_users_score;
        AfricaUsersScore = africa_users_score;
        AustraliaUsersScore = australia_users_score;
    }


    void display() {
        cout << " Director name: " << DirectorName << endl;
        cout << " Duration: " << Duration << endl;
        cout << " Actor 2 name: " << Actor2Name << endl;
        cout << " Genres: " << Genres << endl;
        cout << " Actor 1 name: " << Actor1Name << endl;
        cout << " Movie title: " << MovieTitle << endl;
        cout << " Number of voted users: " << NumVotedUsers << endl;
        cout << " Actor 3 name: " << Actor3Name << endl;
        cout << " Movie IMDb link: " << MovieImdbLink << endl;
        cout << " Num user for reviews: " << NumUserForReviews << endl;
        cout << " Language: " << Language << endl;
        cout << " Country: " << Country << endl;
        cout << " Title year: " << TitleYear << endl;
        cout << " ID: " << Id << endl;
        cout << " North American users' average score: " << NorthAmericaUsersScore << endl;
        cout << " South American users' average score: " << SouthAmericaUsersScore << endl;
        cout << " European users' average score: " << EuropeUsersScore << endl;
        cout << " Asian users' average score: " << AsiaUsersScore << endl;
        cout << " African users' average score: " << AfricaUsersScore << endl;
        cout << " Australian users' average score: " << AustraliaUsersScore << endl;
    }

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
    int NorthAmericaUsersScore;
    int SouthAmericaUsersScore;
    int EuropeUsersScore;
    int AsiaUsersScore;
    int AfricaUsersScore;
    int AustraliaUsersScore;
};