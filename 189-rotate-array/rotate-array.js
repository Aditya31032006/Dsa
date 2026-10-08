var rotate = function(nums, k) {
    let n = nums.length;
    k = k % n;

    nums.reverse();

    nums.splice(0, k, ...nums.slice(0, k).reverse());
    nums.splice(k, n - k, ...nums.slice(k).reverse());
};