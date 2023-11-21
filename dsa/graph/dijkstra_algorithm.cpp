#include <bits/stdc++.h> 
#include<unordered_map>
#include<list>
#include<vector>
#include<set>

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // create adjacency list

    unordered_map<int, list<pair<int, int>>> adj;
    for(int i=0; i<edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // create distance array
    vector<int>distance(vertices, INT_MAX);

    distance[source] = 0;

    // create set for storing node & wt
    set<pair<int, int>> st;
    st.insert(make_pair(distance[source], source));

    while(!st.empty())
    {
        // get top node
        auto top = *(st.begin());

        int topNodeDistance = top.first;
        int topNode = top.second;

        // remove top record now
        st.erase(st.begin());

        for(auto nbr: adj[topNode])
        {
            if((topNodeDistance+nbr.second)<distance[nbr.first])
            {
                // check if entry already exists in set
                auto record = st.find(make_pair(distance[nbr.first],nbr.first));

                if(record != st.end())
                {
                    st.erase(record);
                }

                // distance update & push this pair in set
                distance[nbr.first] = topNodeDistance+nbr.second;
                st.insert(make_pair(distance[nbr.first], nbr.first));
            }
        }
    }
    return distance;
}
