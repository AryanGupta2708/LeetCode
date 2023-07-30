class Solution {
private : 
  bool canCompleteTrips(long long time,vector<int> &travelTimes,int totalTrips)
  {
      long long tripsCompleted = 0,n = travelTimes.size();
      for(int i=0; i < n; ++i)
      {
          tripsCompleted += time/travelTimes[i];
      }
      return tripsCompleted >= totalTrips;
  }
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        int minTime = *min_element(time.begin(),time.end());
        /*You can tighten the lower-bound to min(time) because you need to spend 
        at least that much time to carry out a single trip. You can also tighten the
        upper-bound to min(time) * totalTrips because that much time is sufficient for the
        fastest bus to perform all trips by itself.*/
        long long low = minTime,high = 1LL*minTime*totalTrips;
        while(low <= high)
        {
            long long mid = low + (high-low)/2;
            canCompleteTrips(mid,time,totalTrips) ? high = mid-1 : low = mid+1;
        }
        return low;
    }
}; 