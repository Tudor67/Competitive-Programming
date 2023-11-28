class Solution {
public:
    int maxCoins(vector<int>& piles) {
        const int N = piles.size() / 3;
        
        priority_queue<int> maxHeap(piles.begin(), piles.end());

        int res = 0;
        for(int i = 1; i <= N; ++i){
            maxHeap.pop();
            res += maxHeap.top();
            maxHeap.pop();
        }

        return res;
    }
};