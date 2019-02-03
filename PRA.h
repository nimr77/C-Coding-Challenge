#include <iostream>
#include <string.h>//for using strcat
#include <strings.h>//for using sprintf
#include <ctype.h>//for using bzero


using namespace std;

static double Results[500];//Where the Results are
static double *Numbers;//the Numbers
static int G=0;//Where are we , so we wont change the results (writte over them)
static char *OP;//My Oprations 

class Equation;//calling the class 

//this Function for knowing where is the last Value of an Array
int KnowingMyLast(char T[]){
int i =0;
while(T[i]){
    i++;
}
return i;
}
//To check if its NOT a Number or and ABC.. charecter
int IfANumber(char T[]){

    int i =0;
    int r= 1;
    while(T[i]){
       if (T[i] >='0'|| T[i] == '+' || T[i]== '-' || T[i] == '*' || T[i] == '/' || T[i] == ')' || T[i] == '(' ) {
          
       }else
       {
           cout << "There is unvalide value in the Equation which is = "<< T[i] << " ,position: "<< i <<endl;
           r=0;
       }
       
       i++;
    }
    return r;
}

//This Function to Check if its a charecter or NOT
int TextChar(char T[],int *t){
int r =1,i=0;
while(T[i]){
    if ( 'a'<=T[i]<='Z' && T[i] >'9' ) {
        cout << "There is a Charecter in the Equation which is = "<< T[i] << " ,position: "<< i <<endl;
        r=0;
        *t = i;
    }
    i++;
}
return r;
}

//if its an Space , it will try to remove it , if it falied it will report an ERROR
void TextFix(char T[],int Tail){
    int i=0;
    for(i =0; i <=3; i++){
        if ( isspace(T[i]) || T[i] == '\t' || !T[i] ) {
            
            cout << "There is a Space !"<< " \nat "<< i<<" ,Trying to Fix it !"<<endl;
            i++;
            T[i] = T[i];
        if (!T[i]) {
            cout <<"ERROR ! "<<endl;
            exit(-1);
        }
            //cout << T[i];
            continue;
        }

        
        T[i] = T[i];
        i++;
    }
    
}

//How to Varifie the Equation , Which is by using a function to control whats in the equation 
//and repport an ERROR if there is by return the value of r to the main
int Varifie(char T[],int Tail,int *t){
int i=0,r=1;
TextFix(T,Tail);
r = TextChar(T,t);
if (r==1) {
 r= IfANumber(T);
}

return r;
}

//to change the marks () into a Value , by :
//knowing Where to Start and Where to end (s - Start , f - Finich) 
//The Text T with its Value Valuer
void outNuminatext(char T[],int s , int f ,double Valuer){
int i=0,size;
//puts(T);
while (T[i]){
i++;
}
size = i;
char *NT = new char [i+10];
i=0;
while(T[i]){
    *(NT +i) = T[i];
    if (i==s) {
       // cout << T[i]<< endl;
        char V[30];
        //int Valuer = (int )Valuer;
        sprintf(V,"%g",Valuer);
        strcat(NT,V);
        i = KnowingMyLast(NT);
        while(T[f]){
         *(NT +i) = T[f];

         f++;i++;
        }
        break;
    }
    i++;
}
i=0;

while(T[i]){
    T[i] = ' ';
    T[i] = *(NT+i);i++;
}
}

//To Varify if the Number of ( is equel to )
int countInBetween(const char T[]){
     int R=0;
     int L=0;
     int r=0;
    int i=0;
    while(T[i]){
      if (T[i] == '(' ) {
        R++;
    }
    if ( T[i] == ')') {
        L++;
    }
    
    i++;
    }
    if (R == L) {
        //cout << R << " "<< L;
        r=1;
    }
    
  return r;
}


// to Count the Size of the Equation
int countSize(const char T[])
{
    int i = 0;
    while (T[i] != '\0')
    {
        i++;
    }
    return i;
}

//Knowing the Size of my Oprations (there Number)
int KnowingTheOP(const char T[]){
    int i=0,r=0;
    while(T[i] != '\0'){
       if (T[i] == '+' || T[i]== '-' || T[i] == '*' || T[i] == '/')
        {
     r++;
        }
        i++;
    }
return r;
}

//My Class 
class Equation
{
  private:
   
    double R = 0;  //the Result
    int Size ;   // The Size
    char *Eq;      //The Equation
   int SizeOP;       // MY Opration
    //For Doing the Math
    double Domath(double V1, double V2, char op)
    {
        double R;
        if (op == '+')
        {
            R = V1 + V2;
        }
        if (op == '*')
        {
            R = V1 * V2;
        }
        if (op == '-')
        {
            R = V1 - V2;
        }
        if (op == '/')
        {
            R = V1 / V2;
        }
        cout << V1 << op << V2 << "=" << R << endl;
        return R;
    }

  public:
   //it Give me the Results as Public 
    double GiveVal()
    {
        return R;
    }
    
    //my Constructer
       Equation(const char EQ[] = "1+1"){
        
        //To Varify the Number of the openig perntesis ( is equel to )
        int  r = countInBetween(EQ);
        if (r==0) {
            cout << " Please Check your Input."<<endl;
            exit(-1);
        }
        
        //Here We Start my Mager the Value of Size , so we can create a dynamic Array
        Size = countSize(EQ);
        Eq = new char[Size];
        Numbers = new double[Size];
        SizeOP  = KnowingTheOP(EQ);

         OP = new char[SizeOP];
         char *T1= new char[Size];
        char *NEq;

        double Rt = 0;//My Current return Value
         char MyNumber[10];//My Number , the Current Number
         int w=0;// a pointer , that i did use to count 
         //same here 
        int i =0,j=0,u=0;
        int n =0,P1 = 0,P2 = Size;
        int m =0,k=0,C=0;
        //here we start Lopong in the Equation to Analyse it and know 
        //where is ( and it's End)  
     while (EQ[i]){
        *(Eq+u) = EQ[i];u++; 
    
        if (EQ[i] == ')' || EQ[i] == '(') {//after finding the ( or ) we start Lopping in the Equation again but , Looking for 
                                           // the end of ) and copying the Value into another Equation named T1 and reanalyse it 
        n=(i+1);
        k = ++m;//to point use where is our opening mark , so we will loop again if its been found we will chack if it's our close mark
        if ((EQ[i]) == '(') {
            P1 = i;//the Position of my (
        }
        
        //cout << "P1 " << P1 << "P2 "<< P2;
            while(EQ[n]){
           
           // cout << "Working";
            if (EQ[n] == '(') {
              m++;//pointing if we find a new Opening
             }
          //cout << m;
            if (EQ[n] == ')') {
            if (m==k) {
                    P2 = n;//if its Correct and we find the end of ( , we move to reanalyse the new Equation , and save its Value 
                    Equation Opj(T1);
                    Rt = Opj.GiveVal();
                    Results[G] = Rt;
                    //cout << Rt;
                    G++;
              break;
             }
              m--;//if we find a new close mark , we change the value of m , so we will know if its not OUR close mark
               }
              *(T1 + j) = EQ[n];
                n++;j++;
           }
          i = n;
          //cout << "||| i = " << i << endl;
        continue;//we can just change it to break 
    }

    i++;
}

// if the Equation has a new result we re put it agin the Equation in Place of ()
if(G != 0){
outNuminatext(Eq,(P1 -1),(P2+1),Results[G-1]);
cout << "The Equation is :";
puts(Eq);
}
//resize the sizeOP
//and check if we are at the End of the Equation
SizeOP  = KnowingTheOP(Eq);
if (P2 != Size) {//if we are not  we will copy it to the Equation , by first copy the rest into a new value and copy it again at the end of Eq
     NEq = new char[Size - P2];
    int j =P2,l=0;
    while (EQ[j]){
         *(NEq+l) = EQ[j];
         j++;l++;
    }
    strcat(Eq,NEq);
}
//to know that its the End of the Equation and we have a value before this end
strcat(Eq,".");
i=0;k=0;
OP = new char[SizeOP];
        while (*(Eq + i) != '\0')//we Loop in our Current Equation to Find its Numbers and its Operators
        {  
            // here we are looking after its Numbers
            if (*(Eq + i) != '+' && *(Eq + i) != '*' && *(Eq + i) != '/' && *(Eq + i) != ')' && *(Eq + i) != '(' && *(Eq + i) != '.')
            {
               MyNumber[w] = *(Eq + i);
               w++;
                if (*(Eq + i) == '-') { // for the Negative Value
                     *(Eq + i) == '+';
                }
                

             }
            if (*(Eq + i) == '.') {// if its the End of the Equation we add the Last Number
               *(Numbers +C) = (double)atof(MyNumber); C++;w=0;bzero(MyNumber,sizeof(MyNumber));
            }
            
            // Konwing the Opration that We Are Using
            if (*(Eq + i) == '+' || *(Eq + i) == '-' || *(Eq + i) == '*' || *(Eq + i) == '/' )
            {
               *(Numbers +C) = (double)atof(MyNumber); C++;w=0;bzero(MyNumber,sizeof(MyNumber));//after changing the Value from Text to Number we do reset the Array
                *(OP+k) = *(Eq + i);k++;

            }
            
       
   i++; }

  i=0;
    //cout << C;
while( *(OP+(i)) ){//We Loop into The Operators and Do The Math
//puts(OP);
cout << i<<"|||"<<endl;
    //cout <<*(OP+(i)) << endl;
    R = Domath(*(Numbers+(i)),*(Numbers+(i+1)),*(OP+(i)) );i++;
    *(Numbers+(i)) = R;
    
    //cout << "       "<<R;
}


    }

    void printer()// to Print The Final Result R
    {
        cout << "The Final Result is = " << R << endl;
    }
};