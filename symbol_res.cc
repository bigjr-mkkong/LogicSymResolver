#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
#include "math.h"
#include "stdint.h"

using namespace std;

/*
&: and
|: or
>: direction
~: not
*/

struct symbol_t{
    char c;
    int val;
};

struct symbol_t symbol_table[1000];
int alloc_pt=30;
map<char,struct symbol_t*> char2addr; 

struct symbol_t* get_new_entry(char c, int val){
    alloc_pt++;
    symbol_table[alloc_pt]=(symbol_t){.c = c, .val = val};
    return &(symbol_table[alloc_pt]);
}

stack< struct symbol_t* > num;
stack<char> op;

vector<char> op_list={'&','|','>','~','(',')'};
map<char,int> priority{{'&',2},{'|',1},{'>',0},{'~',3}};
int num_of_sym=0;
uint64_t t_board;

int apply(int opra, int oprb, char opc){
    switch(opc){
        case '&':
            return opra & oprb;
        case '|':
            return opra | oprb;
        case '~':
            return !opra;
        case '>':
            return ((!oprb)|opra);
        default:
            printf("Wrong logic operand: %c, quit",opc);
            exit(0);
    }
}

int main(void){
    ios::sync_with_stdio(false);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(find(op_list.begin() ,op_list.end() ,s[i]) == op_list.end() &&\
             char2addr.find(s[i]) == char2addr.end()){
            symbol_table[num_of_sym] = (symbol_t){.c = s[i], .val = 0};
            char2addr.insert(pair<char, struct symbol_t*>(s[i],&symbol_table[num_of_sym]));
            num_of_sym++;
        }
    }

    t_board=pow(2,num_of_sym);
    int tmp=0;

    while(t_board--){
        for(int i=0;i<num_of_sym;i++){
            symbol_table[i].val=(int)((t_board|((uint64_t)1)<<i)==t_board);
            printf("%c:%d ",symbol_table[i].c,symbol_table[i].val);
        }
        
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                continue;
            }else if(s[i]=='('){
                op.push('(');
            }else if(s[i]>='A' && s[i]<='Z'){
                num.push(char2addr.find(s[i])->second);
            }else if(s[i] == ')'){
                while(!op.empty() && op.top() != '('){
                    if(op.top()=='~'){
                        int opd1 = num.top()->val;
                        num.pop();

                        char opc = op.top();
                        op.pop();
                        
                        num.push(get_new_entry(0, apply(opd1, 0, opc)));
                    }else{
                        int opd1 = num.top()->val;
                        num.pop();
                        int opd2 = num.top()->val;
                        num.pop();

                        char opc = op.top();
                        op.pop();
                        
                        num.push(get_new_entry(0, apply(opd1, opd2, opc)));
                    }
                }
                if(!op.empty())
                    op.pop();
            }else{
                while(!op.empty() && *priority.find(op.top()) >= *priority.find(s[i])){
                    if(op.top()=='~'){
                        int opd1 = num.top()->val;
                        num.pop();

                        char opc = op.top();
                        op.pop();
                        
                        num.push(get_new_entry(0, apply(opd1, 0, opc)));
                    }else{
                        int opd1 = num.top()->val;
                        num.pop();
                        int opd2 = num.top()->val;
                        num.pop();

                        char opc = op.top();
                        op.pop();
                        
                        num.push(get_new_entry(0, apply(opd1, opd2, opc)));
                    }
                }
                op.push(s[i]);
            }
        }

        while(!op.empty()){
            int opd1 = num.top()->val;
            num.pop();
            int opd2 = num.top()->val;
            num.pop();

            char opc = op.top();
            op.pop();
                    
            num.push(get_new_entry(0, apply(opd1, opd2, opc)));
        }
        printf("\t Result: %s",num.top()->val==1?"True":"False");
        printf("\n");
    }
    getchar();
    getchar();
}