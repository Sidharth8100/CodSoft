//basic calculator 
#include<bits/stdc++.h>
using namespace std;


int main(){
    char op;//short for operation to be used
    //algorithm for basic two operator calculator with one operation
    int num1, num2;
    cout<<"Enter the simple equation to solve"<<endl;
cout<<"Example ->  2 + 3 // 4 * 6 , Don't forget space"<<endl;
cout<<"Use only the four basic algebraic operators (+, -, *, / )"<<endl;
    cin>>num1 >> op >>num2;
    switch(op) {
        case '+':
            cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
            break;
        case '-':
            cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
            break;
        case '*':
            cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0)
                cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
            else
                cout << "Division by zero is not allowed." << endl;
            break;
        default:
            cout << "Operator outside scope of calculator " << endl;
            break;
    }
 return 0;
}
