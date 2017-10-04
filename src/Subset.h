#ifndef _SUBSET_H
#define _SUBSET_H

#include <vector>

class Subset {
   //Members
private:
   std::vector<int> *orig;
   int sum;
   std::vector<int> indices;

   //Constructor
public:
   Subset(std::vector<int> * orig);
   Subset(Subset const &orig);

   //Methods
public:
   void calcSum();
   bool addIndice(int num);

   //Accessors
public:
   int getSum() { return this->sum; }
   std::vector<int> getIndices() { return this->indices; }

};



std::vector<int> Subset_Sum(std::vector<int> *orig, int target);
void floatLargestSubsetToTop(std::vector<Subset> & subsetVec);


#endif
