var numSubarrayProductLessThanK = function (nums, k) {
  if (k <= 1) return 0;
  let left = 0;
  let product = 1;
  let res = 0;

  for (let right = 0; right < nums.length; right++) {
    product *= nums[right];
    while (product >= k) product /= nums[left++];
    res += right - left + 1;
  }
  return res;
};

let nums = [10, 5, 2, 6];
let k = 100;

console.log(numSubarrayProductLessThanK(nums, k));
