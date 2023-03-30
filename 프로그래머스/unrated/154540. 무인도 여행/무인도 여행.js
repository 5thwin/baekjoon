let mapY, mapX;
let visitMap;
const dy = [-1, 0, 1, 0];
const dx = [0, 1, 0, -1];
function solution(maps) {
  var answer = [];
  mapY = maps.length;
  mapX = maps[0].length;
  visitMap = Array.from(Array(mapY), () => Array(mapX).fill(false));
  for (let y = 0; y < mapY; y++) {
    for (let x = 0; x < mapX; x++) {
      if (maps[y][x] === 'X' || visitMap[y][x])
        continue;
      answer.push(bfs(y, x, maps));
    }
  }
  if (answer.length === 0) return [-1];
  answer.sort((a, b) => a < b ? -1 : 1);
  return answer;
}
function bfs(sy, sx, maps) {
  const queue = [];
  let sum = 0;
  queue.push([sy, sx]);
  visitMap[sy][sx] = true;
  while (queue.length !== 0) {
    const [cury, curx] = queue.shift();
    sum += Number.parseInt(maps[cury][curx]);
    for (let dir = 0; dir < 4; dir++) {
      const ny = cury + dy[dir];
      const nx = curx + dx[dir];
      if (ny < 0 || nx < 0 || ny >= mapY || nx >= mapX || maps[ny][nx] == 'X') continue;
      if (visitMap[ny][nx]) continue;
      visitMap[ny][nx] = true;
      queue.push([ny, nx]);
    }
  }
  return sum;
}

console.log(solution(["X591X", "X1X5X", "X231X", "1XXX1"]));
