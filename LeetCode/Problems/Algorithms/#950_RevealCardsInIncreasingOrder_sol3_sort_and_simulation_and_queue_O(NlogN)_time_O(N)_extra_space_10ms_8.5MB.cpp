class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        const int N = deck.size();
        
        // Simulate the revealing process on deck [0, 1, 2, 3, 4, ..., N - 1]
        // This deck is revealed in the order [0, 2, 4, ...]
        // This means that we should put the smallest card on index 0,
        // the second smallest card on index 2, the third smallest card on index 4, ...
        queue<int> q;
        for(int i = 0; i < N; ++i){
            q.push(i);
        }
        
        vector<int> sortedDeck = deck;
        sort(sortedDeck.begin(), sortedDeck.end());
        
        vector<int> res(N);
        for(int k = 0; k < N; ++k){
            int i = q.front(); q.pop();
            if(!q.empty()){
                int j = q.front(); q.pop();
                q.push(j);
            }
            
            res[i] = sortedDeck[k];
        }
        
        return res;
    }
};