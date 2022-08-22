class fenwick {
public:
    vector<int> bit;
    int N;
    fenwick(int N) {
        this->N = N + 5;
        bit.resize(this->N, 0);
    }
    
    int getParent(int n) {
        return (n - (n & -n));
    }
    
    int getNext(int n) {
        return (n + (n & -n));
    }
    
    int query(int index) {
        int result = 0;
        while(index > 0) {
            result += bit[index];
            index = getParent(index);
        }
        return result;
    }
    
    void update(int index, int value) {
        ++index;
        while(index < N) {
            bit[index] += value;
            index = getNext(index);
        }
    }
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int N = nums.size();
        vector<int> result(N);
        const int offset = 1e4;
        fenwick tree(2 * offset + 1);
        for (int i = N - 1; i >= 0; --i) {
            result[i] = tree.query(nums[i] + offset);
            tree.update(nums[i] + offset, 1);
        }
        return result;
    }
};