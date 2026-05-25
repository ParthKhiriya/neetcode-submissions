class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(string s: tokens) {
            if(s == "+" || s == "-" || s == "*" || s == "/") {
                int firstTop = st.top();
                st.pop();
                int secondTop = st.top();
                st.pop();
                if(s == "+") st.push(firstTop + secondTop);
                else if(s == "-") st.push(secondTop - firstTop);
                else if(s == "*") st.push(firstTop * secondTop);
                else if(s == "/") st.push(floor(secondTop / firstTop));
            } else {
                st.push(stoi(s));
            }
        }

        return st.top();
    }
};
