class Solution {
public:
    int minJumps(vector<int>& arr) {
        if(arr.size() == 1){
            return 0;
        }
        
        const int N = arr.size();
        unordered_map<int, vector<int>> positionsOf;
        for(int i = 0; i < N; ++i){
            positionsOf[arr[i]].push_back(i);
        }
        
        vector<int> visited(N, false);
        unordered_set<int> pos1;
        unordered_set<int> pos2;
        pos1.insert(0);
        pos2.insert(N - 1);
        visited[0] = true;
        visited[N - 1] = true;
        
        int step = 0;
        while(!pos1.empty()){
            if(pos1.size() > pos2.size()){
                swap(pos1, pos2);
            }
            
            unordered_set<int> tempPos;
            for(int pos: pos1){
                for(int nextPos: {pos - 1, pos + 1}){
                    if(0 <= nextPos && nextPos < N){
                        if(pos2.count(nextPos)){
                            return step + 1;
                        }
                        if(!visited[nextPos]){
                            tempPos.insert(nextPos);
                            visited[nextPos] = true;
                        }
                    }
                }
                for(int nextPos: positionsOf[arr[pos]]){
                    if(0 <= nextPos && nextPos < N){
                        if(pos2.count(nextPos)){
                            return step + 1;
                        }
                        if(!visited[nextPos]){
                            tempPos.insert(nextPos);
                            visited[nextPos] = true;
                        }
                    }
                }
                positionsOf[arr[pos]].clear();
            }
            
            pos1 = move(tempPos);
            step += 1;
        }
        
        return -1;
    }
};