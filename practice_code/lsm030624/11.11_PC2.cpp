#include <bits/stdc++.h>
using namespace std;

struct mycmp{ // 내가 정의한 우선순위 함수
    bool operator()( string t, string u){
        cout << "\n" << t.back() << " vs. " << u.back() ;
        return t.back() < u.back();  // 마지막 문자로 정렬
    }
};


int main(){ // priority_queue
	string words[10]= {"Summer", "Time", "Kill","BeerBox", "C++",
	                   "YouTube", "막걸리", "010-5678","뽕","GoodBoy" };

	priority_queue< string , vector<string>,  mycmp > Strpq( words, words+9);


	while(!Strpq.empty()){
		cout <<  "\n " << Strpq.top();
		Strpq.pop();
	}
	return 0;
} // end of main()

// 출력 결과는 영어 -> 숫자 -> 특수문자(+) -> 한글
// 이유는 영어, 숫자, 특수문자는 ASCII 코드로 변환하여 계산하는 반면, 한글은 바이트 변환 후 마지막 1바이트만 부호 있는 8비트 char형으로써 계산하므로 음수가 될 수 있음. 
