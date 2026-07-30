class Solution {
public:
   
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]]++;
        }

        vector<vector<int>> bucket(n + 1);

        for(auto &it : mp){
            int value = it.first;
            int freq = it.second;

            bucket[freq].push_back(value);
        }

        vector<int> result;
        for(int i = n ; i >= 0 ; i--){
            if(bucket.size() == 0)
                continue;
            
            while(bucket[i].size() > 0 && k > 0){
                result.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
        }

        return result;

    }
};
