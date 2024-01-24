#include <iostream>
using namespace std;

struct element
{
    int dane;
    element* next = 0;
};


struct kolejka
{
    element* first = 0;

    void push(int dane)
    {
        element* nowy = new element;
        nowy->dane = dane;

        if (this->first == 0)
        {
            this->first = nowy;
        }
        else
        {
            element* ostatni = this->findLastElement();
            ostatni->next = nowy;
        }
    }

    element* findLastElement()
    {
        if (first == 0)
        {
            return 0;
        }

        element* curr = this->first;
        while (curr->next != 0)
        {
            curr = curr->next;
        }
        return curr;
    }


    void pop()
    {
        cout<<first -> dane<<endl;
        first = first -> next;

    }




};




int main()
{

    kolejka fifo;
    fifo.push(1);
    fifo.push(5);
    fifo.push(7);
    fifo.push(100);

    fifo.pop();
    fifo.pop();
    fifo.pop();
    fifo.pop();




}


