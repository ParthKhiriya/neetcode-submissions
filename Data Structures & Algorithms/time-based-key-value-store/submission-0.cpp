class TimeMap {
public:
    unordered_map<string, map<int, string>> mpp;

    TimeMap() { }
    
    void set(string key, string value, int timestamp) {
        mpp[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = mpp[key].upper_bound(timestamp);
        return it == mpp[key].begin() ? "" : prev(it)->second;
    }
};
