class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        const int N = s.length();

        vector<int> childrenCount(N);
        for(int node = 1; node < N; ++node){
            childrenCount[parent[node]] += 1;
        }

        queue<int> q;
        vector<int> firstMaxLen(N);
        vector<int> secondMaxLen(N);
        for(int node = 0; node < N; ++node){
            if(childrenCount[node] == 0){
                q.push(node);
            }
        }

        int res = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            res = max(res, firstMaxLen[node] + 1 + secondMaxLen[node]);

            if(node == 0){
                break;
            }

            int len = firstMaxLen[node] + 1;
            if(s[node] != s[parent[node]] && len >= firstMaxLen[parent[node]]){
                secondMaxLen[parent[node]] = firstMaxLen[parent[node]];
                firstMaxLen[parent[node]] = len;
            }else if(s[node] != s[parent[node]] && len >= secondMaxLen[parent[node]]){
                secondMaxLen[parent[node]] = len;
            }

            childrenCount[parent[node]] -= 1;
            if(childrenCount[parent[node]] == 0){
                q.push(parent[node]);
            }
        }

        return res;
    }
};