class MedianFinder {
public:
    vector<int> nums;
    priority_queue<int> pq;
    priority_queue<int,vector<int>,greater<int>> lpq;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // nums.push_back(num);
        pq.push(num);
        if(!lpq.empty() && lpq.top()<pq.top()){
            lpq.push(pq.top());
            pq.pop();
        }
        if(pq.size() > lpq.size()+1){
            lpq.push(pq.top());
            pq.pop();
        }
        if(lpq.size() > pq.size()+1){
            pq.push(lpq.top());
            lpq.pop();
        }
    }
    
    double findMedian() {
        // int n = nums.size();
        // sort(nums.begin(), nums.end());
        // if(n%2 != 0) return nums[n/2];
        // // cout << nums[n/2]<<" "<<nums[n/2-1] << endl;
        // double mid = (double)(nums[n/2]+nums[n/2-1])/2;
        // return mid;
        if(pq.size() == lpq.size()) return (pq.top() + lpq.top())/2.0;
        else if(pq.size() > lpq.size()) return pq.top();
        else return lpq.top();
    }
};
