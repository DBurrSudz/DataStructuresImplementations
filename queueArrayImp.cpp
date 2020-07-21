#include <iostream>
#include <iomanip>
using namespace std;



class Queue{
    private:
        int array[5];
        int front;
        int rear;

    public:

        /**
         * @brief Public Constructor that initializes the array values to 0 and the front and rear to -1.
         */
        Queue(){
            front = -1;
            rear = -1;
            for (int x = 0; x <= 5; x++){
                array[x] = 0;
            }
        }

        /**
         * @brief Checks if the queue is empty.
         * @return If the queue is empty.
         */
        bool isEmpty(){
            if (rear == -1 && front == -1){
                return true;
            }
            else{
                return false;
            }
        }

        /**
         * @brief Checks if the queue is full.
         * @return If the queue is full.
         */
        bool isFull(){
            if (rear == 4){
                return true;
            }
            else{
                return false;
            }
        }

        /**
         * @brief Adds an item to the rear of the queue.
         */
        void enqueue(int data){
            if (isFull()){
                cout << "The queue is full." << endl;
            }

            else{
                if (isEmpty()){
                    front = 0;
                    rear = 0;
                    array[rear] = data;
                }
                else{
                    rear++;
                    array[rear] = data;
                }
            }
        }


        /**
         * @brief Removes an item from the front of the queue.
         * @return Value removed from the queue.
         */
        int dequeue(){
            int dataOut;
            if (isEmpty()){
                cout << "The queue is already empty. " << endl;
            }
            if (rear == front){
                dataOut = array[front];
                front = rear = -1;
            }
            else{
                dataOut = array[front];
                front++;
            }
            return dataOut;
        }

        /**
         * @brief Gets the amount of items in the queue.
         * @return Number of items in the queue.
         */
        int count(){
            return (rear - front) + 1;
        }

};

int main(){

}