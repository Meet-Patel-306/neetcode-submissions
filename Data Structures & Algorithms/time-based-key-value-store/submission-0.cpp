class TimeMap {
public:
    unordered_map<string,vector<pair<string,int>>> um;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        um[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        vector<pair<string,int>> val = um[key];
        string getval = "";
        for(auto i:val){
            if(i.second == timestamp){
                return i.first;
            }else if(i.second < timestamp){
                getval = i.first;
            }
        }
        return getval;
    }
};
