let res = [];

var solve = (nums, target, curr, pointer, temp_sum) => {
    if (temp_sum === target) res.push([...curr]);
    if (temp_sum > target) return;
    let prev = -1;
    for (let i = pointer; i < nums.length; i++) {
        if (nums[i] === prev) continue;
        curr.push(nums[i]);
        solve(nums, target, curr, i + 1, temp_sum + nums[i]);
        curr.pop();
        prev = nums[i];
    }
}


var combinationSum2 = function (nums, target) {
    nums.sort((a, b) => a - b);
    solve(nums, target, [], 0, 0);
    return res;
};
let nums = [2, 5, 2, 1, 2];
let target = 5;
for (const x of combinationSum2(nums, target)) {
    console.log(x);
}