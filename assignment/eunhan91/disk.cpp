/*
1. 사용한 AI: 6.0 Astra(High)
2. 과제에 활용한 부분: edge case에 대한 실수를 물어 전체적으로 활용하였습니다.
3. 어떤 도움이 필요했는지: 설계 당시에 고려하지 못했던 edge case들로 인한 예상치
못한 동작을 다루는데 도움이 필요하였습니다.
4. AI 제시 코드에서 추가, 개선한 부분:전체적으로 다루지 못한 상황이 무엇인지만 질문하고
직접적으로 코드 수정에 사용하지는 않았습니다.
*/

#include <bits/stdc++.h>
#include <ranges>

using namespace std;

struct FILE_TYPE{
    string file_name;
    int file_size;
}; //node

vector<string> KEY_WORD{"dummy", "write", "delete", "compact", "show"};

class T_DISK{
    list<FILE_TYPE> memory_; //리스트로 파일 이름과 크기만 관리(중복가능)
    unordered_map<string, vector<list<FILE_TYPE>::iterator>> type_table_; //map으로 key에 대한 MEMORY의 이터레이터를 따로 관리 벡터로서 파편화된 파일도 같이 관리한다.

    public:
        T_DISK(int mem_size){
            memory_.emplace_back      (" ",  mem_size );
            type_table_[" "].push_back(memory_.begin());
        }//end of allocator

        void rebuilds_free_space(){
            auto & free_space_vec=type_table_[" "];
            type_table_[" "].clear();

            for(auto it=memory_.begin(); it != memory_.end();)
                if(it->file_size==0) it=memory_.erase(it); //크기가 0인 " "노드 삭제 
                else                 ++it;

            for(auto it=memory_.begin(); it != memory_.end(); ++it){
                if(it->file_name !=" ") continue;

                while(next(it)!=memory_.end() && 
                      next(it)->file_name==" ") {
                    it->file_size+=next(it)->file_size;
                    memory_.erase(next(it));
                }

                free_space_vec.push_back(it);
            }//end of loop
        }//end of rebuilds_free_space

        void write_file   ();
        void delete_file  ();
        void compact_file ();
        void show_file    ();
};


void T_DISK::write_file   (){
    string fname;
    int fsize;

    cin>>fname>>fsize;

    if(!type_table_[fname].empty()){
        cout<<"error"<<'\n';
        return;
    }//exception handling 1: 이미 존재하는 원소의 재입력

    int free_space=accumulate(type_table_[" "].begin(), type_table_[" "].end(), 0, [](auto a, auto b){
        return a+b->file_size;
    });

    if(free_space < fsize){
        cout<<"diskfull"<<'\n';
        return;
    }//exception handling 2: 메모리 용량 부족

    auto itr=ranges::find_if(type_table_[" "],[&](auto x){
        return x->file_size >= fsize;
    });

    if(itr != type_table_[" "].end()){
        auto new_it=memory_.insert(*itr, FILE_TYPE{fname, fsize});

        type_table_[fname].push_back(new_it);

        (*itr)->file_size-=fsize;
    }

    else{
        for(auto it:type_table_[" "]){
            if(fsize==0) break;

            int chunk=min(fsize, it->file_size);

            type_table_[fname].push_back(memory_.insert(it,FILE_TYPE{fname, chunk}));

            fsize-=chunk;
            it->file_size-=chunk;
        }//end of loop
    }

    rebuilds_free_space();
}//end of write_file()

void T_DISK::delete_file  (){
    string fname;

    cin>>fname;

    if(type_table_[fname].empty()){
        cout<<"error"<<'\n';
        return;
    }//exception handling: 존재하지 않는 파일을 지울려고 시도하는 경우

    for(auto it:type_table_[fname])
        it->file_name=" ";

    type_table_[fname].clear();
    rebuilds_free_space();
}//end of delete_file()

void T_DISK::compact_file (){
    for(auto it:type_table_[" "])
        memory_.splice(memory_.end(), memory_, it);

    for(auto it=memory_.begin(); it!=memory_.end(); ++it)
        while(next(it)!=memory_.end() && 
              it->file_name == next(it)->file_name) {//end 검사를 먼저하는 것이 안전하다!
            it->file_size+=next(it)->file_size;

            type_table_[it->file_name].erase(ranges::find(type_table_[it->file_name], next(it)));
            memory_.erase                   (next(it));
        }//end of while loop
    

    rebuilds_free_space();
}//end of compact_file()

void T_DISK::show_file    (){
    string fname;

    cin>>fname;

    if(type_table_[fname].empty()){
        cout<<"error"<<'\n';
        return;
    }//exception handling: 없는 파일을 출력하려는 경우

    for(auto elem:type_table_[fname]){
        int location=0;

        for(auto it=memory_.begin(); it!=elem; ++it)
            location+=it->file_size;

        cout<<location<<" ";
    }//end of loop

    cout<<'\n';
}//end of show_file()


int get_tid(string mystirng){
    auto itr=ranges::find(KEY_WORD, mystirng);

    if(itr!=KEY_WORD.end()) return itr-KEY_WORD.begin();
    else                    return -1;
}

int main(){
    string cmd;
    int mem_size, idx;

    cin>>mem_size;

    T_DISK disk(mem_size);

    while(true){
        cin>>cmd;

        if(cmd=="end") break;

        idx=get_tid(cmd);
    
        switch (idx){
            case 1: disk.write_file   (); break; //write
            case 2: disk.delete_file  (); break; //delete
            case 3: disk.compact_file (); break; //compact
            case 4: disk.show_file    (); break; //show
            default: exit(1); //error
        }//end of switch statement
    }//end of loop
}//end of main()