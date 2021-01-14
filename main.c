#include "trie.h"
#include <stdio.h>



int main(int argc, char const *argv[])
{
    char *word=NULL;
    Trie t;

    //Creating a new tree
    if(build_trie(&t)==False)
    {
         printf("faild to build trie");
         return False;
    }
    //else (after we build new trie)
    int max_len_word;
    //Absorbing a word in a string
    do 
    {
    max_len_word=get_word(&word);
    if(max_len_word>0)
    {
        //Insert word to trie
        if(insert_word(&t,word,max_len_word)==False)
        {
            printf("faild to insert word");
            return False;
        }
    }
    //Memory release
    if(word != NULL){ free(word);}
    
    }while (max_len_word!=EOF);


    //Print
   bool revres=(argc>1 && *(argv[1]) == 'r');
    print_trie(&t , revres);
   destroy_trie(&t);

    return 0;
}
