#include <bits/stdc++.h>
using namespace std;

int V;

bool isSafe(int v, vector<vector<int>> &graph, vector<int> &path, int pos) {
    if (graph[path[pos - 1]][v] == 0)
        return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool hamiltonianUtil(vector<vector<int>> &graph, vector<int> &path, int pos) {
    if (pos == V) {
        return graph[path[pos - 1]][path[0]] == 1;
    }

    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            if (hamiltonianUtil(graph, path, pos + 1))
                return true;

            path[pos] = -1;
        }
    }

    return false;
}

bool findHamiltonianCycle(vector<vector<int>> &graph) {
    vector<int> path(V, -1);

    path[0] = 0;

    if (!hamiltonianUtil(graph, path, 1)) {
        return false;
    }

    cout << "\nHamiltonian Cycle Exists:\n";
    for (int i = 0; i < V; i++)
        cout << path[i] << " -> ";
    cout << path[0] << "\n";

    return true;
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];

    if (!findHamiltonianCycle(graph)) {
        cout << "\nNo Hamiltonian Cycle Found\n";
    }

    return 0;
}