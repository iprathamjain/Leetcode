/*
    Implement data structure that gets the median from a data stream

    Max heap of lower values & min heap of higher values, access to mids

    Time: O(log n) + O(1)
    Space: O(n)
*/

class MedianFinder {
public:
    MedianFinder() {
        
    }
    //max and heap two containers
    void addNum(int num) {
        maxheap.push(num);
        if(maxheap.size() and minheap.size() and maxheap.top()>minheap.top())
        {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        
        if(maxheap.size() > minheap.size() + 1){
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        if(minheap.size() > maxheap.size() + 1){
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian() {
        if (minheap.size() == maxheap.size()) {
            return  (minheap.top() + maxheap.top()) / 2.0;
        } else {
            if(minheap.size() > maxheap.size())
                return minheap.top();
            else
                return maxheap.top();
        }
    }
private:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
};
