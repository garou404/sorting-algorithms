#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <ctype.h>

char * strtoupper( char * dest, const char * src ) {
    char * result = dest;
    while( *dest++ = toupper( *src++ ) );
    return result;
}

int create_file(char* algo_name, char extension){
    pid_t res_fork = fork();
    if(!res_fork) { // touch file_sort.c
        char* file_to_create = malloc(sizeof(char)*50);
        sprintf(file_to_create, "%s_sort/%s_sort.%c", algo_name, algo_name, extension);
        char *args[] = {"touch", file_to_create, NULL};
        execvp("touch", args);
        return 0;
    }else {
        int statut;
        waitpid(res_fork, &statut, 0);
        return 1;
    }
}

int write_content(char*algo_name, char extension){
    // template file content reading
    
    FILE* f_template;
    if(extension == 'h'){
        f_template = fopen("./template/template_h", "r");
    }else if(extension == 'c'){
        f_template = fopen("./template/template_c", "r");
    }

    if(f_template == NULL){
        printf("template file opening failed\n");
        return EXIT_FAILURE;
    }
    // get file size
    fseek(f_template, 0, SEEK_END);
    long template_size = ftell(f_template);
    fseek(f_template, 0, SEEK_SET);

    // read content
    char* content_template = malloc(sizeof(char)*(template_size+1));
    fread(content_template, sizeof(char), template_size, f_template);
    content_template[template_size] = '\0';

    // writing customed template to new file
    char* file_path = malloc(sizeof(char)*50);
    sprintf(file_path, "%s_sort/%s_sort.%c", algo_name, algo_name, extension);
    FILE* f_new = fopen(file_path, "w");
    if(f_new==NULL){
        printf("Failed to open %s\n", file_path);
        return EXIT_FAILURE;
    }
    if(extension == 'h'){
        char*upper_algo_name = malloc(sizeof(char)*20);
        upper_algo_name = strtoupper(upper_algo_name, algo_name);
        if(fprintf(f_new, content_template, upper_algo_name, upper_algo_name)<0){
            printf("Failed to write to %s_sort.h\n", algo_name);
            return EXIT_FAILURE;
        }
    }else{
        if(fprintf(f_new, content_template, algo_name, algo_name)<0){
            printf("Failed to write to %s_sort.h\n", algo_name);
            return EXIT_FAILURE;
        }
    }    
    return EXIT_SUCCESS;

}

int main(int argc, char** argv) {
    if(argc != 2){
        printf("Usage: create name_algo\n");
        return EXIT_FAILURE;
    }

    // file creation
    char* buffer=malloc(sizeof(char)*30);
    strcpy(buffer, argv[1]);
    pid_t res_fork = fork();
    if(!res_fork) { // mkdir folder
        char folder[30]; 
        sprintf(folder, "%s_sort", buffer);
        char *args[] = {"mkdir", folder, NULL};
        execvp("mkdir", args);
    }else {
        int statut;
        waitpid(res_fork, &statut, 0);
        
        create_file(buffer, 'c');
        write_content(buffer, 'c');

        create_file(buffer, 'h');
        write_content(buffer, 'h');
    }
    return EXIT_SUCCESS;
}
