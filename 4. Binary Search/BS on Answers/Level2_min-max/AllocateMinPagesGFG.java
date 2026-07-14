class Solution {
    public static boolean isPossible(int[] arr, int n, int k, int maxPage) {
        int pageSum=0, count=1;
        for(int e: arr) {
            if(e>maxPage)
                return false;
                
            if(pageSum+e > maxPage) {
                pageSum=e;
                if(++count > k) return false;
            }
            else {
                pageSum+=e;
            }
        }
        
        return count<=k;
    }
    
    public int findPages(int[] arr, int k) {
        // code here
        if(k>arr.length)
            return -1;
            
        int result = -1;
            
        int low = Arrays.stream(arr).min().getAsInt();
        int high = Arrays.stream(arr).sum();
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(arr, arr.length, k, mid)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return result;
    }
}