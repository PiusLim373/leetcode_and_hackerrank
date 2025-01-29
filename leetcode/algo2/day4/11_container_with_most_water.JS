var maxArea = function (h) {
    let left = 0, right = h.length - 1;
    let max_area = 0;
    while (left < right) {
        let low = Math.low(h[left], h[right]);
        let area = (right - left) * low;
        if (area >= maxArea) maxArea = area;
        if (h[left] == h[right]) {
            left++;
            right--;
        }
        else if (h[left] > h[right]) right--;
        else left++;
    }
    return maxArea;
};

height = [1, 8, 6, 2, 5, 4, 8, 3, 7];

console.log(maxArea(height));