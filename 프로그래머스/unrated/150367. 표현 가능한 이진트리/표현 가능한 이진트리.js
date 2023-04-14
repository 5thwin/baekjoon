
function numToBin(num) {
  let bin = num.toString(2);

  /*포화 이진트리의 노드 개수는 2^n - 1*/
  /*앞에 0을 붙여줌*/
  let twoSquare = 1;
  while (1) {
    if (twoSquare - 1 < bin.length && bin.length <= twoSquare * 2 - 1)
      break;
    twoSquare *= 2;
  }
  let rest = (twoSquare * 2 - 1) - bin.length;
  return '0'.repeat(rest) + bin;
}

function isTree(bin, parent) {
  if (bin.length === 1) {
    return (parent === '1') || (parent === '0' && bin === '0');
  }
  const middle = Math.floor(bin.length / 2);
  const left = bin.substr(0, middle);
  const right = bin.substr(middle + 1);
  /*부모가 0이었으면 자식도 모두 0이어야 함*/
  if (parent === '0') {
    if (bin[middle] === '1')
      return false;
    return isTree(left, '0') && isTree(right, '0');
  }
  return isTree(left, bin[middle]) && isTree(right, bin[middle]);
}

function solution(numbers) {
  var answer = [];
  numbers.forEach((number) => {
    const bin = numToBin(number);
    answer.push(isTree(bin, '1') ? 1 : 0);
  })
  return answer;
}