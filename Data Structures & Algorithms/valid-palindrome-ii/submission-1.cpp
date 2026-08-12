class Solution {
public:
    bool isPallindrome(string s){
        int l = 0;
        int r = s.length() - 1;
        while(l < r){
            if(s[l] != s[r]){
                return false;
            }
            l++,r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int l = 0;
        int r = s.length() - 1;
        while(l < r){
            if(s[l] != s[r]){
                return isPallindrome(s.substr(0, l) + s.substr(l + 1))
                || isPallindrome(s.substr(0, r) + s.substr(r + 1));
            }
            l++;
            r--;
        }
        return true;
    }
};