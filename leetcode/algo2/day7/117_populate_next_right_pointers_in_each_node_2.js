function Node(val, left, right, next) {
  this.val = val === undefined ? null : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
  this.next = next === undefined ? null : next;
}

var connect = function (root) {
  if (root === undefined) return undefined;
  let q = [];
  q.push(root);
  while (q.length) {
    let curr = undefined,
      next = undefined;
    let counter = q.length;
    while (counter--) {
      if (!curr) {
        curr = q.shift();
        if (curr.left) q.push(curr.left);
        if (curr.right) q.push(curr.right);
      } else if (!next) {
        next = q.shift();
        curr.next = next;
        if (next.left) q.push(next.left);
        if (next.right) q.push(next.right);
      } else {
        curr = q.shift();
        next.next = curr;
        if (curr.left) q.push(curr.left);
        if (curr.right) q.push(curr.right);
        next = curr;
      }
    }
  }
  return root;
};
