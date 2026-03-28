class Solution {
    public int difference(String s1,String s2)
    {
        int hour1 = Integer.parseInt(s1.substring(0,2));
        int min1 = Integer.parseInt(s1.substring(3,5));
        int total1 = (hour1*60) + min1;

        int hour2 = Integer.parseInt(s2.substring(0,2));
        int min2 = Integer.parseInt(s2.substring(3,5));
        int total2 = (hour2*60) + min2;

        int diff1 = Math.abs(total1 - total2);
        int diff2 = 1440 - diff1;

        return Math.min(diff1,diff2);
    }
    public int findMinDifference(List<String> timePoints) 
    {
        
        Collections.sort(timePoints);
        
        timePoints.add(timePoints.get(0));
        int n = timePoints.size();

        int minDiff = 999999;

        for(int i = 0;i < n-1;i++)
        {
            String str1 = timePoints.get(i);
            String str2 = timePoints.get(i+1);
            
            int ans = difference(str1,str2);
            minDiff = Math.min(ans,minDiff);
        }

        return minDiff;
    }
}