#include<bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    priority_queue<int> lmaxh;
    priority_queue<int,vector<int>,greater<int>> rminh;
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(lmaxh.empty() || num <lmaxh.top()){
            lmaxh.push(num);
        }
        else{
            rminh.push(num);
        }
        if(abs((int)lmaxh.size()-(int)rminh.size())>1){
            rminh.push(lmaxh.top());
            lmaxh.pop();
        }
        else if(lmaxh.size()< rminh.size()){
            lmaxh.push(rminh.top());
            rminh.pop();
        }
    }
    
    double findMedian() {
        if(lmaxh.size()==rminh.size()){
            double mean=(lmaxh.top()+rminh.top());
            return mean/2;
        }
        return lmaxh.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */