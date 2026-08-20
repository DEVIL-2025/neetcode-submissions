class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l = 0;
        int e = s1.length();
        sort(s1.begin(), s1.end());
        
        while((l + e - 1) < s2.length()){
            string temp = s2.substr(l, e);
            sort(temp.begin(), temp.end());
            cout<<temp<<" ";
            if(temp == s1){
                return true;
            }
            l++;
        }
        return false;
    }
};
