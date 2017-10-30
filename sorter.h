/**
* Group members: Suhail Azmin Bin Saiful Adli & Maryam Farid Iskandar
* Class: CS 214
* File: sorter.h
* Description: Sorter.h is the header file that holds all the data from
*			   movie_metadata.csv in struct member variables and 
*              function declarations.
*
**/




#ifndef SORTER_H_
#define SORTER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#include <unistd.h>
#include <dirent.h>

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

extern char *token;

void merge(struct item_t *a,struct item_t *tmp, int left, int mid, int right, char *what);
void msort(struct item_t *a,struct item_t *tmp, int left, int right, char *what);
void merge_sort(struct item_t *a,struct item_t *tmp, const int size, char *what);
void copytmp(struct item_t *a,struct item_t *tmp,int tmp_pos,int position);
void copytrue(struct item_t *a,struct item_t *tmp,int right);

void display(struct item_t *a,const int size,char *token,int count);
void outputcsv(char *filename, struct item_t *a, const int size, char *token, int count);

#endif /* SORTER_H_ */
