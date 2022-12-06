#pragma once
#include <iostream>
#include <string>
using namespace std;

// Node of the linked list
struct NodeHeapMovie
{
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

    //every node(movie) will have a left and a right pointer, also will have a key and a value
    
    // Constructor
    NodeHeapMovie();
    NodeHeapMovie(string, int, string, string, string, string, int, string, string, int, string, string, int, double, int, double, double, double, double, double, double);
};
