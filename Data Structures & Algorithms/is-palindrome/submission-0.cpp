class Solution {
public:
    void to_lowerCase(string &s){
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                char temp = s[i] - 'A' + 'a';
                s[i] = temp;
            }
        }
    }

    bool isPalindrome(string s) {
        string s1 = "";
        to_lowerCase(s);
        for(int i = 0 ; i < s.length() ; i++){
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')
             || (s[i] >= '0' && s[i] <= '9')){
                s1 += s[i];
            }
        }
        string s2 = s1;
        reverse(s1.begin(), s1.end());
        if(s2 == s1){
            return true;
        }
        else{
            return false;
        }
    }
};
