// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the index of the minimum key.
    int findMinKey(vector<int>& key, vector<bool>& mst)
    {
        int mini = INT_MAX;
        int idx = -1;

        // Loop through each vertex to find the minimum key.
        for (int i = 0; i < key.size(); i++)
        {
            // If the key is smaller and the vertex is not yet included in the MST.
            if (key[i] < mini && !mst[i])
            {
                mini = key[i];
                idx = i;
            }
        }
        return idx;
    }

    // Function to find the sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // Initialization of key, mst, and parent vectors.
        vector<int> key(V, INT_MAX);
        vector<bool> mst(V, false);
        vector<int> parent(V, -1);

        // The key of the starting vertex is set to 0.
        key[0] = 0;

        while (true)
        {
            // Find the vertex with the minimum key that is not yet included in the MST.
            int miniKey = findMinKey(key, mst);

            // If all vertices are included, break the loop.
            if (miniKey == -1)
                break;

            // Mark the selected vertex as included in the MST.
            mst[miniKey] = true;

            // Update key values of the adjacent vertices if they are smaller.
            for (auto edge : adj[miniKey])
            {
                int node = edge[0];
                int wt = edge[1];

                // If the weight is smaller and the vertex is not yet included in the MST.
                if (wt < key[node] && !mst[node])
                {
                    key[node] = wt;
                    parent[node] = miniKey;
                }
            }
        }

        // Calculate the sum of weights in the MST.
        int sum = 0;
        for (int i = 0; i < key.size(); i++)
        {
            sum += key[i];
        }
        return sum;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}
// { Driver Code Ends
