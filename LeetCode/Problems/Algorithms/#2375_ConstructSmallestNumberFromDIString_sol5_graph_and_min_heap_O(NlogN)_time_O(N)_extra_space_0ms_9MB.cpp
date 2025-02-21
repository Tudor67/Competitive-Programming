class Solution {
public:
    string smallestNumber(string pattern) {
        const int N = pattern.length();

        vector<vector<int>> G(N + 1);
        vector<int> inDegree(N + 1);
        for(int i = 0; i < N; ++i){
            if(pattern[i] == 'I'){
                G[i].push_back(i + 1);
                inDegree[i + 1] += 1;
            }else{
                G[i + 1].push_back(i);
                inDegree[i] += 1;
            }
        }

        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int node = 0; node <= N; ++node){
            if(inDegree[node] == 0){
                minHeap.push(node);
            }
        }

        string res(N + 1, '0');
        for(char digit = '1'; digit <= '1' + N; ++digit){
            int node = minHeap.top();
            minHeap.pop();

            res[node] = digit;

            for(int nextNode: G[node]){
                inDegree[nextNode] -= 1;
                if(inDegree[nextNode] == 0){
                    minHeap.push(nextNode);
                }
            }
        }

        return res;
    }
};