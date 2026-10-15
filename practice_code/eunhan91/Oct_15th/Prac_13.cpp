#include <iostream>
#include <fstream>

int main(){
    int x;

    std::ifstream myfile("Prac_13.txt");

    while(!myfile.eof()){
        myfile>>x;
        std::cout<<x<<'\n';
    } //line break 때문에 EOF를 감지하지 못했다.

    /*
    fstream의 file 형태에 따라 UB가 발생할 수 있기 때문에 file.eof를 while의 종료조건으로 쓰기는 적절하지 않다.
    reference:iostream-120 - cin for file read.cpp
    */
}