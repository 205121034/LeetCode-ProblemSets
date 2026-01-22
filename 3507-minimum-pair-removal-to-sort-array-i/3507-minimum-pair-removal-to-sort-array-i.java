class Solution {
    public int minimumPairRemoval(int[] nums) {
        if (nums.length <= 1) {
            return 0;
        }
        
        java.util.List<Integer> list = new java.util.ArrayList<>();
        for (int num : nums) {
            list.add(num);
        }
        
        int operations = 0;
        
        while (list.size() > 1) {
            boolean sorted = true;
            for (int i = 0; i < list.size() - 1; i++) {
                if (list.get(i) > list.get(i + 1)) {
                    sorted = false;
                    break;
                }
            }
            
            if (sorted) {
                break;
            }
            
            int minSum = Integer.MAX_VALUE;
            int minIndex = -1;
            
            for (int i = 0; i < list.size() - 1; i++) {
                int sum = list.get(i) + list.get(i + 1);
                if (sum < minSum) {
                    minSum = sum;
                    minIndex = i;
                }
            }
            
            list.remove(minIndex);
            list.set(minIndex, minSum);
            
            operations++;
        }
        
        return operations;
    }
}