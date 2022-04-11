#include<iostream>
#include<array>
#include<vector>
#include<unordered_set>
#include<deque>
using namespace std;

class Graph {
  private:
    int n;
    int m;
    vector<unordered_set<int>> nodes; // Adjacency list
  public:
    Graph (int _n, int _m): n(_n), m(_m), nodes(n+1) { }
    void AddEdge (int n, int m) {
      nodes[n].insert(m);
      nodes[m].insert(n); // It is an undirected graph after all.
    }
    vector<int> BFS (int s) {
      vector<int> result(n+1, -1);  // All nodes are un-reachable
      vector<int> visited(n+1, 0);  // All nodes are un-visited
      deque<int> pipeline;
      pipeline.push_back(s);
      result[s] = 0;                // Directly connected
      visited[s] = 1;               // And is visited
      while (!pipeline.empty()) {
        int cur = pipeline.front();
        pipeline.pop_front();
        int distance = result[cur]; // The distance of a node from s should be known when I had added it to the pipeline
        // Check all it's adjacent vertices
        for (auto x : nodes[cur]) {
          if (!visited[x]) { // If this adjacent node is not visited yet
            pipeline.push_back(x); // Add it to be checked later
            result[x] = distance + 6; // We know that this is + 1 step away from s as it's parent was
            visited[x] = 1;
          }
        }
      }
      return result;
    }
};

int main () {
  int q;
  cin >> q; // number of queries
  while(q-- > 0) {
    int n, m;
    cin >> n >> m;
    class Graph *graph = new Graph(n, m);
    while(m-- > 0) {
      int u, v;
      cin >> u >> v;
      graph->AddEdge(u, v);
    }
    int s;
    cin >> s;
    vector<int> result = graph->BFS(s);
    bool need_space = false;
    for (int i = 1; i <= n; ++i) {
      if (need_space)
          cout << ' '; // Add a space
      if (i != s) {
        cout << result[i];
        need_space = true; // now we need space before the print
      } else
        need_space = false;
    }
    cout << endl;
    delete graph;
  }
  return 0;
}

