class TimeMap {
    map<string, vector<pair<string, int>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {

        auto& values = mp[key];

        int s = 0;
        int e = values.size() - 1;
        string res = "";
        while(s <= e){
            int mid = s + (e - s) / 2;
            if(values[mid].second <= timestamp){
                res = values[mid].first;
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }

        return res;
    }
};
