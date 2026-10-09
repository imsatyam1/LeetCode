class Solution {
    public boolean checkOnesSegment(String s) {
        char[] arr = s.toCharArray();
        int cnt = 0, ans = 0;
        int n = arr.length;

        for(int i=0; i<n; i++)
        {
            while(i <n && arr[i] == '1')
            {
                if(i + 1 == n || arr[i+1] == '0') ans++;
                
                i++;
            }
        }
        
        return (ans == 1) ? true : false;
    }
}