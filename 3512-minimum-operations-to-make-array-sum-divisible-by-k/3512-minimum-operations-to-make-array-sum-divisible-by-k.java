class Solution {
public int minOperations(int[] nums, int k) {
    long sum = 0;
    for (int num : nums) {
        sum += num;
    }
    
    int remainder = (int)(sum % k);
    
    if (remainder == 0) {
        return 0;
    }
    
    return remainder;
}
}