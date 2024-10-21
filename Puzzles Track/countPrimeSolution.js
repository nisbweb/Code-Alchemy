// Count Primes
//     Given an integer n, return the number of prime numbers less than n.

//     Input:
//     A non-negative integer n.
//     Output:
//     The count of prime numbers less than n.

//     Example:
//     Input:
//     10

//     Output:
//     4

let n=10;

function isPrime(num) {
  for (let f = 2; f * f <= num; f++) {
    if (num % f === 0) {
      return false;
    }
  }
  return true;
}

function countPrimes(n) {
  let count = 0;
  for (let i = 2; i <= n - 1; i++) {
    if (isPrime(i)) {
      count++;
    }
  }
  return count;
}

console.log(countPrimes(n));
