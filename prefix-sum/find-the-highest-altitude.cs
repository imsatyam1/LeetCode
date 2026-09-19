public class Solution {
    public int LargestAltitude(int[] gain) {
        int n = gain.Length;
        int maxAltitude = 0;

        int altitude = 0;

        for(int i=0; i<n; i++)
        {
            altitude += gain[i];
            maxAltitude = Math.Max(maxAltitude, altitude);
        }

        return maxAltitude;
    }
}