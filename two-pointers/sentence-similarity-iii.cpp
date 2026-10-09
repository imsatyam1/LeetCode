class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if(sentence1.length() < sentence2.length()) swap(sentence1, sentence2);

        deque<string> dq1;
        deque<string> dq2;
        string token;
        
        stringstream ss1(sentence1);
        while(ss1 >> token){
            dq1.push_back(token);
        }

        stringstream ss2(sentence2);
        while(ss2 >> token){
            dq2.push_back(token);
        }

        while(!dq1.empty() && !dq2.empty() && dq1.front() == dq2.front()){
            dq1.pop_front();
            dq2.pop_front();
        }

        while(!dq1.empty() && !dq2.empty() && dq1.back() == dq2.back()){
            dq1.pop_back();
            dq2.pop_back();
        }

        return dq2.empty();
    }
};