class MyCalendar {
public:
    map<int,int>mpp;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        mpp[startTime]++;
        mpp[endTime]--;
        int sum=0;
        for(auto &it : mpp){
            sum+=it.second;
            if(sum>1){
                mpp[startTime]--;
                mpp[endTime]--;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */