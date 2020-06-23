class Solution {
public:
    int hIndex(vector<int>& citations) {
        const int N = citations.size();
        int answer = 0;
        for(int i = N - 1, h = 1; i >= 0; --i, ++h){
            if(citations[i] >= h){
                answer = h;
            }
        }
        return answer;
    }
};