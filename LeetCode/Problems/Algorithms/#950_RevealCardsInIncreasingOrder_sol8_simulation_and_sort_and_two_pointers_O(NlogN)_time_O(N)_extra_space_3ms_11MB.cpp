class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        const int N = deck.size();

        vector<int> sortedDeck = deck;
        sort(sortedDeck.begin(), sortedDeck.end());

        vector<int> res(N);
        res[0] = sortedDeck[0];

        int i = 0;
        for(int added = 1; added < N; ++added){
            while(res[i] != 0){
                i = (i + 1) % N;
            }
            i = (i + 1) % N;
            while(res[i] != 0){
                i = (i + 1) % N;
            }
            res[i] = sortedDeck[added];
        }

        return res;
    }
};