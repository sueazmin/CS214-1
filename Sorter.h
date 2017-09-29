#ifndef SORTER_H_
#define SORTER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item_t {
    char incomplete[2000];
    char color[20];
    char director_name[20];
    char num_critic_for_reviews[50];
    char duration[20];
    char director_facebook_likes[50];
    char actor_3_facebook_likes[50];
    char actor_2_name[50];
    char actor_1_facebook_likes[50];
    char gross[50];
    char genres[50];
    char actor_1_name[50];
    char movie_title[50];
    char num_voted_users[50];
    char cast_total_facebook_likes[50];
    char actor_3_name[50];
    char facenumber_in_poster[50];
    char plot_keywords[100];
    char movie_imdb_link[500];
    char num_user_for_reviews[50];
    char language[50];
    char country[50];
    char content_rating[50];
    char budget[50];
    char title_year[50];
    char actor_2_facebook_likes[50];
    char imdb_score[50];
    char aspect_ratio[50];
    char movie_facebook_likes[50];
};

void merge(struct item_t *arr[], int lo, int mid, int hi, int meta);
void sort(struct item_t *arr[], int lo, int hi, int meta);
int compare(struct item_t *item1, struct item_t *item2, int meta);

#endif /* SORTER_H_ */
