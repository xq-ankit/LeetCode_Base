class MyCalendarThree {
public:
map<int,int>mpp;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        mpp[start]++;
        mpp[end]--;
        int sum=0;
        int ans=0;
        for(auto &it :mpp){
            sum+=it.second;
            ans=max(ans,sum);
            
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */