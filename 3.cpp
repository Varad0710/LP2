//prims algorithm
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<pair<pair<int,int>,int>> prims(int n,vector<pair<pair<int,int>,int>>& edges){
        unordered_map<int,vector<pair<int,int>>> adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i].first.first;
            int v=edges[i].first.second;
            int w=edges[i].second;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<bool> mst(n+1);
        vector<int> key(n+1);
        vector<int> parent(n+1);
        for(int i=0;i<=n;i++){
            mst[i]=false;
            parent[i]=-1;
            key[i]=INT_MAX;
        }
        key[1]=0;
        parent[1]=-1;
        for(int i=1;i<n;i++){
            int mini=INT_MAX;
            int u;
            for(int v=1;v<=n;v++){
                if(mst[v]==false && key[v]<mini){
                    mini=key[v];
                    u=v;
                }
            }
            mst[u]=true;
            for(auto i:adj[u]){
                int v=i.first;
                int w=i.second;
                if(mst[v]==false && w<key[v]){
                    key[v]=w;
                    parent[v]=u;
                }
            }
        }
        vector<pair<pair<int,int>,int>> ans;
        for(int i=2;i<=n;i++){
            ans.push_back({{parent[i],i},key[i]});
        }
        return ans;
    }
};

int main()
{
    vector<pair<pair<int,int>,int>> data={{{1,2},2},{{2,1},2},{{1,3},4},{{3,1},4},{{2,3},3},{{3,2},3}};
    Solution s;
    vector<pair<pair<int,int>,int>> ans=s.prims(3,data);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].first.first<<" - "<<ans[i].first.second<<" - "<<ans[i].second<<endl;
    }

    return 0;
}


//kruskals algorithm
#include<bits/stdc++.h>

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    }

    void makeset(vector<int>& parent, vector<int>& rank, int n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int findparent(vector<int>& parent, int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findparent(parent, parent[node]);
    }

    void unionset(int u, int v, vector<int>& parent, vector<int>& rank) {
        u = findparent(parent, u);
        v = findparent(parent, v);
        if (rank[u] < rank[v]) {
            parent[u] = v;
        } else if (rank[v] < rank[u]) {
            parent[v] = u;
        } else {
            parent[v] = u;
            rank[u]++;
        }
    }

    vector<pair<pair<int, int>, int>> kruskals(int n, vector<pair<pair<int, int>, int>>& edges) {
        vector<vector<int>> edgeList;
        for (auto& e : edges) {
            edgeList.push_back({e.first.first, e.first.second, e.second});
        }

        sort(edgeList.begin(), edgeList.end(), cmp);

        vector<int> parent(n + 1);
        vector<int> rank(n + 1);
        makeset(parent, rank, n + 1);

        vector<pair<pair<int, int>, int>> result;

        for (auto& e : edgeList) {
            int u = findparent(parent, e[0]);
            int v = findparent(parent, e[1]);
            int wt = e[2];
            if (u != v) {
                result.push_back({{e[0], e[1]}, wt});
                unionset(u, v, parent, rank);
            }
        }
        return result;
    }
};

int main() {
    vector<pair<pair<int, int>, int>> data = {
        {{1, 2}, 2}, {{2, 1}, 2}, {{1, 3}, 4},
        {{3, 1}, 4}, {{2, 3}, 3}, {{3, 2}, 3}
    };
    Solution s;
    vector<pair<pair<int, int>, int>> ans = s.kruskals(3, data);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first.first << " - " << ans[i].first.second << " - " << ans[i].second << endl;
    }
    return 0;
}
