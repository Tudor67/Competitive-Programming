class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26, 0);
        for(char task: tasks){
            cnt[task - 'A'] += 1;
        }
        
        string s(1 + tasks.size() * (n + 1), '.');
        int remaining_tasks = tasks.size();
        int pos = 0;
        for(int iteration = 1; remaining_tasks > 0; ++iteration){
            for(int task = 'A'; task <= 'Z'; ++task){
                if(cnt[task - 'A'] > 0){
                    s[pos] = task;
                    pos += 1;
                    cnt[task - 'A'] -= 1;
                    remaining_tasks -= 1;
                }
            }
            pos = max(iteration * (n + 1), pos);
        }
        
        int answer = 0;
        for(int pos = (int)s.length() - 1; pos >= 0; --pos){
            if(s[pos] != '.'){
                answer = pos + 1;
                break;
            }
        }
        
        return answer;
    }
};