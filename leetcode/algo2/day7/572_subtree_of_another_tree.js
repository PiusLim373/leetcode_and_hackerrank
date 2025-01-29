function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

var helper = function (root, subRoot) {
  if (!root && !subRoot) return true;
  if (!root || !subRoot) return false;
  return (
    root.val === subRoot.val &&
    helper(root.left, subRoot.left) &&
    helper(root.right, subRoot.right)
  );
};

var isSubtree = function (root, subRoot) {
  if (!root) return false;
  if (!subRoot) return true;
  return (
    helper(root, subRoot) ||
    isSubtree(root.left, subRoot) ||
    isSubtree(root.right.subRoot)
  );
};
