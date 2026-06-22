class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Return 0 if we did not get the word even after traversing the whole wordList, and also return 0 if beginword = endword
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end() || beginWord == endWord)  {
            return 0;
        }

        int n = wordList.size();
        int m = wordList[0].size();

        vector<vector<int>> adjList(n);
        unordered_map<string, int> mpp;
        for(int i=0; i<n; i++) {
            mpp[wordList[i]] = i;
        }

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int count = 0;
                for(int k=0; k<m; k++) {
                    if(wordList[i][k] != wordList[j][k]) {
                        count++;
                    }
                }
                if(count == 1) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        queue<int> q;
        int result = 1;
        unordered_set<int> visit;

        for(int i=0; i<m; i++) {
            for(char c = 'a'; c <= 'z'; c++) {
                if(c == beginWord[i]) {
                    continue;
                }
                string word = beginWord.substr(0, i) + c + beginWord.substr(i+1);
                if(mpp.find(word) != mpp.end() && visit.find(mpp[word]) == visit.end()) {
                    q.push(mpp[word]);
                    visit.insert(mpp[word]);
                }
            }
        }

        while(!q.empty()) {
            result++;
            int size = q.size();
            for(int i=0; i<size; i++) {
                int node = q.front();
                q.pop();
                if(wordList[node] == endWord) {
                    return result;
                }
                for(auto it: adjList[node]) {
                    if(visit.find(it) == visit.end()) {
                        visit.insert(it);
                        q.push(it);
                    }
                }
            }
        }

        return 0;
    }
};
