/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxConsecutiveOnes = function(nums) {
    const groups= nums.join('').split('0')
    const len= groups.map((group)=> group.length)
    return Math.max(...len)
};