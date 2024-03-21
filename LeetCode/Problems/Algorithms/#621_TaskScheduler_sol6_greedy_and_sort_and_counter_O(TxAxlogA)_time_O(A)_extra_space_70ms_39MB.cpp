class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        const int T = tasks.size();
        const int A = 26;
        
        unordered_map<char, int> freqOf;
        for(char c: tasks){
            freqOf[c] += 1;
        }

        vector<int> f;
        for(const pair<const char, int>& P: freqOf){
            f.push_back(P.second);
        }

        sort(f.begin(), f.end());

        int res = 0;
        while(f.back() >= 1){
            int contrib = 0;
            int startIndex = max(0, (int)f.size() - (n + 1));
            for(int i = startIndex; i < (int)f.size(); ++i){
                if(f[i] >= 1){
                    f[i] -= 1;
                    contrib += 1;
                }
            }

            sort(f.begin(), f.end());

            if(f.back() >= 1){
                res += n + 1;
            }else{
                res += contrib;
            }
        }

        return res;
    }
};