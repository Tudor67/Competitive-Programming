class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        // Rule 1
        if(count(suits.begin(), suits.end(), suits[0]) == 5){
            return "Flush";
        }
        
        // Rule 2, 3, 4
        const int MAX_RANK = *max_element(ranks.begin(), ranks.end());
        vector<int> count(MAX_RANK + 1);
        for(int rank: ranks){
            count[rank] += 1;
        }
        
        int maxCount = *max_element(count.begin(), count.end());
        if(maxCount >= 3){
            return "Three of a Kind";
        }
        
        if (maxCount >= 2){
            return "Pair";
        }
        
        return "High Card";
    }
};