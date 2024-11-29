#include <bits/stdc++.h>
#include "./Rubiks3DRepresentation.cpp"
#include "./Rubiks1DRepresentation.cpp"
#include "./RubiksBitBoardRepresentation.cpp"
#define endl '\n'
using namespace std;
signed main() {

    cout<<"3D representation"<<endl;
    Rubiks3DArray obj;
    obj.print();
    Rubiks1DRepresentation obj1;
    cout<<"1D representation"<<endl;
    obj1.print();
    RubiksBitBoardRepresentation obj2;
    cout<<"BitBoardRepresentation representation"<<endl;
    obj2.print(18);
    cout<<endl;
    obj.b();
    obj1.b();
    obj2.b();
    obj.print();
    obj1.print();

}