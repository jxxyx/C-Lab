#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 255
#define MAGIC_WORD "cat"

int main() {
  char sentence[MAX_LENGTH + 1];
  printf("Enter a sentence, up to 255 characters:\n");
  // reads character into an array of char until a newline or end-of-file indicator is encountered
  fgets(sentence, MAX_LENGTH + 1, stdin);

  // This are the variables that will be passed on later to allow for the code to work.
  char word[MAX_LENGTH + 1];
  int word_count = 0;
  int word_length = 0;

  // Initiating the int i == 0
  int i = 0;

  // Crafting a for loop to run through all of the characters until the charcters are fully read
  for (; sentence[i] != '\0'; i++) {
    // This is to check theall the character in the if loop is an alphabet
    if (isalpha(sentence[i])) {
      // executing the checking function for word array, then adding it into word length
      word[word_length++] = sentence[i];
    } else {
      // Word array is null-terminated by \0
      word[word_length] = '\0';

      // Word count will be incremented
      word_count++;
      
      // Checking if the magic word is present in the sentence typed
      if (strcmp(word, MAGIC_WORD) == 0) {
        printf("You said the magic word!\n");
      }
      // This will reset the word length
      word_length = 0;

      // Print the word and its length.
      printf("%s %d\n", word, strlen(word));
    }
  }

  // if the last word is not empty, print it
  if (word_length > 0) {
    printf("%s %d\n", word, strlen(word));
  }

  return 0;
}