class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        const int N = profits.size();

        auto decCapitalComp = [&](int lhs, int rhs){
            return (capital[lhs] > capital[rhs]);
        };
        auto incProfitsComp = [&](int lhs, int rhs){
            return (profits[lhs] < profits[rhs]);
        };
        priority_queue<int, vector<int>, decltype(decCapitalComp)> minHeap(decCapitalComp);
        priority_queue<int, vector<int>, decltype(incProfitsComp)> maxHeap(incProfitsComp);

        for(int i = 0; i < N; ++i){
            minHeap.push(i);
        }

        for(int step = 1; step <= min(N, k); ++step){
            while(!minHeap.empty() && capital[minHeap.top()] <= w){
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            if(!maxHeap.empty()){
                w += profits[maxHeap.top()];
                maxHeap.pop();
            }
        }

        return w;
    }
};