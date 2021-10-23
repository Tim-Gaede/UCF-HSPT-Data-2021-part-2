
#include <stdio.h>
#include <string.h>


int main()
{
   char   line[10001];
   int    numStrings;

   // Figure out how many strings to process
   fgets(line, sizeof(line), stdin);
   sscanf(line, "%d", &numStrings);

   // Loop over the strings
   for (int i = 0; i < numStrings; i++)
   {
      // Get this line
      fgets(line, sizeof(line), stdin);

      // As long as we get a space or end of line, grab a substring of *'s
      // and output letter
      char * ch = strtok(line, " \r\n");
      while (ch != NULL)
      {
         // Print letter based on length
         printf("%c", strlen(ch) + 'A' - 1);

         // Get next substring of *'s
         ch = strtok(NULL, " \r\n");
      }

      // All done with this line, so newline!
      printf("\n");
   }

   // Always return 0 for HSPT
   return 0;
}

