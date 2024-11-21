// beecrowd 1301 - Interval Product

#include <iostream>
#include <vector>
using namespace std;

int a[100000];
int t[3 * 100000];  // Segment tree array

// Build the segment tree
void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];  // Leaf node stores the value
    } else {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);  // Left child
        build(a, v * 2 + 1, tm + 1, tr);  // Right child
        t[v] = t[v * 2] * t[v * 2 + 1];  // Internal node stores product of left and right children
    }
}

// Update the value in the segment tree
void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;  // Update the leaf node
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, new_val);  // Update left child
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val);  // Update right child
        t[v] = t[v * 2] * t[v * 2 + 1];  // Update internal node
    }
}

// Query the product of elements from index l to r
int product(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 1;  // Neutral element for multiplication
    if (l == tl && r == tr)
        return t[v];  // If the segment is completely within the range
    int tm = (tl + tr) / 2;
    return product(v * 2, tl, tm, l, min(r, tm)) * product(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);  // Combine the results from both sides
}

int main() {
    int n, k;
    vector<char> out;  // Vector to store the results of product queries

    while (cin >> n >> k) {
        out.clear();  // Clear the result vector
        int aux;
        for (int i = 0; i < n; ++i) {
            cin >> aux;
            // Store the transformed values (-1 for negative, 0 for zero, 1 for positive)
            a[i] = (aux > 0) ? 1 : (aux < 0) ? -1 : 0;
        }

        build(a, 1, 0, n - 1);  // Build the segment tree

        while (k > 0) {  // Process each command
            char command;
            cin >> command;
            if (command == 'C') {
                int pos, up, new_value;
                cin >> pos >> up;
                // Transform the value: 1 for positive, -1 for negative, 0 for zero
                new_value = (up > 0) ? 1 : (up < 0) ? -1 : 0;
                update(1, 0, n - 1, pos - 1, new_value);  // Update the segment tree
            }
            else if (command == 'P') {
                int l, r;
                cin >> l >> r;
                int result = product(1, 0, n - 1, l - 1, r - 1);  // Get the product from the segment tree
                // Convert the product result to the desired output format
                if (result > 0) {
                    out.push_back('+');
                } else if (result < 0) {
                    out.push_back('-');
                } else {
                    out.push_back('0');
                }
            }
            k -= 1;
        }

        // Output the result of all product queries
        for (int i = 0; i < out.size(); i++) {
            cout << out[i];
        }
        cout << '\n';
    }

    return 0;
}
