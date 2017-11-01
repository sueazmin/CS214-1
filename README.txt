Multi-process Sorter: Part 1
Group Members: Suhail Azmin Bin Saiful Adli & Maryam Farid Iskandar

FILES: sorter.c, mergesort.c, sorter.h, makefile

DESIGN:

The sorter sorts all csv files simultaneously that is found in the given input directory or current working directory if none is given.
The csv file must match the format under ASSUMPTIONS or it will be ignored. The output of the sorted file is a new csv file in 
the given output directory or in the same directory as the original file if none is given.

Simultaneous sorting is achieved by crawling through all non-hidden directories at the same time by forking. If an csv file is found
and it does not has "sorted" in its name, the sorter will attempt to sort it in another fork. Child process from forking directory is
killed after it is done scanning its directory while the child from the sorting is killed after it is done attempting to sort.

The number of processes is tracked with a text file (pidlist.txt). Each child process appends its id in the textfile. After waiting for
all child processes, the initial parent process counts the number of entries, prints them in the terminal and deletes the textfile.


ASSUMPTIONS:

The following are the variables that can be used with the sorting command -c. The first line of the csv file must match with them
in exact order: 
	color, director_name, num_critic_for_reviews, duration, director_facebook_likes, actor_3_facebook_likes, actor_2_name, 
	actor_1_facebook_likes, gross, actor_1_name, movie_title, num_voted_users, cast_total_facebook_likes, actor_3_name, 
	facenumber_in_poster, plot_keywords, movie_imdb_link, num_user_for_reviews, language, country, content_rating, budget, 
	title_year, actor-2_facebook_likes, imdb_score, aspect_ratio, movie_facebook_likes

The only possible combination of commands given to the sorter program are as follow:
 ./sorter -c "variable"
		Input directory is the current working directory and the output of sorted files is in the same directory as the original file.

 ./sorter -c "variable" -d "input_dir"
		Input directory is the given input directory and the output of sorted files is in the same directory as the original file.

 ./sorter -c "variable" - d "input_dir" -o "output_dir"
		Input directory is the given input directory and the output of sorted files is in the output directory.

The sorter assumes that the commands are given in that specific order.

The sorter ignores hidden directories and csv files with "sorted" in its name.

Multiple variables is not supported.


DIFFICULTIES:

Forking in general is challenging since it is a new concept. Trying to get the process id and the total of processes is even more
challenging. There were several other attempts (using wexitstatus, shared memory, etc.) before settling on appending to a text
file as it is more straightforward, easier to debug and can handle many child processes.

Fork is unavailable on Windows environment. Going to ilab, dual-booting Linux, coding in virtual machine, etc. are too tedious.
Makefile, pscp and putty are used to help with coding remotely through ilab quickly.


HOW TO USE:

Makefile is provided. Compile with the following commands before using it:
	make
	OR
	gcc -o sorter sorter.c mergesort.c

There are 3 ways to use the sorter program:
 ./sorter -c "variable"
		Input directory is the current working directory and the output of sorted files is in the same directory as the original file.

 ./sorter -c "variable" -d "input_dir"
		Input directory is the given input directory and the output of sorted files is in the same directory as the original file.

 ./sorter -c "variable" - d "input_dir" -o "output_dir"
		Input directory is the given input directory and the output of sorted files is in the output directory.
		
variable = 		any 1 variable under ASSUMPTIONS
input_dir = 	absolute or relative path for input directory
output_dir = 	absolute or relative path for output directory