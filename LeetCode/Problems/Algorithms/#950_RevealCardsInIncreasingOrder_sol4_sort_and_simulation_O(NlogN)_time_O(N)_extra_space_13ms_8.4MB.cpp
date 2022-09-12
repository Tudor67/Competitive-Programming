class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        const int N = deck.size();
        
        vector<int> sortedDeck = deck;
        sort(sortedDeck.begin(), sortedDeck.end());
        
        vector<int> res(N);
        res[0] = sortedDeck[0];
        int added = 1;
        
        int idx = 0;
        while(added < N){
            while(res[idx] > 0){
                idx = (idx + 1) % N;
            }
            idx = (idx + 1) % N;
            while(res[idx] > 0){
                idx = (idx + 1) % N;
            }
            res[idx] = sortedDeck[added];
            added += 1;
        }
        
        return res;
    }
};