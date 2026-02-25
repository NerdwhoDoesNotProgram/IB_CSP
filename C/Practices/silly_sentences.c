// IB 7th Silly Sentences - C
#include <stdio.h>

int main(){
	char word1[20];
	char word2[20];
	char word3[20];
    char word4[20];

	printf("Enter a noun: ");
    scanf("%s", &word1);
	printf("Enter an adjective: ");
    scanf("%s", &word2);
	printf("Enter a verb: ");
    scanf("%s", &word3);
    printf("Enter an adverb: ");
    scanf("%s", &word4);

	printf("Once a %s, %s stumbled upon a %s and made everyone laugh %s.\n", word1, word2, word3, word4);
	return 0;
}

