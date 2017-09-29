#include "sorter.h"

/*
 * merging for sort()
 */
void merge(struct item_t *arr[], int lo, int mid, int hi, int meta){
	int left = mid-lo+1, right = hi-mid, i, j, k = lo;

	struct item_t **L = malloc(left*sizeof(struct item_t));
	struct item_t **R = malloc(right*sizeof(struct item_t));

	for(i=0; i < left; i++){
		L[i] = calloc(1, sizeof(struct item_t));
		memcpy(L[i], arr[lo+i], sizeof(struct item_t));
	}
	for(i=0; i < right; i++){
		R[i] = calloc(1, sizeof(struct item_t));
		memcpy(R[i], arr[mid+1+i], sizeof(struct item_t));
	}

	i = 0;
	j = 0;

	while(i < left && j < right){
		if(compare(L[i], R[j], meta) < 0){
			memcpy(arr[k++], L[i++], sizeof(struct item_t));
		} else {
			memcpy(arr[k++], R[j++], sizeof(struct item_t));
		}
	}

	while(i < left)
		memcpy(arr[k++], L[i++], sizeof(struct item_t));

	while(j < right)
		memcpy(arr[k++], R[j++], sizeof(struct item_t));

	free(L);
	free(R);
}


/*
 * mergesort
 */
void sort(struct item_t *arr[], int lo, int hi, int meta){
	if(lo < hi){
		int mid = (lo + hi)/2;
		sort(arr, lo, mid, meta);
		sort(arr, mid+1, hi, meta);
		merge(arr, lo, mid, hi, meta);
	}

}

int compare(struct item_t *item1, struct item_t *item2, int meta){
	switch(meta){
		case 0:
			return strcmp(item1->incomplete, item2->incomplete);
		case 1:
			return strcmp(item1->color, item2->color);
		case 2:
			return strcmp(item1->director_name, item2->director_name);
		case 3:
			return (int)item1->num_critic_for_reviews < (int)item2->num_critic_for_reviews;
		case 4:
			return (int)item1->duration >= (int)item2->duration;
		case 5:
			return (int)item1->director_facebook_likes < (int)item2->director_facebook_likes;
		case 6:
			return (int)item1->actor_3_facebook_likes < (int)item2->actor_3_facebook_likes;
		case 7:
			return strcmp(item1->actor_2_name, item2->actor_2_name);
		case 8:
			return (int)item1->actor_1_facebook_likes < (int)item2->actor_1_facebook_likes;
		case 9:
			return (int)item1->gross < (int)item2->gross;
		case 10:
			return strcmp(item1->genres, item2->genres);
		case 11:
			return strcmp(item1->actor_1_name, item2->actor_1_name);
		case 12:
			return strcmp(item1->movie_title, item2->movie_title);
		case 13:
			return (int)item1->num_voted_users < (int)item2->num_voted_users;
		case 14:
			return (int)item1->cast_total_facebook_likes < (int)item2->cast_total_facebook_likes;
		case 15:
			return strcmp(item1->actor_3_name, item2->actor_3_name);
		case 16:
			return (int)item1->facenumber_in_poster < (int)item2->facenumber_in_poster;
		case 17:
			return strcmp(item1->plot_keywords, item2->plot_keywords);
		case 18:
			return strcmp(item1->movie_imdb_link, item2->movie_imdb_link);
		case 19:
			return (int)item1->num_user_for_reviews < (int)item2->num_user_for_reviews;
		case 20:
			return strcmp(item1->language, item2->gross);
		case 21:
			return strcmp(item1->country, item2->country);
		case 22:
			return strcmp(item1->content_rating, item2->content_rating);
		case 23:
			return (int)item1->budget < (int)item2->budget;
		case 24:
			return (int)item1->title_year < (int)item2->title_year;
		case 25:
			return (int)item1->actor_2_facebook_likes < (int)item2->actor_2_facebook_likes;
		case 26:
			return (int)item1->imdb_score < (int)item2->imdb_score;
		case 27:
			return (int)item1->aspect_ratio < (int)item2->aspect_ratio;
		case 28:
			return (int)item1->movie_facebook_likes < (int)item2->movie_facebook_likes;

			//should not happen
		default:
			return -1;
	}

}

