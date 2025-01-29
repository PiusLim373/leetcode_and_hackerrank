var res = [];
var temp = [];
var target = 0;

const dfs_helper = (graph, curr) => {
    temp.push(curr);
    if (curr === target) res.push([...temp]);
    for (const x of graph[curr]) dfs_helper(graph, x)
    temp.pop();
}

var allPathsSourceTarget = function (graph) {
    target = graph.length - 1;
    dfs_helper(graph, 0);
    return res;
};
let graph = [[4, 3, 1], [3, 2, 4], [3], [4], []];
console.log(allPathsSourceTarget(graph));