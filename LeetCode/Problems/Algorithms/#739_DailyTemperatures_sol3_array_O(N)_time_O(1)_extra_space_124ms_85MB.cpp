class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        const int N = t.size();
        
        vector<int> answer(N);
        int suffMax = t[N - 1];
        for(int i = N - 2; i >= 0; --i){
            if(t[i] < suffMax){
                int j = i + 1;
                while(t[i] >= t[j]){
                    j = j + answer[j];
                }
                answer[i] = j - i;
            }
            suffMax = max(suffMax, t[i]);
        }
        
        return answer;
    }
};