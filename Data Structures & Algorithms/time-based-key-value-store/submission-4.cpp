class TimeMap {
    map<string, vector<pair<string, int>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        vector<int> time;
        for(auto p : mp[key]) { 
            time.push_back(p.second); 
        } 

        int s = 0;
        int e = time.size() - 1;
        int ans = -1;
        while(s <= e){
            int mid = s + (e - s) / 2;
            if(time[mid] <= timestamp){
                ans = mid;
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }

        if(ans == -1){
            return "";
        }

        return mp[key][ans].first;     
    }
};
