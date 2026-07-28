class Solution {
    public static int feb(int n, int[] arr) {
        if (n <= 3)
            return n;

        if (arr[n] == -1)
            arr[n] = feb(n-1, arr) + feb(n-2, arr);

        return arr[n];
    } 

    public int climbStairs(int n) {
        int arr[] = new int[n+1];
        Arrays.fill(arr, -1);
        
        return feb(n, arr);
    }
}