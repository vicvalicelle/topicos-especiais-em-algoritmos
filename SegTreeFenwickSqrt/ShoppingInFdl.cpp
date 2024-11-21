// beecrowd 2531 - ShoppingInFdl
// Time limit exceeded

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5;
int segtree_max[4*MAXN], segtree_min[4*MAXN], lazy[4*MAXN];

// Function to build the segment tree
void build(vector<int>& price, int node, int start, int end) {
    lazy[node] = 0;
   // If it is a leaf node, set max and min values
    if(start == end) {
        segtree_max[node] = price[start];
        segtree_min[node] = price[start];
    } else {
        int mid = (start + end) / 2;
        build(price, 2*node, start, mid);
        build(price, 2*node+1, mid+1, end);
        // Set the current node's max and min values
        segtree_max[node] = max(segtree_max[2*node], segtree_max[2*node+1]);
        segtree_min[node] = min(segtree_min[2*node], segtree_min[2*node+1]);
    }
}

// Function to update the price in a range with lazy propagation
void update_range(int node, int start, int end, int l, int r, int val) {
    // If there is a pending update, apply it
    if(lazy[node] != 0) {
        segtree_max[node] += lazy[node];
        segtree_min[node] += lazy[node];
        if(start != end) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    // If the current segment is completely outside the range to update
    if(start > end || start > r || end < l)
        return;
    // If the current segment is completely inside the range to update
    if(start >= l && end <= r) {
        segtree_max[node] += val;
        segtree_min[node] += val;
        if(start != end) {
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    // If the current segment overlaps the range to update
    int mid = (start + end) / 2;
    update_range(node*2, start, mid, l, r, val);
    update_range(node*2 + 1, mid + 1, end, l, r, val);
    // Update the current node's max and min values after changes
    segtree_max[node] = max(segtree_max[node*2], segtree_max[node*2+1]);
    segtree_min[node] = min(segtree_min[node*2], segtree_min[node*2+1]);
}

// Function to query the maximum price in a range
int query_max(int node, int start, int end, int l, int r) {
    // If the current segment is completely outside the query range
    if(start > end || start > r || end < l)
        return -1e9; // return a very low value
    // Apply any pending updates
    if(lazy[node] != 0) {
        segtree_max[node] += lazy[node];
        segtree_min[node] += lazy[node];
        if(start != end) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    // If the current segment is completely inside the query range
    if(start >= l && end <= r)
        return segtree_max[node];
    // If the current segment overlaps the query range
    int mid = (start + end) / 2;
    int left = query_max(node*2, start, mid, l, r);
    int right = query_max(node*2 + 1, mid + 1, end, l, r);
    return max(left, right);
}

// Function to query the minimum price in a range
int query_min(int node, int start, int end, int l, int r) {
    // If the current segment is completely outside the query range
    if(start > end || start > r || end < l)
        return 1e9; // return a very high value
    // Apply any pending updates
    if(lazy[node] != 0) {
        segtree_max[node] += lazy[node];
        segtree_min[node] += lazy[node];
        if(start != end) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    // If the current segment is completely inside the query range
    if(start >= l && end <= r)
        return segtree_min[node];
    // If the current segment overlaps the query range
    int mid = (start + end) / 2;
    int left = query_min(node*2, start, mid, l, r);
    int right = query_min(node*2 + 1, mid + 1, end, l, r);
    return min(left, right);
}

int main() {
    int n, q;
   // Read input until EOF
    while(cin >> n) {
        cin.ignore();
        vector<int> price(n);
        // Read the prices
        for(int i = 0; i < n; i++) {
            cin >> price[i];
        }
        // Build the segment tree
        build(price, 1, 0, n-1);
        cin >> q;
        // Process each query
        for(int i = 0; i < q; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            if(x == 1) {
                // Update the price in the store
                update_range(1, 0, n-1, y-1, y-1, z - query_max(1, 0, n-1, y-1, y-1));
            }
            if(x == 2) {
                // Query the price difference between two stores
                int max_val = query_max(1, 0, n-1, y-1, z-1);
                int min_val = query_min(1, 0, n-1, y-1, z-1);
                cout << max_val - min_val << endl;
            }
        }
    }
    return 0;
}
