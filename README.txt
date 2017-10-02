project:
cs214-The Sorter Part 0

DESIGN:

The sorter program is designed to sort a csv file using mergesort for certain variables with the help of structs
to record each data from the file. The csv file must match the format mentioned in ASSUMPTIONS. It will print all
the rows/lines from the file that have incomplete column data first in the order they appear in the original file.


ASSUMPTIONS:

Since we are using arrays for our struct member variables, we assume that the device running this 
program should have sufficient memory to handle it.

The sorting function only works on the following variables: color, director_name, num_critic_for_reviews,
duration, director_facebook_likes, actor_3_facebook_likes, actor_2_name, actor_1_facebook_likes, gross,
actor_1_name, movie_title, num_voted_users, cast_total_facebook_likes, actor_3_name, facenumber_in_poster,
plot_keywords, movie_imdb_link, num_user_for_reviews, language, country, content_rating, budget, title_year,
actor-2_facebook_likes, imdb_score, aspect_ratio and movie_facebook_likes.

 
DIFFICULTIES:
We find it hard to use pointers for struct member variables instead of arrays since it will require
a lot of malloc functions and make our code more messy.



HOW TO USE:
(Terminal method)

1) compile the code : gcc Sorter.c Mergesort.c 
2) run the code : cat "filename.csv" | ./a.out -c "variable"

Note:
1. Type "-c" before choosing which column to sort.
2. Replace "filename.csv" with any csv file that match the format mentioned in ASSUMPTIONS.
3. Replace "variable" with any variable listed in ASSUMPTIONS.



Brief description of submitted files:

sorter.h
    - Holds data from given csv file in struct members.
    - Holds function declarations.

sorter.c
    - Calls functions from Mergesort.c.
    - Record and sort data from movie_metadata.csv using mergesort algorithm.
    

mergesort.c
    - holds function definition for mergesort.
  

README.txt
    - description of submitted files
