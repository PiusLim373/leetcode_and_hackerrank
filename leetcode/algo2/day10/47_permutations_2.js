let res = [];
let temp = [];
let fre = new Map();
let target_length;

var dfs = function () {
    if (temp.length === target_length) {
        res.push([...temp]);
        return;
    }
    for (let x of fre.keys()) {
        if (fre.get(x) > 0) {
            temp.push(x);
            fre.set(x, fre.get(x) - 1);
            dfs();
            fre.set(x, fre.get(x) + 1);
            temp.pop();
        }
    }
}

var permuteUnique = function (nums) {
    target_length = nums.length;
    for (const x of nums) {
        if (fre.get(x) === undefined) fre.set(x, 1);
        else fre.set(x, fre.get(x) + 1);
    }
    dfs()
    return res;
};

let nums = [1, 1, 2, 2, 3];
console.log("hii")
for (const x of permuteUnique(nums)) {
    console.log(x);
}