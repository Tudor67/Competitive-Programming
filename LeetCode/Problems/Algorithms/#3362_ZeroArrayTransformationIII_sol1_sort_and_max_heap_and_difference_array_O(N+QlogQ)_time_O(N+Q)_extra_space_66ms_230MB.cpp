class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        const int N = nums.size();
        const int Q = queries.size();

        using Segment = pair<int, int>;
        vector<Segment> sortedSegments(Q);
        for(int i = 0; i < Q; ++i){
            sortedSegments[i] = {queries[i][0], queries[i][1]};
        }

        sort(sortedSegments.begin(), sortedSegments.end());

        vector<int> delta(N + 1);
        priority_queue<int> waitingMaxHeap;

        int segmentIndex = 0;
        int deltaPrefSum = 0;
        for(int i = 0; i < N; ++i){
            deltaPrefSum += delta[i];

            while(segmentIndex < Q && sortedSegments[segmentIndex].first <= i){
                waitingMaxHeap.push(sortedSegments[segmentIndex].second);
                segmentIndex += 1;
            }

            while(!waitingMaxHeap.empty() && waitingMaxHeap.top() >= i && deltaPrefSum < nums[i]){
                deltaPrefSum += 1;
                delta[waitingMaxHeap.top() + 1] -= 1;
                waitingMaxHeap.pop();
            }

            if(deltaPrefSum < nums[i]){
                return -1;
            }
        }

        return waitingMaxHeap.size();
    }
};