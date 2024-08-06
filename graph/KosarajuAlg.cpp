//Strongly Connected Components (Kosaraju's Algo)
/*
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly connected components in the graph.

*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void dfs1(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs1(neighbor, adj, visited, st);
        }
    }
    st.push(node);
}

void dfs2(int node, vector<vector<int>>& transpose, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : transpose[node]) {
        if (!visited[neighbor]) {
            dfs2(neighbor, visited, transpose);
        }
    }
}

int kosaraju(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    stack<int> st;

    // Step 1: Perform a DFS and push nodes onto a stack in the order of completion
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            dfs1(i, adj, visited, st);
        }
    }

    // Step 2: Create the transpose of the graph
    vector<vector<int>> transpose(V);
    for (int i = 0; i < V; ++i) {
        for (int neighbor : adj[i]) {
            transpose[neighbor].push_back(i);
        }
    }

    // Step 3: Perform DFS on the transposed graph in the order of nodes in the stack
    fill(visited.begin(), visited.end(), false);
    int sccCount = 0;
    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (!visited[node]) {
            ++sccCount;
            dfs2(node, transpose, visited);
        }
    }

    return sccCount;
}
