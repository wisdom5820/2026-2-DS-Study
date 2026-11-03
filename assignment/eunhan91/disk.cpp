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

        void rebuilds_free_space();//end of rebuilds_free_space()

        void what_happen(string word){
            cerr<<"\n>Serious Error happened ";
            exit(1);
        }

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
        auto free_space_vec=type_table_[" "];

        for(auto pos=free_space_vec.begin(); pos!=free_space_vec.end(); ++pos){
            if(fsize==0) break;

            auto it=*pos;
            int chunk=min(fsize, it->file_size);

            it->file_name=fname;
            it->file_size=chunk;

            type_table_[fname].push_back(it);

            fsize-=chunk;
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

    rebuilds_free_space();
}//end of delete_file()

void T_DISK::compact_file (){
    
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
    }

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
            default: disk.what_happen (cmd); //error
        }//end of switch statement
    }//end of loop
}//end of main()