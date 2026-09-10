/*
1. 사용한 AI: Gemini 3 Flash(High)
2. 과제에 활용한 부분: 33행~44행(최대 입찰가 찾기)
3. 어떤 도움이 필요했는지: 내림차순으로 정리된 struct의 중복되지 않는 최대값을 찾는 logic 작성에 도움을 받았다.
4. AI 제시 코드에서 추가, 개선한 부분: 41행에서 break를 사용하여 무의미한 비교를 반복하는 로직을 return 0;을 이용하여 만족하는 최선의 값을 찾았다면 바로 그 값을 출력하고 프로그램을 종료하도록 개선하였다. 루프 하단에 존재하던 i=j를 for문의 증감식에 넣어 사용 토큰 개수를 축약하였다.
*/
#include <bits/stdc++.h>

using namespace std;

struct bidding
{
    string name;
    int price;

    bool operator<(bidding B){
        return price > B.price;
    }
};

int main(){
    int num, i, j;
    cin>>num;

    bidding b[num];


    for(i=0;i<num; i++)
        cin >> b[i].name >> b[i].price;

    sort(b, b+num);

    for (i = 0; i < num; i=j) {
        j = i;

        while(j < num && b[i].price==b[j].price)
            j++;

        if(j-i==1){
            cout<<b[i].name;
            return 0;
        }

    }

    cout<<"NONE";
}