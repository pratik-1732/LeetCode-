class MedianFinder {
public:
    vector<int> arr;
    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int>> mini;
    double median= 0.0;
    vector<double> ans;
    int signum(int a, int b){
        if(a==b) return 0; 
        else if(a>b) return 1;
        else return -1;
    }

    void callmedian(int ele){
        switch(signum(maxi.size(), mini.size())){
            case 0: 
                if(ele>median){
                    mini.push(ele);
                    median= mini.top();
                }
                else{
                    maxi.push(ele);
                    median= maxi.top();
                }
            break;
            case 1:
                if(ele>median){
                    mini.push(ele);
                    median= (maxi.top()+mini.top())/2.0;
                }
                else{
                    mini.push(maxi.top());
                    maxi.pop();
                    maxi.push(ele);
                    median= (maxi.top()+mini.top())/2.0;
                }
            break;
            case -1:
                if(ele>median){
                    maxi.push(mini.top());
                    mini.pop();
                    mini.push(ele);
                    median= (maxi.top()+mini.top())/2.0;
                }
                else{
                    maxi.push(ele);
                    median= (maxi.top()+mini.top())/2.0;
                }
            break;
        }
    }

    MedianFinder() {    
    }
    
    void addNum(int num) {
        arr.push_back(num);
        callmedian(num);
        ans.push_back(median);
    }
    
    double findMedian() {
        int n= ans.size();
        return ans[n-1];
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */