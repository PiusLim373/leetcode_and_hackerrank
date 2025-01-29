var minSubArrayLen = function (target, nums) {
  let left = 0;
  let sum = 0;
  let res = Number.MAX_VALUE;

  for (let i = 0; i < nums.length; i++) {
    sum += nums[i];
    while (sum >= target) {
      res = Math.min(res, i - left + 1);
      sum -= nums[left++];
    }
  }
  return res === Number.MAX_VALUE ? 0 : res;
};
let nums = [2, 3, 1, 2, 4, 4];
target = 7;

console.log(minSubArrayLen(target, nums));
