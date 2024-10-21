// Reverse Words in a String
//     Write a program to reverse the words in a given string. The input string contains words separated by spaces, but the words themselves should not be reversed, only their order.

//     Input:
//     A string with words separated by spaces.

//     Output:
//     A string with the words reversed in order.

//     Example 1:
//     Input:
//     "hello world"
//     Output:
//     "world hello"

//     Example 2:
//     Input:
//     "data structures and algorithms"
//     Output:
//     "algorithms and structures data"

// WRITE YOUR CODE HERE

let str = "data structures and algorithms";

function reverse(str){
    let reversedString = str.split(" ").reverse().join(" ");
    return reversedString;
}

console.log(reverse(str));