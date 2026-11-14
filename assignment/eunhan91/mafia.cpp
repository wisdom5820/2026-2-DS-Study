/*
1. 사용한 AI: GPT-6 Astra(High)
2. 과제에 활용한 부분: identifier의 작성에 도움 받았다.
3. 어떤 도움이 필요했는지: 어떤 역할을 하는 것들인지를 이름만으로 알 수 있게 
적절한 identifier 선택에 도움 받았다.
4. AI 제시 코드에서 추가, 개선한 부분: 해당사항 없음
*/
#include <bits/stdc++.h>

using namespace std;

#define Get_or_create_member(roster, name) ((roster).contains((name)) ? (roster)[(name)] : ((roster)[(name)]=new node((name))))

struct node{
    string name;
    node * boss=nullptr;
    vector<node *> subordinates;

    public:
        node(string member_name){
            name=member_name;
        }

        int subordinate_count();
        int depth();
};//end of node

using node_map=map<string, node *>;


int node::subordinate_count(){
    int total=0;

    for(auto subordinate:subordinates)
        total += subordinate->subordinate_count()+1;
    
    return total;
}//end of node::subordinate_count

int node::depth(){
    int current_depth=0;
    node * current_node=this;

    while(true){
        if(current_node->boss==nullptr) break; //root

        current_depth++;
        current_node=current_node->boss;
    }//end of loop

    return current_depth;
}//end of node::depth


void build_organization(node_map & roster){
    int n_people;

    cin>>n_people;

    for(int i=0; i<n_people-1; ++i){
        string subordinate, boss;

        cin>>subordinate>>boss;

        node * subordinate_node=Get_or_create_member(roster, subordinate);
        node * boss_node=Get_or_create_member(roster, boss);

        boss_node->subordinates.push_back(subordinate_node);
        subordinate_node->boss=boss_node;
    }//end of loop
}//end of build_organization

bool compare_rank(node * lhs, node * rhs){
    int count_1=lhs->subordinate_count();
    int count_2=rhs->subordinate_count();

    if(count_1 != count_2) return count_1 > count_2;

    int depth_1=lhs->depth();
    int depth_2=rhs->depth();

    if(depth_1 != depth_2) return depth_1 < depth_2;

    return lhs->name < rhs->name;
}//end of compare_rank

vector<string> calculate_rankings(node_map& roster){
    vector<string> ranked_names;

    for(const auto &[name,_]:roster)
        ranked_names.push_back(name);

    ranges::sort(ranked_names, compare_rank, [&](string name) {return roster.at(name);});//[]사용 불가

    return ranked_names;
}//end of calculate_rankings

void print_and_clear(vector<string>& ranked_names, node_map & roster){
    for(auto & name:ranked_names)
        cout<<name<<'\n';

    for(auto &[_, member]: roster)
        delete member;

    roster.clear();
}//end of print_and_clear



int main(){
    node_map mafia_roster;

    build_organization(mafia_roster);//input()

    auto ranked_names = calculate_rankings(mafia_roster);//compute()
    
    print_and_clear(ranked_names, mafia_roster);//output()
}//end of main