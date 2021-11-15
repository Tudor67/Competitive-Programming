class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        const int INF = 1e8;
        const int N = t.size();
        const int MAX_VAL = *max_element(t.begin(), t.end());
        
        vector<int> answer(N);
        vector<int> firstPosOf(MAX_VAL + 1, INF);
        for(int i = N - 1; i >= 0; --i){
            int minPos = INF;
            for(int greaterTemp = t[i] + 1; greaterTemp <= MAX_VAL; ++greaterTemp){
                minPos = min(minPos, firstPosOf[greaterTemp]);
            }
            if(minPos != INF){
                answer[i] = minPos - i;
            }
            firstPosOf[t[i]] = i;
        }
        
        return answer;
    }
};