/*
1. 사용한 AI: GPT-6 Astra(High)
2. 과제에 활용한 부분: identifier의 작성, X 매크로 작성, 138행 예외처리
3. 어떤 도움이 필요했는지: disk.cpp 작성 때 교수님께 token 처리 방법을 배웠습니다. 제가 생각하지 못한 방법이라, 이후 여러가지 토큰 처리 방법에 대하여 고민하는 시간을 가졌습니다. 그때
linux 커널을 작성하는 코딩 고수들의 tech를 알게 됐습니다. enum을 통한 구현이었는데, 위와 같은 방법을 사용해보고 싶었습니다. 다만, 문제의 조건이 string입력이 제시되어 있어, 
kernal의 switch 사용을 그대로 따르지는 못했고, 적절히 token ID를 얻는 방법을 고안해내지 못해 AI에게 string에 대한 적절한 ID를 구하는 방법이 무엇이 있을지 질문하였습니다.
덕분에 X 매크로라는 테크닉을 알게되어 구현에 사용합니다. 이외에는 적절한 identifeir작성에 도움을 받았고, 고려하지 못한 edge case를 예외처리하였습니다.
4. AI 제시 코드에서 추가, 개선한 부분: 해당사항 없음
5. 참고한 외부 코드:
리눅스 커널에서 enum으로 재부팅 방식을 구분하고, 해당 값을 switch문에서 사용하는 구조를 참고하였습니다. 이를 제 코드의 명령 구분에 적용하고자 하였습니다. 

참고한 파일:
- https://github.com/torvalds/linux/blob/master/include/linux/reboot.h
- https://github.com/torvalds/linux/blob/master/arch/x86/kernel/reboot.c

문자열 테이블과 enum의 대응 관계를 한곳에서 관리하기 위한 X 매크로는 위 코드에서 가져온 것이 아니라, AI의 설명을 통해 문법과 동작을 이해하고 적용하였습니다.
*/
#include <bits/stdc++.h>

using namespace std;



#define FOR_EACH_COMMAND(X) \
        X(INSERT, "+")     \
        X(ERASE, "-")   \
        X(DEPTH, "depth")   \
        X(LEAF, "leaf")     \
        X(QUIT, "quit") 

        // 명령 목록을 한곳에서 관리하고, 이 목록으로 enum과 문자열 대응 테이블을 생성한다.
        // 예를 들어 X(MUL, "MUL")을 추가하면 양쪽에 함께 반영되므로,
        // enum과 테이블을 따로 수정하다가 대응 관계가 어긋나는 것을 방지할 수 있다.
        
#define MAKE_COMMAND_ENUM(command_id, command_text) command_id, //name이 식별자 text가 string

enum command{
    INVALID,
    FOR_EACH_COMMAND(MAKE_COMMAND_ENUM)
};

#undef MAKE_COMMAND_ENUM

#define MAKE_COMMAND_ENTRY(command_id, command_text) {command_id, command_text}, //위의 table을 통해 제시하셨던 방법에서의 vector와 enum을 동시에 관리

vector<pair<command, string>> COMMAND_TABLE{
    FOR_EACH_COMMAND(MAKE_COMMAND_ENTRY)
};

#undef MAKE_COMMAND_ENTRY




struct node
{
    string key;
    node * parent=nullptr;
    node * left=nullptr;
    node * right=nullptr;

    public:
        node(string initial_key, node * parent_node=nullptr)
        : key (initial_key), 
          parent(parent_node){}
};

class binary_tree_for_searching{
    node * root=nullptr;
    map<string, node *> nodes_by_key;

    int compute_depth(node * current_node){
        int current_depth=1;

        while(current_node->parent!=nullptr){
            current_node=current_node->parent;
            current_depth++;
        }

        return current_depth;
    }

    public:
        void insert              (){
            string key;

            cin>>key;

            if(nodes_by_key.contains(key)) return;

            node * current_node=root;

            for(;;){
                if(root==nullptr){
                    nodes_by_key[key]=root=new node(key);
                    return;
                }

                node * & child_link= current_node->key > key ? current_node->left : current_node->right;

                if(child_link==nullptr){
                    child_link=nodes_by_key[key]=new node(key, current_node);
                    return;
                }

                current_node=child_link;
            }
        }

        void erase               (){
        string key;

        cin>>key;

        if(!nodes_by_key.contains(key)) return;

        node * target_node=nodes_by_key[key], * replacement_node;
        while(target_node->left!=nullptr || target_node->right!=nullptr){
            if(target_node->left != nullptr){
                replacement_node=target_node->left;

                while(replacement_node->right != nullptr)
                    replacement_node=replacement_node->right;
            }

            else{
                replacement_node=target_node->right;

                while(replacement_node->left != nullptr)
                    replacement_node=replacement_node->left;
            }

            target_node->key=replacement_node->key;
            nodes_by_key[target_node->key]=target_node;
            target_node=replacement_node;
        }

        if(target_node->parent==nullptr) root=nullptr;

        else{
            if(target_node->parent->left==target_node) target_node->parent->left=nullptr;
            else                                       target_node->parent->right=nullptr;
        }

        nodes_by_key.erase(key);

        delete target_node;
    }

        void print_keys_at_depth (){
            int target_depth;
            bool has_nodes_at_target_depth=false;

            cin>>target_depth;

            for(const auto &[key, current_node]:nodes_by_key){
                if(target_depth==compute_depth(current_node)){
                    cout<<key<<" ";
                    has_nodes_at_target_depth=true;
                }
            }

            if(!has_nodes_at_target_depth) cout<<"NO";

            cout<<endl;
        }

        void print_leaf_keys     (){
            for(const auto & [key, current_node]:nodes_by_key)
                if(current_node->left ==nullptr && 
                   current_node->right==nullptr) cout<<key<<" ";
            cout<<endl;
        }

        ~binary_tree_for_searching(){
            for(auto & [_, current_node]:nodes_by_key)
                delete current_node;
        }
}search_tree;


command parse_command(string input_command_text){
    for(const auto &[command_id, command_text]:COMMAND_TABLE) 
        if(command_text==input_command_text) return command_id;

    return INVALID;
};

void report_invalid_command_and_exit(){
    cout<<"You enter invalid command"<<endl;
    exit(1);
}



void run_command_loop(){
    for(;;){
        string input_command_text;

        cin>>input_command_text;

        command parsed_command=parse_command(input_command_text);

        
        switch(parsed_command){
            case INSERT: search_tree.insert             (); break;

            case ERASE:  search_tree.erase              (); break;

            case DEPTH:  search_tree.print_keys_at_depth(); break;
            
            case LEAF:   search_tree.print_leaf_keys    (); break;

            case QUIT:   return;       
            
            default:     report_invalid_command_and_exit();
        }
    }
}


int main(){
    run_command_loop();
}