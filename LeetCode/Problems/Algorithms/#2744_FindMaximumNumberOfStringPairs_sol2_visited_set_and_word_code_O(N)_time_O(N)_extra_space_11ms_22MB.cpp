class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int maxPairs = 0;

        unordered_set<int> avail;
        for(string& word: words){
            int wordCode = (word[0] - 'a') * 26 + (word[1] - 'a');
            int revWordCode = (word[1] - 'a') * 26 + (word[0] - 'a');
            if(avail.count(revWordCode)){
                maxPairs += 1;
                avail.erase(revWordCode);
            }else{
                avail.insert(wordCode);
            }
        }

        return maxPairs;
    }
};