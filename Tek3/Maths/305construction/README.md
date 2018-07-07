# 305construction
## What's that ?
305construction is a project’s software that helps organize construction, based on the MPM method starting from a file
that describes all of the project’s tasks.</br>
This program displays:</br>
* Total duration of construction,</br>
* The earliest and latest dates for each task,</br>
* A Gantt diagram that specifies intervals of fluctuation</br>
## Gantt chart ?
A Gantt chart is a type of bar chart that illustrates a project schedule. Gantt charts illustrate the start and finish dates of the terminal elements and summary elements of a project. Terminal elements and summary elements comprise the work breakdown structure of the project.</br>
![image1](https://upload.wikimedia.org/wikipedia/commons/thumb/5/57/GanttChartAnatomy.svg/896px-GanttChartAnatomy.svg.png)
## How to use it ?
```
USAGE:
    ./305construction file
DESCRIPTION:
    file  The file you want to use. It must be a .csv file
```
Here is an example of file you must use:
```
>>> cat house.csv
Car;carpenter;4;Fou
Hea;heat;3;Ele;Mas
Cov;cover;2;Car
Ele;electricity;1;Cov;Mas
Fin;finishing touches;9;Cov;Ele;Mas;Plu
Fou;foundations;8;Lan
Mas;masonry;4;Lan;Fou
Plu;plumbing;1;Ele;Mas
Lan;landscaping;3
```
This file describes all of the tasks. Each line represents a task, and contains 4 separate pieces of information that are sepa-
rated by semicolons, in the following order:</br>
* the task’s code,</br>
* the description of the task,</br>
* the duration of the task,</br>
* the list of the task’s prerequisites (they are also separated by semicolons).
### Example
```
>>> ./305construction house.csv
total duration of construction:  28 weeks
Lan must begin at t=0
Fou must begin at t=3
Car must begin at t=11
Mas must begin between t=11 and t=13
Cov must begin at t=15
Ele must begin at t=17
Plu must begin at t=18
Hea must begin between t=18 and t=25
Fin must begin at t=19
Lan       (0)      ===
Fou       (0)         ========
Car       (0)                 ====
Mas       (2)                 ====
Cov       (0)                     ==
Ele       (0)                       =
Plu       (0)                        =
Hea       (7)                        ===
Fin       (0)                         =========
```
