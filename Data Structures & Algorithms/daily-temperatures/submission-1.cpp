class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st; // Push the index in the stack 
        vector<int> result(n, 0);

        for(int i=0; i<n; i++) {
            while(!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int topIndex = st.top();
                st.pop();
                result[topIndex] = i - topIndex;
            }
            st.push(i);
        }

        return result;
    }
};
