class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        const int N = tasks.size();
        
        long long day = 0;
        map<int, long long> lastDay;
        for(int i = 0; i < N; ++i){
            if(lastDay.count(tasks[i]) && day - lastDay[tasks[i]] <= space){
                day = lastDay[tasks[i]] + space + 1;
            }else{
                day = day + 1;
            }
            lastDay[tasks[i]] = day;
        }
        
        return day;
    }
};