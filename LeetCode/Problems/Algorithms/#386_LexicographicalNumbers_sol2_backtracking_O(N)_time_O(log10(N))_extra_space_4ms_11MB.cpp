class Solution {
private:
    void back(int level, int num, int n, vector<int>& sortedNums){
        for(int digit = !level; digit <= 9; ++digit){
            int nextNum = num * 10 + digit;
            if(nextNum <= n){
                sortedNums.push_back(nextNum);
                back(level + 1, nextNum, n, sortedNums);
            }else{
                break;
            }
        }
    }
    
public:
    vector<int> lexicalOrder(int n) {
        vector<int> sortedNums;
        back(0, 0, n, sortedNums);
        return sortedNums;
    }
};