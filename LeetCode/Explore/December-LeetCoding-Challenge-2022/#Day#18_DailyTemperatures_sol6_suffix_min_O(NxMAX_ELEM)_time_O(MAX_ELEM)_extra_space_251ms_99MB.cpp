class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        const int N = temperatures.size();
        const int MAX_TEMPERATURE = *max_element(temperatures.begin(), temperatures.end());
        const int INF = 1e9;

        vector<int> answer(N);
        vector<int> closestRightPosOf(MAX_TEMPERATURE + 1, INF);
        for(int i = N - 1; i >= 0; --i){
            int closestRightPos = INF;
            for(int t = temperatures[i] + 1; t <= MAX_TEMPERATURE; ++t){
                closestRightPos = min(closestRightPos, closestRightPosOf[t]);
            }
            if(closestRightPos != INF){
                answer[i] = closestRightPos - i;
            }
            closestRightPosOf[temperatures[i]] = i;
        }

        return answer;
    }
};