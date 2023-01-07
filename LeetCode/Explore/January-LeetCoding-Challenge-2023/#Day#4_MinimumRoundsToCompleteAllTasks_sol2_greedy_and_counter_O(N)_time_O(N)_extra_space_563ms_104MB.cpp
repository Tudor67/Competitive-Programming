class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        const int N = tasks.size();

        unordered_map<int, int> count;
        for(int task: tasks){
            count[task] += 1;
        }

        int res = 0;
        for(const pair<int, int>& P: count){
            int taskCount = P.second;
            if(taskCount >= 2){
                res += (taskCount + 2) / 3;
            }else{
                return -1;
            }
        }

        return res;
    }
};