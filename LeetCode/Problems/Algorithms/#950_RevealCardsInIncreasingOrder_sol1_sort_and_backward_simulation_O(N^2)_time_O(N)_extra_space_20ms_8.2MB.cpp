class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        const int N = deck.size();
        
        vector<int> sortedDeck = deck;
        sort(sortedDeck.begin(), sortedDeck.end());
        
        vector<int> res = sortedDeck;
        for(int step = 3; step <= N; ++step){
            int last = res.back();
            copy_backward(res.end() - step + 1, res.end() - 1, res.end());
            res[N - step] = sortedDeck[N - step];
            res[N - step + 1] = last;
        }
        
        return res;
    }
};