function solution(cap, n, deliveries, pickups) {
    let answer = 0;

    let deliveryCount = 0;
    let pickupCount = 0;
    for(let i = n-1; i >= 0; i--){
        deliveryCount += deliveries[i];
        pickupCount+= pickups[i];
        while (deliveryCount > 0 || pickupCount > 0)
        {
            deliveryCount -= cap;
            pickupCount -= cap;
            answer += (i + 1) * 2;
        }    
    }
    return answer;
}

console.log(solution(3,2,[3,0],[0,2]));