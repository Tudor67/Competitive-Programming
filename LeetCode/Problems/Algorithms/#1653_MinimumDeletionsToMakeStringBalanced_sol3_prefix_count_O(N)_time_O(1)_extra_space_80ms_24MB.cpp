class Solution {
public:
    int minimumDeletions(string s) {
        int minDeletions = 0;

        int bCount = 0;
        for(char c: s){
            if(c == 'a'){
                if(bCount >= 1){
                    minDeletions += 1;
                    bCount -= 1;
                }
            }else{
                bCount += 1;
            }
        }

        return minDeletions;
    }
};