#include <Rcpp.h>
#include <stdlib.h>
using namespace Rcpp;
using namespace std;
 
// define pairs
typedef pair<double,int> pairType;
 
//define method for sorting
struct comparison{
   inline bool operator() (const pairType& a, const pairType& b){
       return a.first<b.first;
   }
};
 
// function for sorting vector
NumericVector indexSort(NumericVector p)
{
    // sorting  a vector in ascending order and return 
    // a vector of the index of the sorted vector 
    int i, size = p.size();
	NumericVector resultVec(size);
	vector<pairType> newVec(size);
 
	//sorting
	for (i = 0; i < size; i++){
		newVec[i] = (make_pair(p[i],i));
	}
	sort(newVec.begin(),newVec.end(),comparison());
 
	//pushing back index vector
	for (i = 0; i < size; i ++){
		resultVec[i] = newVec[i].second;
	}
 
	return(resultVec);
}
 
// using a vector of p-values and false discovery rate threshold to 
// label all the significant results
// where 1 is significant,  is insignificant
// [[Rcpp::export]]
NumericVector FDRcontrol(NumericVector p, double alpha)
{
    float threshold1, threshold2;
    int i = 0, size = p.size();
    
	NumericVector passed(size);
	NumericVector index = indexSort(p);
 
    while ( i < size){
        threshold1 = alpha * (i+1) / size;
        threshold2 = alpha * (i+2) / size;
        if (threshold1 > p[index[i]]){
            if (threshold2 < p[index[i+1]]){
                for (int j = 0; j <= i; j++){
                    passed[index[j]] = 1;
                }
            }
        } 
        i++;
    }
    return(passed);
}
