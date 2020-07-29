class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26, 0);
        for(char task: tasks){
            cnt[task - 'A'] += 1;
        }
        
        vector<char> remaining_tasks;
        for(char task = 'A'; task <= 'Z'; ++task){
            if(cnt[task - 'A']){
                remaining_tasks.push_back(task);
            }
        }
        
        string s(1 + tasks.size() * (n + 1), '.');
        int pos = 0;
        for(int iteration = 1; !remaining_tasks.empty(); ++iteration){
            for(char task: remaining_tasks){
                s[pos] = task;
                pos += 1;
                cnt[task - 'A'] -= 1;
            }
            
            // remove tasks with cnt[task - 'A'] == 0
            int m = 0;
            for(int i = 0; i < remaining_tasks.size(); ++i){
                if(cnt[remaining_tasks[i] - 'A']){
                    remaining_tasks[m] = remaining_tasks[i];
                    m += 1;
                }
            }
            remaining_tasks.resize(m);
            
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