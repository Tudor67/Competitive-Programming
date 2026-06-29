class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> freq(26);
        for(char c: text){
            freq[c - 'a'] += 1;
        }
        return min({freq['b' - 'a'], freq['a' - 'a'],
                    freq['l' - 'a'] / 2, freq['o' - 'a'] / 2, freq['n' - 'a']});
    }
};