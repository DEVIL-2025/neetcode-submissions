class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int idx = 0;
        for(int i = 1 ; i < arr.size() ; i++){
            if(abs(x - arr[idx]) > abs(x - arr[i])){
                idx = i;
            }
        }

        vector<int> res = {arr[idx]};
        int l = idx - 1;
        int r = idx + 1;
        while(res.size() < k){
            if(l >= 0 && r < arr.size()){
                if(abs(x - arr[l]) <= abs(x - arr[r])){
                    res.push_back(arr[l--]);
                }
                else{
                    res.push_back(arr[r++]);
                }
            }
            else if(l >= 0){
                res.push_back(arr[l--]);
            }
            else if(r < arr.size()){
                res.push_back(arr[r++]);
            }
        }

        sort(res.begin(), res.end());
        return res;
    }
};