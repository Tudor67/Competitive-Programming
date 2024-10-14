class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        const int N = intervals.size();

        vector<int> p(N);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(),
             [&](int lhs, int rhs){
                return (intervals[lhs] < intervals[rhs]);
             });
        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int i: p){
            int l = intervals[i][0];
            int r = intervals[i][1];
            if(!minHeap.empty() && minHeap.top() < l){
                minHeap.pop();
            }
            minHeap.push(r);
        }

        return minHeap.size();
    }
};