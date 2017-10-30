#include "sorter.h"

char *token = "color,director_name,num_critic_for_reviews,duration,director_facebook_likes,actor_3_facebook_likes,actor_2_name,actor_1_facebook_likes,gross,genres,actor_1_name,movie_title,num_voted_users,cast_total_facebook_likes,actor_3_name,facenumber_in_poster,plot_keywords,movie_imdb_link,num_user_for_reviews,language,country,content_rating,budget,title_year,actor_2_facebook_likes,imdb_score,aspect_ratio,movie_facebook_likes";

void create_sorted(char  *outdir, char *filename,  char *columnsort);
void remove_whtspace(struct item_t *Record, int size);
char * trim(char *string);


int main(){
	printf("start\n");
	
	create_sorted(NULL, "movie100.csv", "color");
	
	
	printf("end\n");
	return 0;
}

void create_sorted(char *outdir, char *filename, char *columnsort) {
    FILE *stream = fopen(filename, "r");
	
	printf("file opened!\n");

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
					printf("wrong metadata\n");
					/*
					printf("token:\n%s\n", token);
					printf("line:\n%s\n", line);
					printf("%d\n", strcmp(token, line));
					*/
					int i, len = strlen(line);
					for(i=405; i < len; i++){
						printf("%d: %c - %c >> %d\n", i, line[i], token[i], (line[i]==token[i]));
					}
					printf("line: %d\n", strlen(line));
					printf("tok: %d\n", strlen(token));
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
	//change filename to include outdir, if  necessary and  "sorted-column"
	char filepath[100];
	if(outdir != NULL){
		strcat(filepath, outdir);
		printf("1: %s\n", filepath);
	}
	//maybe check if outdir is relative path here?
	//if relative, change it to absolute
	strcat(filepath, filename);
	int i, n = strlen(filepath);
	for(i=n-1; i > (n-5); i--){
		filepath[i] = '\0';
	}
	strcat(filepath, "-sorted-");
	strcat(filepath, columnsort);
	strcat(filepath, ".csv");
	
	display(Record, true_size, token, count);
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