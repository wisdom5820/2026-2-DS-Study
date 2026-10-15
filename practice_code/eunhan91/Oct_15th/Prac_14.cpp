#include <iostream>
#include <iterator>
#include <fstream>
#include <ranges>
#include <string>
#include <sstream>

int main(){
    std::ostream_iterator<int> o_it(std::cout,"\n");

    std::fstream myfile;
    myfile.open("Prac_14.txt");//생성자 사용도 가능

    std::istream_iterator<int> i_it(std::cin);

    for(auto w:std::ranges::views::iota(0,6)){
        std::cout<<*i_it<<'\n'; //istream_iterator의 값을 갱신하면서 출력
        ++i_it;
    }

    for(auto w:std::ranges::views::iota(0,6)){
        *o_it=w;
        ++o_it; //아무것도 하지 않음
    }

    for(auto w:std::ranges::views::iota(0,6)){
        std::istringstream myinput(std::to_string(w));

        std::istream_iterator<int> i1_it(myinput);

        std::ostream_iterator<int> o1_it(std::cout, "\n");
        *o1_it=*i1_it;
        ++i1_it;
    }
}