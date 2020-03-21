#ifndef LISTITERATOR_H
#define LISTITERATOR_H


#include <list>
#include <iostream>



template <typename T>
class ListIterator
{
    public:
        ListIterator();
        ListIterator(const list<T>& list);
        void next();

    protected:

    private:
        list<T> iterableList;
        list<T>::iterator it;

};

#endif // LISTITERATOR_H
