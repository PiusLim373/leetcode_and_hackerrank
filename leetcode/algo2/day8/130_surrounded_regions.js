
var dfs = function (board, i, j) {
    let m = board.length;
    let n = board[0].length;

    let dir_x = [0, 1, 0, -1];
    let dir_y = [-1, 0, 1, 0];
    let q = [];

    q.push([i, j]);
    board[i][j] = '#';

    while (q.length) {
        let curr = q.shift();
        for (let k = 0; k < dir_x.length; k++) {
            let visit_x = curr[0] + dir_x[k];
            let visit_y = curr[1] + dir_y[k];

            if (visit_x >= 0 && visit_y >= 0 && visit_x <= m - 1 && visit_y <= n - 1 && board[visit_x][visit_y] === 'O') {
                q.push([visit_x, visit_y]);
                board[visit_x][visit_y] = '#';
            }
        }
    }
}

var solve = function (board) {
    let m = board.length;
    let n = board[0].length;

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (i === 0 || j === 0 || i === m - 1 || j === n - 1) {
                if (board[i][j] === 'O') dfs(board, i, j);
            }
        }
    }

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (board[i][j] === '#') board[i][j] = 'O';
            else if (board[i][j] === 'O') board[i][j] = 'X';
        }
    }
};
let board = [["X", "X", "X", "X"], ["X", "O", "O", "X"], ["X", "X", "O", "X"], ["X", "O", "X", "X"]];
solve(board)
for (const x of board) {
    console.log(x);
}