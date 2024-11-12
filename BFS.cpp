#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX_VERTER = 100;
bool seen[MAX_VERTER];
vector<vector<int>> adj(MAX_VERTER);

void visit(int u) {
    cout << u << "\n";
}

void bfs(int s) {
    queue<int> q;
    q.push(s);
    seen[s] = true;
    while (!q.emty()) {
        int u = q.front();
        visit(u);
        q.pop();
        for (auto v : adj[u]) {
            if (!seen[v]) {
                seen[v] = true;
                q.push(v);
            }
        }
    }
}

void add_edge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main () {
    add_edge(0, 1);
    add_edge(0, 2);
    add_edge(0, 3);
    add_edge(1, 4);
    add_edge(1, 5);
    add_edge(2, 3);
    bfs(0);
    return 0;
}