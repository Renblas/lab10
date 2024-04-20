#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Trie structure
typedef struct Trie
{	
    struct Trie* childs[26];
    int count;
    char letter;
} Trie;

// Initializes a trie structure
struct Trie *createTrie(int is_word, char let)
{
    Trie* t = (Trie*)malloc(sizeof(Trie) * 1);
    t->count = is_word;
    t->letter = let;

    return t;
}

// computes the number of occurances of the word
int numberOfOccurances(struct Trie *pTrie, char *word)
{
}

// deallocate the trie structure
struct Trie *deallocateTrie(struct Trie *pTrie)
{
}

// Inserts the word to the trie structure
void insert(struct Trie *pTrie, char *word)
{
    Trie* cur = pTrie;

    int i = 0;
    while (i < strlen(word)) {
        i++;
    }


}

// this function will return number of words in the dictionary,
// and read all the words in the dictionary to the structure words
int readDictionary(char *filename, char **pInWords)
{
    FILE* fp = fopen(filename, "r");

    int i = 0;
    while(NULL != fgets( pInWords[i], 1000, fp)) {
        i++;
    }

    fclose(fp);
    return i;
}

// Main
int main(void)
{
	char *inWords[256];
    for (int i = 0; i < 256; i++) {
        inWords[i] = (char *) malloc(sizeof(char) * 32);
    }
	
	//read the number of the words in the dictionary
	int numWords = readDictionary("dictionary.txt", inWords);
	for (int i=0;i<numWords;++i)
	{
		printf("%s\n",inWords[i]);
	}
	
	struct Trie *pTrie = createTrie('0', 0);
	for (int i=0;i<numWords;i++)
	{
		insert(pTrie, inWords[i]);
	}
	// parse lineby line, and insert each word to the trie data structure
	char *pWords[] = {"notaword", "ucf", "no", "note", "corg"};
	for (int i=0;i<5;i++)
	{
		printf("\t%s : %d\n", pWords[i], numberOfOccurances(pTrie, pWords[i]));
	}
	pTrie = deallocateTrie(pTrie);
	if (NULL != NULL)
		printf("There is an error in this program\n");
	return 0;
}
