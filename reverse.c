#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xmalloc.h"

struct node{
    char *s;
    struct node *next;  
};

int main(int argc, char* argv[]) {
    if(argc>3) {
        fprintf(stderr, "usage: reverse <input> <output>\n");
        exit(1);
    }
    if(argc == 3 && strcmp(argv[1], argv[2])==0) {
        fprintf(stderr, "reverse: input and output file must differ\n");
        exit(1);
    }  
    struct node *head = NULL;
    char *c = NULL;
    size_t cap = 0;
    FILE *input_stream = stdin; 
    if(argc>1) {
        input_stream = fopen(argv[1], "r");
        if(!input_stream) {
            fprintf(stderr, "reverse: cannot open file \'%s\'\n", argv[1]);
            exit(1);
        }
    }
    FILE *output_stream = stdout;
    if(argc>2) {
        output_stream = fopen(argv[2], "w");
        if(!output_stream) {
            fprintf(stderr, "reverse: cannot open file \'%s\'\n", argv[2]);
            exit(1);
        }
    }
    while(getline(&c, &cap, input_stream) != -1) {
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        if(newnode == NULL) {
            fprintf(stderr, "Memory overflow\n");
            exit(1);
        }
        newnode->s = strdup(c);
        newnode->next = head;
        head = newnode;
    } 
    if(fclose(input_stream) == EOF) {
        fprintf(stderr, "Error closing the input file/stream\n");
        exit(1);
    }
    free(c);
    if(head == NULL) {
        fprintf(stderr, "reverse: input and output file must differ\n");
        exit(1);
    }
    while(head != NULL) {
        struct node *tmp = head;
        fputs(head->s, output_stream);
        head = head->next;
        free(tmp->s);
        free(tmp);
    }
    if(fclose(output_stream) == EOF) {
        fprintf(stderr, "Error closing the output file/stream\n");
        exit(1);
    }
    return 0;
}
