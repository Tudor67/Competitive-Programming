class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        const int N = piles.size();
        const int MAX_STONES = *max_element(piles.begin(), piles.end());

        vector<int> count(MAX_STONES + 1);
        for(int stones: piles){
            count[stones] += 1;
        }

        for(int stones = MAX_STONES; stones >= 1; --stones){
            while(k >= 1 && count[stones] >= 1){
                k -= 1;
                count[stones] -= 1;
                count[stones - (stones / 2)] += 1;
            }
        }

        int remainingStones = 0;
        for(int stones = 1; stones <= MAX_STONES; ++stones){
            remainingStones += stones * count[stones];
        }

        return remainingStones;
    }
};