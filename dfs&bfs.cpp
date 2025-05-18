//dfs - recursion
#include <bits/stdc++.h>
using namespace std;

void dfstraversal(unordered_map<int,vector<int>>& adj,vector<int>& ans,unordered_map<int,bool>& vis,int node){
    vis[node]=true;
    ans.push_back(node);
    for(int i:adj[node]){
        if(!vis[i]) dfstraversal(adj,ans,vis,i);
    }
}

vector<int> dfs(vector<pair<int,int>>& edges){
    unordered_map<int,vector<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
       
    }
    vector<int> ans;
    unordered_map<int,bool> vis;
    for(int i=0;i<edges.size();i++){
        if(!vis[edges[i].first]) dfstraversal(adj,ans,vis,edges[i].first);
    }
    return ans;
}

int main()
{
    return 0;
}


//dfs - stack
#include <bits/stdc++.h>
using namespace std;

void dfstraversal(unordered_map<int,vector<int>>& adj, vector<int>& ans, unordered_map<int,bool>& vis, int node) {
    stack<int> s;
    s.push(node);
    vis[node] = true;    
    while(!s.empty()) {
        int front = s.top();
        s.pop();
        ans.push_back(front); 
        for(int i : adj[front]) {
            if(!vis[i]) {
                s.push(i);
                vis[i] = true; 
            }
        }
    }
}

vector<int> dfs(vector<pair<int,int>>& edges){
    unordered_map<int,vector<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
       
    }
    vector<int> ans;
    unordered_map<int,bool> vis;
    for(int i=0;i<edges.size();i++){
        if(!vis[edges[i].first]) dfstraversal(adj,ans,vis,edges[i].first);
    }
    return ans;
}

int main()
{
    return 0;
}


//bfs
#include <bits/stdc++.h>
using namespace std;

void bfstraversal(unordered_map<int,vector<int>>& adj,vector<int>& ans,unordered_map<int,bool>& vis,int node){
    vis[node]=true;
    queue<int> q;
    q.push(node);
    while(!q.empty()){
        int front=q.front();
        ans.push_back(front);
        q.pop();
        for(int i:adj[front]){
            if(!vis[i]){
                q.push(i);
                vis[i]=true;
            }
        }
    }
}

vector<int> bfs(vector<pair<int,int>>& edges){
    unordered_map<int,vector<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
       
    }
    vector<int> ans;
    unordered_map<int,bool> vis;
    for(int i=0;i<edges.size();i++){
        if(!vis[edges[i].first]) bfstraversal(adj,ans,vis,edges[i].first);
    }
    return ans;
}

int main()
{
    return 0;
}