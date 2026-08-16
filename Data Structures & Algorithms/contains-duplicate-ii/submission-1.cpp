class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> s;
        int i = 0, j = 0;
        while(j < n){
            if(abs(i - j) > k){
                //shrink
                s.erase(nums[i]);
                i++;
            }

            //element already seen
            if(s.find(nums[j]) != s.end()){
                return true;
            }

            s.insert(nums[j]);
            j++;
        }
        return false;
    }
};