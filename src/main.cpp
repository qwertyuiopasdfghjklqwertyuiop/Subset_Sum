#include <iostream>
#include <vector>
#include <cmath>

#include "./Subset.h"



int main(){
   srand(time(NULL));
   int target = rand() % 151;

   // Create original vector
   std::vector<int> *orig = new std::vector<int>;

   for(int k = 0; k < 10; k++)
   {
      orig->push_back(rand() % 30);
   }

   // Calculate subset sub and save value to var indices
   std::vector<int> indices( Subset_Sum(orig, target) );

   // print indices and values then print sum and target afterwards
   int sum = 0;
   for(int k = 0; k < indices.size(); k++)
   {
      std::cout << indices[k] << ": " << (*orig)[ indices[k] ] << std::endl;
      sum += (*orig)[indices[k]];
   }

   std::cout << "Sum: " << sum << std::endl;
   std::cout << "Target: " << target << std::endl;

   delete orig;
   return 0;
}


