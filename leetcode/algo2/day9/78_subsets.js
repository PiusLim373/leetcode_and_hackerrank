var subsets = function (nums) {
    let res = [[]];
    for (let i = 0; i < nums.length; i++) {
        let size = res.length;
        for (let j = 0; j < size; j++) {
            let temp = [...res[j]];
            temp.push(nums[i]);
            res.push(temp);
        }
    }
    return res;
};

let nums = [1, 2, 3, 4];
for (const x of subsets(nums)) {
    console.log(x);
}