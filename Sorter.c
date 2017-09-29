#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEFAULT_LEN 1000

int main( int argc, char *argv[] )  {
    FILE *file;


    file = stdin;
        char line[200000];
    int size = 0, len = 0, count = 0, i, c;
    char *token = NULL;


    char old_name[64];  // Space for 63 characters plus string terminator
    char new_name[64];
    if (file) {
        while (fgets(line, sizeof(line), file)) {

            
            
            sscanf(line,"\"%63[^\"]\", %63[^,]",old_name,new_name);

                    printf("%s, %s",old_name,new_name);


            


                            

                            // token = strtok(line,",");
                            // sscanf(line, "%c,%19[^,],%c",A[len].color, A[len].director_name, A[len].num_critic_for_reviews);
                            // printf("%d\n", sscanf(line, "%19[^A-Z],%19[^'o']",A[len].color, A[len].director_name, A[len].num_critic_for_reviews));
                            // printf("%s\n", A[len].director_name);
                            // test[0][0] = line;
                            // printf("%c\n", test);


                            // while(token != NULL)
                            // { 
                            //      // printf("%s\n", token );
                            //     token = strtok(NULL,",");
                            // }
                            // if (line[0] != '\0') {
                            //   printf("hi");
                            //   printf("%c\n", line[1] );
                          // }

                            // fprintf(stderr, "invalid format: %s\n", line);
                            // printf("%s\n",A[len].director_name );

        }
        


    }



    // if (strcmp(argv[1],"-c")==0 ) {
    //     // printf("%s",argv[1]);           // testing je ni

    //     //sort function here


    // } else {
    //     file = fopen (argv[1], "r");
    //     if (file == NULL) {
    //         printf ("I'm sorry Dave, I can't do that\n");
    //         printf (" (open the file '%s', that is).\n", argv[1]);
    //         return 1;

    //         //error
    //     }
    // }


    // char temp[DEFAULT_LEN];
    // //char *array[];
    // char ***array;
    // // array = malloc(1223*sizeof(char*));
    

    // char *token = NULL;
    // char line[100];
    // int column = 0;
    // int row = 0;
    // char asd[1000000];

    // if (( array = (char***) malloc(1000 * sizeof(char**))) == NULL )
    //         return -1;

    //     // then allocate memory to hold array COLS
    //     for (int i = 0; i < 1000; i++)
    //     {
    //         if (( array[i] = (char**) malloc(12 * sizeof(char**))) == NULL )
    //             return -2;
    //     }


    // // fgets (temp, DEFAULT_LEN, file);
    // // token = strtok(temp, ",");
    
    // // array[row][column++]=token;
    // // printf("%s\n", array[0][column-1]);

    // while(fgets(temp,sizeof(temp),file))
    // {
    //     token = strtok(temp,",");
    //     while(token != NULL)
    //     {
    //         sscanf(token, "%99s", line);
    //         strcpy(asd,line );
    //         array[row][column++] = asd;
    //         // printf("%s\n", array[row][column-1]);
    //         token = strtok(NULL,",");
    //         if (column > 2)
    //         {
    //             column = 0;
    //         }
    //         printf("%s\n", array[0][0]);

    //     }
    //     ++row ;
    // }
    // printf("%s\n", array[0][0]);






    // while(token = strtok(NULL, ","))
    // {
    //     array[row][column++]=token;
    //     // printf ("%s", array[1]);

    //     // printf ("%s", token);

    // }
    // printf("%s\n", array[0][column-1] );
    



    // while(fgets (temp, DEFAULT_LEN, file))
    // {
    //                         printf("%s\n", array[0][1]);

    //                 printf("%s", temp);

    //     token = strtok(temp, ",");
    //     // printf ("%s", token);
    //     // printf ("%d", column);




    //     array[row][column++]=token;
    //     // printf("%s\n", array[1][column-1]);


    //     while(token = strtok(NULL, ","))
    //     {
    //         // printf("%d", column );
    //         array[row][column++]=token;
    //          // printf ("%s", token);
    //         printf("%s", array[row][column-1]);
    //         printf("%s", array[0][0]);



    //     }
    //                         printf("%s", array[0][0]);

    //                 // printf("%s\n", array[row][column-3]);
    //                  // printf("%s\n", array[0][0]);


    //     column = 0;
    //     row++;
    //     // while(token = strtok(NULL, ","))
    //     // {
    //     //     // printf("%d", column );
    //     //     array[row][column++]=token;
    //     //      // printf ("%s", token);
    //     //     printf("%s", array[row][column-1]);
    //     //     printf("%s", array[0][0]);



    //     // }
 
    //     // printf ("%s", temp);
    //     // token = strtok(temp, ",");
    //     // printf ("%s", token);

    // }
    // for(int i = 0; i < 3; i++) {
    //     for(int j = 0; j < 3; j++) {
    //         printf("%s", array[i][j]);
    //     }
    //     printf("\n");
    // } 



    // fputs(array[0][0],stdout);





    // Only close file if you opened it yourself.

    // if (argc != 1)
    //     fclose (file);
    return 0;
}
