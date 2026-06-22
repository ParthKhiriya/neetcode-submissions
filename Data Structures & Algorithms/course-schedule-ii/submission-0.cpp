class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> inDegree(numCourses, 0);

        for(auto it: prerequisites) {
            int course = it[0];
            int prereq = it[1];
            adjList[prereq].push_back(course);
            inDegree[course]++;
        }

        int completedCourses = 0;
        vector<int> result(numCourses);

        queue<int> q;
        for(int i=0; i<numCourses; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            completedCourses++;
            result.push_back(node);

            for(auto it: adjList[node]) {
                inDegree[it]--;
                if(inDegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        vector<int> empty;
        return completedCourses == numCourses ? result : empty;
    }
};
