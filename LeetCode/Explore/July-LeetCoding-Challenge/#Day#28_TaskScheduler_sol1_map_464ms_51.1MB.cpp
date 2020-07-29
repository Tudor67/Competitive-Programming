class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> cnt;
        for(char task: tasks){
            cnt[task] += 1;
        }
        
        string s(1 + tasks.size() * (n + 1), '.');
        int pos = 0;
        for(int iteration = 1; !cnt.empty(); ++iteration){
            for(map<char, int>::iterator it = cnt.begin(); it != cnt.end();){
                char task = it->first;
                s[pos] = task;
                pos += 1;
                cnt[task] -= 1;
                ++it;
                if(cnt[task] == 0){
                    cnt.erase(task);
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