# palindrome
## What's that ?
The program find iterated reversal palindromes.
## Palindrome ?
A palindrome is a word or number wich reads the same backward or forward (that's for numbers, numbers unvariant when reversed).
A 'n' iteration turnover palindrome is a number which leads to a palindrome after 'n' iterations of the following procedure:
1.reverse the number,
2.add both the number and its reversal to obtain a new number,
3.iterate from the first step until you get a palindromic number.
### Example
```
121 is a 0 iteration turnover palindrome,
123 is a 1 iteration reversal palindrome,
4782 is a 3 iterations turnover palindrome.
```
## How to use it ?
```
USAGE:
    ./palindrome number base

DESCRIPTION:
    number  integer to be transformed (>=0)
    base    base in wich the procedure will be executed (1<base<=10) [def: 10]
```
