class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int size;
    KthLargest(int k, vector<int>& nums) {
        for(int i:nums) pq.push(i);
        size = k;
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size()>size) pq.pop();
        return pq.top();
    }
};
