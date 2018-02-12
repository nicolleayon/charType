/*
* Nicolle Ayon C.
* nayoncam
* Classifies the characters on each line of the input file into the following categories:
* alphabetic (upper or lower case), numeric(digits 0-9), punctuation, 
* and white space (space, tab, or newline).
* charType.c
* =============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// void allocateMemory(char* s, char* a, char* d, char* p, char* w);
void extract_chars(char* s, char* a, char* d, char* p, char* w);

int main(int argc, char* argv[]){
   FILE* in;  /* file handle for input */
   FILE* out; /* file handle for output */

   char line[256]; /* char array to store words from input file */
   char *a, *d, *p, *w;

   /* check command line for correct number of arguments */
   if( argc != 3 ){ // arg0 = name of program, arg1 = inputfile, arg2 = output file
      printf("Usage: %s <input file> <output file>\n", argv[0]);
      exit(EXIT_FAILURE);
   }

   /* open input file for reading */
   in = fopen(argv[1], "r");
   if( in == NULL ){
      printf("Unable to read from file %s\n", argv[1]);
      exit(EXIT_FAILURE);
   }

   /* open output file for writing */
   out = fopen(argv[2], "w");
   if( out == NULL ){
      printf("Unable to write to file %s\n", argv[2]);
      exit(EXIT_FAILURE);
   }

   int counter = 1; 
   while(fgets(line, 256, in) != NULL){
      
      int slength = strlen(line); //create a variable to hold length of char array

      int count = 1; //start at one bc last thing in array will be a null (so save space for that)
      for(int i = 0; i < slength; i++){
         if(isalpha((int)line[i])){
            count++; } }
      a = calloc(count, sizeof(int)); //ALPHABETIC

      count = 1;
      for(int i = 0; i < slength; i++){
         if(isdigit((int)line[i])){
            count++; } }
      d = calloc(count, sizeof(int)); //NUMERIC
      
      
      count = 1; 
      for(int i = 0; i < slength; i++){
         if(ispunct((int)line[i])){
         count++; } }
      p = calloc(count, sizeof(int)); //PUNCTUATION
      

      count = 1; 
      for(int i = 0; i < slength; i++){
         if(isspace((int)line[i])){
            count++; } }
      w = calloc(count, sizeof(int)); //WHITE SPACE

      // allocateMemory(line, a, d, p, w);
      extract_chars(line, a, d, p, w);
      int alength = strlen(a);
      a[alength] = '\0'; // "output arrays will be terminated by the null character '\0', making them into valid C strings"
      int dlength = strlen(d);
      d[dlength] = '\0';
      int plength = strlen(p);
      p[plength] = '\0';
      int wlength = strlen(w);
      w[wlength] = '\0';

      fprintf(out, "line %d contains:\n", counter);
      if(alength == 1)
         fprintf(out, "%d alphabetic character: %s\n", alength, a); //singular "character"
      else
         fprintf(out, "%d alphabetic characters: %s\n", alength, a); //character's' (PLURAL)
      if(dlength == 1)
         fprintf(out, "%d numeric character: %s\n", dlength, d);
      else
         fprintf(out, "%d numeric characters: %s\n", dlength, d);
      if(plength == 1)
         fprintf(out, "%d punctuation character: %s\n", plength, p);
      else
         fprintf(out, "%d punctuation characters: %s\n", plength, p);
      if(wlength == 1)
         fprintf(out, "%d whitespace character: %s\n", wlength, w);
      else
         fprintf(out, "%d whitespace characters: %s\n", wlength, w);
      counter++;

      //de-allocates using free() and sets all pointers to null to avoid memory leaks - checked using valgrind
      free(a);
      free(d);
      free(p);
      free(w);
      a = NULL;
      d = NULL;
      p = NULL;
      w = NULL;
   }

   

   /* close input and output files */
   fclose(in);
   fclose(out);
   return(EXIT_SUCCESS);

   }

void extract_chars(char* s, char* a, char* d, char* p, char* w){ //STORE APPROPRIATE CHAR IN APPROPRIATE ARRAYS

   int slength = strlen(s); //creater a variable to hold length of char array
   
   //stores all alpha char in array a
   int count = 0; 
   for(int i = 0; i < slength; i++){    
      if(isalpha((int)s[i])){
         a[count] = s[i];
         count++;
      }
   }

   //stores all numeric char in array d
   count = 0; 
   for(int i = 0; i < slength; i++){
      if(isdigit((int)s[i])){
         d[count] = s[i];
         count++;
      }
   }

   //stores all punctuation char in array p
   count = 0; 
   for(int i = 0; i < slength; i++){
      if(ispunct((int)s[i])){
         p[count] = s[i];
         count++;
      }
   }

   //stores all whitespace char in array w
   count = 0; 
   for(int i = 0; i < slength; i++){
      if(isspace((int)s[i])){
         w[count] = s[i];
         count++;
      }
   }
} 



