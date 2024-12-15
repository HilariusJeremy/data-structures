#include <bits/stdc++.h>

using namespace std;

class Array {
    private:
        int *arr;
        int length = 0;
        int capacity = 0;

    public:
        Array(){
            arr = new int[16];
            capacity = 16;
        }

        // Size input must be positive
        Array(int size){
            if(size <= 0) throw invalid_argument("Invalid input");
            arr = new int[size];
            capacity = size;
        }

        int size(){
            return length;
        }
        
        bool isEmpty(){
            return length==0;
        }

        void clear(){
            for(int i = 0 ; i<length ; i++){
                arr[i] = 0;
            }
            length = 0;
        }
        
        int get(int index){
            if(index<=0 || index>=length) throw out_of_range("Index out of range");
            return arr[index];
        }

        void set(int index, int x){
            if(index<=0 || index>=length) throw out_of_range("Index out of range");
            arr[index] = x;
        }

        void add(int x){
            if(length+1 >= capacity){
                if(capacity==0) capacity=1;
                else capacity *= 2;
                int *arrCopy = new int[capacity];
                for(int i = 0 ; i<length ; i++){
                    arrCopy[i] = arr[i];
                }

                //Won't it cause segfault since the array is dynamically initialized?
                delete[] arr;
                arr = arrCopy;
            }

            arr[length++] = x;
        }

        void removeAt(int index){

            int *arrCopy = new int[length-1];
            for(int i = 0, j = 0 ; i<length ; i++, j++){
                if(j==index) j--;
                else arrCopy[i] = arr[j];
            }
            capacity = --length;
            delete[] arr;
            arr = arrCopy;

        }

        bool remove(int x){
            for(int i = 0 ; i<length ; i++){
                if(arr[i]==x){
                    removeAt(i);
                    return true;
                }
            }
            return false;
        }

        int indexOf(int x){
            for(int i = 0 ; i< length ; i++){
                if(arr[i]==x) return i;
            }
            return -1;
        }

        bool contains(int x){
            return indexOf(x) != -1;
        }

        void display(){
            for (int i = 0 ; i<length ; i++){
                cout << arr[i] << '\n';
            }

        }

};

int main(){
    Array arr = Array(10);
    cout << arr.isEmpty() << '\n';
    arr.add(1);
    arr.add(2);
    arr.add(3);

    arr.display();
    return 0;
}