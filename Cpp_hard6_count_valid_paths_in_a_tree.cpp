class Solution {
public:
    long long countPaths(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjacencyList(n + 1);
        for (const auto& edge : edges) {
            adjacencyList[edge[0]].push_back(edge[1]);
            adjacencyList[edge[1]].push_back(edge[0]);
        }

        long long count = 0;

        for (int i = 1; i <= n; ++i) {
            vector<bool> visited(n + 1, false);
            dfs(i, i, adjacencyList, visited, count);
        }

        return count;
    }

private:
    bool isPrime(int num) {
        if (num < 2) {
            return false;
        }
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    void dfs(int start, int current, const vector<vector<int>>& adjacencyList, vector<bool>& visited, long long& count) {
        visited[current] = true;

        if (isPrime(current)) {
            count++;
        }

        for (int neighbor : adjacencyList[current]) {
            if (!visited[neighbor]) {
                dfs(start, neighbor, adjacencyList, visited, count);
            }
        }

        visited[current] = false; // Backtrack
    }
};