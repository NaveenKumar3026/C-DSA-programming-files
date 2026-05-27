#include<bits/stdc++.h>
using namespace std;

class IP{
    public:
    char c[100];
    double d[100];
    int ctop, dtop;

    IP(){
        ctop=-1, dtop=-1;
    }

    int precedence(char ch) {
    if(ch == '+' || ch == '-') return 1;
    if(ch == '*' || ch == '/') return 2;
    return 0;
}


    void push(char ch){
        if(ctop+1==100) return;
        ctop+=1;
        c[ctop]=ch;
    }
    char pop(){
        if(ctop==-1) return '\0';
        char ch = c[ctop];
        ctop--;
        return ch;
    }
    char top(){
        char a;
        if(ctop==-1){}
        else{
            a = c[ctop];
        }
        return a;
    }

    bool isEmpty(){
        if(ctop==-1) return true;
        return false;
    }

    void Push(double d){
        if(dtop+1==100) return;
        dtop+=1;
        d[dtop]=d;
    }
    double Pop(){
        if(dtop==-1) return;
        double a = d[dtop];
        dtop--;
        return a;
    }
    double Top(){
        double a;
        if(dtop==-1){}
        else{
            a = d[dtop];
        }
        return a;
    }
    bool IsEmpty(){
        if(dtop==-1) return true;
        return false;
    }


    string infixToPostfix(string infix){
        string postfix="";
        for(int i=0;i<infix.length();i++){
            char ch=infix[i];
            if(isdigit(ch)){
                while(i<infix.length() && isdigit(infix[i])){
                    postfix+=infix[i];
                    i++;
                }
                postfix+=' ';
                i--;
            }
            else if(ch=='('){
                push(ch);
            }
            else if(ch==')'){
                while(!isEmpty() && c[ctop]!='('){
                    char cc = pop();
                    postfix+=cc;
                    postfix+=' ';
                }
                pop();
            }
            else{
                while(!isEmpty() && precedence(top())>=precedence(ch)){
                    char cc=pop();
                    postfix+=cc;
                    postfix+=' ';
                }
                push(ch);
            }

        }
        while(!isEmpty()){
            char cc = pop();
            postfix+=cc;
            postfix+=' ';
        }

        return postfix;
    }

    double evaluate(string postfix){
        string num="";
        for(int i=0;i<postfix.length();i++){
            char ch=postfix[i];
            if(isdigit(ch)){
                num="";
                while(i<postfix.length() && isdigit(postfix[i])){
                    num+=postfix[i];
                    i++;
                }
                double val=stod(num);
                Push(val);
            }
            else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'){
                double a1=Pop();
                double a2=Pop();
                double res=0;
                switch(ch){
                    case '+': res = a2 + a1; break;
                    case '-': res = a2 - a1; break;
                    case '*': res = a2 * a1; break;
                    case '/': res = a2 / a1; break;
                }
                Push(res);
            }
        }
        return Pop();
    }
};
