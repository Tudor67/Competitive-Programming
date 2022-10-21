class Solution {
public:
    bool checkIfPangram(string sentence) {
        const int A = 26;
        const int FIRST_CHAR = 'a';
        const int FULL_MASK = (1 << A) - 1;
        
        int visMask = 0;
        for(char c: sentence){
            visMask |= (1 << (c - FIRST_CHAR));
        }
        
        return (visMask == FULL_MASK);
    }
};