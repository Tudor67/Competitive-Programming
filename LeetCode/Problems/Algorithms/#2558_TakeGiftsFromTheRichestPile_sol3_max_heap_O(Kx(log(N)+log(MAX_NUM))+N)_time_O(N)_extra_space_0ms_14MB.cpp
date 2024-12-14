class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        const int N = gifts.size();
        const long long TOTAL_GIFTS = accumulate(gifts.begin(), gifts.end(), (long long)0);

        long long takenGifts = 0;
        priority_queue<int> maxHeap(gifts.begin(), gifts.end());
        for(int i = 1; i <= k; ++i){
            int pileGifts = maxHeap.top();
            maxHeap.pop();

            int pileRemGifts = sqrt(pileGifts);
            takenGifts += (pileGifts - pileRemGifts);

            maxHeap.push(pileRemGifts);
        }

        return TOTAL_GIFTS - takenGifts;
    }
};