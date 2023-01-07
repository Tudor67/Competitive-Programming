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
                if(taskCount % 3 == 0){
                    res += taskCount / 3;
                }else if(taskCount % 3 == 1){
                    res += 2;
                    res += (taskCount - 4) / 3;
                }else{
                    res += 1;
                    res += (taskCount - 2) / 3;
                }
            }else{
                res = -1;
                break;
            }
        }

        return res;
    }
};