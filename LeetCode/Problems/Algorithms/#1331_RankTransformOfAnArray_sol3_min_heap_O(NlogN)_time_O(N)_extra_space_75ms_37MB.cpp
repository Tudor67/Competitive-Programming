class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        const int N = arr.size();

        auto comp = [&](int lhs, int rhs){
            return arr[lhs] > arr[rhs];
        };
        priority_queue<int, vector<int>, decltype(comp)> minHeap(comp);

        for(int i = 0; i < N; ++i){
            minHeap.push(i);
        }

        vector<int> rank(N);
        int currRank = 1;
        while(!minHeap.empty()){
            int i = minHeap.top();
            while(!minHeap.empty() && arr[i] == arr[minHeap.top()]){
                rank[minHeap.top()] = currRank;
                minHeap.pop();
            }
            currRank += 1;
        }

        return rank;
    }
};