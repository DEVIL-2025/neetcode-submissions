class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]]++;
        }
        vector<pair<int, int>> vec;
        for(auto i : mp){
            vec.push_back({i.second, i.first});
        }

        sort(vec.begin(), vec.end());

        vector<int> ans;
        for(int i = vec.size() - 1 ; i >= 0 ; i--){
            if(k > 0){
                ans.push_back(vec[i].second);
                k--;
            }
            else{
                break;
            }
        }

        return ans;
    }
};
