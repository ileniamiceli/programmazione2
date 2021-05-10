#ifndef NODO_HPP
#define NODO_HPP

#include <iostream>
#include <sstream>

using namespace std;

template<class T>

class Nodo{
    T value;
    Nodo<T> * next;

    public:
        Nodo(T value, Nodo<T> * next) : value(value), next(next){}
        Nodo(T value) : Nodo(value, NULL){}
        Nodo() : Nodo(0, NULL){}

        Nodo<T> * getNext(){
            return this->next;
        }

        T getValue(){
            return this->value;
        }

        void setNext(Nodo<T> * next){
            this->next = next;
        }

        void setValue(T value){
            this->value = value;
        }

        string toString(){
            stringstream stream;
            stream << "Valore nodo = " << value << ", successivo = " << next;
            return stream.str();
        }

        friend ostream& operator<<(ostream& out, Nodo<T>& n){
            out << n.toString();
            return out;
        }
};

#endif