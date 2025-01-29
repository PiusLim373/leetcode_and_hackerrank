var subsetsWithDup = function (nums) {
    let res = [[]];
    nums = nums.sort((a, b) => a - b);
    let start;
    for (let i = 0; i < nums.length; i++) {
        if (i === 0 || nums[i] !== nums[i - 1]) start = 0;
        for (let end = res.length; start < end; start++) {
            let temp = [...res[start]];
            temp.push(nums[i]);
            res.push(temp);
        }
    }
    return res;
};

let nums = [1, 2, 2, 3];
for (const x of subsetsWithDup(nums)) {
    console.log(x);
}