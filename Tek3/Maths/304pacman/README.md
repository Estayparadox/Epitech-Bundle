# 304pacman
## What's that ?
This program creates a short path for the ghosts in Pacman with the help of the Dijkstra algorithm.
It notes its distance from the ghost in each visited square of the map.
## Dijkstra ?
Dijkstra's algorithm is an algorithm for finding the shortest paths between nodes in a graph, which may represent, for example, road networks. It was conceived by computer scientist Edsger W. Dijkstra in 1956 and published three years later.</br></br>
### Step by step:
1 • Assign to every node a tentative distance value.</br>
2 • Set the initial node as current. Mark all other nodes unvisited. Create a set of all the unvisited nodes called the unvisited set.</br>
3 • For the current node, consider all of its neighbors and calculate their tentative distances. Compare the newly calculated tentative distance to the current assigned value and assign the smaller one.</br>
4 • When we are done considering all of the neighbors of the current node, mark the current node as visited and remove it from the unvisited set.</br>
5 • If the destination node has been marked visited or if the smallest tentative distance among the nodes in the unvisited set is "infinity", then stop. The algorithm has finished.</br>
6 • Otherwise, select the unvisited node that is marked with the smallest tentative distance, set it as the new "current node", and go back to step 3.</br></br>
![image1](https://media.giphy.com/media/ZkIkk3Y8E6hgc/giphy.gif)
## How to use it ?
```
USAGE:
    ./304pacman [file c1 c2] [-h]
DESCRIPTION:
    file  the map you want to use.
    c1    the character to display for a wall.
    c2    the character to display for an empty space.
    -h    help command.
```
### Example:
So you have to use a rectangular map consisting of 1, 0, one P and one F:</br> 1 for walls, 0 for empty spaces, P for Pacman and F for the ghost.
```
>>> cat map2 
111111111111111 
100000010000001 
101011010110101 
100P00010000001 
101010111010101 
101010010000001 
101011010110111 
111010000010111 
100000000010F01 
101010000010111 
111010111110111 
100000110000001 
101110110101101 
100100010001001 
110001110101011 
100100010000001 
101110110111101 
101010000000001 
111111111111111
```
So if you use the program you will obtain:
```
>>> ./304pacman map2 ’@’ ’ ’ 
@@@@@@@@@@@@@@@
@ @109890@
@ @ @@8@0@@7@9@
@  P767@987678@
@ @ @5@@@7@5@7@
@ @8@43@765456@
@ @7@@2@8@@3@@@
@@@6@21090@2@@@
@765432101@1F1@
@8@6@43212@2@@@
@@@7@5@@@@@3@@@
@  876@@765456@
@ @@@7@@8@6@@7@
@  @ 8 @987@98@
@@   @@@0@8@0@@
@  @   @109012@
@ @@@7@@2@@@@3@
@ @ @654345654@
@@@@@@@@@@@@@@@
```

