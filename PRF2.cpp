#include "PRA.h"// My Functions and class

int main(){
// we Ask you to give me a value
int Tail =0;
char *Text = new char[60000];
cout << "Give me an Equation :\n like 3+(5+(4*3))-12 \n";
cin >> Text;

//We Check it 
Tail = sizeof(Text);
int i=0;
if ( Varifie(Text ,Tail ,&i) == 0 ) {
    exit(-1);
}
//if there is no ERRORs we create the Equation Object
Equation X(Text);
X.printer();
}