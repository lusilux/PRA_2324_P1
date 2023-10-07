
#include<ostream>
#include"list.h"

using namespace std;

template <typename T> class ListArray : public List<T> {
	private:  
		T* array;
		int n;
		int max;
		static const int MINSIZE = 2; 

		void resize(int new_size){
			T* a = new T[new_size];
			for(int i = 0; i < max; i++)a[i] = array[i];
			delete[] array;
			array = a;
			max = new_size;  
		} 
	public:
		ListArray(){
			array = new T[MINSIZE];
			n = 0;
			max = 2;
		} 
		~ListArray(){
			delete[] array; 
		} 	

		T operator[](int pos){
			if (pos >= 0 && pos < n) { return array[pos]; }
			else { throw out_of_range("Posición no válida del array\n"); }
		} 
		friend ostream& operator<<(ostream &out, const ListArray<T> &list){
			for(int i = 0; i < list.n; i++)out << list.array[i] << " "; 
			return out;
		} 

		void insert(int pos, T e) override{
			if (pos < 0 || pos >= max) { throw out_of_range("Posición no válida del array\n"); }
			else{
				int i = 0;
				if(max == n)resize(n+1);
				n++;
				T* a = new T[max];

				for(i = 0; i < pos; i++){
					a[i] = array[i];
				}
				a[i] = e;
				i++;
				while(i < n){
					a[i] = array[i-1];  
					i++;
				}  
				delete[] array;
				array = a;
			}	
		} 
		void append(T e) override{
			if(max == n)resize(n+1);
			array[n] = e; 
			n++; 
		} 
		void prepend(T e) override{
			insert(0,e);
		} 
		T remove(int pos) override{
			if (pos < 0 || pos >= n) { throw out_of_range("Posición no válida del array\n"); }
			else{
			  	T x = array[pos];
				T* a = new T[max];

				//Diferenciamos dos casos

				if(pos == 0){
					for(int i = 0; i < n-1;i++){
						a[i] = array[i+1];
					}
				}else{

					for(int i = 0; i < pos; i++){
						a[i] = array[i];  
					}
					for(int i = pos+1; i < n; i++){
						a[i-1] = array[i];  
					}

				}	
				delete[] array;
				array = a;
				n--;
				return x;
			}	
		} 
		T get(int pos) override{
			if (pos < 0 || pos >= n) { throw out_of_range("Posición no válida del array\n"); }
			else return array[pos]; 
		} 
		int search(T e) override{
			for(int i = 0; i < n; i++)if(array[i] == e)return i;
			return -1; 
		} 
		bool empty() override{return n == 0;} 
		int size() override{return n;} 
};

//template <typename T> int ListArray<T> ::MINSIZE = 2;
/*
template <typename T> ListArray<T> ::ListArray(){
	array = new T[MINSIZE];
	n = 0;
	max = 2;
} 
template <typename T> ListArray<T> ::~ListArray(){
	delete[] array; 
} 

template <typename T> T ListArray<T> ::operator[](int pos){
	if (pos >= 0 && pos < max) { return array[pos]; }
	else { throw out_of_range(“Posición no válida del array\n”); }
}  

ostream& operator<<(ostream &out, const ListArray<T> &list){
	for(int i = 0; i < max; i++)out << list[i] << " "; 
	return out;
} 

template <typename T> void ListArray<T> ::resize(int new_size){
	T* a = new T[new_size];
	for(int i = 0; i < max; i++)a[i] = array[i];
	delete[] array;
	array = a;
	max = new_size;   
} 

*/
