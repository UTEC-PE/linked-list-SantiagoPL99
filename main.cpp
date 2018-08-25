#include <iostream>
#include "list.h"

using namespace std;

int main()
{
    List<int>* lista = new List<int>;
    lista-> push_back(3);
    lista-> push_back(1);
    lista -> push_back(14);
    lista-> push_front(4);
    lista-> print();
    lista-> pop_back();
    cout << endl;
    lista-> print();
    lista -> push_back(14);
    cout << endl;
    lista-> print();
    lista-> pop_front();
    cout << endl;
    lista-> print();
}