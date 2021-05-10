#ifndef LISTA_HPP
#define LISTA_HPP

#include "nodo.hpp"

using namespace std;

template<class T>
class Lista{
    Nodo<T> * head;
    int length;

    public:
        Lista(Nodo<T> * head) : head(head), length(0){}
        Lista() : Lista(NULL){}

        void insert(Nodo<T> * n){
            //inserimento in coda
            if (head == NULL){
                head = n;
                length++;
                return;
            }

            Nodo<T> *current = head;
            while(current->getNext() != NULL){
                current = current->getNext();
            }
            current->setNext(n);
            length++;
        }

        void insert(T value){
            Nodo<T> * temp = new Nodo<T>(value);
            this->insert(temp);
        }

        void insertInOrder(T value){
            Nodo<T> * temp = new Nodo<T>(value);

            if(head == NULL){
                this->insert(temp);
                return;
            }

            if(head->getValue() >= value){
                temp->setNext(head);
                head = temp;
                length++;
                return;
            }
            Nodo<T> * prev = head;
            Nodo<T> * current = head->getNext();

            while(current != NULL){

                if(prev->getValue() < value && current->getValue() >= value){
                    prev->setNext(temp);
                    temp->setNext(current);
                    length++;
                    return;
                }
                else{
                    //current = current->getNext();
                    //prev = prev->getNext();
                    prev = current;
                    current = current->getNext();
                }

            }
            prev->setNext(temp);
            length++;
            return;
        }

        bool search(T value){
            if(head == NULL){
                return false;
            }

            Nodo<T> * temp = head;
            while(temp != NULL){

                if(temp->getValue() == value)
                    return true;

                temp = temp->getNext();//else
            }
            return false;
        }

        Nodo<T> * deleteNode(T value){
            
            if(this->search(value)){

                if(head->getValue() == value){
                    Nodo<T> * tmp = head;
                    head = head->getNext();
                    length--;
                    return tmp;
                }

                Nodo<T> * prev = head;
                Nodo<T> * current = head->getNext();
                
                while(current != NULL){

                    if(current ->getValue() == value){
                        prev->setNext(current->getNext());
                        length--;
                        return current;
                    }
                    prev = current;
                    current = current->getNext();
                }
                
            }
            return NULL;
        }

        int getLength(){
            return this->length;
        }

        Nodo<T> * getHead(){
            return this->head;
        }

        friend ostream& operator<<(ostream& out, Lista<T>& l){
            out << "Lista di lunghezza " << l.length << " \t head = " << l.head << endl;
            Nodo<T> * current = l.head;
            while(current != NULL){
                out << "\t" << current->toString() << endl;
                current = current->getNext();
            }
            return out;
        }
};

#endif