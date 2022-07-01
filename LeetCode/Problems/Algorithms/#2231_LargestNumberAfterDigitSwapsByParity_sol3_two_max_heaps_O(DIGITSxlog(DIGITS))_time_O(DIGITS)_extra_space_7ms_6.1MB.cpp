class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);
        
        vector<priority_queue<int>> maxHeaps(2);
        for(char c: s){
            int parity = (c - '0') % 2;
            maxHeaps[parity].push(c - '0');
        }
        
        int maxNum = 0;
        for(char c: s){
            int parity = (c - '0') % 2;
            int digit = maxHeaps[parity].top();
            maxHeaps[parity].pop();
            maxNum = 10 * maxNum + digit;
        }
        
        return maxNum;
    }
};