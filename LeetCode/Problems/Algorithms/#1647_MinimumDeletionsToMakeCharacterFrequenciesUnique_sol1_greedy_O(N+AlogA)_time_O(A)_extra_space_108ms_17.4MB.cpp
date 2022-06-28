class Solution {
public:
    int minDeletions(string s) {
        const int A = 26;
        const int MIN_CHAR = 'a';
        
        vector<int> count(A);
        for(char c: s){
            count[c - MIN_CHAR] += 1;
        }
        
        vector<int> v;
        for(int i = 0; i < (int)count.size(); ++i){
            if(count[i] > 0){
                v.push_back(count[i]);
            }
        }
        
        sort(v.begin(), v.end());
        
        int deleteOperations = 0;
        for(int i = (int)v.size() - 2; i >= 0; --i){
            if(v[i] >= v[i + 1]){
                if(v[i + 1] == 0){
                    deleteOperations += v[i];
                    v[i] = 0;
                }else{
                    deleteOperations += (v[i] - v[i + 1] + 1);
                    v[i] = v[i + 1] - 1;
                }
            }
        }
        
        return deleteOperations;
    }
};