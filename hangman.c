#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h> 
int word(char *string) ;
int checkCorrect(char *myword, char ch) ;
int checkAlreadyGuessed(char *alreadyGuessed, char ch) ;
int includeMinus(char *str) ;
int enteredCorrect(char *myword, char *currentCorrect, char ch) ;
int includeCapital(char *str) ;
int k,l;
int strlen(char *str)
{   int leng = 0 ;
   if ( str == 0 ) return 0 ;
   for (leng=0; str[leng] ; leng++) ;
   return leng ;
}
void strcpy(char *to, char *from)
{
 if ( !to || !from ) 
  fprintf(stderr, "strcpy:input error\n") ;
    for (;*from;to++, from++) *to=*from;
 *(to) = 0 ;
}
int main(void)
{  
   char myword[200], ch, alreadyGuessed[20] = {0} ;
   char currentCorrect[200] =
      "******************************************************************************************************************************" ;
   int chance = 6, fin=0, i=0 ;
   word(myword) ;
   if ( strlen(myword) < 1 )
   {
    getchar() ;
    return 0 ;
   }
   //printf("selected & retuned words >%s<\n", myword) ;
   currentCorrect[strlen(myword)] = 0 ;
   //printf("selected word : %s\n", myword) ;
   printf("-------------------------------------\nB311030 �輼���� Hangman �Դϴ�\n %d�� �Է��� ��ȸ�� ���ҽ��ϴ�. \n ���纸����~~!\n-------------------------------------\n", 
         chance) ;
   while ( chance > 0 && fin == 0 )
   {
      scanf("%c", &ch ) ;
   //fgets(in,10, stdin) ;
   //printf("INPUT->%c\n",ch) ;
   // printf("INPUT->%s\n",in) ;
  //in[0]=ch;
	   if (ch=='\n')
         continue ;
    printf("\n %c �� �Է��ϼ̽��ϴ� \n", ch) ;
   //alreadyGuessed[i]=ch;
   //i++;
   if ( 1==checkAlreadyGuessed(alreadyGuessed, ch))
    printf("�̹� �Է��Ͻ� �ܾ��Դϴ� �ٽ� �Է����ּ���\n");
   else
   {
	   if (1!=checkCorrect(myword, ch))
	   {
		chance-- ;
		printf("��! ��ȸ�� �����̽��ϴ�. %d �� ��ȸ �����̽��ϴ�\n", chance);
		printf("���ݱ��� ���߽� �� : %s �Դϴ�\n", currentCorrect) ; 
	   }
	   else
	   {
		   enteredCorrect(myword,currentCorrect,ch);
		   printf("%d �� ��ȸ �����̽��ϴ�\n", chance) ;
		   printf("���ݱ��� ���߽� �� %s �Դϴ�\n", currentCorrect) ; 
	   }
   }


	   {
		   k=strlen(myword);
		   for(l=0;myword[l];l++)
		   {
			   if(myword[l]==currentCorrect[l])
				   k--;
		   }
	   }
	   
	   if (k==0)
		{
				printf("\n����!! �����մϴ�\n") ;
		}
		else if(chance==0)
		{
			printf("����.. �ٽõ����غ�����\n ������ %s �����ϴ�.",myword) ;
		}
      /* fill the following */
      fflush(stdout);
	}
   getchar() ;
   return 0;
}
int includeCapital(char *str) 
{
 if(*str<='Z'&&*str>='A')
 {
   return 1;
 }
  return 0 ;
}

 int includeMinus(char *str) 
{
  for (;*str;str++){
 if ('-' == *str)
 {
  return 1;
 }}
 return 0;
}

int checkCorrect(char *myword, char ch) 
{
 int num=0;
 for(;*myword;*myword++)
 {
  if(*myword==ch)
	  num++;
 }
 if(num>0) return 1;
 else return 0;
}

int checkAlreadyGuessed(char *alreadyGuessed, char ch) 
{
	int a=0;
	int num=0;
	for (;alreadyGuessed[a]!=0;a++)
 {
	  if(ch==alreadyGuessed[a])
		  num++;
 }
 if(num==2) return 1;
 return 0;
}
int enteredCorrect(char *myword, char *currentCorrect, char ch) 
{
	int a;
	for(a=0;myword[a];a++)
	{
		if(ch==myword[a])
			currentCorrect[a]=ch;
	}
	return 1;
}
int word(char *string)
{
   FILE *fp  ;
   char str[100] ;
   int i, fi, nthWord ;
   fp = fopen("words.txt", "r") ;
   if ( fp == 0 ) {
    fprintf(stderr, "words.txt ����.\n") ;
    strcpy(string, "") ;
    return 0 ;
   }
    srand(time(0)) ;
    //printf("%d %d\n", RAND_MAX, rand() ) ;
 #define LASTWORD 479623
 #define MIN_LENGTH 6

    nthWord = (int)( (float) rand()/(float) RAND_MAX * ((float)LASTWORD) + 0.5 ) ;
    if ( nthWord + 100 > LASTWORD )
       nthWord = nthWord - 100 ;
    //printf("nth word = %d\n", nthWord ) ;
    for ( i = 1 ; i < nthWord ; i++ )
    {
     fi = fscanf(fp, "%s", str) ;
     if ( fi == EOF )
        break ;
    }
    for ( ; ; )
    {
     if ( strlen(str) >= MIN_LENGTH && !includeMinus(str) && !includeCapital(str) )
     {
       // printf("My selected word %s\n", str) ;
     strcpy(string, str) ;
     break ;
     }
     fi = fscanf(fp, "%s", str) ;
     if ( fi == EOF )
        break ;
    }
 fclose(fp) ;
 return 0 ;
}



