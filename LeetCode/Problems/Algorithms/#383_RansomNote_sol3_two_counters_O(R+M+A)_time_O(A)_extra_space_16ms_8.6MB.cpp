class Solution {
private:
    const int A = 26;
    const int FIRST_CHAR = 'a';
    
    vector<int> getCounter(const string& S){
        vector<int> count(A);
        for(char c: S){
            count[c - FIRST_CHAR] += 1;
        }
        return count;
    }
    
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> ransomCount = getCounter(ransomNote);
        vector<int> magazineCount = getCounter(magazine);
        
        for(char c = FIRST_CHAR; c < FIRST_CHAR + A; ++c){
            if(ransomCount[c - FIRST_CHAR] > magazineCount[c - FIRST_CHAR]){
                return false;
            }
        }
        
        return true;
    }
};