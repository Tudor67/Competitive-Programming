class Solution {
public:
    int numberOfSpecialChars(string word) {
        int lowerVisMask = 0;
        int upperVisMask = 0;
        for(char c: word){
            if(islower(c)){
                lowerVisMask |= 1 << (c - 'a');
            }else{
                upperVisMask |= 1 << (c - 'A');
            }
        }
        return popcount((unsigned int)(lowerVisMask & upperVisMask));
    }
};