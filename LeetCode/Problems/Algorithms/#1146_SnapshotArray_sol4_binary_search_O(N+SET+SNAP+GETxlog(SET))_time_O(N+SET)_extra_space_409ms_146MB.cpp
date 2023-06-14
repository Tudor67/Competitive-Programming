class SnapshotArray {
private:
    vector<vector<pair<int, int>>> v;
    int currentSnapID;

public:
    SnapshotArray(int length) {
        v.assign(length, {{0, 0}});
        currentSnapID = 0;
    }
    
    void set(int index, int val) {
        v[index].push_back({currentSnapID, val});
    }
    
    int snap() {
        currentSnapID += 1;
        return currentSnapID - 1;
    }
    
    int get(int index, int snap_id) {
        vector<pair<int, int>>::iterator it = upper_bound(v[index].begin(), v[index].end(),
                                                          pair<int, int>{snap_id, INT_MAX});
        return prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */