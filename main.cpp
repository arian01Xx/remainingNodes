#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void dfs(vector<int> adj[], int node, vector<int>& vis){
        vis[node]=1;
        for(int child: adj[node]){
            if(!vis[child]){
                dfs(adj, child, vis);
            }
        }
    }
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> adj[n];
        for(auto& x: invocations){
            adj[x[0]].emplace_back(x[1]); //lo mismo de siempre
        }

        vector<int> vis(n,0);
        dfs(adj, k, vis);

        bool c=false; //no infectado conectado con infectado
        for(int i=0; i<n; i++){
            bool tmp=false;
            if(!vis[i]){ //no infectado
                for(int x: adj[i]){
                    if(vis[x]){ //si infectado
                        tmp=true;
                        break;
                    }
                }
                if(tmp){
                    c=true;
                    break;
                }
            }
        }

        vector<int> ans;
        for(int i=0; i<n; i++){
            if(vis[i]){
                if(c) ans.emplace_back(i); //desinfectado
            }else{
                ans.emplace_back(i); //puro desinfectado desde el principio
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}