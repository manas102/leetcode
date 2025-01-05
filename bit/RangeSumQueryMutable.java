// Question: https://leetcode.com/problems/range-sum-query-mutable/
// BIT: https://cp-algorithms.com/data_structures/fenwick.html
class RangeSumQueryMutable {
    int[] bit;
    int[] nums;
    int inputLen;
    public NumArray(int[] nums) {
        this.inputLen = nums.length;
        this.bit = new int[inputLen+1];
        this.nums = nums;
        Arrays.fill(this.bit, 0);
        for (int i = 0; i < nums.length; ++i) {
            updateInternal(i, nums[i]);
        }
    }
    
    public void update(int index, int val) {
        int diff = val - this.nums[index];
        this.nums[index] = val;
        updateInternal(index, diff);
    }

    private void updateInternal(int index, int delta) {
        ++index; // 1 based index
        for (; index <= this.inputLen; index += (index & -index)) {
            this.bit[index] += delta;
        }
    }
    
    public int sumRange(int left, int right) {
        return sum(right) - sum(left-1);
    }

    private int sum(int index) {
        ++index; // 1 based index
        int ret = 0;
        for (; index > 0; index -= (index & -index)) {
            ret += this.bit[index];
        }
        return ret;
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(index,val);
 * int param_2 = obj.sumRange(left,right);
 */