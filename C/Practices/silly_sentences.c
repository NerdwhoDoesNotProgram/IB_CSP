// IB 7th Silly Sentences - C
#include <stdio.h>
#include <string.h>

int main(){
	char first[20];
	char last[50];
	char full_name[70] = "";
	char word1[20];
	char word2[20];
	char word3[20];
    char word4[20];


	printf("Please enter a First name: ");
	scanf("%s", first);

	printf("Please enter a Last name: ");
	scanf("%s", last);

	strcat(full_name, first);
	strcat(full_name, " ");
	strcat(full_name, last);

	printf("Enter a noun: ");
    scanf("%s", word1);

	printf("Enter an adjective: ");
    scanf("%s", word2);

	printf("Enter a verb (past tense): ");
    scanf("%s", word3);

    printf("Enter an adverb: ");
    scanf("%s", word4);


	printf("While visiting the spooky zoo, %s noticed a %s %s that %s %s into the bushes, leaving everyone feeling totally terrified.", full_name, word2, word1, word3, word4);

	return 0;
}

