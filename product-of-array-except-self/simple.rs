impl Solution {
    // Explain for 1 2 3 4
    // pre:           1  1 2 6
    // suf reverse: 24 12 4 1
    // result:       24 12 8 6
    // Time complexity is O(n)+O(n) = O(n)
    pub fn product_except_self(nums: Vec<i32>) -> Vec<i32> {
        let mut products: Vec<i32> = vec![];
        products.push(1);
        for i in 1..nums.len() {
            products.push(products[i-1]*nums[i-1]);
        }
        let mut suffix = 1;
        for i in (0..nums.len()).rev() {
            products[i] *= suffix;
            suffix *= nums[i];
        }
        products
    }
}