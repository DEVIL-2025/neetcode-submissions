class LRUCache {
    vector<pair<int, int>> lruCache;
    int n;
public:
    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        for(int i = 0 ; i < lruCache.size() ; i++){
            if(lruCache[i].first == key){
                int val = lruCache[i].second;
                pair<int, int> temp = lruCache[i];
                lruCache.erase(lruCache.begin() + i);
                lruCache.push_back(temp);

                return val;
            }
        }
        return -1;
    }
    
    void put(int key, int value) {
        for(int i = 0 ; i < lruCache.size() ; i++){
            if(lruCache[i].first == key){
                lruCache.erase(lruCache.begin() + i);
                lruCache.push_back({key, value});
                return;
            }
        }

        if(lruCache.size() == n){
            lruCache.erase(lruCache.begin());
            lruCache.push_back({key, value});
        }
        else{
            lruCache.push_back({key, value});
        }
    }
};
