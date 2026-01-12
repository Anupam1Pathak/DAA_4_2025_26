#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;


void complexRec(int n) {
int count = 0;

   if (n <= 2) {
       return;
   }


   int p = n;
   while (p > 0) {
       vector<int> temp(n);
       for (int i = 0; i < n; i++) {
           temp[i] = i ^ p;
           
           count++;
           
       }
       p >>= 1;
   }


   vector<int> small(n);
   for (int i = 0; i < n; i++) {
       small[i] = i * i;
       
       count++;
   }


   if (n % 3 == 0) {
       reverse(small.begin(), small.end());
       count++;
   } else {
       reverse(small.begin(), small.end());
       count++;
   }


   complexRec(n / 2);
   complexRec(n / 2);
   complexRec(n / 2);
   
   cout<<"counts = "<<count;
  
   
   
}
int main() {
   int n = 3;
   auto start = high_resolution_clock::now();
complexRec(n);
   auto end = high_resolution_clock::now();
   
   
    auto duration = duration_cast<nanoseconds>(end-start);
   cout<<"\nDuration is "<<duration.count()<<"Nanoseconds";
   

}
