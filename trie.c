#include "trie.h"
#define RESIZE 10

int get_word(char** word){
    //  Allocation of memory
    //  and its increase according to a fixed number
    char *w=(char*) calloc(RESIZE , sizeof(char));
    if(w==NULL)
        return False; //check alloc

    int capcity=RESIZE;
    char c=' ';
    
    while(c==' ' || c=='\0' || c=='\n' || c=='\t' || c== '\r')
    {
        c=getchar();
        if(c=='\0') 
            return EOF;
    }
    // Running on word until the end of a word
    int len=0;
    while(c !=' ' && c != '\0' && c!='\n' && c!='\t' && c != '\r' && c!=EOF)
    {
        if(len==capcity)
        {
            char *w2=realloc (w, (capcity + RESIZE)*sizeof(char));
            if(w2==NULL)
            {
                if(w!=NULL)
                {
                    free(w);
                }
            }
            w=w2;
            capcity+=RESIZE;
        }
        w[len++]=c;
        c=getchar();
    }
    //the end of the string
    w[len]='\0';
    *word=w;

    if(c==EOF)
    {
        return EOF;
    }
return len;
}


int build_trie(ptrie t)
{
t->root=(pnode)calloc(1,sizeof(Node)); //Alloc of space in memory for new Node
if(t->root==NULL) 
    return False; //must check the calloc

t->root->letter='\0';  // the root is known as '\0'
t->longestWord=0; // for start
return 0; 
}

//to free the memory
void free_node(pnode node){
    if(node==NULL)
        return;
    for(size_t i=0; i<NUM_LETTERS;i++){
        free_node(node->children[i]);
    }
    free(node);
}

void destroy_trie(ptrie t)
{
    free_node(t->root);
}

int print_trie(ptrie t, bool tag)
{
    if(t == NULL)
    {
        printf("Can't print empty trie\n");
        return False;
    }
    char* word = calloc(sizeof(char), t->longestWord);
    if(word == NULL){return False;}

    if(tag){
        print_node_rev(t->root, word, 0);
    }
    else{
        print_node(t->root, word, 0);
    }
    if(word != NULL)
        {free(word);}
    return 0;
}

void print_node(pnode n, char* w, size_t size){
    if(size>0)
    {w[size-1]=n->letter;}

    w[size]='\0';
    if(n->count > 0)//If the letter repeats itself
        {printf("%s %d\n", w, (int)n->count);}

    for(size_t i = 0 ; i<NUM_LETTERS ; i++){
        if(n->children[i]!= NULL){//If there are children
            print_node(n->children[i], w, size+1);
            w[size] = '\0'; //We have reached the end of the word
        }
    }
}
void print_node_rev(pnode n, char* w, size_t size)
{
     if(size>0){
         w[size-1]=n->letter;
         }

    for(size_t i = 0 ; i<NUM_LETTERS ; i++)
    {
        if(n->children[NUM_LETTERS-i-1]!= NULL)
        {//If there are children
             w[size] = '\0';
            print_node_rev(n->children[NUM_LETTERS-i-1], w, size+1);
        }
    }

    w[size]='\0';
    if(n->count > 0)
        printf("%s %d\n", w, (int)n->count);

}


int add_childe_trie(pnode n, size_t i)
{
  if(n == NULL || n->children[i] != NULL || i < 0 || i>= NUM_LETTERS)
    return False;

  pnode son = (pnode)calloc(1, sizeof(Node));

  if(son == NULL){return False;}

  son->letter = 'a' + i;
  n->children[i] = son;

  return 0;
}
int char_to_lower(char *c){
    // chack and change cher cher in word to lower
if('A' <= *c && *c <= 'Z')
    *c = *c - 'A' + 'a';

if('a' <= *c && *c <= 'z')
    return 0;
else
    return False;//if is not abc
}

int insert_word(ptrie t , char* word, size_t max_len_word)
{
    pnode n=t->root;
    for(size_t i = 0 ; i<max_len_word ; i++)
    {
        //Running if all the letter's word is lower and change
        if(char_to_lower(word+i)==False)
            continue;
        
        size_t i_son = word[i]-'a';
        if(n->children[i_son]==NULL)
        {
            if(add_childe_trie(n,i_son)==False)
            {
                printf("add child failed\n");
                return False;
            }//else go to be son (go down)
        }
       
        n=n->children[i_son];

    }

     if(n->letter!='\0')//if the son in't the lef
        {n->count++;}//promote the number of leaves
    
    if(t->longestWord<=max_len_word)
        {t->longestWord=max_len_word+1;} 
          
    
return 0;
}
