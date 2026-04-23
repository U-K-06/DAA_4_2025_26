#include <bits/stdc++.h>
using namespace std;
#include <chrono>

int operations = 0;
int maxDepth = 0;

void complexRec(int n, int depth) {
    depth++;
    if (depth > maxDepth) maxDepth = depth;
    if (n <= 2) return;

    int p = n;
    while (p > 0) {
        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            temp[i] = i ^ p;
            operations++;
        }
        operations += n; 
        p >>= 1;
    }

    vector<int> small(n);
    for (int i = 0; i < n; i++) {
        small[i] = i * i;
        operations++;
    }
    operations += n; 
    reverse(small.begin(), small.end());
    operations += n;

    complexRec(n / 2, depth);
    complexRec(n / 2, depth);
    complexRec(n / 2, depth);
}

int main() {
    auto start = chrono::high_resolution_clock::now();
    complexRec(14, 0);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    cout << "Operations: " << operations << endl;
    cout << "Max depth: " << maxDepth << endl;
    cout << "Time: " << duration.count() << " ms" << endl;
    return 0;
}

// Recurance relation: T(N) = 3T(N/2)+N*LOG(N)
// master theorem: theta(n^(1.584)) case 1(f(n)< n^k)