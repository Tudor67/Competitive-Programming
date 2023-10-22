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
    stack<vector<NestedInteger>::const_iterator> begins;
    stack<vector<NestedInteger>::const_iterator> ends;

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        begins.push(nestedList.cbegin());
        ends.push(nestedList.cend());
    }
    
    int next() {
        int num = begins.top()->getInteger();
        begins.top() += 1;
        return num;
    }
    
    bool hasNext() {
        while(!begins.empty()){
            if(begins.top() == ends.top()){
                begins.pop();
                ends.pop();
            }else if(begins.top()->isInteger()){
                break;
            }else{
                const vector<NestedInteger>& nestedList = begins.top()->getList();
                begins.top() += 1;
                begins.push(nestedList.cbegin());
                ends.push(nestedList.cend());
            }
        }
        return !begins.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */