public class Solution {
    public bool CheckIfPangram(string sentence) {
        int[] freq = new int[26];

        foreach(char ch in sentence)
        {
            int indx = ch - 'a';
            freq[indx]++;
        }

        for(int i=0; i<26; i++) 
        {
            if(freq[i] == 0) return false;
        }

        return true;
    }
}