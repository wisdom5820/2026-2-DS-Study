#include <bits/stdc++.h>

class Point{
    private:
        int x,y;
    public:
    Point(int _x=0, int _y=0): x(_x), y(_y){};
    void out();
    friend Point operator-- (Point & p,int);
    //후위 감소 연산을 외부 함수로 구현
};

void Point::out(){
    std::cout<<this->x<<" "<<this->y;
}

Point operator-- (Point & p, int){
    Point temp(p.x, p.y);

    p.x--;
    p.y--;

    return temp;
}

int main(){
    Point pt;

    pt--.out();
    std::cout<<'\n';
    pt.out();
}