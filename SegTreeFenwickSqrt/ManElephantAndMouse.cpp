// beecrowd  - Man Elephant and Mouse

#include <iostream>
#include <vector>
using namespace std;

// Arrays to hold the count of each symbol for players, and the lazy propagation array
vector<int> player[3], lazy;
int players, operations;

// Function to build the segment tree
void build(int node, int start, int end) {
    if(start == end) {
        player[0][node] = 1;  // Man symbol
        player[1][node] = 0;  // Elephant symbol
        player[2][node] = 0;  // Rat symbol
    } else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        // Sum the counts of each symbol in the node
        for(int i = 0; i < 3; i++) {
            player[i][node] = player[i][2 * node] + player[i][2 * node + 1];
        }
    }
}

// Function to handle range updates using lazy propagation
void update(int node, int start, int end, int l, int r) {
    if(lazy[node] != 0) {
        int temp[3];
        // Apply lazy update to rotate the symbols
        for(int i = 0; i < 3; i++) {
            temp[(i + lazy[node]) % 3] = player[i][node];
        }
        // Update the current node
        for(int i = 0; i < 3; i++) {
            player[i][node] = temp[i];
        }
        if(start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    // Return if the range does not overlap
    if(start > r || end < l) return;
    // If the current segment is fully within the update range, apply it
    if(start >= l && end <= r) {
        int temp[3];
        for(int i = 0; i < 3; i++) {
            temp[(i + 1) % 3] = player[i][node];  // Rotate the symbols
        }
        for(int i = 0; i < 3; i++) {
            player[i][node] = temp[i];
        }
        if(start != end) {
            lazy[node * 2]++;
            lazy[node * 2 + 1]++;
        }
        return;
    }
    // Otherwise, propagate the update further down
    int mid = (start + end) / 2;
    update(node * 2, start, mid, l, r);
    update(node * 2 + 1, mid + 1, end, l, r);
    // Recalculate the values for the current node
    for(int i = 0; i < 3; i++) {
        player[i][node] = player[i][node * 2] + player[i][node * 2 + 1];
    }
}

// Function to query the counts of each symbol in a range
void query(int node, int start, int end, int l, int r, int* result) {
    if(start > r || end < l) return;
    // Apply any pending updates
    if(lazy[node] != 0) {
        int temp[3];
        for(int i = 0; i < 3; i++) {
            temp[(i + lazy[node]) % 3] = player[i][node];
        }
        for(int i = 0; i < 3; i++) {
            player[i][node] = temp[i];
        }
        if(start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    // If the current segment is fully within the query range, accumulate the results
    if(start >= l && end <= r) {
        for(int i = 0; i < 3; i++) {
            result[i] += player[i][node];
        }
        return;
    }
    // Otherwise, propagate the query to the child nodes
    int mid = (start + end) / 2;
    query(node * 2, start, mid, l, r, result);
    query(node * 2 + 1, mid + 1, end, l, r, result);
}

int main() {
    int x, y;
    char c;

    // Read input until EOF
    while(cin >> players >> operations) {
        cin.ignore();  // Ignore newline after reading the integers
        // Resize arrays to fit the number of players
        for(int i = 0; i < 3; i++) {
            player[i].assign(4 * players, 0);  // 4 * players to handle large segment tree size
        }
        lazy.assign(4 * players, 0);  // Lazy array for segment tree
        build(1, 0, players - 1);  // Build the segment tree for the players

        // Process the operations
        for(int i = 0; i < operations; i++) {
            cin >> c >> x >> y;  // Read operation and range
            if(c == 'C') {
                int res[3] = {0, 0, 0};
                query(1, 0, players - 1, x - 1, y - 1, res);  // Perform the query
                for(int j = 0; j < 3; j++) {
                    if(j != 0) cout << " ";  // Space between values
                    cout << res[j];
                }
                cout << endl;  // Output the result
            }
            if(c == 'M') {
                update(1, 0, players - 1, x - 1, y - 1);  // Perform the update
            }
        }
        cout << endl;  // Blank line after each test case
    }
    return 0;
}
