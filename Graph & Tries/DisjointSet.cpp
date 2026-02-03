#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent, rank, size;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int findUPar(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }   
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }   
};

int main() {
    DisjointSet ds(7);
    ds.unionBySize(0, 2);
    ds.unionBySize(0, 1);
    ds.unionBySize(3, 4);
    ds.unionBySize(5, 6);
    ds.unionBySize(3, 5);
    if (ds.findUPar(0) == ds.findUPar(3)) {
        cout << "same component" << endl;
    } else {
        cout << "different components" << endl;
    }
    ds.unionBySize(1, 3);

    if (ds.findUPar(0) == ds.findUPar(3)) {
        cout <<" same component" << endl;
    } else {
        cout << " different components" << endl;
    }
    cout << "This is a Disjoint Set implementation." << endl;
    return 0;      
}