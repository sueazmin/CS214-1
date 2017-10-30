/**
* Group members: Suhail Azmin Bin Saiful Adli & Maryam Farid Iskandar
* Class: CS 214
* File: sorter.c
* Description: Sorter.c is the main file that calls the all the functions from
*              Mergesort.c with the help of Sorter.h to record the data from
*              movie_metadata.csv and sort them using merge sort algorithm.
*
**/




#include "sorter.h"

char *token = "color,director_name,num_critic_for_reviews,duration,director_facebook_likes,actor_3_facebook_likes,actor_2_name,actor_1_facebook_likes,gross,genres,actor_1_name,movie_title,num_voted_users,cast_total_facebook_likes,actor_3_name,facenumber_in_poster,plot_keywords,movie_imdb_link,num_user_for_reviews,language,country,content_rating,budget,title_year,actor_2_facebook_likes,imdb_score,aspect_ratio,movie_facebook_likes";

void show_dir_content(FILE *pidlist, char *columnsort, char *path, char *outdir) ;
void create_sorted(char  *outdir, char *filename,  char *columnsort);
void remove_whtspace(struct item_t *Record, int size);
char * trim(char *string);

/*	TO-DO LIST
* - test with absolute & relative path for outdir (show_dir_content) & (create_sorted)
* - or just change relative path to absolute? (use realpath())

*/


int main(int argc, char *argv[]) {
	
	if(argc < 2){
		printf("not enough command\n");
		return 0;
	}

	remove("pidlist.txt");
	FILE *pidlist = fopen("pidlist.txt", "a");
	
	
	//this is thing is ugly
	//it assumes the user is following the convention in order
	if(argc < 4){	//scan current dir
		char cwd[255];
		getcwd(cwd, sizeof(cwd));
		printf("Sort by: %s, Input dir: %s, Output dir: none\n", argv[2], cwd);
		show_dir_content(pidlist, argv[2], cwd, NULL);
		
	} else if(argc < 6){
		printf("Sort by: %s, Input dir: %s, Output dir: none\n", argv[2], argv[4]);
		show_dir_content(pidlist, argv[2], argv[4], NULL);
		
	} else {
		printf("Sort by: %s, Input dir: %s, Output dir: %s\n", argv[2], argv[4], argv[6]);
		show_dir_content(pidlist, argv[2], argv[4], argv[6]);
	}
	
	
	
	//wait for all child processes to exit
	pid_t parent;
	int status = 0;
	while((parent = wait(&status) > 0));
	
	//save file buffer into pidlist by closing it
	fclose(pidlist);
	
	//open it again & count
	pidlist = fopen("pidlist.txt", "r");
	int totalpid = 0;
	printf("\nInitial PID: %d\n", getpid());
	printf("PIDs of all child processes: ");
	
	//go thru pidlist.txt, print, increment totalpid
	char buffer[10];
	while (fgets(buffer, 10, pidlist)){
		if(buffer[strlen(buffer)-1] == '\n')
			buffer[strlen(buffer)-1]= ',';	//replace newline with comma
		printf("%s ", buffer);
		totalpid++;
	}
	printf("\nTotal number of processes: %d\n", totalpid);
	fclose(pidlist);
	remove("pidlist.txt");		//delete after done
	
	
    return 0;
}


/* scan dir, fork when csv/new dir is found
*   call create_sorted on csv
*/
void show_dir_content(FILE *pidlist, char *columnsort, char *path, char *outdir) {
  DIR * d = opendir(path);
  if(d==NULL) return; 
  struct dirent * dir;
  while ((dir = readdir(d)) != NULL)
    {

      if(dir-> d_type != DT_DIR){ // not dir
       
        char *dot = strrchr(dir->d_name, '.');
        if (dot && !strcmp(dot, ".csv") && strstr(dir->d_name, "sorted") == NULL) { //find csv
            //printf("hello %s\n", dir->d_name);
			
			pid_t pid = fork();
			if(pid == 0){
				printf("found %s/%s\n", path, dir->d_name);
				create_sorted(outdir, dir->d_name, columnsort);
				fprintf(pidlist, "%d\n", getpid());
				exit(1);
			}
        }

      } 
      else if(dir->d_type == DT_DIR && dir->d_name[0] != '.' && strcmp(dir->d_name,"..")!=0 ) // if dir & not hidden
      {
        char d_path[255];
        sprintf(d_path, "%s%s", path, dir->d_name);
		
		pid_t pid = fork();
		if(pid == 0){
			printf("new dir: %s\n", d_path);
			fprintf(pidlist, "%d\n", getpid());
			show_dir_content(pidlist, columnsort, d_path, outdir);	//recursive
			exit(1);
		}

      }
    }
    closedir(d); // close directory
}

/* create Record object from csv file, mergesort by -c column, output to -o outdir
* output on the same folder if outdir is null
*/
void create_sorted(char *outdir, char *filename, char *columnsort) {
    FILE *stream = fopen(filename, "r");

    //Hold each line from movie_metadata.csv file
    char line[200000];

    int size = 0, len = 0, count = 0;

    //struct pointer to hold every data from movie_metadata.csv file
    struct item_t *Record = NULL;

    //hold first line of movie_metadata.csv file which is the column types.
    int first_row = 1;
    int true_size = 0;
	//token is in sorter.h

    if (stream) {
        while (fgets(line, sizeof(line), stream)) {
            if (first_row ==1)
            {
                first_row++;
				
				line[strlen(line)-2] = '\0';
				if(strcmp(token, line) != 0){	//wrong metadata on 1st line
					//printf("wrong metadata\n");
					return;
				}
                continue;
            }
            true_size++;


            //allocate memory for struct item_t pointer
            if (len == size) {
                size = size ? size * 2 : 1000;
                Record = realloc(Record, sizeof(*Record) * size);
                if (Record == NULL) {
                    fprintf(stderr, "out of memory for %d items\n", size);
                    return;
                }
            }

            //scan each line until a comma that seperates between two data and
            //separate them into designated struct member variables.
            if (sscanf(line, "%190[^,\n],%190[^,\n],%190[^,\n],%190[^,\n],%230[^,\n],%400[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%490[^,],%490[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%499[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%490[^,\n]",
                       Record[len].color, Record[len].director_name, &(Record[len].num_critic_for_reviews),Record[len].duration,
                       Record[len].director_facebook_likes,Record[len].actor_3_facebook_likes,Record[len].actor_2_name,
                       Record[len].actor_1_facebook_likes,Record[len].gross,Record[len].genres,Record[len].actor_1_name,
                       Record[len].movie_title,Record[len].num_voted_users,Record[len].cast_total_facebook_likes,Record[len].actor_3_name,
                       Record[len].facenumber_in_poster,Record[len].plot_keywords,Record[len].movie_imdb_link,Record[len].num_user_for_reviews,
                       Record[len].language,Record[len].country,Record[len].content_rating,Record[len].budget,Record[len].title_year,
                       Record[len].actor_2_facebook_likes,Record[len].imdb_score,Record[len].aspect_ratio,Record[len].movie_facebook_likes) != 28)
                        {
                            //if there is empty data in line, put it in the "incomplete" member variable from struct
                            if (sscanf(line, "%190[^,\n],%190[^,\n],%190[^,\n],%190[^,\n],%230[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],\"%490[^\"]\",%490[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%400[^,\n],%499[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%400[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%490[^,\n]",
                       Record[len].color, Record[len].director_name, &(Record[len].num_critic_for_reviews),Record[len].duration,
                       Record[len].director_facebook_likes,Record[len].actor_3_facebook_likes,Record[len].actor_2_name,
                       Record[len].actor_1_facebook_likes,Record[len].gross,Record[len].genres,Record[len].actor_1_name,
                       Record[len].movie_title,Record[len].num_voted_users,Record[len].cast_total_facebook_likes,Record[len].actor_3_name,
                       Record[len].facenumber_in_poster,Record[len].plot_keywords,Record[len].movie_imdb_link,Record[len].num_user_for_reviews,
                       Record[len].language,Record[len].country,Record[len].content_rating,Record[len].budget,Record[len].title_year,
                       Record[len].actor_2_facebook_likes,Record[len].imdb_score,Record[len].aspect_ratio,Record[len].movie_facebook_likes) != 28)
                        {
                            strcpy(Record[count++].incomplete ,line);
                            true_size--;

                        }
                        else
                        {
                            len++;
                        }

                        }
                        else
                        {
                            len++;
                        }
        }
    }


    //temporary struct item_t pointer for sorting purpose in Mergesort.c
    struct item_t *tmp =  (struct item_t*) malloc(5000 * sizeof(struct item_t*));

    //calls merge functions from mergesort.c
    remove_whtspace(Record, true_size);
    merge_sort(Record, tmp, true_size, columnsort);

	//sorting done!
	//change filename to include outdir, if necessary and  add "sorted-column"
	char filepath[1024];
	if(outdir != NULL){
		strcat(filepath, outdir);
	}

	strcat(filepath, filename);
	int i, n = strlen(filepath);
	for(i=n-1; i > (n-5); i--){
		filepath[i] = '\0';
	}
	strcat(filepath, "-sorted-");
	strcat(filepath, columnsort);
	strcat(filepath, ".csv");
	printf("new file: %s\n", filepath);
	
	outputcsv(filepath, Record, true_size, token, count);
    free(tmp);
    free(Record);	
}

/*remove leading whitespace
 */
void remove_whtspace(struct item_t *Record, int size){
	int i;
	for(i=0; i < size; i++){
		struct item_t temp = Record[i];
		strcpy(temp.actor_1_facebook_likes, trim(Record[i].actor_1_facebook_likes));
		strcpy(temp.actor_1_name, trim(Record[i].actor_1_name));
		strcpy(temp.actor_2_facebook_likes, trim(Record[i].actor_2_facebook_likes));
		strcpy(temp.actor_2_name, trim(Record[i].actor_2_name));
		strcpy(temp.actor_3_facebook_likes, trim(Record[i].actor_3_facebook_likes));
		strcpy(temp.actor_3_name, trim(Record[i].actor_3_name));
		strcpy(temp.aspect_ratio, trim(Record[i].aspect_ratio));
		strcpy(temp.budget, trim(Record[i].budget));
		strcpy(temp.cast_total_facebook_likes, trim(Record[i].cast_total_facebook_likes));
		strcpy(temp.color, trim(Record[i].color));
		strcpy(temp.content_rating, trim(Record[i].content_rating));
		strcpy(temp.country, trim(Record[i].country));
		strcpy(temp.director_facebook_likes, trim(Record[i].director_facebook_likes));
		strcpy(temp.director_name, trim(Record[i].director_name));
		strcpy(temp.duration, trim(Record[i].duration));
		strcpy(temp.facenumber_in_poster, trim(Record[i].facenumber_in_poster));
		strcpy(temp.genres, trim(Record[i].genres));
		strcpy(temp.gross, trim(Record[i].gross));
		strcpy(temp.imdb_score, trim(Record[i].imdb_score));
		strcpy(temp.language, trim(Record[i].language));
		strcpy(temp.movie_facebook_likes, trim(Record[i].movie_facebook_likes));
		strcpy(temp.movie_imdb_link, trim(Record[i].movie_imdb_link));
		strcpy(temp.movie_title, trim(Record[i].movie_title));
		strcpy(temp.num_critic_for_reviews, trim(Record[i].num_critic_for_reviews));
		strcpy(temp.num_user_for_reviews, trim(Record[i].num_user_for_reviews));
		strcpy(temp.num_voted_users, trim(Record[i].num_voted_users));
		strcpy(temp.plot_keywords, trim(Record[i].plot_keywords));
		strcpy(temp.title_year, trim(Record[i].title_year));
		Record[i] = temp;
	}
}

/* remove_whtspace helper
*/
char * trim(char *string){
	if(string == NULL) return NULL;
	if(strlen(string) == 0) return "";

	while(isspace((unsigned char) *string)) string++;
	
	return string;
}
