class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
          vector<vector<int>> result;
        vector<int> path;
        dfs(graph, 0, path, result);  // Start DFS from node 0
        return result;
    }
     void dfs(vector<vector<int>>& graph, int node, vector<int>& path, vector<vector<int>>& result) {
        path.push_back(node);  // Add the current node to the path
        
        // If we reached the target node (n - 1), add the current path to result
        if (node == graph.size() - 1) {
            result.push_back(path);
        } else {
            // Recur for all the neighbors of the current node
            for (int neighbor : graph[node]) {
                dfs(graph, neighbor, path, result);
            }
        }
        
        path.pop_back();  // Backtrack and remove the current node from the path
    }
};