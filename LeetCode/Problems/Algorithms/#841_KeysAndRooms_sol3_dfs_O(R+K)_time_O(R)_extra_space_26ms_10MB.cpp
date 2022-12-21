class Solution {
private:
    void dfs(int room, vector<bool>& vis, vector<vector<int>>& rooms){
        if(vis[room]){
            return;
        }
        vis[room] = true;
        for(int nextRoom: rooms[room]){
            dfs(nextRoom, vis, rooms);
        }
    }

public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        const int R = rooms.size();

        vector<bool> vis(R, false);
        dfs(0, vis, rooms);

        return (count(vis.begin(), vis.end(), true) == R);
    }
};