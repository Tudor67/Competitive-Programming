class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        // Step 1: create candidatesSets
        //         candidatesSets[0] contains even (valid) candidates
        //         candidatesSets[1] contains odd (valid) candidates
        vector<set<int>> candidatesSets(2);
        for(int i = 0; i < n; ++i){
            candidatesSets[i % 2].insert(i);
        }

        for(int i: banned){
            candidatesSets[i % 2].erase(i);
        }

        // Step 2: bfs from node p
        //         update candidatesSets after each step of bfs
        //         (by updating I mean removing visited candidates)
        vector<int> res(n, -1);
        queue<int> q;
        q.push(p);
        res[p] = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            int parity = (node + k - 1) % 2;
            int l = max(0, node - k + 1);     // start pos of the leftmost window of size k that includes current node
            int r = min(node + k - 1, n - 1); // end pos of the rightmost window of size k that includes current node

            int a = l + ((l + k - 1) - node); // min candidate connected with the current node
            int b = r - (node - (r - k + 1)); // max candidate connected with the current node

            set<int>::iterator itStart = candidatesSets[parity].lower_bound(a);
            set<int>::iterator itEnd = candidatesSets[parity].upper_bound(b);

            for(set<int>::iterator it = itStart; it != itEnd; it = next(it)){
                int nextNode = *it;
                if(res[nextNode] == -1){
                    res[nextNode] = res[node] + 1;
                    q.push(nextNode);
                }
            }

            candidatesSets[parity].erase(itStart, itEnd);
            candidatesSets[node % 2].erase(node);
        }

        return res;
    }
};