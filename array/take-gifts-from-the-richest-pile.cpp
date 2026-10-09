class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        int n = gifts.size();

        for(int i=0; i<n; i++){
            pq.push(gifts[i]);
        }

        int i =0;
        while(i<k){
            int temp = pq.top();
            pq.pop();

            temp = sqrt(temp);
            pq.push(temp);

            i++;
        }

        long long sum = 0;
        while(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};