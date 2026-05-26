class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<double> st;

        vector<pair<int, int>> couple;
        for(int i=0; i<n; i++) {
            couple.push_back({position[i], speed[i]});
        }
        sort(couple.rbegin(), couple.rend());

        for(auto& p : couple) {
            double time = ((double)(target - p.first)/p.second);
            st.push_back(time);
            if(st.size() >= 2 && st.back() <= st[st.size() - 2]) {
                st.pop_back();
            }
        }

        return st.size();
    }
};
