class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        const int R = rooms.size();
        const int Q = queries.size();
        
        // Step 1: sort rooms
        vector<pair<int, int>> sortedRoomSizeId(R);
        for(int i = 0; i < R; ++i){
            sortedRoomSizeId[i] = {rooms[i][1], rooms[i][0]};
        }
        
        sort(sortedRoomSizeId.begin(), sortedRoomSizeId.end());
        
        // Step 2: sort queries
        vector<tuple<int, int, int>> sortedQuerySizePrefIdx(Q);
        for(int i = 0; i < Q; ++i){
            sortedQuerySizePrefIdx[i] = {queries[i][1], queries[i][0], i};
        }
        
        sort(sortedQuerySizePrefIdx.begin(), sortedQuerySizePrefIdx.end());
        
        // Step 3: process sorted queries
        set<int> roomIds;
        for(const pair<int, int>& P: sortedRoomSizeId){
            int roomId = P.second;
            roomIds.insert(roomId);
        }
        
        vector<int> answer(Q, -1);
        int rIdx = 0;
        for(const tuple<int, int, int>& T: sortedQuerySizePrefIdx){
            int qMinSize, qPref, qIdx;
            tie(qMinSize, qPref, qIdx) = T;
            
            while(rIdx < R && sortedRoomSizeId[rIdx].first < qMinSize){
                roomIds.erase(sortedRoomSizeId[rIdx].second);
                rIdx += 1;
            }
            
            if(roomIds.empty()){
                break;
            }else{
                int roomId = INT_MAX;
                int minDist = INT_MAX;
                multiset<int>::iterator it = roomIds.lower_bound(qPref);
                if(it != roomIds.end()){
                    roomId = *it;
                    minDist = abs(*it - qPref);
                }
                if(it != roomIds.begin() && abs(*prev(it) - qPref) <= minDist){
                    roomId = *prev(it);
                    minDist = abs(*prev(it) - qPref);
                }
                answer[qIdx] = roomId;
            }
        }
        
        return answer;
    }
};