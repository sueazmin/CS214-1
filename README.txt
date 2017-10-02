project:
cs214-The Sorter Part 0

Design:

We desined this sorter program to only use mergesort on movie_metadata.csv with the help of structs 
to record each data from the file. It will print all the rows/lines from the file that have incomplete 
column data first in the order they appear in the original file.

Assumptions:
Since we are using arrays for our struct member variables, we assume that the device running this 
program should have sufficient memory to handle it.

Difficulties:
We find it hard to use pointers for struct member variables instead of arrays since it will require
a lot of malloc functions and make our code more messy.



How to use:
(Terminal method)

1) compile the code : gcc Sorter.c Mergesort.c 
2) run the code : cat movie_metadata.csv | ./a.out -c director name    (must put "-c" before choosing which column to sort) 

Brief description of submitted files:

Sorter.h
    - holds data from movie_metadata.csv in struct members.
    - holds function declarations.

Sorter.c
    - calls functions from Mergesort.c.
    - Record and sort data from movie_metadata.csv using mergesort algorithm.
    

Mergesort.c
    - holds function definition for mergesort.
  

README.txt
    - description of submitted files
