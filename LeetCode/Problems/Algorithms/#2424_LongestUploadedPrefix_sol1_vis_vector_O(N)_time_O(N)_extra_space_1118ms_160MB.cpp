class LUPrefix {
private:
    vector<bool> vis;
    int maxPrefixLen;
    
public:
    LUPrefix(int n) {
        vis.resize(n + 1, false);
        maxPrefixLen = 0;
    }
    
    void upload(int video) {
        vis[video] = true;
    }
    
    int longest() {
        while(maxPrefixLen + 1 < (int)vis.size() && vis[maxPrefixLen + 1]){
            maxPrefixLen += 1;
        }
        return maxPrefixLen;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */