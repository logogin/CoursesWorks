//============================Sahin Yakov=================================
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
//-----------------------------Prototype---------------------------------
int SearchSymb      (char* , char , int);
int Size_of_Memory  (char *);
void Look_for_Arr   (FILE *);
void Look_for_Int   (FILE *);
/*void Look_for_Char  (FILE *);
void Look_for_Double(FILE *);
void Look_for_Float (FILE *);*/
//-------------------------Main------------------------------------------
void main(void)
{
   FILE *pFile;
   int name1;
   char Name[80];
   clrscr();
   printf("Please, Enter the file's name:\n ");
   gets(Name);

   if((pFile = fopen(Name, "r")) != NULL)
     {
       Look_for_Arr(pFile);
       Look_for_Int(pFile);
     /* Look_for_Char(pFile);
      Look_for_Double(pFile);
      Look_for_Float(pFile);*/
     }
   else
       {
      printf("Can't open the file!");
      printf("\nPress any key...");
      getch();
      exit(1);
       }
   printf("Press any key to end!");
   getch();
}
//------------------------Function scan file-------------------------------
void Look_for_Arr(FILE *pFile)
{
  char *Buf;
  int i = 0;
  int CursorP;
//----------------------------Printing Array and Size-----------------------
   printf("\n\nName\t\tSize\n");
   for( ; i < 25; i++, printf("*"));
   printf("\n");
   rewind(pFile);
   while(!feof(pFile))
    {
       while(*Buf == ' ') Buf++;
        //if(strstr(Buf, "/*End Of Definition*/"))
          // break;
         while((CursorP = SearchSymb(Buf, '[', 0)) != 0)
              {
            Buf += CursorP;
            while(*Buf != ' ' && *Buf != ','
                      && *Buf != '*' && *Buf != '\t')
                  Buf --;
                  Buf ++;
            while(*Buf != ';' && *Buf != ',' && *Buf != '\n'
                      && *Buf != ')' && *Buf != ' ')
                 {
                while(*Buf != '[')
                     {
                      printf("%c", *Buf);
                      Buf++;
                     }
                printf("\t\t");
                Buf++;
                while(*Buf != ' ' && *Buf != ',' && *Buf != ';')
                     {
                    if(*Buf == ']')
                      {
                        Buf++;
                        continue;
                      }
                    if(*Buf == '[')
                       printf(" x ");
                    else
                       printf("%c", *Buf);
                    Buf++;
                       }
                 }
        printf("\n");
        Buf++;
       }
   fgets(Buf, 100, pFile);
   }
fclose(pFile);
}
//-------------------------------------------------------------------------
void Look_for_Int(FILE *pFile)
{
  char *Buf;
  int CursorP;

  rewind(pFile);
  while(!feof(pFile))
       {
       while(*Buf == ' ') Buf++;
          {
         while((CursorP = SearchSymb(Buf, 'i', 0)) != 0)
              {
            Buf += CursorP;
            while(*Buf != ' ' && *Buf != ','
                      && *Buf != '*' && *Buf != '\t')
                  Buf --;
                  Buf ++;
            while(*Buf != ';' && *Buf != ',' && *Buf != '\n'
                      && *Buf != ')' && *Buf != ' ')
                while(*Buf != ';')
                     {
                      printf("%c", *Buf);
                      Buf++;
                     }
       printf("\t\t");
       Buf++;
       printf("2 byte");
       printf("\n");
       Buf++;
       fgets(Buf, 100, pFile);
       fclose(pFile);
              }
          }
       }
}

//========================================================================
int SearchSymb(char *Str, char c, int y)
{
    char *tmpStr;
    int Pos = +y;
    strcpy(tmpStr, Str);
    tmpStr+=y;
    while(*tmpStr != ';' && *tmpStr != '\n')
      {
         if(*tmpStr == c)
            return Pos;
         Pos++;
         tmpStr++;
      }
return 0;
}
//=============Find a memory that we need===================================
/*int Size_of_Memory(char *Str)
{

 return 0;
}                              */

