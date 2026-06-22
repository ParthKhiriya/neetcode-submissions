class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> inDegree(numCourses, 0);
        for(auto it: prerequisites) {
            adjList[it[1]].push_back(it[0]);
            inDegree[it[0]]++;
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }      

        int completedCourses = 0;  

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            completedCourses++;

            for(auto it: adjList[node]) {
                inDegree[it]--;
                if(inDegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        return completedCourses == numCourses;
    }
};
