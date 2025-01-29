var intervalIntersection = function (a, b) {
  let p1 = 0,
    p2 = 0;
  let res = [];
  while (p1 < a.length && p2 < b.length) {
    let low = max(a[p1][0], b[p2][0]);
    let high = min(a[p1][1], b[p2][1]);
    if (low <= high) res.push([low, high]);
    if (a[p1] == b[p2]) {
      p1++;
      p2++;
    } else {
      let c = a[p1][0],
        d = a[p1][1],
        e = b[p2][0],
        f = b[p2][1];
      if (d == f) {
        if (c > e) p1++;
        else p2++;
      } else if (d > f) p2++;
      else p1++;
    }
  }
  return res;
};

var a = [
  [0, 2],
  [5, 10],
  [13, 23],
  [24, 25],
];
var b = [
  [1, 5],
  [8, 12],
  [15, 24],
  [25, 26],
];
console.log(intervalIntersection(a, b));
