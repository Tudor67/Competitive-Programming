class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        const int N = temperatures.size();

        vector<int> answer(N);
        int suffMax = temperatures[N - 1];
        for(int i = N - 2; i >= 0; --i){
            if(temperatures[i] < suffMax){
                int j = i + 1;
                while(temperatures[i] >= temperatures[j]){
                    j = j + answer[j];
                }
                answer[i] = j - i;
            }else{
                suffMax = temperatures[i];
            }
        }

        return answer;
    }
};