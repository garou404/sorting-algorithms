#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


int create_file(char* buffer, char extension){
    pid_t res_fork = fork();
    if(!res_fork) { // touch file_sort.c
        char* file_to_create = malloc(sizeof(char)*50);
        sprintf(file_to_create, "%s/%s.%c", buffer, buffer, extension);
        char *args[] = {"touch", file_to_create, NULL};
        execvp("touch", args);
        return 0;
    }else {
        int statut;
        waitpid(res_fork, &statut, 0);
        printf("end of waitpid 2\n");
        return 1;
    }
}

int main(int argc, char** argv) {
    if(argc != 2){
        printf("Usage: create name_algo\n");
        return EXIT_FAILURE;
    }

    char* buffer=malloc(sizeof(char)*30);
    strcpy(buffer, argv[1]);
    buffer = strcat(buffer, "_sort");
    pid_t res_fork = fork();
    if(!res_fork) { // mkdir folder
        char *args[] = {"mkdir", buffer, NULL};
        execvp("mkdir", args);
    }else {
        int statut;
        waitpid(res_fork, &statut, 0);
        printf("end of waitpid 1\n");
        create_file(buffer, 'c');
        create_file(buffer, 'h');
    
    }
    return EXIT_SUCCESS;
}
