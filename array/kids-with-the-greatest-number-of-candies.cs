public class Solution {
    public IList<bool> KidsWithCandies(int[] candies, int extraCandies) {
        
        int maxCandies = int.MinValue;
        int n = candies.Length;

        List<bool> ans = new List<bool>();

        for(int  i=0; i<n; i++) maxCandies = Math.Max(maxCandies, candies[i]);

        for(int i=0; i<n; i++)
        {
            if(candies[i] + extraCandies >= maxCandies) ans.Add(true);
            else ans.Add(false);
        }

        return ans;
    }
}