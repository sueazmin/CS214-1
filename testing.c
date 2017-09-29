#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 4
 


typedef struct item_t {
    char incomplete[2000];
    char color[200];
    char director_name[200];
    char num_critic_for_reviews[200];
    char duration[200];
    char director_facebook_likes[500];
    char actor_3_facebook_likes[500];
    char actor_2_name[500];
    char actor_1_facebook_likes[500];
    char gross[500];
    char genres[500];
    char actor_1_name[500];
    char movie_title[500];
    char num_voted_users[500];
    char cast_total_facebook_likes[500];
    char actor_3_name[500];
    char facenumber_in_poster[500];
    char plot_keywords[500];
    char movie_imdb_link[500];
    char num_user_for_reviews[500];
    char language[500];
    char country[500];
    char content_rating[500];
    char budget[500];
    char title_year[500];
    char actor_2_facebook_likes[500];
    char imdb_score[500];
    char aspect_ratio[500];
    char movie_facebook_likes[500];



};

void merge(struct item_t *a,struct item_t *tmp, int left, int mid, int right, char *what);
void msort(struct item_t *a,struct item_t *tmp, int left, int right, char *what);
void merge_sort(struct item_t *a,struct item_t *tmp, const int size, char *what);
void display(struct item_t *a,const int size,char token[200000]);

int main(int argc, char *argv[]) {
    FILE *stream = stdin;
    char line[200000];
    int size = 0, len = 0, count = 0, i, c;
    struct item_t *A = NULL;
    char token[200000];
    int aha = 1;
    // char ***test;


    if (stream) {
        while (fgets(line, sizeof(line), stream)) {
            if (aha ==1)
            {
                aha++;
                strcpy(token,line);
                continue;
            }

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
                            if (sscanf(line, "%190[^,\n],%190[^,\n],%190[^,\n],%190[^,\n],%23º[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],\"%490[^\"]\",%490[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%400[^,\n],%499[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%400[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%490[^,\n],%490[^,\n]",
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
                                                                                    printf("%s\n\n", "hello" );




                        }
                        else{
                                                
                            len++;
                        }
                          
                        } 
                        else 
                        {



                            len++;
                        }
        }
        
        //print matrix
        for (i = 0; i < len; i++) {
            printf("%s,%s,%d,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n\n", A[i].color, A[i].director_name, A[i].num_critic_for_reviews, 
                A[i].duration, A[i].director_facebook_likes,A[i].actor_3_facebook_likes,A[i].actor_2_name,
                A[i].actor_1_facebook_likes,A[i].gross,A[i].genres,A[i].actor_1_name,A[i].movie_title,A[i].num_voted_users,
                A[i].cast_total_facebook_likes,A[i].actor_3_name,A[i].facenumber_in_poster,A[i].plot_keywords,A[i].movie_imdb_link,
                A[i].num_user_for_reviews,A[i].language,A[i].country,A[i].content_rating,A[i].budget,A[i].title_year,
                A[i].actor_2_facebook_likes,A[i].imdb_score,A[i].aspect_ratio,A[i].movie_facebook_likes);
        }
        // free(A);
    }

    if (strcmp(argv[1],"-c")==0 ) 
    {
        printf("%s",argv[2]);           // testing je ni


        // int tmp[SIZE];
        struct item_t *tmp =  (struct item_t*) malloc(12 * sizeof(struct item_t*));
        char *what;
        what = argv[2];
    printf("--- C Merge Sort Demonstration --- \n");
 
    printf("Array before sorting:\n");
    display(A,SIZE,token);
            // free(A);

 
    merge_sort(A, tmp, SIZE, what);
 
    printf("Array after sorting:\n");
    display(A,SIZE,token);





        
    } 
    



    return 0;
}




void merge_sort(struct item_t *a,struct item_t *tmp, const int size, char *what)
{
    msort(a, tmp, 0, size - 1, what);
                free(a);

}
 
void msort(struct item_t *a,struct item_t *tmp, int left, int right, char *what)
{

    int mid;  
    if (right > left)
    {
        mid = (right + left) / 2;        //7+0 3, 3+0 1, 1+0 0, | 
        msort(a, tmp, left, mid, what);
        //printf("%d\n", mid);
        msort(a, tmp, mid + 1, right, what);   //1+1
        //printf("%d\n", mid);
       // printf("%d\n", left);
        merge(a, tmp, left, mid + 1, right, what); //0 1 1
    }
}
 
void merge(struct item_t *a,struct item_t *tmp, int left, int mid, int right, char *what)
{

    int i, left_end, count, tmp_pos;
    left_end = mid - 1;  // 0
    tmp_pos = left; // 0
    count = right - left + 1; // 2
    char *tempe = what;
    


    if (strcmp(what,"director_name")==0)
    {
        while ((left <= left_end) && (mid <= right))
        {
            if (a[left].director_name[0] <= a[mid].director_name[0]) 
            {
                strcpy(tmp[tmp_pos++].color,a[left++].color);
                strcpy(tmp[tmp_pos-1].director_name,a[left-1].director_name);
                strcpy(tmp[tmp_pos-1].num_critic_for_reviews, a[left-1].num_critic_for_reviews);
                strcpy(tmp[tmp_pos-1].duration,a[left-1].duration);
                strcpy(tmp[tmp_pos-1].director_facebook_likes,a[left-1].director_facebook_likes);
                strcpy(tmp[tmp_pos-1].actor_3_facebook_likes,a[left-1].actor_3_facebook_likes);
                strcpy(tmp[tmp_pos-1].actor_2_name,a[left-1].actor_2_name);
                strcpy(tmp[tmp_pos-1].actor_1_facebook_likes,a[left-1].actor_1_facebook_likes);
                strcpy(tmp[tmp_pos-1].gross,a[left-1].gross);
                strcpy(tmp[tmp_pos-1].genres,a[left-1].genres);
                strcpy(tmp[tmp_pos-1].actor_1_name,a[left-1].actor_1_name);
                strcpy(tmp[tmp_pos-1].movie_title,a[left-1].movie_title);
                strcpy(tmp[tmp_pos-1].num_voted_users,a[left-1].num_voted_users);
                strcpy(tmp[tmp_pos-1].cast_total_facebook_likes,a[left-1].cast_total_facebook_likes);
                strcpy(tmp[tmp_pos-1].actor_3_name,a[left-1].actor_3_name);
                strcpy(tmp[tmp_pos-1].facenumber_in_poster,a[left-1].facenumber_in_poster);
                strcpy(tmp[tmp_pos-1].plot_keywords,a[left-1].plot_keywords);
                strcpy(tmp[tmp_pos-1].movie_imdb_link,a[left-1].movie_imdb_link);
                strcpy(tmp[tmp_pos-1].num_user_for_reviews,a[left-1].num_user_for_reviews);
                strcpy(tmp[tmp_pos-1].language,a[left-1].language);
                strcpy(tmp[tmp_pos-1].country,a[left-1].country);
                strcpy(tmp[tmp_pos-1].content_rating,a[left-1].content_rating);
                strcpy(tmp[tmp_pos-1].budget,a[left-1].budget);
                strcpy(tmp[tmp_pos-1].title_year,a[left-1].title_year);
                strcpy(tmp[tmp_pos-1].actor_2_facebook_likes,a[left-1].actor_2_facebook_likes);
                strcpy(tmp[tmp_pos-1].imdb_score,a[left-1].imdb_score);
                strcpy(tmp[tmp_pos-1].aspect_ratio,a[left-1].aspect_ratio);
                strcpy(tmp[tmp_pos-1].movie_facebook_likes,a[left-1].movie_facebook_likes);

            }
            else
            {
                strcpy(tmp[tmp_pos++].color ,a[mid++].color);
                strcpy(tmp[tmp_pos-1].director_name ,a[mid-1].director_name);
                strcpy(tmp[tmp_pos-1].num_critic_for_reviews, a[mid-1].num_critic_for_reviews);
                strcpy(tmp[tmp_pos-1].duration ,a[mid-1].duration);
                strcpy(tmp[tmp_pos-1].director_facebook_likes ,a[mid-1].director_facebook_likes);
                strcpy(tmp[tmp_pos-1].actor_3_facebook_likes ,a[mid-1].actor_3_facebook_likes);
                strcpy(tmp[tmp_pos-1].actor_2_name ,a[mid-1].actor_2_name);
                strcpy(tmp[tmp_pos-1].actor_1_facebook_likes ,a[mid-1].actor_1_facebook_likes);
                strcpy(tmp[tmp_pos-1].gross ,a[mid-1].gross);
                strcpy(tmp[tmp_pos-1].genres ,a[mid-1].genres);
                strcpy(tmp[tmp_pos-1].actor_1_name ,a[mid-1].actor_1_name);
                strcpy(tmp[tmp_pos-1].movie_title ,a[mid-1].movie_title);
                strcpy(tmp[tmp_pos-1].num_voted_users ,a[mid-1].num_voted_users);
                strcpy(tmp[tmp_pos-1].cast_total_facebook_likes ,a[mid-1].cast_total_facebook_likes);
                strcpy(tmp[tmp_pos-1].actor_3_name ,a[mid-1].actor_3_name);
                strcpy(tmp[tmp_pos-1].facenumber_in_poster ,a[mid-1].facenumber_in_poster);
                strcpy(tmp[tmp_pos-1].plot_keywords ,a[mid-1].plot_keywords);
                strcpy(tmp[tmp_pos-1].movie_imdb_link ,a[mid-1].movie_imdb_link);
                strcpy(tmp[tmp_pos-1].num_user_for_reviews ,a[mid-1].num_user_for_reviews);
                strcpy(tmp[tmp_pos-1].language ,a[mid-1].language);
                strcpy(tmp[tmp_pos-1].country ,a[mid-1].country);
                strcpy(tmp[tmp_pos-1].content_rating ,a[mid-1].content_rating);
                strcpy(tmp[tmp_pos-1].budget ,a[mid-1].budget);
                strcpy(tmp[tmp_pos-1].title_year ,a[mid-1].title_year);
                strcpy(tmp[tmp_pos-1].actor_2_facebook_likes ,a[mid-1].actor_2_facebook_likes);
                strcpy(tmp[tmp_pos-1].imdb_score ,a[mid-1].imdb_score);
                strcpy(tmp[tmp_pos-1].aspect_ratio ,a[mid-1].aspect_ratio);
                strcpy(tmp[tmp_pos-1].movie_facebook_likes ,a[mid-1].movie_facebook_likes);

            }
        }
        
    }




 
    
    while (left <= left_end)
    {
        strcpy(tmp[tmp_pos++].color,a[left++].color);
        strcpy(tmp[tmp_pos-1].director_name,a[left-1].director_name);
        strcpy(tmp[tmp_pos-1].num_critic_for_reviews, a[left-1].num_critic_for_reviews);
        strcpy(tmp[tmp_pos-1].duration,a[left-1].duration);
        strcpy(tmp[tmp_pos-1].director_facebook_likes,a[left-1].director_facebook_likes);
        strcpy(tmp[tmp_pos-1].actor_3_facebook_likes,a[left-1].actor_3_facebook_likes);
        strcpy(tmp[tmp_pos-1].actor_2_name,a[left-1].actor_2_name);
        strcpy(tmp[tmp_pos-1].actor_1_facebook_likes,a[left-1].actor_1_facebook_likes);
        strcpy(tmp[tmp_pos-1].gross,a[left-1].gross);
        strcpy(tmp[tmp_pos-1].genres,a[left-1].genres);
        strcpy(tmp[tmp_pos-1].actor_1_name,a[left-1].actor_1_name);
        strcpy(tmp[tmp_pos-1].movie_title,a[left-1].movie_title);
        strcpy(tmp[tmp_pos-1].num_voted_users,a[left-1].num_voted_users);
        strcpy(tmp[tmp_pos-1].cast_total_facebook_likes,a[left-1].cast_total_facebook_likes);
        strcpy(tmp[tmp_pos-1].actor_3_name,a[left-1].actor_3_name);
        strcpy(tmp[tmp_pos-1].facenumber_in_poster,a[left-1].facenumber_in_poster);
        strcpy(tmp[tmp_pos-1].plot_keywords,a[left-1].plot_keywords);
        strcpy(tmp[tmp_pos-1].movie_imdb_link,a[left-1].movie_imdb_link);
        strcpy(tmp[tmp_pos-1].num_user_for_reviews,a[left-1].num_user_for_reviews);
        strcpy(tmp[tmp_pos-1].language,a[left-1].language);
        strcpy(tmp[tmp_pos-1].country,a[left-1].country);
        strcpy(tmp[tmp_pos-1].content_rating,a[left-1].content_rating);
        strcpy(tmp[tmp_pos-1].budget,a[left-1].budget);
        strcpy(tmp[tmp_pos-1].title_year,a[left-1].title_year);
        strcpy(tmp[tmp_pos-1].actor_2_facebook_likes,a[left-1].actor_2_facebook_likes);
        strcpy(tmp[tmp_pos-1].imdb_score,a[left-1].imdb_score);
        strcpy(tmp[tmp_pos-1].aspect_ratio,a[left-1].aspect_ratio);
        strcpy(tmp[tmp_pos-1].movie_facebook_likes,a[left-1].movie_facebook_likes);



    }
    while (mid <= right)
    {
        strcpy(tmp[tmp_pos++].color ,a[mid++].color);
        strcpy(tmp[tmp_pos-1].director_name ,a[mid-1].director_name);
        strcpy(tmp[tmp_pos-1].num_critic_for_reviews, a[mid-1].num_critic_for_reviews);
        strcpy(tmp[tmp_pos-1].duration ,a[mid-1].duration);
        strcpy(tmp[tmp_pos-1].director_facebook_likes ,a[mid-1].director_facebook_likes);
        strcpy(tmp[tmp_pos-1].actor_3_facebook_likes ,a[mid-1].actor_3_facebook_likes);
        strcpy(tmp[tmp_pos-1].actor_2_name ,a[mid-1].actor_2_name);
        strcpy(tmp[tmp_pos-1].actor_1_facebook_likes ,a[mid-1].actor_1_facebook_likes);
        strcpy(tmp[tmp_pos-1].gross ,a[mid-1].gross);
        strcpy(tmp[tmp_pos-1].genres ,a[mid-1].genres);
        strcpy(tmp[tmp_pos-1].actor_1_name ,a[mid-1].actor_1_name);
        strcpy(tmp[tmp_pos-1].movie_title ,a[mid-1].movie_title);
        strcpy(tmp[tmp_pos-1].num_voted_users ,a[mid-1].num_voted_users);
        strcpy(tmp[tmp_pos-1].cast_total_facebook_likes ,a[mid-1].cast_total_facebook_likes);
        strcpy(tmp[tmp_pos-1].actor_3_name ,a[mid-1].actor_3_name);
        strcpy(tmp[tmp_pos-1].facenumber_in_poster ,a[mid-1].facenumber_in_poster);
        strcpy(tmp[tmp_pos-1].plot_keywords ,a[mid-1].plot_keywords);
        strcpy(tmp[tmp_pos-1].movie_imdb_link ,a[mid-1].movie_imdb_link);
        strcpy(tmp[tmp_pos-1].num_user_for_reviews ,a[mid-1].num_user_for_reviews);
        strcpy(tmp[tmp_pos-1].language ,a[mid-1].language);
        strcpy(tmp[tmp_pos-1].country ,a[mid-1].country);
        strcpy(tmp[tmp_pos-1].content_rating ,a[mid-1].content_rating);
        strcpy(tmp[tmp_pos-1].budget ,a[mid-1].budget);
        strcpy(tmp[tmp_pos-1].title_year ,a[mid-1].title_year);
        strcpy(tmp[tmp_pos-1].actor_2_facebook_likes ,a[mid-1].actor_2_facebook_likes);
        strcpy(tmp[tmp_pos-1].imdb_score ,a[mid-1].imdb_score);
        strcpy(tmp[tmp_pos-1].aspect_ratio ,a[mid-1].aspect_ratio);
        strcpy(tmp[tmp_pos-1].movie_facebook_likes ,a[mid-1].movie_facebook_likes);

    }
 
    for (i = 0; i < count; i++)
    {

                                                            // printf("%s\n", tmp[right].director_name );
                                                            // printf("%s\n", "hello" );
                                                            // printf("%d\n", count );
                                                            // printf("%d\n", right );




        strcpy(a[right].color, tmp[right].color);
        strcpy(a[right].director_name, tmp[right].director_name);
        strcpy(a[right].num_critic_for_reviews, tmp[right].num_critic_for_reviews);
        strcpy(a[right].duration, tmp[right].duration);
        strcpy(a[right].director_facebook_likes, tmp[right].director_facebook_likes);
        strcpy(a[right].actor_3_facebook_likes, tmp[right].actor_3_facebook_likes);
        strcpy(a[right].actor_2_name, tmp[right].actor_2_name);
        strcpy(a[right].actor_1_facebook_likes, tmp[right].actor_1_facebook_likes);
        strcpy(a[right].gross, tmp[right].gross);
        strcpy(a[right].genres, tmp[right].genres);
        strcpy(a[right].actor_1_name, tmp[right].actor_1_name);
        strcpy(a[right].movie_title, tmp[right].movie_title);
        strcpy(a[right].num_voted_users, tmp[right].num_voted_users);
        strcpy(a[right].cast_total_facebook_likes, tmp[right].cast_total_facebook_likes);
        strcpy(a[right].actor_3_name, tmp[right].actor_3_name);
        strcpy(a[right].facenumber_in_poster, tmp[right].facenumber_in_poster);
        strcpy(a[right].plot_keywords, tmp[right].plot_keywords);
        strcpy(a[right].movie_imdb_link, tmp[right].movie_imdb_link);
        strcpy(a[right].num_user_for_reviews, tmp[right].num_user_for_reviews);
        strcpy(a[right].language, tmp[right].language);
        strcpy(a[right].country, tmp[right].country);
        strcpy(a[right].content_rating, tmp[right].content_rating);
        strcpy(a[right].budget, tmp[right].budget);
        strcpy(a[right].title_year, tmp[right].title_year);
        strcpy(a[right].actor_2_facebook_likes, tmp[right].actor_2_facebook_likes);
        strcpy(a[right].imdb_score, tmp[right].imdb_score);
        strcpy(a[right].aspect_ratio, tmp[right].aspect_ratio);
        strcpy(a[right].movie_facebook_likes, tmp[right].movie_facebook_likes);



        right = right - 1;
    }
                    // free(a);


}
 
void display(struct item_t *a,const int size,char token[200000])
{
    int i;
    printf("%s\n", token );
    for(i = 0; i < size; i++)
    {
        printf("%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n\n", 
            a[i].color, a[i].director_name, a[i].num_critic_for_reviews, 
            a[i].duration, a[i].director_facebook_likes,a[i].actor_3_facebook_likes,a[i].actor_2_name,
            a[i].actor_1_facebook_likes,a[i].gross,a[i].genres,a[i].actor_1_name,a[i].movie_title,a[i].num_voted_users,
            a[i].cast_total_facebook_likes,a[i].actor_3_name,a[i].facenumber_in_poster,a[i].plot_keywords,a[i].movie_imdb_link,
            a[i].num_user_for_reviews,a[i].language,a[i].country,a[i].content_rating,a[i].budget,a[i].title_year,
            a[i].actor_2_facebook_likes,a[i].imdb_score,a[i].aspect_ratio,a[i].movie_facebook_likes);

    }
        // printf("%s\n",a[i].director_name);
 
}