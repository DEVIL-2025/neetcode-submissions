class Solution {
public:
    string decodeString(string s) {
        int n = s.length();
        stack<char> st;
        for(int i = 0 ; i < n ; i++){
            if((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z')
              || (s[i] == '[')){

                st.push(s[i]);

            }
            else if(s[i] == ']'){
                string ss = "";
                while(!st.empty() && (st.top() < '0' || st.top() > '9')){
                    if(st.top() >= 'a' && st.top() <= 'z'){
                        ss = st.top() + ss;
                    }
                    st.pop();
                }
                string digit = "";
                while(!st.empty() && st.top() >= '0' && st.top() <= '9'){
                    digit = st.top() + digit;
                    st.pop();
                }
                int top = stoi(digit);
                string curr = "";
                while(top != 0){
                    curr = curr + ss;
                    top--;
                }

                for(auto &i : curr){
                    st.push(i);
                }
            }
        }
        string ans = "";
        while(!st.empty()){
            char top = st.top();
            st.pop();
            ans += top;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};