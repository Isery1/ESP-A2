

#include <stdio.h>
#include <stdlib.h>


/*char* getSentence(char *str)
{
  return 0;
}

void swapSenntence(char* str1, char* str2){
  char* temp;
  temp = (char*) malloc(sizeof(str1));


  for(int i = 0;i < sizeof(str1)/sizeof(char*);i++){
    temp[i] = str1[i];
  }
  str1 = (char*) realloc(str1, sizeof(str2));

  for(int i = 0;i < sizeof(str2)/sizeof(char*);i++){
    str1[i] = str2[i];
  }

  str2 = (char*) realloc(str2, sizeof(str1));

   for(int i = 0;i < sizeof(temp)/sizeof(char*);i++){
    str2[i] = temp[i];
  }

  free(temp);


}
*/
int main()
{

char* str1 = 'Das ist ein Beispielsatz.';
char* str2 = 'This is an example sentence';

//swapSenntence(str1, str2);

/*for(int i = 0; i <sizeof(str1)/sizeof(char*); i++){
  printf("%c", str1[i]);
}

printf("\n");

for(int i = 0; i <sizeof(str2)/sizeof(char*); i++){
  printf("%c", str2[i]);
}
*/

printf("%i\n", sizeof(&str1));
printf("%i\n", sizeof(char));
}
