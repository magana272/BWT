//
//  RNAseq.cpp
//  bwt
//
//  Created by Manuel Magana on 7/5/23.
//

#include "RNAseq.hpp"

RNAseq::RNAseq(string seq){
     sequence = seq;
     
}
void RNAseq::print(){
    cout << this->sequence << endl;
}
string RNAseq::BWTcompress(){
    string bwtResult = "";
    vector<string> RotateMatrix =  vector<string>();
    string temp;
    temp = sequence;
    temp.push_back('$');
    int seqLength = temp.length()-1;
    char tempchar = temp.at(seqLength);
    temp.insert(0,&tempchar,1);
    temp.pop_back();
    RotateMatrix.push_back(temp);

    //  Rotate
    for(int i =0 ; i <seqLength; i++)
    {
        tempchar = temp.back();
        temp = temp.insert(0,&tempchar,1);
        temp.pop_back();
        RotateMatrix.push_back(temp);
    }
    
    BWTcompressSortHelper(&RotateMatrix);
    int matSize = RotateMatrix.size();
    for(int i = 0; i < RotateMatrix.size(); i++)
    {
        bwtResult.push_back(RotateMatrix.at(i).back());
        }
    
    cout << "BWT:" << bwtResult << endl;
    return bwtResult;

}
void RNAseq::BWTcompressSortHelper(vector<string> *RotateMatrix ){
    sort(RotateMatrix->begin(),RotateMatrix->end());

}
string RNAseq::getSequence(){
    return sequence;
}
string RNAseq::BWTdecompress(){
    return "IMPLEMENT ME";
}
void RNAseq::printMatrix(const vector<string>& mat){
    int length = mat.size();
    for(int i  = 0; i < length; i++){
         cout << mat.at(i)<< endl ;
    }
}
