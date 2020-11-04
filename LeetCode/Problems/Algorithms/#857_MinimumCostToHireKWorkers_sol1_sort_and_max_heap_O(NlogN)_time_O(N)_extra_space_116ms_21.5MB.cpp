class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        const int N = quality.size();
        vector<tuple<double, int, int>> rwq(N);
        for(int i = 0; i < N; ++i){
            rwq[i] = {(double)wage[i] / (double)quality[i], wage[i], quality[i]};
        }
        
        sort(rwq.begin(), rwq.end());
        
        priority_queue<int> maxHeap;
        double minQualitySum = 0;
        for(int i = 0; i < K; ++i){
            int q = get<2>(rwq[i]);
            maxHeap.push(q);
            minQualitySum += q;
        }
        
        double r = get<0>(rwq[K - 1]);
        double answer = minQualitySum * r;
        for(int i = K; i < N; ++i){
            int q = get<2>(rwq[i]);
            maxHeap.push(q);
            minQualitySum += q;
            
            minQualitySum -= maxHeap.top();
            maxHeap.pop();
            
            r = get<0>(rwq[i]);
            answer = min(minQualitySum * r, answer);
        }
        
        return answer;
    }
};