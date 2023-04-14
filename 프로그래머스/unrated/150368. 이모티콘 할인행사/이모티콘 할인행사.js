
function solution(users, emoticons) {
    var answer = [];
    let maxEmoticonPlus = 0;
    let maxPrice = 0;
    const discount = [10, 20, 30, 40];

    /*eNum 이모티콘을 dNum 만큼 할인했을 때*/
    const table = []; //할인율 저장하는 배열
    function dfs(eIdx,dIdx){
        table[eIdx] = dIdx;  //eIdx번째 이모티콘의 할인율 기록
        if (eIdx === emoticons.length -1){ //마지막 이모티콘인 경우
            /*플러스 가입자 수와 총 가격 계산*/
            const [totalPlus, totalPrice] = calculate();
            if (maxEmoticonPlus > totalPlus) 
                return;
            if(maxEmoticonPlus < totalPlus){
                maxEmoticonPlus=totalPlus;
                maxPrice = totalPrice;
                return;
            }
            maxPrice = Math.max(maxPrice, totalPrice);
            return;
        }
        for (let i = 0; i < 4; i++){
            dfs(eIdx + 1, i);
        }
    }
    function calculate(){
        let totalPlus = 0;
        let totalPrice = 0;
        /*각각의 사용자가 살 이모티콘 계산*/
        users.forEach(([userPercent, userPlusPrice]) => {
            let userPrice = 0; //사용자 토탈 가격
            table.forEach((dIdx, eIdx)=>{
                if (discount[dIdx] < userPercent) //사용자가 사지 않는 이모티콘
                    return; 
                const discountedPrice = emoticons[eIdx] * (100 - discount[dIdx]) / 100;
                userPrice += discountedPrice;
            })
            if (userPrice >= userPlusPrice){ //총 구매가격이 플러스 가입가격을 넘을 경우
                userPrice = 0;
                totalPlus++;
            }
            totalPrice += userPrice;
        })
        return [totalPlus, totalPrice]
    }
    for (let i =0; i<4; i++){
        dfs(0, i);
    }
    return [maxEmoticonPlus, maxPrice];
}