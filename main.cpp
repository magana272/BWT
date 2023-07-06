//
//  main.cpp
//  bwt
//
//  Created by Manuel Magana on 7/5/23.
//

#include <iostream>
#include <fstream>
#include <string>
#include "RNASequenceFile.hpp"
#include "RNAseq.hpp"


using namespace std;
const char BWT_COMPRESSED_FILE_OUT[] = "./BWTcompress.txt";
const char BWT_DECOMPRESSED_FILE_OUT[] = "./DEcompress.txt";
int main(){
    ifstream myfile;
    string rnaSEQFile;
    bool fileCheck;
    std::string currentSeq;
    std::cout << "Please Provide me with the the file the contains:" << std::endl;
    std::cout << "Default output file: outfile.txt" << std::endl;
    //std::cin  >> rnaSEQFile;
    rnaSEQFile = "/Users/magana272/Desktop/compBio/BWT/test.txt";
    myfile.open(rnaSEQFile);
    fileCheck = myfile.is_open();
    if(fileCheck){
        RNASequenceFile seqfile = RNASequenceFile(&myfile);
        seqfile.BWTcompress();
        seqfile.writeCompressedfile("/Users/magana272/Desktop/compBio/BWT/outfile.txt");
        
    }
    else{
        std::cout<< "File does not exist";
    }
}
