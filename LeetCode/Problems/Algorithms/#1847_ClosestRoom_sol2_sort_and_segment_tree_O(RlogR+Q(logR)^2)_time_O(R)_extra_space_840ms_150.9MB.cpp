class SegmentTree{
private:
    const int N;
    vector<int> tree;
    
    void update(int node, int l, int r, const int& POS, const int& VAL){
        if(l == r){
            tree[node] = VAL;
        }else{
            int mid = (l + r) / 2;
            if(POS <= mid){
                update(2 * node + 1, l, mid, POS, VAL);
            }else{
                update(2 * node + 2, mid + 1, r, POS, VAL);
            }
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }
    
    int query(int node, int l, int r, const int& L, const int& R){
        if(r < L || R < l){
            return 0;
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        return max(query(2 * node + 1, l, mid, L, R),
                   query(2 * node + 2, mid + 1, r, L, R));
    }
    
    int getFirstPos(int node, int l, int r, const int& START_POS, const int& MIN_VAL){
        if(tree[node] < MIN_VAL){
            return N;
        }
        if(l == r){
            return l;
        }
        int mid = (l + r) / 2;
        if(START_POS <= mid && MIN_VAL <= query(0, 0, N - 1, START_POS, mid)){
            return getFirstPos(2 * node + 1, l, mid, START_POS, MIN_VAL);
        }else{
            return getFirstPos(2 * node + 2, mid + 1, r, START_POS, MIN_VAL);
        }
    }
    
public:
    SegmentTree(const int& N): N(N){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.resize(2 * minLeaves);
    }
    
    void update(const int& POS, const int& VAL){
        update(0, 0, N - 1, POS, VAL);
    }
    
    int getFirstPos(int startPos, const int& MIN_VAL){
        startPos = min(startPos, N - 1);
        startPos = max(0, startPos);
        return getFirstPos(0, 0, N - 1, startPos, MIN_VAL);
    }
};

class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        const int R = rooms.size();
        const int Q = queries.size();
        
        // Step 1: sort rooms
        vector<pair<int, int>> sortedRooms(R);
        for(int i = 0; i < R; ++i){
            sortedRooms[i] = {rooms[i][0], rooms[i][1]};
        }
        
        sort(sortedRooms.begin(), sortedRooms.end());
        
        // Step 2: create the segment tree
        SegmentTree segmentTreeLR(R);
        SegmentTree segmentTreeRL(R);
        for(int i = 0; i < R; ++i){
            int roomId = sortedRooms[i].first;
            int roomSize = sortedRooms[i].second;
            segmentTreeLR.update(i, roomSize);
            segmentTreeRL.update(R - 1 - i, roomSize);
        }
        
        // Step 3: process queries
        vector<int> answer(Q, -1);
        vector<int> candidateRoomIds;
        for(int i = 0; i < Q; ++i){
            int qPrefRoomId = queries[i][0];
            int qMinSize = queries[i][1];
            
            int startPos = lower_bound(sortedRooms.begin(), sortedRooms.end(), pair<int, int>{qPrefRoomId, qMinSize}) - sortedRooms.begin();
            
            int idx1 = segmentTreeLR.getFirstPos(startPos, qMinSize);
            int idx2 = R - 1 - segmentTreeRL.getFirstPos(R - 1 - (startPos - 1), qMinSize);
            
            candidateRoomIds.clear();
            if(0 <= idx2 && idx2 < R){
                candidateRoomIds.push_back(sortedRooms[idx2].first);
            }
            if(0 <= idx1 && idx1 < R){
                candidateRoomIds.push_back(sortedRooms[idx1].first);
            }
            
            if(!candidateRoomIds.empty()){
                if(abs(qPrefRoomId - candidateRoomIds.front()) <= abs(qPrefRoomId - candidateRoomIds.back())){
                    answer[i] = candidateRoomIds.front();
                }else{
                    answer[i] = candidateRoomIds.back();
                }
            }
        }
        
        return answer;
    }
};