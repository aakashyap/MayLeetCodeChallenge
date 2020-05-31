/*

There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
 

Constraints:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
1 <= numCourses <= 10^5

*/

class Solution {
public:
    vector<vector<int>> adjmat;
    vector<int> visited;
    bool dfs(int i) {
        if (visited[i] == 1) {
            return false;
        }
        visited[i] = 1;
        for (auto &x:adjmat[i]) {
            if(!dfs(x)) return false;
        }
        visited[i] = 2;
        return true;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adjmat.resize(numCourses);
        unordered_set<int> s;
        visited.resize(numCourses,false);
        for (auto &x:prerequisites) {
            adjmat[x[0]].push_back(x[1]);
            s.insert(x[0]);
        }
        for (auto &x:s) {
            if (!visited[x]) {
                if(!dfs(x)) return false;
            }
        }
        return true;
    }
};