//
//  RNASequenceFile.hpp
//  bwt
//
//  Created by Manuel Magana on 7/5/23.
//

#ifndef RNASequenceFile_hpp
#define RNASequenceFile_hpp


#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include "RNAseq.hpp"

using namespace std;
class RNASequenceFile{
    public:
        int BWTcompress();
        int BWTdecompress();
        int getNumberOfSequence();
        void printCompression();
        void print();
        RNASequenceFile saveCompression(const char outfile[]);
        RNASequenceFile(ifstream * input);
        void writeCompressedfile(const char * fileoutput);
        
    private:
        int numberOfSequences;
        vector<RNAseq> *dataMatrix = nullptr;
        vector<RNAseq> *compressedDataMatrix = nullptr;
        std::ifstream *fileInput;
        std::ifstream *fileOutPut;
};


#endif /* RNASequenceFile_hpp */
