//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int s)
    {
        // Code here
        //vector<int>visited(V, 0);
        vector<int>dist(V, INT_MAX);
        //visited[s] = 1;
        dist[s] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
        q.push({0,s});
        while(!q.empty()){
            auto cur = q.top();
            q.pop();
            int node = cur.second;
            int dis = cur.first;
            //if(visited[node]) continue ;
            //visited[node] = 1;
            for(auto x: adj[node]){
                if(dist[x[0]]>dis+x[1]){
                    dist[x[0]] = dis+x[1];
                    //visited[x[0]] =1;
                    q.push({dist[x[0]],x[0]});
                }
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends