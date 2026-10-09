class Solution {
public:
    bool isCycleDFS(vector<vector<int>>& adj, int u, vector<bool>& visited, vector<bool>& inRecursion){
        visited[u] = true;
        inRecursion[u] = true;

        for(int &v: adj[u]){
            if(visited[v] == false && isCycleDFS(adj, v, visited, inRecursion)){
                return true;
            }
            else if(inRecursion[v] == true){
                return true;
            }
        }

        inRecursion[u] = false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();

        vector<bool> visited(v, false);
        vector<bool> inRecursion(v, false);

        for(int i=0; i<v; i++){
            if(!visited[i]){
                isCycleDFS(graph, i, visited, inRecursion);
            }
        }

        vector<int> safeNodes;

        for(int i=0; i<v; i++){
            if(!inRecursion[i]){
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};