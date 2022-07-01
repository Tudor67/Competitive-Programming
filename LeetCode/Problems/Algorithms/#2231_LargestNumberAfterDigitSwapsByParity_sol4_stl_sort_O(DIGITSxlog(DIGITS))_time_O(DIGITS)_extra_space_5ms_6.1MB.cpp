class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);
        
        vector<int> evenDigits;
        vector<int> oddDigits;
        for(char c: s){
            if((c - '0') % 2 == 0){
                evenDigits.push_back(c - '0');
            }else{
                oddDigits.push_back(c - '0');
            }
        }
        
        sort(evenDigits.begin(), evenDigits.end());
        sort(oddDigits.begin(), oddDigits.end());
        
        int maxNum = 0;
        for(char c: s){
            if((c - '0') % 2 == 0){
                int digit = evenDigits.back();
                evenDigits.pop_back();
                maxNum = 10 * maxNum + digit;
            }else{
                int digit = oddDigits.back();
                oddDigits.pop_back();
                maxNum = 10 * maxNum + digit;
            }
        }
        
        return maxNum;
    }
};