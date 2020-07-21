#include <iostream>
using namespace std;

class Queue{
private:
    struct Node{
        int key; //Data in the node
        Node* next; //Link to next node
    };

    Node* front;
    Node* rear;
    int total;


    /**
     * @brief Creates a new node.
     * @param key Key to be inserted into node.
     * @return Newly created node.
     */
    Node* getNode(int key){
        Node* newNode = new Node;
        newNode->key = key;
        newNode->next = NULL;

        return newNode;
    }


public:
    Queue(){
        front = NULL;
        rear = NULL;
        total = 0;
    }

    /**
     * @brief Checks if the queue is empty.
     * @return If the queue is empty.
     */
    bool isEmpty(){
        if(total == 0) return true;
        else return false;
    }


    /**
     * @brief Adds a value to the end of the queue.
     * @param key The key to be added to the queue.
     */
    void enqueue(int key){
        if(front == NULL && rear == NULL){
            front = getNode(key);
            rear = front;
        }
        else{
            Node* newNode = getNode(key);
            rear->next = newNode;
            rear = newNode;
        }

        total++;
    }


    /**
     * @brief Removes an item from the front of the queue.
     * @return Value removed from the front of the queue.
     */
    int dequeue(){
        if(front == NULL && rear == NULL){
            cout << "The list is already empty." << endl;
            return -1;
        }
        else{
            Node* deleteNode = front;
            int data = deleteNode->key;
            front = deleteNode->next;
            delete deleteNode;
            total--;
            return data;
        }

    }


    /**
     * @brief Gets the total items in the queue
     * @return The total items in the queue.
     */
    int getCount(){
        return total;
    }

    /**
     * @brief Gets the node at the front of the queue.
     * @return A pointer to the front of the queue.
     */
    Node* getFront(){
        return front;
    }


    /**
     * @brief Gets the value at the rear of the queue.
     * @return The value at the rear of the queue.
     */
    int getRear(){
        if(front == NULL && rear == NULL){
            cout << "The list is already empty." << endl;
            return -1;
        }
        return rear->key;
    }
};