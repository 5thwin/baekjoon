function solution(n, costs) {
  var answer = 0;
  const parent = Array(n).fill(0).map((_,index)=>index);

  costs.sort((a,b)=>{
    let costA = a[2];
    let costB = b[2];
    if(costA > costB) return 1;
    return -1;
  })
  console.log(costs);
  costs.forEach(element => {
    const [src, des, cost] = element;
    if(union(src, des, parent))
      answer += cost;
  });
  return answer;
}
console.log(solution(4,	[[0,1,1],[0,2,2],[1,2,5],[1,3,1],[2,3,8]]));

function min(a, b){
  return a < b ? a : b;
}

function find(a, parent){
  if(a === parent[a])
    return a;
    parent[a] = find(parent[a], parent);
    return parent[a];
}

function union(a, b, parent){
  let pa = find(a, parent);
  let pb = find(b, parent);
  if(pa !== pb){
    parent[pa] = parent[pb] = min(pa, pb);
    return true;
  }
  return false;
}
