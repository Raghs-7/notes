#include<iostream>
using namespace std;

// priority order --> ^ then * and  / then + and -
// Infix --> when every operand is in between (p + q)
// prefix(use in LISP) --> when operand is pre --> *+pq-mn
// postfix(used in stack based calculator) --> pq + mn-* 

void InfixToPostfix(){
    // make a stack and a string name answer
    // now let say our infix expression goes to --> a+b*(c^d-e)
    // then interatee over it 
    //                st               ans
    //   a                              a
    //   +            +                 a
    //   b            +                 ab
    //   *            +*                ab
    //   (            +*(               ab
    //   c            +*(               abc
    //   ^            +*(^              abc
    //   d            +*(^              abcd
    //   -            +*(-              abcd^
    //   e            +*(-              abcd^e-
    //   )            +*                abcd^e-
    // done with interation then abcd^e-*+
    
}
 

int main(){
    cout << "hello world" << endl;
    return 0;
}