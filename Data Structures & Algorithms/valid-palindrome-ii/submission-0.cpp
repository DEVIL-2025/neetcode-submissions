class Solution {
public:
    bool isPallindrome(string s){
        int l = 0 ; 
        int r = s.length() - 1;
        while(l < r){
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        if(isPallindrome(s)){
            return true;
        }

        for(int i = 0 ; i < s.size() ; i++){
            string newS = s.substr(0, i) + s.substr(i + 1);
            if(isPallindrome(newS)){
                return true;
            }
        }
        return false;
    }
};