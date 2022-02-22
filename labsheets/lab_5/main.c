#include "insertionSort.h"
#include <sys/time.h>

double calculateTimeDifference(struct timeval t1,struct timeval t2);

int main(){
   // File to write results 
   FILE* results = fopen("results.txt","w");

   // Time measurement variables
   struct timeval t1, t2;
   double elapsedTime;

   // Configuring filenames and number of entries in the corresponding file
   char *files[5] = {
      "10",
      "100",
      "1000",
      "10000",
      "100000"
   };
   int num_entries[5] = {
      10,
      100,
      1000,
      10000,
      100000
   };

   for(int i = 0; i < 5; i++) {
      fprintf(results ,"For %d inputs:\n", num_entries[i]);
      
      // Calculating time to read
      gettimeofday(&t1, NULL);
      CreditCard  *cards = ExtractCreditCardInformationFromFile(files[i]);
      gettimeofday(&t2, NULL);
      fprintf(results, "Time taken to read data from file: %lf ms\n", calculateTimeDifference(t1, t2));

      // Calculating time to sort the array
      gettimeofday(&t1, NULL);
      int bottom_of_stack; // For calculating stack size
      InsertionSort(cards, num_entries[i]);
      gettimeofday(&t2, NULL);
      fprintf(results, "Time taken to sort data from file: %lf ms\n", calculateTimeDifference(t1, t2));
      fprintf(results, "Stack space used to sort data from file: %llu\n", (unsigned long long)&bottom_of_stack-(unsigned long long)top_of_stack);
      free(cards);
   }
   return 0; 
}

double calculateTimeDifference(struct timeval t1,struct timeval t2) {
   // Calculating elapsed time
   double elapsedTime = ((double)(t2.tv_sec - t1.tv_sec))*1000;
   elapsedTime += ((double)(t2.tv_usec - t1.tv_usec))/1000;
   return elapsedTime;
}
