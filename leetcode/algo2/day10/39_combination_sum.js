let res = [];
var solve = (candidates, target, temp_arr, pointer, sum) => {
    if (sum === target) {
        res.push([...temp_arr]);
        return;
    }
    if (pointer >= candidates.length || sum >= target) {
        return;
    }
    temp_arr.push(candidates[pointer]);
    solve(candidates, target, temp_arr, pointer, sum + candidates[pointer]);
    temp_arr.pop();
    solve(candidates, target, temp_arr, pointer + 1, sum);
}


var combinationSum = function (candidates, target) {
    solve(candidates, target, [], 0, 0);
    return res;
};


let candidates = [2, 3, 6, 7];
let target = 6;
for (const x of combinationSum(candidates, target)) {
    console.log(x);
}