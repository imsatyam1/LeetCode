public class Solution {
    public int CountMatches(IList<IList<string>> items, string ruleKey, string ruleValue) {
        int n = items.Count;
        int count = 0;

        for(int i=0; i<n; i++)
        {
            switch (ruleKey)
            {
                case "type":
                    if(items[i][0] == ruleValue) 
                        count++;
                    break;

                case "color":
                    if(items[i][1] == ruleValue) 
                        count++;
                    break;

                case "name":
                    if(items[i][2] == ruleValue) 
                        count++;
                    break;
            }
        }

        return count;
    }
}