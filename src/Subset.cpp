#include "./Subset.h"

Subset::Subset(std::vector<int> * orig)
{
   this->orig = orig;
   this->sum = 0;
}

Subset::Subset(Subset const &orig)
{
   this->orig = orig.orig;
   this->sum = orig.sum;
   this->indices = orig.indices;
}

void Subset::calcSum()
{
   /* goes through the stored indices in the original vector
    and adds values of the location to sum to find the total */
   int sum = 0;
   for(int k = 0; k < this->indices.size(); k++)
   {
      sum += (*this->orig)[ this->indices[k] ];
   }

   this->sum = sum;
}

bool Subset::addIndice(int num)
{
   /* check if indice actually exists in orig vector
    and if it does add it to sum and indices vector */
   if(num < 0 || num >= (*this->orig).size())
      return false;

   this->indices.push_back(num);
   sum += (*this->orig)[num];
   return true;
}

//=========================================================================
//=================== CLASS DEFINITION END ================================
//=========================================================================

std::vector<int> Subset_Sum(std::vector<int> *orig, int target)
{
   /* make sure at least one number from orig fits within target
      and if it doesn't then you return and empty vector as the solution */
   for(int k = 0; k < orig->size(); k++)
   {
      if((*orig)[k] <= target)
         break;
      else if(k == (*orig).size() - 1)
         return std::vector<int>();
   }

   /* if the sum of all the numbers is less than or equal to the target
      return the original vector as the solution */
   int sum = 0;
   for(int k = 0; k < orig->size(); k++)
      sum += (*orig)[k];

   if(sum <= target)
   {
      std::vector<int> allIndices;
      allIndices.resize(orig->size());
      for(int k = 0; k < orig->size(); k++)
         allIndices[k] = k;
      return allIndices;
   }

   /* real subset sum stuff: loop over every number in the original vector
      and add that to already existing subsets that we create */
   std::vector<Subset> sets;
   sets.push_back(Subset(orig)); // empty Subset pushed to vector
   for(int k = 0; k < orig->size(); k++)  // loop over every int in original
   {
      int numOfSets = sets.size();
      for(int i = 0; i < numOfSets; i++)  // loop over every existing subset
      {
         if(sets[i].getSum() + (*orig)[k] <= target) // if it doesn't go over target create a new subset
         {
            Subset temp = Subset(sets[i]);
            temp.addIndice(k);

            if(temp.getSum() == target)   // return temp if temp is perfect
               return temp.getIndices();

            sets.push_back(temp);   // not perfect but within target so add it to sets
         }
      }
   }
   floatLargestSubsetToTop(sets);   // float larget Subset to end
   return sets[sets.size() -1].getIndices();     // return last (now largest) subset
}


void floatLargestSubsetToTop(std::vector<Subset> & subsetVec)
{
   for(int k = 0; k < subsetVec.size() - 1; k++)
   {
      if(subsetVec[k].getSum() > subsetVec[k+1].getSum())
      {
         Subset temp(subsetVec[k]);
         subsetVec[k] = subsetVec[k+1];
         subsetVec[k+1] = temp;
      }
   }
}
