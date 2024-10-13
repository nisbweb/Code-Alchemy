// Given an array of integers as input, output the indices of two numbers in the array 
// which add up to a specified target.

//Sample Input:
// 5 --> Number of elements in array
// 2 4 5 9 8 --> Array elements
// 7 --> Target sum value

//Sample Output:
// 0 2

function twoSum(nums, target) {
    let store = new Map();
    for(let j=0;j<nums.length;j++){
        let x = target - nums[j];
        if(store.has(x)){
            let i = store.get(x);
            return [i,j];
        }
        store.set(nums[j],j);
    }
    return [0,0];
}