# Trade
![badge1](https://img.shields.io/badge/license-MIT-brightgreen.svg)
![badge2](https://img.shields.io/badge/language-C%2B%2B-ff69b4.svg)
## What's that ?
A trading robot that optimizes the gains by buying and selling stocks according to the stock market, like traders.</br>
The program can perform the following 3 actions:</br>
BUY via the syntax buy n, where n is the number of shares to buy.</br>
A commission of 0.15% rounded upwards on the total amount of the order is deducted.</br>
SELL via the sell n syntax, where n is the number of shares for sale at the current price. A commission of 0.15% rounded upwards on the total amount of the order is deducted.</br>
WAIT via the wait syntax. No shares are bought or sold.</br></br>
The stock market quotations are transmitted to the program via 'trade_moulinette.php'; it is also this program that executes the order placed by Trade.</br>
At each turn (representing one day), 'trade_moulinette.php' sends the current share price to 'trade' who then places an order.
The number of laps is determined in advance.
## How to use it ?
You can run the program by the command line:
```
USAGE:
    ./trade_moulinette -f file -p binary -m capital [-o]
DESCRIPTION:
    -f  file    where file contains the sequence of integers representing the price of the action; these integers will be
                sent one by one to your program each turn.
    -p  binary  where binary is the path to your program.
    -m  capital where capital is the amount of money you initially have.
    -o          displays the values of the action on the standard output.
```
### Examples:
```
>>> ./trade_moulinette.php -p trade -f titres.txt -m 10000
[PERIOD]  1489 days
[PROFIT]  +2252 (from 10000) 
[AVERAGE] +1.51 per day
[ERROR]   none
```
```
>>> ./trade_moulinette.php -p trade -f titres.txt -m 10000 -o | head -n 5
[3322] -> wait
[3306] -> wait
[3275] -> wait 
[3280] -> buy 2 
[3293] -> wait
```
```
>>> ./trade_moulinette.php -p trade -f titres.txt -m 10000 -o | tail -n 5
[4072] -> buy 4
[4116] -> wait
[4178] -> wait 
[4176] -> sell 31
[PERIOD]  1489 days
[PROFIT]  +2252 (from 10000) 
[AVERAGE] +1.51 per day
[ERROR]   none
```
