

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int getlength(char* str)
{
  int length = 0;
  while(str[length]!='\0')
  {
    length++;
  }


  return length;
}

int getlengthRows(char** str){

  int length_rows = 0;
  while (str[length_rows] != NULL)
  {
    length_rows++;
  }
  return length_rows;
}

void swapSenntence(char** str1, char** str2)
{


  char* temp =  malloc(sizeof(str1));
  temp = *str1;

  *str1 = 0;
  *str1 = realloc(*str1, sizeof(str2));
  *str1 = *str2;

  *str2 = 0;
  *str2 = realloc(*str2, sizeof(temp));
  *str2 = temp;

  //free(temp);
}

/*void getInput(char** str, int iterations){

  char** temp =  (char**) malloc(100);

  temp[iterations-1] =  malloc(100);


  fgets(temp[iterations-1], 100, stdin);

  //printf("%d\n", getlength(temp[iterations-1]));

  if(getlength(temp[iterations-1]) >= iterations* 99){
    iterations++;
    getInput(str, iterations);
  }
  

 // *str = realloc(*str, iterations*100);

  for(int i = 0; i<iterations;i++){
 //   str[i*99] = temp[i];
    printf("%s", temp[i]);

  }
}*/

char *myStrCpy(char* str1, char* str2, int length)
{
  while(length--)
  {
    *str1++ = *str2++;
  }
  return str1;
}

void printSentences(char** str, int length_rows)
{

  printf("Text: \n");
  for (int i = 0;i<length_rows;i++)
  {
    printf("%s ", str[i]);
  }
  printf("\n");

}

void printSentencesWithRowNumber(char** str, int length_rows)
{

  printf(" Nr. | Satz \n");
  printf("-----+----------------------------------------\n");
  for(int i = 0; i<length_rows;i++)
  {
    printf("   %d | %s\n", i+1, str[i]);
  }
}

void printStatistics(char** str, int lenght_rows)
{
  int characters = 0;
  int letters = 0;
  int capital_letters = 0;
  int lowercase_letters = 0;

  for(int rows = 0;rows < lenght_rows;rows++)
  {
    for(int cols = 0;cols < getlength(str[rows]);cols++)
    {
      if((str[rows][cols] >= 65) && (str[rows][cols] <=90))
      {
        capital_letters++;
      }

      if((str[rows][cols] >= 97) && (str[rows][cols] <=122))
      {
        lowercase_letters++;
      }

      if(str[rows][cols] != ' ')
      {
        characters++;
      }
    }
  }
  letters = capital_letters + lowercase_letters;

  printf("Text-Statistik:\n");
  printf("%d Sätze, %d Zeichen\n", lenght_rows, characters);
  printf("%d Buchstaben (%d Großbuchstaben, %d Kleinbuchstaben)\n", letters, capital_letters, lowercase_letters);

}

void mergeSentences(char*** str, int rows, int number_1, int number_2, int length_1, int length_2)
{

  char* temp = malloc(length_1);
  char and[] = " und ";
  strncpy(temp, *str[number_1], length_1-1),

  //str[0][number_1] = NULL;
  //*str[number_1] = realloc(*str[number_1], sizeof(temp));

  strcat(temp, and);

  printf("%s\n", temp);

  strcat(temp,str[0][number_2]);

  printf("%s\n", temp);

  *str[number_1] = NULL;
  *str[number_1] = realloc(*str[number_1], sizeof(temp));

  strncpy(str[0][number_1], temp, getlength(temp));

  printf("%s\n", temp);


  for(int i = 0; i<rows-number_2-1;i++)
  {
    str[0][number_2+i] = NULL;
    str[0][number_2+i] = realloc(str[0][number_2+i], sizeof(str[number_2+i+1]));
    printf("0\n");
    str[0][number_2+i] = str[0][number_2+1+i];
    printf("%s\n", *str[number_2+i]);
  }

  free(temp);
}





int main()
{
  char** str1 =  (char**) malloc(100);
  str1[0] = malloc(100);
  str1[1] = malloc(100);
  str1[2] = malloc(100);

  str1[0] = "ESP ist shit.";
  str1[1] = "Ich hasse alles.";
  str1[2] = "Gaga";

  int sen1 = 2;
  int sen2 = 3;

  //char option[3]; 

  //while(option[0] != 'e')
  //{
    char option[3] = {0,0,0};

    printf("Wählen Sie eine Option:\n");
    printf("  t: Text-Statistik\n");
    printf("  s: Zwei Sätze vertauschen\n");
    printf("  c: Zwei Sätze zusammenketten\n");
    printf("  p: Text mit Zeilennummer ausgeben\n");
    printf("  o: Text ohne Zeilennummer ausgeben\n");
    printf("  e: Programm beenden\n");


    
    //scanf("%c", &option);
    printf("Ihre Wahl: ");
    fgets(option, 3, stdin);

    switch(option[0])
    {
      case 't': printStatistics(str1, getlengthRows(str1));
        break;
      case 's': swapSenntence(&str1[sen1-1], &str1[sen2-1]);
        break;
      case 'c': mergeSentences(&str1, getlengthRows(str1), 0,1, getlength(str1[0]), getlength(str1[1]));
        break;
      case 'p': printSentencesWithRowNumber(str1, getlengthRows(str1));
        break;
      case 'o': printSentences(str1, getlengthRows(str1));
        break;
      default: printf("%c\n", option[0]);
    }

    

  //getInput(&str1[0], 1);

  //}

//TODO: 
//Zusammenketten
//Eingabe
//Fehlermeldungen
//Speicher, free

}

