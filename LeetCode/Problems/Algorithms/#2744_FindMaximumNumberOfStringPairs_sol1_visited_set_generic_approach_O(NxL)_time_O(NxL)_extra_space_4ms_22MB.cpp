class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int maxPairs = 0;

        unordered_set<string> avail;
        for(string& word: words){
            string revWord(word.rbegin(), word.rend());
            if(avail.count(revWord)){
                maxPairs += 1;
                avail.erase(revWord);
            }else{
                avail.insert(word);
            }
        }

        return maxPairs;
    }
};