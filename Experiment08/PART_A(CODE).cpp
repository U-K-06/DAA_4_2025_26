#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <climits>

using namespace std;
using namespace std::chrono;

const double TIMEOUT_MS = 2000.0;

struct Metrics {
    string algorithmName;
    double executionTimeMs = 0.0;
    long long operations = 0;
    string status = "Completed";
};

// 1. Binary Search
int binarySearch(const vector<int>& arr, int target, Metrics& metrics) {
    auto start = high_resolution_clock::now();
    metrics.algorithmName = "Binary Search";
    metrics.operations = 0;

    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        metrics.operations++;
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) break;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }

    auto end = high_resolution_clock::now();
    metrics.executionTimeMs = duration<double, milli>(end - start).count();
    return -1;
}

// 2A. Subset Sum Verification
bool verifySubsetSum(const vector<int>& subset, int target, Metrics& metrics) {
    auto start = high_resolution_clock::now();
    metrics.algorithmName = "Subset Sum (Verification)";
    metrics.operations = 0;

    int sum = 0;
    for (int x : subset) {
        metrics.operations++;
        sum += x;
    }

    auto end = high_resolution_clock::now();
    metrics.executionTimeMs = duration<double, milli>(end - start).count();

    return sum == target;
}

// 2B. Subset Sum Decision
bool subsetRec(const vector<int>& arr, int n, int target, Metrics& metrics, time_point<high_resolution_clock> start) {
    metrics.operations++;

    if (duration<double, milli>(high_resolution_clock::now() - start).count() > TIMEOUT_MS) {
        metrics.status = "Timeout";
        return false;
    }

    if (target == 0) return true;
    if (n == 0) return false;

    return subsetRec(arr, n - 1, target, metrics, start) ||
           subsetRec(arr, n - 1, target - arr[n - 1], metrics, start);
}

bool solveSubsetSum(const vector<int>& arr, int target, Metrics& metrics) {
    auto start = high_resolution_clock::now();
    metrics.algorithmName = "Subset Sum (Decision)";
    metrics.operations = 0;
    metrics.status = "Completed";

    bool result = subsetRec(arr, arr.size(), target, metrics, start);

    metrics.executionTimeMs = duration<double, milli>(high_resolution_clock::now() - start).count();
    return result;
}

// 3. TSP Brute Force
int tsp(const vector<vector<int>>& graph, Metrics& metrics) {
    auto start = high_resolution_clock::now();
    metrics.algorithmName = "TSP (Brute Force)";
    metrics.operations = 0;

    int n = graph.size();
    vector<int> v;

    for (int i = 1; i < n; i++) v.push_back(i);

    int minCost = INT_MAX;

    do {
        metrics.operations++;

        if (duration<double, milli>(high_resolution_clock::now() - start).count() > TIMEOUT_MS) {
            metrics.status = "Timeout";
            break;
        }

        int cost = 0, k = 0;

        for (int i : v) {
            cost += graph[k][i];
            k = i;
        }
        cost += graph[k][0];

        minCost = min(minCost, cost);

    } while (next_permutation(v.begin(), v.end()));

    metrics.executionTimeMs = duration<double, milli>(high_resolution_clock::now() - start).count();
    return minCost;
}

// Print
void print(const Metrics& m) {
    cout << left << setw(30) << m.algorithmName
         << setw(15) << m.status
         << setw(20) << m.operations
         << fixed << setprecision(4)
         << m.executionTimeMs << " ms\n";
}

int main() {
    cout << string(80, '-') << "\n";
    cout << setw(30) << "Algorithm"
         << setw(15) << "Status"
         << setw(20) << "Operations"
         << "Time\n";
    cout << string(80, '-') << "\n";

    // Binary Search
    vector<int> arr(1000000);
    iota(arr.begin(), arr.end(), 1);
    Metrics m1;
    binarySearch(arr, 999999, m1);
    print(m1);

    // Subset Verification
    Metrics m2;
    verifySubsetSum({10, 20, 30, 40}, 100, m2);
    print(m2);

    // Subset Decision
    Metrics m3;
    solveSubsetSum({3, 4, 5, 2}, 9, m3);
    print(m3);

    // TSP
    vector<vector<int>> g = {
        {0,10,15,20},
        {10,0,35,25},
        {15,35,0,30},
        {20,25,30,0}
    };
    Metrics m4;
    tsp(g, m4);
    print(m4);

    cout << string(80, '-') << "\n";
}