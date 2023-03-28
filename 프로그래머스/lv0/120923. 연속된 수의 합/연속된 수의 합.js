function solution(num, total) {
  var answer = [];
  let avg = Math.ceil(total / num);
  let add = -Math.floor(num / 2);
  for (let i = 0; i < num; i++) {
    answer.push(avg + add);
    add++;
  }
  return answer;
}
