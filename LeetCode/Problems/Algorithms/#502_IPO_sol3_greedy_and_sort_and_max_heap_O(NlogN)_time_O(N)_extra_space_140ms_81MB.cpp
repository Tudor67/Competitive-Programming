class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        const int N = profits.size();

        vector<int> p(N);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(),
            [&](int lhs, int rhs){
                return (capital[lhs] < capital[rhs]);
            });
        
        int i = 0;
        priority_queue<int> maxHeap;
        for(int step = 1; step <= min(N, k); ++step){
            while(i < N && capital[p[i]] <= w){
                maxHeap.push(profits[p[i]]);
                i += 1;
            }
            if(!maxHeap.empty()){
                w += maxHeap.top();
                maxHeap.pop();
            }
        }

        return w;
    }
};