var backspaceCompare = function (s, t) {
  let ss = "",
    tt = "";
  for (let i = 0; i < s.length; i++) {
    if (s[i] !== "#") {
      ss = ss.concat(s[i]);
    } else if (ss.length) {
      ss = ss.slice(0, ss.length - 1);
    }
  }
  for (let i = 0; i < t.length; i++) {
    if (t[i] !== "#") {
      tt = tt.concat(t[i]);
    } else if (tt.length) {
      tt = tt.slice(0, tt.length - 1);
    }
  }
  console.log(ss, tt);
  return ss === tt;
};

var s = "ab###";
var t = "c#d#";
console.log(backspaceCompare(s, t));
