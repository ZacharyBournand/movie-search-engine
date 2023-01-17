#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "linkedListSearch.cpp"
#include "minHeapMovieSearch.cpp"
#include "minHeapUserRatingsSearch.cpp"
#include "graphSearch.cpp"

using namespace std;

int main()
{
    string inputString;
    string inputString2;

    cout << "Welcome to the Movie Search Engine!" << endl;
    
    do {
        cout << endl << "Choose a data structure to perform the Movie Search Engine:" << endl;
        cout << "   1. Linked list: Get all searching filter options" << endl;
        cout << "   2. Min heap: Get the 8 movie searching filter options" << endl;
        cout << "   3. Min heap: Get 1 filter option -> A movie's individual user ratings" << endl;
        cout << "   4. Graph: Get 1 filter option -> A movie's individual user ratings" << endl;

        cout << endl << "Press a number between 1 & 4 to choose your filter option: ";

        // Get the user's input
        getline(cin, inputString);

        int input = stoi(inputString);

        switch (input) {
        case 1:
            // Displays the information of the movie searched for
            linkedListSearch();
            break;
        case 2:
            // Displays the movies in the genre searched for
            minHeapMovieSearch();
            break;
        case 3:
            // Displays the movies made by a specific director searched for
            minHeapUserRatingsSearch();
            break;
        case 4:
            // Displays the movies in the duration range searched for (in ascending order)
            graphSearch();
            break;
        default:
            cout << "You entered an incorrect value. Please re-enter a correct value:" << endl;
        }

        cout << endl << endl << endl << "Would you like to choose a data structure to perform the Movie Search Engine (Yes/No)? ";

        // Get the user's input
        getline(cin, inputString2);

    } while (inputString2 == "Yes" || inputString2 == "yes");

    return 0;
}
