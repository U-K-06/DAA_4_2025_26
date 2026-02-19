#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int maxMin(int k, vector<int>& arr) {
    sort(arr.begin(), arr.end());
    
    int min_unfairness = INT_MAX;
    
    for (int i = 0; i <= arr.size() - k; i++) {
        int current_unfairness = arr[i + k - 1] - arr[i];
        if (current_unfairness < min_unfairness) {
            min_unfairness = current_unfairness;
        }
    }
    
    return min_unfairness;
}


// time complexity = o(n log n)
// space = o(log n) sicne pass by reference