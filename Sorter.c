#include "sorter.h"

 
int main(int argc, char *argv[]) {
    FILE *stream = stdin;
    char line[200000];
    int size = 0, len = 0, count = 0, i, c;
    struct item_t *A = NULL;
    char token[200000];
    int aha = 1;
    int olololo = 0;


    if (stream) {
        while (fgets(line, sizeof(line), stream)) {
            if (aha ==1)
            {
                aha++;
                strcpy(token,line);
                continue;
            }
            olololo++;

            if (len == size) {
                size = size ? size * 2 : 1000;
                A = realloc(A, sizeof(*A) * size);
                if (A == NULL) {
                    fprintf(stderr, "out of memory for %d items\n", size);
                    return 1;
                }
            }
            if (sscanf(line, "%190[^,\n],%190[^,\n],%190[^,\n],%190[^,\n],%230[^,\n],%400[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%490[^,],%490[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%499[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%490[^,\n]",
                       A[len].color, A[len].director_name, &(A[len].num_critic_for_reviews),A[len].duration,
                       A[len].director_facebook_likes,A[len].actor_3_facebook_likes,A[len].actor_2_name,
                       A[len].actor_1_facebook_likes,A[len].gross,A[len].genres,A[len].actor_1_name,
                       A[len].movie_title,A[len].num_voted_users,A[len].cast_total_facebook_likes,A[len].actor_3_name,
                       A[len].facenumber_in_poster,A[len].plot_keywords,A[len].movie_imdb_link,A[len].num_user_for_reviews,
                       A[len].language,A[len].country,A[len].content_rating,A[len].budget,A[len].title_year,
                       A[len].actor_2_facebook_likes,A[len].imdb_score,A[len].aspect_ratio,A[len].movie_facebook_likes) != 28) 
                        {
                            if (sscanf(line, "%190[^,\n],%190[^,\n],%190[^,\n],%190[^,\n],%230[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],\"%490[^\"]\",%490[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%400[^,\n],%499[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%400[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%490[^,\n]",
                       A[len].color, A[len].director_name, &(A[len].num_critic_for_reviews),A[len].duration,
                       A[len].director_facebook_likes,A[len].actor_3_facebook_likes,A[len].actor_2_name,
                       A[len].actor_1_facebook_likes,A[len].gross,A[len].genres,A[len].actor_1_name,
                       A[len].movie_title,A[len].num_voted_users,A[len].cast_total_facebook_likes,A[len].actor_3_name,
                       A[len].facenumber_in_poster,A[len].plot_keywords,A[len].movie_imdb_link,A[len].num_user_for_reviews,
                       A[len].language,A[len].country,A[len].content_rating,A[len].budget,A[len].title_year,
                       A[len].actor_2_facebook_likes,A[len].imdb_score,A[len].aspect_ratio,A[len].movie_facebook_likes) != 28) 
                        {
                            strcpy(A[count].incomplete ,line);
                            printf("%s\n\n", A[count].incomplete );
                            olololo--;

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
        // free(A);
    }

    if (strcmp(argv[1],"-c")==0 ) 
    {

        // int tmp[SIZE];
        struct item_t *tmp =  (struct item_t*) malloc(5000 * sizeof(struct item_t*));
        char *what;
        what = argv[2];
 
    printf("Array before sorting:\n");
    display(A,olololo,token);
            // free(A);

 
    merge_sort(A, tmp, olololo, what);
 
    printf("Array after sorting:\n");
    display(A,olololo,token);

        
    } 
    



    return 0;
}