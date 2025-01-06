/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    if(s.length == 0) return 0
    let arr = s.trim().split(' ');

    
    let lastWord = arr[arr.length - 1];

    return lastWord.length;

};