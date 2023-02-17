//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    private:
    int timer=0;
    void dfs(int node,int parent,vector<int> &vis, int tin[],int low[],vector<int>& mark,vector<int> adj[])
    {
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        int child=0;
        for(auto it: adj[node])
        {
            if(it==parent)continue;
            if(!vis[it])
            {
                dfs(it,node,vis,tin,low,mark,adj);
                low[node]=min(low[node],low[it]);
                if(low[it]>=tin[node]&& parent!=-1)
                {
                    mark[node]=1;
                }
                child++;
            }
            else
            {
                low[node]=min(low[node],tin[it]);
            }
        }
        if(child>1 && parent==-1)
        {
            mark[node]=1;
        }
    }
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int> vis(V,0);
        int tin[V];
        int low[V];
        vector<int> marks(V,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,-1,vis,tin,low,marks,adj);
            }
        }
        vector<int> ans;
        for(int i=0;i<V;i++)
        {
            if(marks[i]==1)
            {
                ans.push_back(i);
            }
        }
        if(ans.size()==0)
        return {-1};
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends