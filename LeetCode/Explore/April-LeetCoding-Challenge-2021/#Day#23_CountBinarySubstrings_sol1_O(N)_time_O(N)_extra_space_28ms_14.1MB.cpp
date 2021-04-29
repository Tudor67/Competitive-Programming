class Solution {
public:
    int countBinarySubstrings(string s) {
        const int N = s.length();
        
        vector<int> groupSizes;
        groupSizes.push_back(1);
        for(int i = 1; i < N; ++i){
            if(s[i - 1] == s[i]){
                groupSizes.back() += 1;
            }else{
                groupSizes.push_back(1);
            }
        }
        
        int answer = 0;
        for(int i = 1; i < (int)groupSizes.size(); ++i){
            answer += min(groupSizes[i - 1], groupSizes[i]);
        }
        
        return answer;
    }
};