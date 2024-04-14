class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        const int N = deck.size();

        vector<int> sortedDeck = deck;
        sort(sortedDeck.begin(), sortedDeck.end());

        queue<int> q;
        for(int i = 0; i < N; ++i){
            q.push(i);
        }

        vector<int> res(N);
        for(int step = 0; step < N; ++step){
            int i = q.front();
            q.pop();

            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }

            res[i] = sortedDeck[step];
        }

        return res;
    }
};