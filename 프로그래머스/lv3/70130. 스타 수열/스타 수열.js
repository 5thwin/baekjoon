function solution(a) {
  var answer = 0;
  const N = a.length;
  const counter = Array(N).fill(0);
  a.forEach(elem => {
    counter[elem]++;
  });
  let maxStarCounter = 0;
  counter.forEach((value, index)=>{
    if (value <= maxStarCounter)
      return;
    const common = index; //common : 공통원소
    let starCounter = 0;
    for(let i = 0; i < N; i++){
      if(a[i+1] == undefined) break;
      if (a[i] != common && a[i + 1] != common) continue;
      if (a[i] == a[i+1]) continue;
      //a[i], a[i+1] 둘중 하나는 common임
      starCounter++;
      i++;
    }
    if(starCounter == 1) return;
    maxStarCounter = maxStarCounter < starCounter ? starCounter : maxStarCounter;
  })
  answer = maxStarCounter * 2;
  return answer;
}
