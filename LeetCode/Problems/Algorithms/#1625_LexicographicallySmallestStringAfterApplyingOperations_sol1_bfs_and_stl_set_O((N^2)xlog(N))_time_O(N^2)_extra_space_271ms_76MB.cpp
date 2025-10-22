class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        const int N = s.length();

        set<string> vis;
        vis.insert(s);

        queue<string> q;
        q.push(s);

        while(!q.empty()){
            string currStr = q.front();
            q.pop();

            // 1st operation
            string nextStr = currStr;
            for(int i = 1; i < N; i += 2){
                nextStr[i] = char('0' + ((currStr[i] - '0') + a) % 10);
            }
            if(!vis.count(nextStr)){
                vis.insert(nextStr);
                q.push(nextStr);
            }

            // 2nd operation
            nextStr = currStr;
            rotate(nextStr.begin(), nextStr.end() - b, nextStr.end());
            if(!vis.count(nextStr)){
                vis.insert(nextStr);
                q.push(nextStr);
            }
        }

        return *vis.begin();
    }
};