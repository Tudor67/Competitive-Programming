class Solution {
public:
    vector<int> partitionLabels(string s) {
        const int N = s.length();
        const int A = 26;
        
        vector<int> lastPosOf(A, -1);
        for(int i = 0; i < N; ++i){
            lastPosOf[s[i] - 'a'] = i;
        }
        
        vector<int> res;
        int minPos = 0;
        int maxPos = 0;
        for(int i = 0; i < N; ++i){
            maxPos = max(maxPos, lastPosOf[s[i] - 'a']);
            if(maxPos == i){
                res.push_back(maxPos - minPos + 1);
                minPos = i + 1;
            }
        }
        
        return res;
    }
};