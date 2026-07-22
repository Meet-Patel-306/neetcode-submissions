class Solution {
   public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if (st.empty()) return false;

                if ((c == ')' && st.top() != '(') || (c == ']' && st.top() != '[') ||
                    (c == '}' && st.top() != '{')) {
                    return false;
                }

                st.pop();
            }
        }
        // cout<<st.empty();
        // if(!st.empty()) cout<<st.top();
        return st.empty() ? true : false;
    }
};
