#ifndef CURSORLIST_HPP
#define CURSORLIST_HPP
#define N 100000

#include <stdexcept>

class List{
private:
    struct Node{
        int value;
        int next;
    };
    Node arr[N];
    int size_;
    int spare;
    int head;
    int tail;
    
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
    int allocate();
    List();
};


List::List():size_(0),spare(0),head(-1),tail(-1){
    for(int i=0;i<N;i++){
        arr[i].next=i+1;
    }
    arr[N-1].value = (-1);
    
}


int List::allocate(){
    int tmp = spare;
    spare = arr[spare].next;
    return tmp;
}


void List::push_front(int x){
   if(size_==N){
        throw std::out_of_range("List is full");
   }
   int node = allocate();
   arr[node].value =x;
   arr[node].next = head;
   head = node;
   if(size_==0){
        tail=node;
   }
   size_++;
    
}

int List::pop_front(){
    if(empty()){
        throw std::out_of_range("List is empty");
    }
    int value = arr[head].value;
    int temp = spare;
    spare = head;
    head=arr[head].next;
    arr[spare].next = temp;
    
    size_--;
    return value;
}

void List::push_back(int x){
    if(size_==N){
        throw std::out_of_range("List is full");
   }
    int node = allocate();
    arr[node].value =x;
    arr[node].next = -1; 
    arr[tail].next = node;
    tail = node;
    if(size_==0){
        head=node;
   }
   size_++;
    
}

int List::pop_back(){
    if(empty()){
        throw std::out_of_range("List is empty");
    }
    int value = arr[tail].value;
    int temp = spare;
    spare = tail;
    int index = head;
    for(int i = 0;i<size_-2;i++){
        index = arr[index].next;
    }
    tail = index;
    arr[tail].next = -1;
    arr[spare].next = temp;
    size_--;

    return value;
}

int List::size(){
    return size_;
}


bool List::empty(){
    return size_==0;
}


void List::clear(){
    size_ = 0;
}


int List::find(int x){
    if(!empty()){
        int index = head;
        for(int i = 0; i<size_;i++){
            
            if(arr[index].value==x) return i;
            index = arr[index].next;
            
        }
    }
    return -1;
}
//indeksy listy od 0
int List::erase(int i){
    if(empty()){
        throw std::out_of_range("List is empty");
    }
    int index = head;
    int j,preindex;
    for(j = 0; j<i;j++){
        preindex = index;
        index = arr[index].next;
    }
    if(index == head){
        return pop_front();
        
    }
    if(index == tail){
       return pop_back();
    }
    int value = arr[index].value;
    arr[preindex].next=arr[index].next;
    int temp = spare;
    spare = index;
    arr[spare].next=temp;
    size_--;
    return value;

}


void List::insert(int i, int x){
    if(i<0){
        throw std::out_of_range("Bad index");
    }
    if(size_==N){
        throw std::out_of_range("List is full");
    }
    int index = head;
    int preindex;
    for(int j = 0; j<i;j++){
        preindex = index;
        index = arr[index].next;
    }
    if(index == head){
        push_front(x);
        return;
    }
    if(index == tail){
        push_back(x);
        return;
    }
    int node = allocate();
    arr[node].value = x;
    int temp = arr[preindex].next;
    arr[preindex].next = node; 
    arr[node].next = temp;
    size_++;
}


int List::remove(int x){
     if(empty()){
        throw std::out_of_range("List is empty");
    }
    int count;
    int index =  head;
    int preindex =head;
    for(int i=0;i<size_;i++){
        if(arr[index].value==x){
            if(index==head){
                int temp = arr[spare].next;
                spare=head;
                arr[spare].next = temp;
            }
            else{
                arr[preindex].next=arr[index].next; 
                int temp = arr[spare].next;
                spare=index;
                arr[spare].next = temp;
            }
            size_--;
            count++;
        }
        preindex=index;
        index = arr[index].next;
        
    }
    return count;
} 


#endif