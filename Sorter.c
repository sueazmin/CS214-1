/**
* Group members: Suhail Azmin Bin Saiful Adli & Maryam Farid Iskandar
* Class: CS 214
* File: sorter.c
* Description: Sorter.c is the main file that calls the all the functions from
*              Mergesort.c with the help of Sorter.h to record the data from
*              movie_metadata.csv and sort them using merge sort algorithm.
*
**/




#include <ctype.h>
#include "sorter.h"

void remove_whtspace(struct item_t *Record, int size);
char * trim(char *string);


int main(int argc, char *argv[]) {

    FILE *stream = stdin;

    //Hold each line from movie_metadata.csv file
    char line[200000];

    int size = 0, len = 0, count = 0;

    //struct pointer to hold every data from movie_metadata.csv file
    struct item_t *Record = NULL;

    //hold first line of movie_metadata.csv file which is the coloumn types.
    char token[200000];
    int first_row = 1;
    int true_size = 0;


    if (stream) {
        while (fgets(line, sizeof(line), stream)) {
            if (first_row ==1)
            {
                first_row++;
                strcpy(token,line);
                continue;
            }
            true_size++;


            //allocate memory for struct item_t pointer
            if (len == size) {
                size = size ? size * 2 : 1000;
                Record = realloc(Record, sizeof(*Record) * size);
                if (Record == NULL) {
                    fprintf(stderr, "out of memory for %d items\n", size);
                    return 1;
                }
            }

            //scan each line until a comma that seperates between two data and
            //seperate them into designated struct member variables.
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

    if (strcmp(argv[1],"-c")== 0 )
    {
        //temporary struct item_t pointer for sorting purpose in Mergesort.c
        struct item_t *tmp =  (struct item_t*) malloc(5000 * sizeof(struct item_t*));

        //which column to sort
        char *column;
        column = argv[2];


    //calls merge functions from mergesort.c
    remove_whtspace(Record, true_size);
    merge_sort(Record, tmp, true_size, column);

    printf("Record array after sorting:\n");
    display(Record,true_size,token,count);
    free(tmp);



    }
    else
    {
        printf("%s\n", "Error! : \"-c\" must be typed before indicating which column to sort." );
    }
    free(Record);





    return 0;
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

char * trim(char *string){
	if(string == NULL) return NULL;
	if(strlen(string) == 0) return "";

	while(isspace((unsigned char) *string)) string++;
	
	return string;
}
