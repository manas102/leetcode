//https://leetcode.com/problems/range-sum-query-mutable/

class RangeSumQueryMutable {
    private int[] segTree;
    private int len;
    private int[] nums;
    public NumArray(int[] nums) {
        this.len = nums.length;
        this.nums = nums;
        this.segTree = new int[4 * len];
        buildTree(0, 0, this.len - 1);
    }
    private void buildTree(int node, int start, int end) {
        if (start == end) {
            this.segTree[node] = this.nums[start];
            return;
        }
        int mid = start + (end - start)/2;
        buildTree(leftChild(node), start, mid);
        buildTree(rightChild(node), mid+1, end);
        this.segTree[node] = this.segTree[leftChild(node)] + this.segTree[rightChild(node)];
    }
    
    public void update(int index, int val) {
        updateInternal(0, 0, this.len-1, index, val);
    }

    private void updateInternal(int node, int start, int end, int idx, int val) {
        if (start == end) {
            this.nums[idx] = val;
            this.segTree[node] = val;
            return;
        }
        int mid = start + (end - start)/2;
        if (idx <= mid) {
            updateInternal(leftChild(node), start, mid, idx, val);// 0 based index
        } else {
            updateInternal(rightChild(node), mid+1, end, idx, val);// 0 based index
        }
        this.segTree[node] = this.segTree[leftChild(node)] + this.segTree[rightChild(node)];
    }
    
    public int sumRange(int left, int right) {
        return sumInternal(0, 0, this.len-1, left, right);   
    }

    private int sumInternal(int node, int start, int end, int left, int right) {
        if (right < start || end < left) {
            return 0;
        }
        if (left <= start && end <= right) {
            return this.segTree[node];
        }
        int mid = start + (end - start) / 2;
        return sumInternal(leftChild(node), start, mid, left, right) + 
        sumInternal(rightChild(node), mid+1, end, left, right);
    }

    private int leftChild(int idx) {
        return 2*idx + 1;
    }
    private int rightChild(int idx) {
        return 2*idx + 2;
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(index,val);
 * int param_2 = obj.sumRange(left,right);
 */