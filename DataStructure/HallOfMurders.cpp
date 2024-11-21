// beecrowd 1861 - Hall of Murders

#include <iostream>
#include <string>
#include <map> // The basic operations of insertion, search, and removal have an average complexity of O(log N)
using namespace std;

int main() { // The complexity of the code depends on the insert/update operations on the map, O(M log N), where M is the total number of distinct entries and N is the number of keys
  string murderer; // Variable to store the murderer's name
  string victim; // Variable to store the victim's name
  map<string, int> murdererCount; // Map to store the murderer and their corresponding count of victims

  while (cin >> murderer >> victim) { 
      cin.ignore(); // Ignore any extra whitespace characters (if necessary)
    
      if (murdererCount[murderer] != -1) { // If the murderer hasn't been marked as a victim (-1), increment their victim count
          murdererCount[murderer] += 1; // Average complexity of O(log N) for map operations
      }
      murdererCount[victim] = -1; // Mark the victim in the map with -1 (indicating they are no longer a murderer)
  }

  cout << "HALL OF MURDERERS" << endl; // Print the header of the result
  for (const auto& entry : murdererCount) { // Loop through the map to output the list of murderers
      if (entry.second >= 1) { // If the murderer has killed at least one person
          cout << entry.first << " " << entry.second << endl; // Print the murderer's name and the count of their victims (O(N) complexity for this loop)
      }
  }

  return 0;
}
