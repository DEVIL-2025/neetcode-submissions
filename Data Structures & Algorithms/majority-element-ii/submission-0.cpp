class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]]++;
        }
        vector<int> res;
        for(auto i : mp){
            if(i.second > nums.size() / 3){
                res.push_back(i.first);
            }
        }

        return res;
    }
};