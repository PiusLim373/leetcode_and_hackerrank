var threeSum = function (nums) {
  var res = [];
  if (nums.length < 3) return res;
  nums.sort((a, b) => a - b);
  for (let i = 0; i < nums.length - 2; i++) {
    if (i > 0 && nums[i] == nums[i - 1]) continue;
    let j = i + 1;
    let k = nums.length - 1;
    let target = 0 - nums[i];

    while (j < k) {
      let sum = nums[i] + nums[j];
      if (sum == target) {
        let temp = [nums[i], nums[j], nums[k]];
        res.push(temp);
        while (j < k && nums[j] == temp[1]) j++;
        while (j < k && nums[k] == temp[2]) k--;
      } else if (sum < target) j++;
      else k--;
    }
  }
  return res;
};

var nums = [-1, 0, 1, 2, -1, -4];
console.log(threeSum(nums));
