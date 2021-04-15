/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    vector<int> integers;
    int idx;
    
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        stack<deque<NestedInteger>> st;
        st.push({});
        for(const NestedInteger& nestedInteger: nestedList){
            st.top().push_back(nestedInteger);
        }
        
        while(!st.empty()){
            if(st.top().empty()){
                st.pop();
            }else{
                NestedInteger nestedInteger = st.top().front();
                st.top().pop_front();
                if(st.top().empty()){
                    st.pop();
                }
                if(nestedInteger.isInteger()){
                    integers.push_back(nestedInteger.getInteger());
                }else{
                    st.push({});
                    vector<NestedInteger> currentList = nestedInteger.getList();
                    for(const NestedInteger& currentNestedInteger: currentList){
                        st.top().push_back(currentNestedInteger);
                    }
                }
            }
        }
        
        idx = -1;
    }
    
    int next() {
        idx += 1;
        return integers[idx];
    }
    
    bool hasNext() {
        return (idx + 1 < (int)integers.size());
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */