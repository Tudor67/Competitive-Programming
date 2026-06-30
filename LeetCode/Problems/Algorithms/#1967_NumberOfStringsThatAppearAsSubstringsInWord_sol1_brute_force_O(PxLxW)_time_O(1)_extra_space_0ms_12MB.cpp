class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int matchings = 0;
        for(string& p: patterns){
            if(word.contains(p)){
                ++matchings;
            }
        }
        return matchings;
    }
};