class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        const int N = piles.size();

        int remainingStones = accumulate(piles.begin(), piles.end(), 0);
        priority_queue<int> maxHeap(piles.begin(), piles.end());
        while(!maxHeap.empty() && k >= 1){
            int stones = maxHeap.top();
            maxHeap.pop();

            k -= 1;
            remainingStones -= stones / 2;

            maxHeap.push(stones - (stones / 2));
        }

        return remainingStones;
    }
};