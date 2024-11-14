class Solution {
public:
    int minimizedMaximum(int N, vector<int>& quantities) {
        const int M = quantities.size();

        priority_queue<tuple<int, int, int>> maxHeap;
        for(int i = 0; i < M; ++i){
            maxHeap.emplace(quantities[i] / 1, quantities[i], 1);
        }

        for(int redistribution = 1; redistribution <= N - M && get<0>(maxHeap.top()) > 1; ++redistribution){
            int q = get<1>(maxHeap.top());
            int stores = get<2>(maxHeap.top());
            maxHeap.pop();
            maxHeap.emplace((q + stores) / (stores + 1), q, stores + 1);
        }

        return get<0>(maxHeap.top());
    }
};