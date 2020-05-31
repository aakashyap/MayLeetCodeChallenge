/*

Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.

Each person may dislike some other people, and they should not go into the same group. 

Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

Return true if and only if it is possible to split everyone into two groups in this way.

Example 1:

Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]
Example 2:

Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Example 3:

Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false
 

Constraints:

1 <= N <= 2000
0 <= dislikes.length <= 10000
dislikes[i].length == 2
1 <= dislikes[i][j] <= N
dislikes[i][0] < dislikes[i][1]
There does not exist i != j for which dislikes[i] == dislikes[j].

*/

class Solution {
public:
    vector<vector<int>> adjgraph;
    vector<int> visited;
    bool dfs(int index, int color) {
        if (visited[index] == -1) {
            visited[index] = color==0? 1:0;
        } else {
            if (visited[index] == color) return false;
            else return true;
        }
        for (auto &x:adjgraph[index]) {
            bool result;
            cout<<x<<endl;
            result = dfs(x,visited[index]);
            if (!result) return false;
        }
        return true;
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        if (N <= 2) return true;
        adjgraph.resize(N);
        visited.resize(N,-1);
        for (auto &ele:dislikes) {
            adjgraph[ele[0]-1].push_back(ele[1]-1);
            adjgraph[ele[1]-1].push_back(ele[0]-1);
        }
        cout<<"here"<<endl;
        for (int i = 0;i<N;++i) {
            bool result = true;
            if (visited[i] == -1)
                result = dfs(i,0);
            if (!result) return false;
        }
        return true;
    }
};

