class Solution {
public:
    int hIndex(vector<int>& citations) {
        const int N = citations.size();
        sort(citations.begin(), citations.end());
        
        int answer = 0;
        for(int i = N - 1; i >= 0; --i){
            if(citations[i] >= N - i){
                answer = N - i;
            }
        }
        
        return answer;
    }
};