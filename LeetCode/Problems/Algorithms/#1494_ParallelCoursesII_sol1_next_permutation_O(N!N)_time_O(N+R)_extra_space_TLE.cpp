class Solution {
public:
    int minNumberOfSemesters(int N, vector<vector<int>>& relations, int K) {
        if(relations.empty()){
            return (N + K - 1) / K;
        }
        
        vector<vector<int>> nextNodes(N + 1);
        vector<int> initialInDegree(N + 1, 0);
        for(const vector<int>& R: relations){
            int x = R[0];
            int y = R[1];
            nextNodes[x].push_back(y);
            initialInDegree[y] += 1;
        }
        
        int minSemesters = N;
        vector<int> p(N + 1);
        iota(p.begin(), p.end(), 0);
        vector<int> inDegree(N + 1);
        vector<int> semOf(N + 1);
        
        do{
            int semester = 1;
            int nodes = 0;
            copy(initialInDegree.begin(), initialInDegree.end(), inDegree.begin());
            fill(semOf.begin(), semOf.end(), 1);
            for(int i = 1; i <= N; ++i){
                int x = p[i];
                if(semester < semOf[x]){
                    semester = semOf[x];
                    nodes = 0;
                }
                if(inDegree[x] == 0){
                    nodes += 1;
                    if(nodes == K + 1){
                        semester += 1;
                        nodes = 1;
                    }
                    for(int nextNode: nextNodes[x]){
                        inDegree[nextNode] -= 1;
                        semOf[nextNode] = max(semOf[nextNode], semester + 1);
                    }
                }else{
                    semester = N;
                    break;
                }
                
            }
            minSemesters = min(minSemesters, semester);
        }while(next_permutation(p.begin() + 1, p.end()));
        
        return minSemesters;
    }
};