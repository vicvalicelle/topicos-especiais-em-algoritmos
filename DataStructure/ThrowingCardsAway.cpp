// beecrowd 1110 - Throwing Cards Away

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
  int number; // Variable to store the number of cards (n)
  queue<int> q; // Queue to represent the stack of cards
  vector<int> discardedCards; // Vector to store the sequence of discarded cards
  vector<int> remainingCards; // Vector to store the remaining card

    while (true) { // Time complexity of O(N), as the operations continue while the queue is not empty
    cin >> number;

    // Exit the loop if the input number is 0
    if (number == 0) {
      break;
    }

    // Add all numbers from 1 to the number 'n' to the queue
    for (int i = 1; i <= number; ++i) {
      q.push(i); // Time complexity for push is typically O(1)
    }

    while (!q.empty()) { // Time complexity for empty is typically O(1)
        int card = q.front(); // Temporarily store the first card in the queue
        q.pop(); // Time complexity for pop is typically O(1)
        discardedCards.push_back(card); // Add the first card to the discarded list

        if (!q.empty()) { 
            // Get the next card to move to the back of the queue
            card = q.front(); // Time complexity for front is typically O(1)
            remainingCards.push_back(card); // Add the card to the remaining cards
            q.pop(); // Remove the card from the queue
        }

        if(!q.empty()){
            // Reinitialize the queue 'q' with the remaining cards
            for (const auto& newCard : remainingCards) {
                q.push(newCard);
            }

            // Clear the remaining cards vector for the next iteration
            remainingCards.clear();
        }
    }
    
      // Print the discarded cards vector
      cout << "Discarded cards: ";
      for (int i = 0; i < discardedCards.size(); ++i) {
        if (i > 0) {
          cout << ", ";
        }
        cout << discardedCards[i];
      }
      cout << endl;
      // Clear the discarded cards vector for the next iteration
      discardedCards.clear();
      
      // Print the remaining card
      cout << "Remaining card: ";
      for (int i = 0; i < remainingCards.size(); ++i) {
        cout << remainingCards[i];
      }
      cout << endl;
      // Clear the remaining cards vector for the next iteration
      remainingCards.clear();
    }
  
  return 0;
}
