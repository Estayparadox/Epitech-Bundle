# PUSHSWAP

The objective of Pushswap is to sort l_a (the first list given as parameter).
In order to accomplish this, it uses few operation.

## Operation

• SA : swap the first two elements of l_a (nothing will happen if there aren’t enough elements).
• SB : swap the first two elements of l_b (nothing will happen if there aren’t enough elements).
• SC : SA and SB at the same time.
• PA : take the first element from l_b and move it to the first position on the l_a list (nothing will happen if l_b is empty).
• PB : take the first element from l_a and move it to the first position on the l_b list (nothing will happen if l_a is empty).
• RA : rotate l_a toward the beginning, the first element will become the last.
• RB : rotate l_b toward the beginning, the first element will become the last.
• RR : RA and RB at the same time.
• RRA : rotate l_a toward the end, the last element will become the first.
• RRB : rotate l_b toward the end, the last element will become the first.
• RRR : RRA and RRB at the same time.

## Compilation

```
make
```

## Usage

```
./push_swap 2 1 3 6 5 8 | cat -e
sa pb pb pb sa pa pa pa$
```