var numIslands = function (grid) {
  let m = grid.length;
  let n = grid[0].length;
  let island_count = 0;

  let dir_x = [0, 1, 0, -1];
  let dir_y = [-1, 0, 1, 0];

  let visit_queue = [];

  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      if (grid[i][j] === "1") {
        visit_queue.push([i, j]);
        grid[i][j] = "0";
        while (visit_queue.length) {
          let curr = visit_queue.shift();
          for (let k = 0; k < dir_x.length; k++) {
            if (
              curr[0] + dir_x[k] >= 0 &&
              curr[1] + dir_y[k] >= 0 &&
              curr[0] + dir_x[k] < m &&
              curr[1] + dir_y[k] < n &&
              grid[curr[0] + dir_x[k]][curr[1] + dir_y[k]] !== "0"
            ) {
              visit_queue.push([curr[0] + dir_x[k], curr[1] + dir_y[k]]);
              grid[curr[0] + dir_x[k]][curr[1] + dir_y[k]] = "0";
            }
          }
        }
        island_count++;
      }
    }
  }
  return island_count;
};
grid = [
  ["1", "1", "0", "0", "0"],
  ["1", "1", "0", "0", "0"],
  ["0", "0", "1", "0", "0"],
  ["0", "0", "0", "1", "1"],
];
console.log(numIslands(grid));
