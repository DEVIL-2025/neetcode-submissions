class Solution {
public:

    int root(int x){
        long long int s = 0;
        long long int e = x;
        long long int mid = s + (e - s) / 2;
        long long int ans;
        while(s <= e){  
            if(mid * mid == x){
                return mid;
            }
            else if(mid * mid < x){
                ans = mid;
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
            mid = s + (e - s) / 2;
        }
        return ans;
    }

    int mySqrt(int x) {
        if(x == 0){
            return 0;
        }
        
        int digit = root(x);

        return digit;

    }
};