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
    stack<deque<NestedInteger>> st;
    
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        st.push(deque<NestedInteger>{nestedList.begin(), nestedList.end()});
    }
    
    int next() {
        if(hasNext()){
            NestedInteger nestedInteger = st.top().front();
            st.top().pop_front();
            return nestedInteger.getInteger();
        }
        return INT_MIN;
    }
    
    bool hasNext() {
        while(!st.empty()){
            if(st.top().empty()){
                st.pop();
            }else{
                NestedInteger nestedInteger = st.top().front();
                if(nestedInteger.isInteger()){
                    return true;
                }else{
                    st.top().pop_front();
                    st.push(deque<NestedInteger>{nestedInteger.getList().begin(), nestedInteger.getList().end()});
                }
            }
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */