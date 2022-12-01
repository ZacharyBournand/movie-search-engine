#pragma once
#include <iostream>
#include <string>
using namespace std;

// Node of the linked list
class NodeUserRating
{
public:
    int UserId;
    string MovieName;
    double Rating;

    NodeUserRating* next;
    // Constructor
    NodeUserRating(int, string, double);
};