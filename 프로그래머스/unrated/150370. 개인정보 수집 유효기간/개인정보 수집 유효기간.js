function solution(today, terms, privacies) {
    var answer = [];
    let termMap = {};
    let endDateList = []
    terms.forEach((term) => {
        const [kind, duration, rest] = term.split(' ');
        termMap[kind] = Number.parseInt(duration);
    })
    privacies.forEach((privacy) => {
        const [year, month, date, kind] = privacy.split(/[' .']/);
        const duration = termMap[kind];
        let endYear = Number.parseInt(year);
        let endMonth = Number.parseInt(month) + duration;
        if(endMonth >= 13){
            endYear +=  Math.floor((endMonth - 1)/12);
            endMonth = (endMonth - 1)%12 + 1
        }
        let endDate = Number.parseInt(date);
        endDateList.push({year: endYear, month: endMonth ,date: endDate});
    })
    const [todayYear, todayMonth, todayDate] = today.split('.').map(el => parseInt(el));
    endDateList.forEach((endDate, index) => {
        const privacyNum = index + 1;
        const {year, month, date} = endDate;
        if(year > todayYear) return;
        if(year === todayYear && month > todayMonth) return;
        if(year === todayYear && month === todayMonth && date > todayDate) return;
        answer.push(privacyNum);
    })
    return answer;
}

terms =  ["B 12"]
privacies = ["2017.12.21 B"]
today = "2019.01.01"
console.log(solution(today, terms, privacies))