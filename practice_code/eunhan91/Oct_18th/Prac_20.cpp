#include <iostream>
#include <vector>

int main(){
    std::vector<int> v1{1,2,3,4,5}, v2;

    //std::copy(v1.begin(), v1.end(), v2.begin());//의도한 연산을 수행할 수 없다 v2는 빈벡터이기 때문

    std::copy(v1.begin(), v1.end(), std::back_inserter(v2));

    for(const auto & w:v2)
        std::cout<<w<<" ";
}