class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        const int N = deck.size();
        
        vector<int> sortedDeck = deck;
        sort(sortedDeck.begin(), sortedDeck.end());
        
        deque<int> dq;
        dq.push_back(sortedDeck.back());
        for(int step = 2; step <= N; ++step){
            dq.push_front(dq.back());
            dq.push_front(sortedDeck[N - step]);
            dq.pop_back();
        }
        
        return vector<int>(dq.begin(), dq.end());
    }
};