#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP

#include <stdexcept>
#define MAX_SIZE 100000

class List{
private:
    int array[MAX_SIZE];
    int listSize;

public:    
    void push_front(int x); // Dołącza element na początek listy
    int pop_front(); // Usuwa i zwraca element z początku listy
    void push_back(int x); // Dołącza element na koniec listy
    int pop_back(); // Usuwa i zwraca element z końca listy
    int size(); // Zwraca liczbę elementów w liście
    bool empty(); // Zwraca `true` gdy lista jest pusta
    void clear(); // Czyści listę
    int find(int x); // Zwraca pozycję pierwszego elementu o wartości x
    int erase(int i); // Usuwa i zwraca element na pozycji `i`
    void insert(int i, int x); // Wstawia element `x` przed pozycję `i`
    int remove(int x); // Usuwa wystąpienia `x` i zwraca ich liczbę
    List();
};


void List::push_front(int x){
    if(listSize<MAX_SIZE){
        for(int i = listSize; i > 0; i--){
            array[i]=array[i-1];
        }
        array[0]=x;
        listSize ++;
    }
    else{
        throw std::out_of_range("List is full");
    }
}

int List::pop_front(){
    int temp = array[0];
    if(empty()){
        throw std::out_of_range("List is empty");
    }
    else{
        for(int i = 0; i<listSize;i++){
            array[i]=array[i+1];
        }
    }
    listSize--;
    return temp;
}

void List::push_back(int x){
    if(listSize<MAX_SIZE){
        array[listSize]=x;
        listSize++;
    }
    else{
        throw std::out_of_range("List is full");
    }
}

int List::pop_back(){
    if(empty()){
        throw std::out_of_range("List is empty");
    }
    else{
        listSize--;
        return array[listSize];
    }
}

int List::size(){
    return listSize;
}

bool List::empty(){
    return listSize==0;
}

void List::clear(){
    listSize=0;
}

int List::find(int x){
   
    if(!empty()){
        for(int i = 0; i<listSize;i++){
            if(array[i]==x){
                return i;
            }
        }
    }
    return -1;
}

int List::erase(int i){
    int temp;
    if(empty()){
        throw std::out_of_range("List is empty");
    }
    else{
        temp = array[i];
        listSize--;
        for(int j = i; j<listSize; j++){
            array[j]=array[j+1];
        }
    }
    return temp;
}
void List::insert(int i, int x){
    if(listSize>=MAX_SIZE){
        throw std::out_of_range("List is full");
    }
    if(i>listSize||i<0){
        throw std::out_of_range("Bad index");
    }
    else{
        for(int  j= listSize; j > i; j--){
            array[j]=array[j-1];
        }
        array[i]=x;
        listSize ++;
    }
}
    int List::remove(int x) {
        if(empty()){
            throw std::out_of_range("List is empty");
        }
        
        int count = 0;
        for (int i = 0; i < listSize;) {
            if (array[i] == x) {
                for (int j = i; j < listSize; j++) {
                    array[j] = array[j + 1];
                }
                listSize--;
                count++;
            } else {
                i++;
            }
        }
        return count;
    }

List::List():listSize(0){}

#endif