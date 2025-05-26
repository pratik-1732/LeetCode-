/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxConsecutiveOnes = function(nums) {
    let cnt=0, ans=0
    for(const x of nums){
        if(x==1) cnt++;
        else{
            ans= Math.max(ans, cnt);
            cnt=0;
        }
    }
    ans= Math.max(ans, cnt);
    return ans;
};