#include <iostream>
#include "list.h"

using namespace std;

int main()
{
    List<int>* lista = new List<int>;
    lista-> push_back(3);
    lista-> push_back(1);
    lista-> push_front(4);
    cout << lista-> front() << endl;
    cout << lista-> back() << endl;
}