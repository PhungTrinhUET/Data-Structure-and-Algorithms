#include <iostream>
#include <queue>
#include <vector>

const int MAX_VERTEX = 100;
bool seen[MAX_VERTEX];
std::vector<std::vector<int>> adj(MAX_VERTEX);

void visit(int u) {
  std::cout << u << "\n";
}

void bfs(int s) {
  std::queue<int> q;
  q.push(s);
  seen[s] = true;
  while (!q.empty()) {
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

/**
 * For undirected graph
 */
void add_edge(int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

int main() {
  add_edge(0, 1);
  add_edge(0, 2);
  add_edge(0, 3);
  add_edge(1, 4);
  add_edge(1, 5);
  add_edge(2, 3);
  bfs(0);
  return 0;
}