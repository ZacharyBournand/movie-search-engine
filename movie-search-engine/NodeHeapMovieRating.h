#pragma once
#include <iostream>
#include <string>
using namespace std;

// Node of the linked list
struct NodeHeapMovieRating
{
    int UserId;
    string MovieName;
    double Rating;
    //every node(movie) will have a left and a right pointer, also will have a key and a value

    // Constructor
    NodeHeapMovieRating() {};
    NodeHeapMovieRating(int user_id,
        string movie_name,
        double rating)
    {
        UserId = user_id;
        MovieName = movie_name;
        Rating = rating;
    }
};
