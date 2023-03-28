function solution(nums) {
  let half = nums.length / 2;
  let setTable = new Set();
  nums.forEach(element => {
    setTable.add(element);
  });
  return Math.min(half, setTable.size);
}
