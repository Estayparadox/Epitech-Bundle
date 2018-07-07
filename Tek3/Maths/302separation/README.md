# 302separation
## What's that ?
A program that find degree of separation between people thanks to Floyd-Warshall algorithm and display incidence and adjacency matrix.

## Floyd-Warshall algorithm ?
Floyd-Warshall algorithm is an algorithm that determines the distance of the shortest paths from a graph.
It is described by an adjacency matrix but can also be described by an incidence matrix.

## How to use it ?
```
USAGE:
    ./302separation [file p1 p2 [-p]] [nb] [-m]
DESCRIPTION:
    file  The file you want to check
    p1 p2 People you want to know their degree of relation
    nb    The maximum size of the path    
    -p    Displays the optimized path taken
    -m    Displays the incidence matrix
```

You must use a special synthax for the file you want to check

### Example:

```
Jesus is friend with Chuck Norris
V is friend with Barack Obama
Barack Obama is friend with Tom Cruiz
Jesus is friend with Sim
Sim is friend with Tom Cruiz
Yvette Horner is friend with Tom Cruiz
Sim is friend with V
```
