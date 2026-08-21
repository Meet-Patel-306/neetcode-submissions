class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> frq(26,0);
        for(int i:tasks) frq[i-'A']++;
        priority_queue<int> pq;
        for(int i:frq){
            if(i>0) pq.push(i);
        }
        queue<pair<int,int>> q;
        int time = 0;
        while(!pq.empty() || !q.empty()){
            time++;
            while(!q.empty() && q.front().second == time){
                pq.push(q.front().first);
                q.pop();
            }
            if(!pq.empty()){
                int f = pq.top();
                f--;
                pq.pop();
                if(f>0){
                    q.push({f,time+n+1});
                }
            }
        }
        return time;
    }
};
