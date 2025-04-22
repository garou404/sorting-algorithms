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
    // if(argc != 2){
    //     printf("Usage: create name_algo\n");
    //     return EXIT_FAILURE;
    // }

    // // file creation
    // char* buffer=malloc(sizeof(char)*30);
    // strcpy(buffer, argv[1]);
    // buffer = strcat(buffer, "_sort");
    // pid_t res_fork = fork();
    // if(!res_fork) { // mkdir folder
    //     char *args[] = {"mkdir", buffer, NULL};
    //     execvp("mkdir", args);
    // }else {
    //     int statut;
    //     waitpid(res_fork, &statut, 0);
    //     printf("end of waitpid 1\n");
    //     create_file(buffer, 'c');
    //     create_file(buffer, 'h');
    // }

    // file content writing
    FILE* template_c = fopen("./template/template_c", "r");
    fseek(template_c, 0, SEEK_END);
    long template_size = ftell(template_c);
    fseek(template_c, 0, SEEK_SET);
    printf("temaplte size %ld\n", template_size);
    char* content = malloc(sizeof(char)*(template_size+1));
    // sprintf("")
    fread(content, sizeof(char), template_size, template_c);
    content[template_size] = '\0';
    printf("%s\n", content);
    FILE* file_c = fopen("test_sort/test_sort.c", "w");
    fprintf(file_c, content, argv[1], argv[1]);
    
    return EXIT_SUCCESS;
}
