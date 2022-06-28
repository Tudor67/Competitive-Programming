class Solution {
public:
    int minDeletions(string s) {
        const int A = 26;
        const int MIN_CHAR = 'a';
        
        vector<int> count(A);
        for(char c: s){
            count[c - MIN_CHAR] += 1;
        }
        
        sort(count.begin(), count.end());
        
        int deleteOperations = 0;
        for(int i = (int)count.size() - 2; i >= 0 && count[i] > 0; --i){
            if(count[i] >= count[i + 1]){
                if(count[i + 1] == 0){
                    deleteOperations += count[i];
                    count[i] = 0;
                }else{
                    deleteOperations += (count[i] - count[i + 1] + 1);
                    count[i] = count[i + 1] - 1;
                }
            }
        }
        
        return deleteOperations;
    }
};