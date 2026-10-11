#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> left_child;
vector<int> right_child;

void swap_at_depth(int node, int depth, int k) {
    if (node == -1) return;
    if (depth % k == 0) {
        swap(left_child[node], right_child[node]);
    }
    swap_at_depth(left_child[node], depth + 1, k);
    swap_at_depth(right_child[node], depth + 1, k);
}

void inorder(int node, vector<int>& out) {
    if (node == -1) return;
    inorder(left_child[node], out);
    out.push_back(node);
    inorder(right_child[node], out);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> n)) return 0;
    left_child.assign(n + 1, -1);
    right_child.assign(n + 1, -1);
    for (int i = 1; i <= n; ++i) {
        int a, b;
        cin >> a >> b;
        left_child[i] = a;
        right_child[i] = b;
    }
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int k;
        cin >> k;
        // Perform swap operation on all nodes with depth multiple of k
        swap_at_depth(1, 1, k);
        // Output inorder traversal
        vector<int> result;
        result.reserve(n);
        inorder(1, result);
        for (size_t j = 0; j < result.size(); ++j) {
            cout << result[j];
            if (j + 1 < result.size()) cout << ' ';
        }
        if (i + 1 < t) cout << '\n';
    }
    return 0;
}

