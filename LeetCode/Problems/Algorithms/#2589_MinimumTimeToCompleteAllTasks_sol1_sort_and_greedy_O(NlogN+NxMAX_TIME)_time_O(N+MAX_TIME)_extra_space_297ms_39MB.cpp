class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        const int N = tasks.size();
        
        int maxTime = 0;
        for(int i = 0; i < N; ++i){
            maxTime = max(maxTime, tasks[i][1]);
        }
        
        vector<int> p(N);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(),
             [&](int lhs, int rhs){
                 return (tasks[lhs][1] < tasks[rhs][1]);
             });
        
        vector<bool> isOn(maxTime + 1, false);
        for(int i: p){
            int startTime = tasks[i][0];
            int endTime = tasks[i][1];
            int targetOn = tasks[i][2];
            int currentOn = count(isOn.begin() + startTime, isOn.begin() + endTime + 1, true);
            
            for(int t = endTime; t >= startTime && currentOn < targetOn; --t){
                if(!isOn[t]){
                    isOn[t] = true;
                    currentOn += 1;
                }
            }
        }

        return count(isOn.begin(), isOn.end(), true);
    }
};