#include<bits/stdc++.h>

using namespace std;

char arr[100];
int top = -1;

bool isEmpty(){
    if(top == -1) return true;
    else return false;
}

void push(char a){
    if(top+1==100){
        cout<<"Stack is full and cannot insert any elements\n";
        return;
    }
        top = top + 1;
        arr[top] = a;
}

char pop(){
	char a;
        if(isEmpty()){
        }
        else
        {
        a = arr[top];
        top--;
        }
        return a;
}

double arr1[100];
int top1 = -1;


bool isempty(){
                if(top1 == -1) return true;
                        else return false;
}

void Push(double a){
        top1 = top1 + 1;
        arr1[top1] = a;
        //cout<<arr1[top1]<<endl;
}

double Pop(){
	double a;
        if(isempty()){
        }
        else
        {
        a = arr1[top1];
        top1--;
        }
        return a;
}

int precedence(char ch) {
    if(ch == '+' || ch == '-') 
        return 1;
    if(ch == '*' || ch == '/') 
        return 2;
    //if(op == '^') 
      //  return 3;
    return 0;
}


double applyOperator(double a, double b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return b - a;
        case '*': return a * b;
        case '/': return b / a;  
     //   case '^': return pow(a, b);
    }
    return 0;
}

string inToPost(string infix) {
    string postfix = "";
    for(char ch : infix) {
        if(isalnum(ch)) {
            postfix += ch;
        }
        else if(ch == '(') {
            push(ch);
        }
        else if(ch == ')') {
            while(!isEmpty() && arr[top] != '(') {
                postfix += pop();
            }
            if(!isEmpty()) pop(); 
        }
        else {  
            while(!isEmpty() && precedence(arr[top]) > precedence(ch)) {
                //if(ch == '^' && st.top() == '^') break; // right associative for '^'
                    postfix += pop();
            }
            push(ch);
        }
    }

    while(!isEmpty()) {
        postfix += pop();
    }

    return postfix;
}

double evaluate(string postfix) {
    for(char ch : postfix) {
        if(isdigit(ch)) {
        double c  = double(ch - '0');
            Push(c);
        }
         else {
            double a = Pop();
            double b = Pop();
            double result = applyOperator(a,b,ch);
            Push(result);
        }
    }
	double ans = Pop();
    return ans;
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cout<<"(It should contain the operators +,-,*,/ and operands in numbers only)"<<endl;
    cin >> infix;

    string postfix = inToPost(infix);
    cout << "Postfix expression: " << postfix << endl;

   double result = evaluate(postfix);
   cout << "Result: " << result << endl;
   return 0;
}