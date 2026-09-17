class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        sort(piles.begin(), piles.end());
        int s = 1;
        int e = piles[n - 1];
        int minTime = piles[n - 1];
        while(s <= e){
            int mid = s + (e - s) / 2;
            int time = 0;
            for(int i = 0 ; i < n ; i++){
                time += (piles[i] + mid - 1) / mid;
            }
            if(time <= h){
                minTime = min(mid, minTime);
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        return minTime;
    }
};
