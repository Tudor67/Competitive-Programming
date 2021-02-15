class Solution {
private:
    vector<int> countChars(const string& S){
        vector<int> count(26, 0);
        for(int c: S){
            count[c - 'a'] += 1;
        }
        return count;
    }
    
public:
    bool isAnagram(string s, string t) {
        vector<int> sCount = move(countChars(s));
        vector<int> tCount = move(countChars(t));
        return (sCount == tCount);
    }
};