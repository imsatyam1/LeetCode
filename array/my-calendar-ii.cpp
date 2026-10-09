class MyCalendarTwo {
        vector<pair<int, int>> overallBooking;
        vector<pair<int, int>> overlappedBooking;
public:
    bool  checkOverlapped(int start1, int end1, int start2, int end2){
        return (max(start1, start2) < min(end1, end2));
    }

    pair<int, int> findOverlappedRegion(int start1, int end1, int start2, int end2){
        return {max(start1, start2), min(end1, end2)};
    }
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(pair<int, int> region: overlappedBooking){
            if(checkOverlapped(region.first, region.second, start, end)){
                return false;
            }
        }
        for(pair<int, int> booking: overallBooking){
            if(checkOverlapped(booking.first, booking.second, start, end)){
                overlappedBooking.push_back(findOverlappedRegion(booking.first, booking.second, start, end));
            }
        }
        overallBooking.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */