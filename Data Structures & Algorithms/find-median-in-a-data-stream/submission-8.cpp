class MedianFinder {
public:
    priority_queue<int> leftMaxHeap;
    priority_queue<int, vector<int>, greater<int>> rightMinHeap;

    MedianFinder() {
    }

    void addNum(int num) {
        leftMaxHeap.push(num);

        rightMinHeap.push(leftMaxHeap.top());
        leftMaxHeap.pop();

        if (rightMinHeap.size() > leftMaxHeap.size()) {
            leftMaxHeap.push(rightMinHeap.top());
            rightMinHeap.pop();
        }
    }

    double findMedian() {
        if (leftMaxHeap.size() > rightMinHeap.size()) {
            return leftMaxHeap.top();
        }

        return (leftMaxHeap.top() + rightMinHeap.top()) / 2.0;
    }
};