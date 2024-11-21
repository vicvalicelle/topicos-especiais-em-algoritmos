//  beecrowd 1566 - Height

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int numCities; // Number of test cases (cities)
    int numPeople; // Number of people in each city

    cin >> numCities;

    vector<vector<int>> heights(numCities); // Vector of vectors to store the heights of people for each city

    for (int i = 0; i < numCities; i++)
    {
        cin >> numPeople;

        vector<int> peopleHeights(numPeople); // Vector to store the heights of people in the current city

        // Read the heights of people in the city
        for (int j = 0; j < numPeople; j++)
        {
            cin >> peopleHeights[j];
        }

        sort(peopleHeights.begin(), peopleHeights.end()); // Sort the heights in ascending order
        heights[i] = peopleHeights; // Store the sorted heights in the corresponding city index
    }

    // Output the sorted heights for each city
    for (int i = 0; i < numCities; i++)
    {
        int size = heights[i].size(); // Get the number of people in the current city
        for (int j = 0; j < size; j++)
        {
            if (j != 0)
            {
                cout << " "; // Print a space before every height except the first
            }
            cout << heights[i][j]; // Print the height
        }
        cout << "\n"; // New line after printing heights for a city
    }

    return 0;
}
