class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);
        
        vector<int> count(10);
        for(char c: s){
            count[c - '0'] += 1;
        }
        
        int maxEven = 8;
        int maxOdd = 9;
        int maxNum = 0;
        for(char c: s){
            if((c - '0') % 2 == 0){
                while(count[maxEven] == 0){
                    maxEven -= 2;
                }
                count[maxEven] -= 1;
                maxNum = 10 * maxNum + maxEven;
            }else{
                while(count[maxOdd] == 0){
                    maxOdd -= 2;
                }
                count[maxOdd] -= 1;
                maxNum = 10 * maxNum + maxOdd;
            }
        }
        
        return maxNum;
    }
};