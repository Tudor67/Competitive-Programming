class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        const int N = quality.size();
        const double INF = 1e18;

        vector<pair<double, int>> rq(N);
        for(int i = 0; i < N; ++i){
            rq[i] = {(double)wage[i] / (double)quality[i], quality[i]};
        }

        sort(rq.begin(), rq.end());

        double minCost = INF;
        long long minQualitySum = 0;
        priority_queue<int> maxHeap;
        
        for(const pair<const double, int>& P: rq){
            double ratio = P.first;
            int q = P.second;

            minQualitySum += q;
            maxHeap.push(q);
            if((int)maxHeap.size() > k){
                minQualitySum -= maxHeap.top();
                maxHeap.pop();
            }

            if((int)maxHeap.size() == k){
                minCost = min(minCost, ratio * minQualitySum);
            }
        }

        return minCost;
    }
};