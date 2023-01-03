//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[n + 1];
        for(auto e : edges) adj[e[0]].push_back({e[1], e[2]}), adj[e[1]].push_back({e[0], e[2]});
        
        vector<int> d(n + 1, INT_MAX);
        d[1] = 0;
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;
        pq.push({0, {1}});
        int minD = INT_MAX;
        vector<int> ans = {-1};
        
        while(pq.size()) {
            vector<int> path = pq.top().second;
            int dis = pq.top().first; pq.pop();
            int node = path.back();
            
            if(node == n && minD > dis) minD = dis, ans = path;
          
            for(auto ad : adj[node]) {
                if(d[node] + ad.second < d[ad.first]) {
                    d[ad.first] = d[node] + ad.second;
                    path.push_back(ad.first);
                    pq.push({d[ad.first], path});
                    path.pop_back();
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends