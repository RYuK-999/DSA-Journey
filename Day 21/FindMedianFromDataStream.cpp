class MedianFinder {
public:

    priority_queue<int> left;                               
    priority_queue<int, vector<int>, greater<int>> right;

    MedianFinder() {}
    
    void addNum(int num) {
        
        if (left.empty() && right.empty()){
            left.push(num);
            return;
        }

        if (left.top() > num){
            left.push(num);
        }
        else{
            right.push(num);
        }

        int diff = abs((int)left.size() - (int)right.size());
        if (diff > 1){
            if (left.size() > right.size()){
                right.push(left.top());
                left.pop();
            }
            else{
                left.push(right.top());
                right.pop();
            }
        }
    }
    
    double findMedian() {
        if (left.size() == right.size()){
            double mean = (left.top() + right.top())/2.0;
            return mean;
        }
        else if (left.size() > right.size()){
            return left.top();
        }
        else{
            return right.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


 // Left priority queue is max heap it stores the values which are lesser
 // Right priority queue is min heap which stores the higher or upper values of the array

