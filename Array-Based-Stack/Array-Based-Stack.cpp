// Author: Omar Mohammad Fayek
//  Problem 8.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Stack Implementation Based on Array Features
#include "STACKHeader.h"

//template<typename T>
int main()
{
    int sz;
    cout << "what size of Stack do you want to create " << endl;
    cin >> sz;
    Stack<int> st(sz);
    st.manageStack(st);

}
