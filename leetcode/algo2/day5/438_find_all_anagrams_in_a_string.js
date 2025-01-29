const lodash = require("lodash")
const check_obj_eq = (a, b) => {
    const k1 = Object.keys(a).sort();
    const k2 = Object.keys(b).sort();
    if (k1.length !== k2.length) return false;
    if (!lodash.isEqual(k1, k2)) return false;
    else {
        for (const k of k1) {
            console.log(a[k], b[k])
            if (a[k] !== b[k]) return false;
        }
        return true;
    }
}
var findAnagrams = function (s, p) {
    let fre_s = {};
    let fre_p = {};
    let res = [];
    for (let i = 0; i < p.length; i++) {
        if (fre_s[p[i]] === undefined) fre_s[p[i]] = 1;
        else fre_s[p[i]]++;
    }
    for (let i = 0; i < s.length; i++) {
        if (i < p.length) {
            if (fre_p[s[i]] === undefined) fre_p[s[i]] = 1;
            else fre_p[s[i]]++;
        }
        else {
            if (fre_p[s[i - p.length]] > 1) fre_p[s[i - p.length]]--;
            else delete fre_p[s[i - p.length]];
            if (fre_p[s[i]] === undefined) fre_p[s[i]] = 1;
            else fre_p[s[i]]++;
        }
        if (check_obj_eq(fre_p, fre_s)) res.push(i - p.length + 1);
    }
    return res;
};

//better solution:
var findAnagrams = function (s, p) {
    const chars = new Array(26).fill(0), res = [];

    for (let i = 0; i < p.length; i++) {
        chars[p.charCodeAt(i) - 97]--;
    }

    main:
    for (let i = 0; i < s.length; i++) {
        chars[s.charCodeAt(i) - 97]++;

        if (i < p.length - 1) continue;
        if (i > p.length - 1) chars[s.charCodeAt(i - p.length) - 97]--;

        for (let j = 0; j < 26; j++) {
            if (chars[j]) continue main;
        }

        res.push(i - p.length + 1);
    }

    return res;
};


let s = "ababababab";
let p = "aab";
console.log(findAnagrams(s, p));
