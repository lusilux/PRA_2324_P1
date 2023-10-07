#include <ostream>
#include "List.h"
#include "Node.h"

using namespace std;

template <typename T> class ListLinked : public List<T> {
	private:  
		int n;
		Node<T> *first; 
	public:
		ListLinked(){
            n = 0;
            first = nullptr;
        } 
		~ListLinked(){
            for(int i = 0; i < n; i++){
                Node<T> *aux = first->next;
                delete first;
                first = aux;
            } 
        } 
        T operator[](int pos){
            if (pos >= 0 && pos < n) { 
                Node<T> *aux = first;
                for(int i = 0; i < pos; i++)aux = aux->next;
                return aux;
             }
			else { throw out_of_range("Posición no válida del array\n"); }
        } 

        friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
            Node<T> *aux = list.first;
            for(int i = 0; i < list.n; i++){
                out << aux.data << " ";
                aux = aux->next; 
            } 
			return out;
        } 
		void insert(int pos, T e) override{
            if (pos == 0) { 
                first = new Node<T>(e.data, first);
            } else {
                Node<T>* prev = first;
                int i = 0;
                while (prev != nullptr && i < pos-1){
                    prev = prev->next;
                    i++;
                }
                if (prev != nullptr) {
                    prev->next = new Node<T>(e.data, prev->next);
                } 
            }
        } 
		void append(T e) override{insert(n,e);} 
		void prepend(T e) override{insert(0,e);} 
		T remove(int pos) override{
            if (pos < 0 || pos >= n) { throw out_of_range("Posición no válida del array\n"); }
            else{
                if(pos == 0){
                    Node<T>* aux = first;
                    first = first->next;
                    delete aux;
                }else{
                    Node<T>* aux = first->next;
                    Node<T>* prev = first;
                    for(int i = 1; i <= pos; i++){
                        aux = aux->next;
                        prev = prev->next;
                    } 
                    prev->next = aux->next;
                    delete aux;
                } 
            } 
        } 
		T get(int pos) override{
            if (pos < 0 || pos >= n) { throw out_of_range("Posición no válida del array\n"); }
			else{
                Node<T>* aux = first; 
                for(int i = 0; i < pos; i++){
                    aux = aux->next;
                }
                return aux; 
            }  
        } 
		int search(T e) override{

            Node<T>* aux = first; 
            int i = 0;
            while (aux != nullptr && aux != e) { 
                aux = aux->next;
                i++;
            }
            if (aux != nullptr)return i;
            else return -1;

        } 
		bool empty() override{return n == 0;} 
		int size() override{return n;}  
};