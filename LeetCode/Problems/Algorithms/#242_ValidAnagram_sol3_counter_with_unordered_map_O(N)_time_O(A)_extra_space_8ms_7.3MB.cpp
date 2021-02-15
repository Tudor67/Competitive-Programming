class Solution {
private:
    unordered_map<int, int> countChars(const string& S){
        unordered_map<int, int> count;
        for(int c: S){
            count[c - 'a'] += 1;
        }
        return count;
    }
    
public:
    bool isAnagram(string s, string t) {
        unordered_map<int, int> sCount = move(countChars(s));
        unordered_map<int, int> tCount = move(countChars(t));
        return (sCount == tCount);
    }
};