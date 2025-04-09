class BIT {
    private int[] tree;

    BIT(int[] nums) {
        // make 1 based index
        this.tree = new int[nums.length + 1];
        for (int i = 1; i <= nums.length; ++i) {
            this.tree[i] = nums[i-1];
        }
        buildTree();
    }

    private void buildTree() {
        for (int i = 1; i < tree.length; ++i) {
            int j = i + getLSB(i);
            if (j < tree.length) {
                this.tree[j] += this.tree[i];
            }
        }
    }

    private int getLSB(int i) { // 00010100 => 11101011 => 11101100
        return i & -i;
    }

    int sumRange(int left, int right) {
        return prefixSum(right) - prefixSum(left-1);
    }

    private int prefixSum(int index) {
        int sum = 0;
        for (int i = index; i > 0; i = i - getLSB(i)) {
            sum += this.tree[i];
        }
        return sum;
    }

    void update(int index, int val) {
        int currVal = sumRange(index, index);
        int newVal = val - currVal; 
        for (int i = index; i < this.tree.length; i = i + getLSB(i)) {
            this.tree[i] += newVal;
        }
    }
}
public class NumArray {
    private BIT bit;

    public NumArray(int[] nums) {
        this.bit = new BIT(nums);
    }
    
    public void update(int index, int val) {
        this.bit.update(index+1, val);
    }
    
    public int sumRange(int left, int right) {
        return this.bit.sumRange(left+1, right+1);
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(index,val);
 * int param_2 = obj.sumRange(left,right);
 */
