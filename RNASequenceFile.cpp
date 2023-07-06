//
//  RNASequenceFile.cpp
//  bwt
//
//  Created by Manuel Magana on 7/5/23.
//

#include "RNASequenceFile.hpp"
#include "RNAseq.hpp"
RNASequenceFile::RNASequenceFile(ifstream *input){
    fileInput = input;
    string currseq;
    dataMatrix = new vector<RNAseq>();
    compressedDataMatrix = new vector<RNAseq>();
    while(fileInput->good()){
        getline(*fileInput,currseq,'\n');
        RNAseq currseqINIT = RNAseq(currseq);
        dataMatrix->push_back(currseqINIT);
    }
}
int RNASequenceFile::BWTcompress(){
    unsigned int length = static_cast<unsigned int>(dataMatrix->size());
    for(int i  = 0 ; i < length; i++){
        RNAseq currcompress = RNAseq(dataMatrix->at(i).BWTcompress());
        cout << "just compressed" << endl;
        cout << currcompress.getSequence() << endl;
        compressedDataMatrix->push_back(currcompress);
    }
    return 0;

}
int  RNASequenceFile::BWTdecompress(){
    return  -1;
}
int  RNASequenceFile::getNumberOfSequence(){
    return this->numberOfSequences;

}
void RNASequenceFile::print(){
    unsigned int numSeq = static_cast<unsigned int>(dataMatrix->size());
    for(int i = 0; i < numSeq; i++){
        dataMatrix->at(i).print();
    }
}
void RNASequenceFile::printCompression(){
    unsigned int numSeq = static_cast<unsigned int>( compressedDataMatrix->size());
    for(int i = 0; i < numSeq; i++){
        compressedDataMatrix->at(i).print();
    }
}
void RNASequenceFile::writeCompressedfile(const char * fileoutput){
    ofstream MyFile(fileoutput);
    unsigned int length = static_cast<unsigned int>(compressedDataMatrix->size());
    
    for(int i  = 0 ; i < length; i++){
        string compressed =  compressedDataMatrix->at(i).getSequence();
        char * cstr = new char [compressed.length()+1];
        strcpy(cstr,compressed.c_str());
        MyFile << cstr <<endl;
        delete[] cstr;
    }
    
    MyFile.close();
}
