#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

struct Subset {
    int parent, rank;
};

bool compareEdges(const Edge &a, const Edge &b) {
    return a.weight < b.weight;
}

int find(Subset subsets[], int node) {
    if (subsets[node].parent != node) {
        subsets[node].parent = find(subsets, subsets[node].parent);
    }
    return subsets[node].parent;
}

void unionByRank(Subset subsets[], int x, int y) {
    int xRoot = find(subsets, x);
    int yRoot = find(subsets, y);

    if (subsets[xRoot].rank < subsets[yRoot].rank) {
        subsets[xRoot].parent = yRoot;
    } else if (subsets[xRoot].rank > subsets[yRoot].rank) {
        subsets[yRoot].parent = xRoot;
    } else {
        subsets[yRoot].parent = xRoot;
        subsets[xRoot].rank++;
    }
}

void kruskalMST(vector<Edge> &edges, int V) {
    sort(edges.begin(), edges.end(), compareEdges);

    vector<Edge> mst; // To store the edges in the MST
    Subset *subsets = new Subset[V];

    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    for (const Edge &edge : edges) {
        int x = find(subsets, edge.src);
        int y = find(subsets, edge.dest);

        if (x != y) {
            mst.push_back(edge);
            unionByRank(subsets, x, y);
        }

        if (mst.size() == V - 1) {
            break;
        }
    }

    cout << "Edges in the Minimum Spanning Tree:\n";
    int mstWeight = 0;
    for (const Edge &edge : mst) {
        cout << edge.src << " -- " << edge.dest << " == " << edge.weight << "\n";
        mstWeight += edge.weight;
    }
    cout << "Total weight of MST: " << mstWeight << endl;

    delete[] subsets;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);

    cout << "Enter the edges (src, dest, weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    kruskalMST(edges, V);

    return 0;
}

