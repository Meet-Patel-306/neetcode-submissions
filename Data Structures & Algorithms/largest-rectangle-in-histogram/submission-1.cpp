class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> rle(n,-1);
        vector<int> lle(n,-1);
        stack<int> s;
        for(int i = n-1;i>=0;i--){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(!s.empty()) rle[i] = s.top();
            s.push(i);
        }
        stack<int> s1;
        for(int i = 0;i<n;i++){
            while(!s1.empty() && heights[s1.top()]>=heights[i]){
                s1.pop();
            }
            if(!s1.empty()) lle[i] = s1.top();
            s1.push(i);
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            int l = lle[i] == -1 ? -1:lle[i];
            int r = rle[i] == -1 ? n:rle[i];
            int width = r-l-1;
            int area = heights[i]*width;
            cout<<area<<" "<<l<<" "<<r<<" "<<heights[i]<<endl;
            ans = max(ans,area); 
        }
        return ans;
    }
};
