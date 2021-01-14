
  
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h> 
#define False -1
#define NUM_LETTERS ((int)26)
#define CHAR_TO_INDEX(c) ((int)c - (int)'a') 

typedef struct _node{
    char letter;
    size_t count;
    struct _node* children[NUM_LETTERS];
    bool end_with_word;

} Node, *pnode;


typedef struct _trie{
    pnode root;
    int longestWord;
} Trie, *ptrie;

int get_word(char** word);
int build_trie(ptrie t);
void destroy_trie(ptrie t);
int print_trie(ptrie t, bool tag);
void print_node(pnode n, char* w, size_t size);
void print_node_rev(pnode n, char* w, size_t size);
int add_childe_trie(pnode n, size_t i);
int char_to_lower(char *c);
int insert_word(ptrie t , char* word, size_t max_len_word);




