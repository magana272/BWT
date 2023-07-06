//
//  RNAseq.hpp
//  bwt
//
//  Created by Manuel Magana on 7/5/23.
//

#ifndef RNAseq_hpp
#define RNAseq_hpp

#ifndef RNASEQ_h
#define RNASEQ_h
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class RNAseq
{
private:
    string sequence;
    void BWTcompressSortHelper(vector<string> *RotateMatrix);
    
public:
    RNAseq();
    RNAseq(string sequence);
    void print();
    void printMatrix(const vector<string>& mat);
    string BWTcompress();
    string BWTdecompress();
    string getSequence();
};
#endif

#endif /* RNAseq_hpp */
