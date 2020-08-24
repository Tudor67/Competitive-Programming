class Solution {
private:
    int string_to_int(const string& s){
        int num = 0;
        for(char c: s){
            num = 10 * num + (c - '0');
        }
        return num;
    }
    
public:
    int openLock(vector<string>& deadends, string target) {
        const int MAX_VAL = (int)1e4;
        vector<bool> vis(MAX_VAL, false);
        for(const string& s: deadends){
            vis[string_to_int(s)] = true;
        }
        
        // bfs
        int target_num = string_to_int(target);
        vector<int> dist(MAX_VAL, -1);
        queue<string> q;
        
        if(!vis[0]){
            q.push("0000");
            dist[0] = 0;
        }

        while(!q.empty() && !vis[target_num]){
            string s = q.front(); q.pop();
            int num = string_to_int(s);

            for(int i = 0; i < 4; ++i){
                char next_char = (s[i] < '9' ? s[i] + 1 : '0');
                char prev_char = (s[i] > '0' ? s[i] - 1 : '9');
                string next_s = s; next_s[i] = next_char;
                string prev_s = s; prev_s[i] = prev_char;

                int next_num = string_to_int(next_s);
                int prev_num = string_to_int(prev_s);

                if(!vis[next_num]){
                    q.push(next_s);
                    vis[next_num] = true;
                    dist[next_num] = 1 + dist[num];
                }
                if(!vis[prev_num]){
                    q.push(prev_s);
                    vis[prev_num] = true;
                    dist[prev_num] = 1 + dist[num];
                }
            }
        }
        
        return dist[target_num];
    }
};