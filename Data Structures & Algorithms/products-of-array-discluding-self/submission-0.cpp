class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);

        for(int i = 0 ; i < n ; i++){
            int ans = 1;
            for(int j = 0 ; j < n ; j++){
                if(i == j){
                    continue;
                }
                ans = ans * nums[j];
            }
            res[i] = ans;
        }

        return res;
    }
};
