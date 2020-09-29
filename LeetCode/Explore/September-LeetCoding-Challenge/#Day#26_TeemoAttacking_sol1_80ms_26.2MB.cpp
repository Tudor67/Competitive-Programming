class Solution {   
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int answer = (timeSeries.empty() ? 0 : duration);
        for(int i = 1; i < timeSeries.size(); ++i){
            if(timeSeries[i - 1] + duration - 1 < timeSeries[i]){
                answer += duration;
            }else{
                answer += timeSeries[i] - timeSeries[i - 1];
            }
        }
        return answer;
    }
};