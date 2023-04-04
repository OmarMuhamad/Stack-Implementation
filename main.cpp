// Problem 8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "STACKHeader.h"

//template<typename T>
int main()
{
    int sz;
    cout << "what size of Stack do you want to create " << endl;
    cin >> sz;
    Stack<string> st(sz);
    st.manageStack(st);

}
