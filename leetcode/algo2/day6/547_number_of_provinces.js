var findCircleNum = function (isConnected) {
  let connected = new Map();
  for (let i = 0; i < isConnected.length; i++) {
    for (let j = 0; j < isConnected[i].length; j++) {
      if (isConnected[i][j]) {
        let temp_arr = [j];
        if (connected.get(i) === undefined) connected.set(i, temp_arr);
        else connected.set(i, connected.get(i).concat(temp_arr));
      }
    }
  }

  let province_count = 0;
  let visit_queue = [];
  for (let key of connected.keys()) {
    if (connected.get(key).length) {
      visit_queue.push(connected.get(key).shift());
      while (visit_queue.length) {
        let curr = visit_queue.shift();
        while (connected.get(curr).length) {
          visit_queue.push(connected.get(curr).shift());
        }
      }
      province_count++;
    }
  }
  return province_count;
};

grid = [
  [1, 0, 0],
  [0, 1, 0],
  [0, 0, 1],
];
console.log(findCircleNum(grid));

// connected = new Map();
// let city = 1;
// let arr = [2];
// if (connected[city] === undefined) connected.set(city, arr); // connected = {1:[2]}
// console.log(connected.get(city)); // print (1) [2], this is correct i guess?

// let arr2 = [3]; //trying to add 3 into the list, result wanted: connected = {1: [2,3]}

// if (connected.get(city) === undefined) connected.set(city, arr2);
// else connected.set(city, connected.get(city).concat(arr2));
// console.log(connected.get(city));
// connected.set(2, [5, 6, 7]);
// connected.set(3, [7, 8, 9]);

// for (let key of connected.keys()) {
//   console.log(connected.get(key).shift());
// }
// console.log("hi");
