#include "sorter.h"

void copytmp(struct item_t *a,struct item_t *tmp,int tmp_pos,int position)
{
    strcpy(tmp[tmp_pos-1].color,a[position-1].color);
    strcpy(tmp[tmp_pos-1].director_name,a[position-1].director_name);
    strcpy(tmp[tmp_pos-1].num_critic_for_reviews, a[position-1].num_critic_for_reviews);
    strcpy(tmp[tmp_pos-1].duration,a[position-1].duration);
    strcpy(tmp[tmp_pos-1].director_facebook_likes,a[position-1].director_facebook_likes);
    strcpy(tmp[tmp_pos-1].actor_3_facebook_likes,a[position-1].actor_3_facebook_likes);
    strcpy(tmp[tmp_pos-1].actor_2_name,a[position-1].actor_2_name);
    strcpy(tmp[tmp_pos-1].actor_1_facebook_likes,a[position-1].actor_1_facebook_likes);
    strcpy(tmp[tmp_pos-1].gross,a[position-1].gross);
    strcpy(tmp[tmp_pos-1].genres,a[position-1].genres);
    strcpy(tmp[tmp_pos-1].actor_1_name,a[position-1].actor_1_name);
    strcpy(tmp[tmp_pos-1].movie_title,a[position-1].movie_title);
    strcpy(tmp[tmp_pos-1].num_voted_users,a[position-1].num_voted_users);
    strcpy(tmp[tmp_pos-1].cast_total_facebook_likes,a[position-1].cast_total_facebook_likes);
    strcpy(tmp[tmp_pos-1].actor_3_name,a[position-1].actor_3_name);
    strcpy(tmp[tmp_pos-1].facenumber_in_poster,a[position-1].facenumber_in_poster);
    strcpy(tmp[tmp_pos-1].plot_keywords,a[position-1].plot_keywords);
    strcpy(tmp[tmp_pos-1].movie_imdb_link,a[position-1].movie_imdb_link);
    strcpy(tmp[tmp_pos-1].num_user_for_reviews,a[position-1].num_user_for_reviews);
    strcpy(tmp[tmp_pos-1].language,a[position-1].language);
    strcpy(tmp[tmp_pos-1].country,a[position-1].country);
    strcpy(tmp[tmp_pos-1].content_rating,a[position-1].content_rating);
    strcpy(tmp[tmp_pos-1].budget,a[position-1].budget);
    strcpy(tmp[tmp_pos-1].title_year,a[position-1].title_year);
    strcpy(tmp[tmp_pos-1].actor_2_facebook_likes,a[position-1].actor_2_facebook_likes);
    strcpy(tmp[tmp_pos-1].imdb_score,a[position-1].imdb_score);
    strcpy(tmp[tmp_pos-1].aspect_ratio,a[position-1].aspect_ratio);
    strcpy(tmp[tmp_pos-1].movie_facebook_likes,a[position-1].movie_facebook_likes);

}
void copytrue(struct item_t *a,struct item_t *tmp,int right)
{
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
        mid = (right + left) / 2;        
        msort(a, tmp, left, mid, what);
        msort(a, tmp, mid + 1, right, what);   
        merge(a, tmp, left, mid + 1, right, what); 
    }
}
 
void merge(struct item_t *a,struct item_t *tmp, int left, int mid, int right, char *what)
{

    int i, left_end, count, tmp_pos;
    left_end = mid - 1;  // 0
    tmp_pos = left; // 0
    count = right - left + 1; // 2
    char *tempe = (char *) malloc(10000 * sizeof(char*));
    tempe = what;
    

    


    if (strcmp(tempe,"color") == 0)
    {
        while ((left <= left_end) && (mid <= right))
        {
            if (a[left].color[0] <= a[mid].color[0]) 
            {
                tmp_pos++;
                left++;
                copytmp(a,tmp,tmp_pos,left);
            }
            else
            {
                tmp_pos++;
                mid++;
                copytmp(a,tmp,tmp_pos,mid);
            }
        }      
    }
    else if(strcmp(tempe,"director_name") == 0)
    {
        while ((left <= left_end) && (mid <= right))
        {
            if (a[left].director_name[0] <= a[mid].director_name[0]) 
            {
                tmp_pos++;
                left++;
                copytmp(a,tmp,tmp_pos,left);
            }
            else
            {
                tmp_pos++;
                mid++;
                copytmp(a,tmp,tmp_pos,mid);
            }
        }      
    }
    else if (strcmp(tempe,"num_critic_for_reviews") == 0)
    {
        while ((left <= left_end) && (mid <= right))
        {
            if (atoi(a[left].num_critic_for_reviews) <= atoi(a[mid].num_critic_for_reviews)) 
            {
                tmp_pos++;
                left++;
                copytmp(a,tmp,tmp_pos,left);
            }
            else
            {
                tmp_pos++;
                mid++;
                copytmp(a,tmp,tmp_pos,mid);
            }
        }      
    }
    else if (strcmp(tempe,"duration") == 0)
    {
        while ((left <= left_end) && (mid <= right))
        {
            if (atoi(a[left].duration) <= atoi(a[mid].duration)) 
            {
                tmp_pos++;
                left++;
                copytmp(a,tmp,tmp_pos,left);
            }
            else
            {
                tmp_pos++;
                mid++;
                copytmp(a,tmp,tmp_pos,mid);
            }
        }      
    }
    else if (strcmp(tempe,"director_facebook_likes") == 0)
    {
        while ((left <= left_end) && (mid <= right))
        {
            if (atoi(a[left].director_facebook_likes) <= atoi(a[mid].director_facebook_likes)) 
            {
                tmp_pos++;
                left++;
                copytmp(a,tmp,tmp_pos,left);
            }
            else
            {
                tmp_pos++;
                mid++;
                copytmp(a,tmp,tmp_pos,mid);
            }
        }      
    }
    else if (strcmp(tempe,"actor_3_facebook_likes") == 0)
    {
        while ((left <= left_end) && (mid <= right))
        {
            if (atoi(a[left].actor_3_facebook_likes) <= atoi(a[mid].actor_1_facebook_likes)) 
            {
                tmp_pos++;
                left++;
                copytmp(a,tmp,tmp_pos,left);
            }
            else
            {
                tmp_pos++;
                mid++;
                copytmp(a,tmp,tmp_pos,mid);
            }
        }      
    }
    else if (strcmp(tempe,"actor_2_name") == 0)
    {
        while ((left <= left_end) && (mid <= right))
        {
            if (a[left].actor_2_name[0] <= a[mid].actor_2_name[0]) 
            {
                tmp_pos++;
                left++;
                copytmp(a,tmp,tmp_pos,left);
            }
            else
            {
                tmp_pos++;
                mid++;
                copytmp(a,tmp,tmp_pos,mid);
            }
        }      
    }
    else if (strcmp(tempe,"actor_1_facebook_likes") == 0)
    {
        while ((left <= left_end) && (mid <= right))
        {
            if (atoi(a[left].actor_1_facebook_likes) <= atoi(a[mid].actor_1_facebook_likes)) 
            {
                tmp_pos++;
                left++;
                copytmp(a,tmp,tmp_pos,left);
            }
            else
            {
                tmp_pos++;
                mid++;
                copytmp(a,tmp,tmp_pos,mid);
            }
        }      
    }
    else if (strcmp(tempe,"gross") == 0)
    {
        while ((left <= left_end) && (mid <= right))
        {
            if (atoi(a[left].gross) <= atoi(a[mid].gross)) 
            {
                tmp_pos++;
                left++;
                copytmp(a,tmp,tmp_pos,left);
            }
            else
            {
                tmp_pos++;
                mid++;
                copytmp(a,tmp,tmp_pos,mid);
            }
        }      
    }
    else if (strcmp(tempe,"genres") == 0)
    {
        while ((left <= left_end) && (mid <= right))
        {
            if (a[left].genres[0] <= a[mid].genres[0]) 
            {
                tmp_pos++;
                left++;
                copytmp(a,tmp,tmp_pos,left);
            }
            else
            {
                tmp_pos++;
                mid++;
                copytmp(a,tmp,tmp_pos,mid);
            }
        }      
    }
    else if (strcmp(tempe,"actor_1_name") == 0)
    {
        while ((left <= left_end) && (mid <= right))
        {
            if (a[left].actor_1_name[0] <= a[mid].actor_1_name[0]) 
            {
                tmp_pos++;
                left++;
                copytmp(a,tmp,tmp_pos,left);
            }
            else
            {
                tmp_pos++;
                mid++;
                copytmp(a,tmp,tmp_pos,mid);
            }
        }      
    }
    else if (strcmp(tempe,"movie_title") == 0)
    {
        while ((left <= left_end) && (mid <= right))
        {
            if (a[left].movie_title[0] <= a[mid].movie_title[0]) 
            {
                tmp_pos++;
                left++;
                copytmp(a,tmp,tmp_pos,left);
            }
            else
            {
                tmp_pos++;
                mid++;
                copytmp(a,tmp,tmp_pos,mid);
            }
        }      
    }
    else if (strcmp(tempe,"num_voted_users") == 0)
    {
        while ((left <= left_end) && (mid <= right))
        {
            if (atoi(a[left].num_voted_users) <= atoi(a[mid].num_voted_userss)) 
            {
                tmp_pos++;
                left++;
                copytmp(a,tmp,tmp_pos,left);
            }
            else
            {
                tmp_pos++;
                mid++;
                copytmp(a,tmp,tmp_pos,mid);
            }
        }      
    }
    else if (strcmp(tempe,"cast_total_facebook_likes") == 0)
    {
        while ((left <= left_end) && (mid <= right))
        {
            if (atoi(a[left].cast_total_facebook_likes) <= atoi(a[mid].cast_total_facebook_likes)) 
            {
                tmp_pos++;
                left++;
                copytmp(a,tmp,tmp_pos,left);
            }
            else
            {
                tmp_pos++;
                mid++;
                copytmp(a,tmp,tmp_pos,mid);
            }
        }      
    }
    else if (strcmp(tempe,"actor_3_name") == 0)
    {
        while ((left <= left_end) && (mid <= right))
        {
            if (a[left].actor_3_name[0] <= a[mid].actor_3_name[0]) 
            {
                tmp_pos++;
                left++;
                copytmp(a,tmp,tmp_pos,left);
            }
            else
            {
                tmp_pos++;
                mid++;
                copytmp(a,tmp,tmp_pos,mid);
            }
        }      
    }
    else if (strcmp(tempe,"facenumber_in_poster") == 0)
    {
        while ((left <= left_end) && (mid <= right))
        {
            if (atoi(a[left].facenumber_in_poster) <= atoi(a[mid].facenumber_in_poster)) 
            {
                tmp_pos++;
                left++;
                copytmp(a,tmp,tmp_pos,left);
            }
            else
            {
                tmp_pos++;
                mid++;
                copytmp(a,tmp,tmp_pos,mid);
            }
        }      
    }
    else if (strcmp(tempe,"plot_keywords") == 0)
    {
        while ((left <= left_end) && (mid <= right))
        {
            if (a[left].plot_keywords[0] <= a[mid].plot_keywords[0]) 
            {
                tmp_pos++;
                left++;
                copytmp(a,tmp,tmp_pos,left);
            }
            else
            {
                tmp_pos++;
                mid++;
                copytmp(a,tmp,tmp_pos,mid);
            }
        }      
    }
    else if (strcmp(tempe,"movie_imdb_link") == 0)
    {
        while ((left <= left_end) && (mid <= right))
        {
            if (a[left].movie_imdb_link[0] <= a[mid].movie_imdb_link[0]) 
            {
                tmp_pos++;
                left++;
                copytmp(a,tmp,tmp_pos,left);
            }
            else
            {
                tmp_pos++;
                mid++;
                copytmp(a,tmp,tmp_pos,mid);
            }
        }      
    }
    else if (strcmp(tempe,"num_user_for_reviews") == 0)
    {
        while ((left <= left_end) && (mid <= right))
        {
            if (atoi(a[left].num_user_for_reviews) <= atoi(a[mid].num_user_for_reviews)) 
            {
                tmp_pos++;
                left++;
                copytmp(a,tmp,tmp_pos,left);
            }
            else
            {
                tmp_pos++;
                mid++;
                copytmp(a,tmp,tmp_pos,mid);
            }
        }      
    }
    else if (strcmp(tempe,"language") == 0)
    {
        while ((left <= left_end) && (mid <= right))
        {
            if (a[left].language[0] <= a[mid].language[0]) 
            {
                tmp_pos++;
                left++;
                copytmp(a,tmp,tmp_pos,left);
            }
            else
            {
                tmp_pos++;
                mid++;
                copytmp(a,tmp,tmp_pos,mid);
            }
        }      
    }
    else if (strcmp(tempe,"country") == 0)
    {
        while ((left <= left_end) && (mid <= right))
        {
            if (a[left].country[0] <= a[mid].country[0]) 
            {
                tmp_pos++;
                left++;
                copytmp(a,tmp,tmp_pos,left);
            }
            else
            {
                tmp_pos++;
                mid++;
                copytmp(a,tmp,tmp_pos,mid);
            }
        }      
    }
    else if (strcmp(tempe,"content_rating") == 0)
    {
        while ((left <= left_end) && (mid <= right))
        {
            if (a[left].content_rating[0] <= a[mid].content_rating[0]) 
            {
                tmp_pos++;
                left++;
                copytmp(a,tmp,tmp_pos,left);
            }
            else
            {
                tmp_pos++;
                mid++;
                copytmp(a,tmp,tmp_pos,mid);
            }
        }      
    }
    else if (strcmp(tempe,"budget") == 0)
    {
        while ((left <= left_end) && (mid <= right))
        {
            if (atoi(a[left].budget) <= atoi(a[mid].budget)) 
            {
                tmp_pos++;
                left++;
                copytmp(a,tmp,tmp_pos,left);
            }
            else
            {
                tmp_pos++;
                mid++;
                copytmp(a,tmp,tmp_pos,mid);
            }
        }      
    }
    else if (strcmp(tempe,"title_year") == 0)
    {
        while ((left <= left_end) && (mid <= right))
        {
            if (atoi(a[left].title_year) <= atoi(a[mid].title_year)) 
            {
                tmp_pos++;
                left++;
                copytmp(a,tmp,tmp_pos,left);
            }
            else
            {
                tmp_pos++;
                mid++;
                copytmp(a,tmp,tmp_pos,mid);
            }
        }      
    }
    else if (strcmp(tempe,"actor_2_facebook_likes") == 0)
    {
        while ((left <= left_end) && (mid <= right))
        {
            if (atoi(a[left].actor_2_facebook_likes) <= atoi(a[mid].actor_2_facebook_likes)) 
            {
                tmp_pos++;
                left++;
                copytmp(a,tmp,tmp_pos,left);
            }
            else
            {
                tmp_pos++;
                mid++;
                copytmp(a,tmp,tmp_pos,mid);
            }
        }      
    }
    else if (strcmp(tempe,"imdb_score") == 0)
    {
        while ((left <= left_end) && (mid <= right))
        {
            if (atoi(a[left].imdb_score) <= atoi(a[mid].imdb_score)) 
            {
                tmp_pos++;
                left++;
                copytmp(a,tmp,tmp_pos,left);
            }
            else
            {
                tmp_pos++;
                mid++;
                copytmp(a,tmp,tmp_pos,mid);
            }
        }      
    }
    else if (strcmp(tempe,"aspect_ratio") == 0)
    {
        while ((left <= left_end) && (mid <= right))
        {
            if (atoi(a[left].aspect_ratio) <= atoi(a[mid].aspect_ratio)) 
            {
                tmp_pos++;
                left++;
                copytmp(a,tmp,tmp_pos,left);
            }
            else
            {
                tmp_pos++;
                mid++;
                copytmp(a,tmp,tmp_pos,mid);
            }
        }      
    }
    else if (strcmp(tempe,"movie_facebook_likes") == 0)
    {
        while ((left <= left_end) && (mid <= right))
        {
            if (atoi(a[left].movie_facebook_likes) <= atoi(a[mid].movie_facebook_likes)) 
            {
                tmp_pos++;
                left++;
                copytmp(a,tmp,tmp_pos,left);
            }
            else
            {
                tmp_pos++;
                mid++;
                copytmp(a,tmp,tmp_pos,mid);
            }
        }      
    }
    else
        printf("%s\n", "error" );


    while (left <= left_end)
    {
        tmp_pos++;
        left++;
        copytmp(a,tmp,tmp_pos,left);



    }
    while (mid <= right)
    {
        tmp_pos++;
        mid++;
        copytmp(a,tmp,tmp_pos,mid);
    }
 
    for (i = 0; i < count; i++)
    {
        copytrue(a,tmp,right);
        right = right - 1;
    }
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
 
}