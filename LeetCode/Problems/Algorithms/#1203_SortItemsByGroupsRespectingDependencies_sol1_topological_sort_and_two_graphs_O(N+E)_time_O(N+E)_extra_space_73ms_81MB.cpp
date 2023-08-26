class Solution {
public:
    vector<int> sortItems(int N, int M, vector<int>& group, vector<vector<int>>& beforeItems) {
        // Step 1: each node with (group[node] == -1) should be seen as a node of a separate group
        //         create new group for each node with (group[node] == -1)
        int newGroupIndex = M - 1;
        for(int node = 0; node < N; ++node){
            if(group[node] == -1){
                newGroupIndex += 1;
                group[node] = newGroupIndex;
            }
        }
        const int TOTAL_GROUPS = newGroupIndex + 1;

        // Step 2: create one graph `G` for the input nodes
        //         create another graph `groupG` for the groups of the input nodes
        using Graph = vector<vector<int>>;
        
        Graph G(N);
        vector<int> inDegree(N);

        Graph groupG(TOTAL_GROUPS);
        vector<int> groupInDegree(TOTAL_GROUPS);

        for(int node = 0; node < N; ++node){
            for(int beforeNode: beforeItems[node]){
                G[beforeNode].push_back(node);
                inDegree[node] += 1;
                if(group[beforeNode] != group[node]){
                    groupG[group[beforeNode]].push_back(group[node]);
                    groupInDegree[group[node]] += 1;
                }
            }
        }

        // Step 3: run standard topological sort on the `groupG` graph
        queue<int> q;
        for(int currentGroup = 0; currentGroup < TOTAL_GROUPS; ++currentGroup){
            if(groupInDegree[currentGroup] == 0){
                q.push(currentGroup);
            }
        }

        vector<int> groupTopOrder;
        while(!q.empty()){
            int currentGroup = q.front();
            q.pop();

            groupTopOrder.push_back(currentGroup);

            for(int nextGroup: groupG[currentGroup]){
                groupInDegree[nextGroup] -= 1;
                if(groupInDegree[nextGroup] == 0){
                    q.push(nextGroup);
                }
            }
        }

        // Step 4: run partial topological sort on the graph `G` for each group separately
        //         process the groups using the topological order of groups (i.e., groupTopOrder from Step 3)
        vector<queue<int>> qFor(TOTAL_GROUPS);
        for(int node = 0; node < N; ++node){
            if(inDegree[node] == 0){
                qFor[group[node]].push(node);
            }
        }

        vector<int> res;
        for(int targetGroup: groupTopOrder){
            while(!qFor[targetGroup].empty()){
                int node = qFor[targetGroup].front();
                qFor[targetGroup].pop();

                res.push_back(node);

                for(int nextNode: G[node]){
                    inDegree[nextNode] -= 1;
                    if(inDegree[nextNode] == 0){
                        qFor[group[nextNode]].push(nextNode);
                    }
                }
            }
        }

        // Step 5: if the res vector doesn't contain all the nodes of the graph `G` => return {}
        if((int)res.size() != N){
            res.clear();
        }

        // Step 6: restore the initial group values of the nodes
        for(int node = 0; node < N; ++node){
            if(group[node] >= M){
                group[node] = -1;
            }
        }

        return res;
    }
};