class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string s:tokens){
            if(s == "+" || s == "-" || s == "*" || s=="/"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int ans = 0;
                if(s == "+") ans = a+b;
                else if(s == "-") ans = b-a;
                else if(s == "*") ans = a*b;
                else ans = b/a;
                st.push(ans);
            }
            else{
                int num = stoi(s);
                st.push(num);
            }
        }
        return st.top();
    }
};
