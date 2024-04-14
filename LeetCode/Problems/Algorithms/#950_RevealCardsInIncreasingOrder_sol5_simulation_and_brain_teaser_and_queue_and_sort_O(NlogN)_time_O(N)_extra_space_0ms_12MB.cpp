class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        const int N = deck.size();

        // Step 1: find the order of revealed/extracted elements
        queue<int> q;
        for(int i = 0; i < N; ++i){
            q.push(i);
        }
        
        vector<int> order(N);
        for(int step = 0; step < N; ++step){
            order[step] = q.front();
            q.pop();

            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
        }

        // Step 2: sort the deck in increasing order
        //         put the sorted elements at their correct indices/positions
        vector<int> sortedDeck = deck;
        sort(sortedDeck.begin(), sortedDeck.end());

        vector<int> res(N);
        for(int i = 0; i < N; ++i){
            res[order[i]] = sortedDeck[i];
        }

        return res;
    }
};