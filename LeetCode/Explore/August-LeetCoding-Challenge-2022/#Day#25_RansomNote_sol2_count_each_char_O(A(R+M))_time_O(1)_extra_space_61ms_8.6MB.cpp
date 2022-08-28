class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        const int A = 26;
        const int FIRST_CHAR = 'a';
        
        for(char c = FIRST_CHAR; c < FIRST_CHAR + A; ++c){
            int ransomCount = count(ransomNote.begin(), ransomNote.end(), c);
            int magazineCount = count(magazine.begin(), magazine.end(), c);
            if(ransomCount > magazineCount){
                return false;
            }
        }
        
        return true;
    }
};