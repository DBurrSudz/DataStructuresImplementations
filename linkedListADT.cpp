#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


struct Node{
    /*Holds Data for Node*/
    int data;
    Node* next;
};

class LinkedList{
private:
    Node* head;
    bool empty;


    /**
     * @brief Checks if the linked list is empty
     * @return If the list is empty.
     */
    bool isEmpty(){
        if (head->data == 0){
            empty = true;
        }

        else{
            empty = false;
        }
        return empty;
    }

    /**
     * @brief Increments the total items in the list.
     */
    void incrementList(){
        head->data++;
    }


    /**
     * @brief Decrements the total items in the list.
     */
    void decrementList(){
        head->data--;
    }

    /**
     * @brief Traverse the end of the linked list.
     * @return A Pointer to the last node in the list.
     */
    Node* traverseToEnd(){
        Node* currentNode = head;
        while (currentNode->next != NULL){
        currentNode = currentNode->next;
        }
        return currentNode;

    }


    /**
     * @brief Finds the node before a specified node.
     * @param position The position of the node in the linked list.
     * @return A Pointer the node before the specified one.
     */
    Node* findPrenode(int position){
        int count = 0;
        Node* previousNode = head;

        while (count < position - 1 ){
            previousNode = previousNode->next;
            count++;
        }
        return previousNode;
    }


public:
    LinkedList(){
        head = new Node();
        head->data = 0;
        head->next = NULL;
    }

    /**
     * @brief Creates a new node to be added to the list.
     * @param data The data to be inserted into the new node.
     * @return The newly created node.
     */
    Node* createNode(int data){
        Node* node = new Node();
        node->data = data;
        node->next = NULL;

        return node;
    }

    /**
     * @brief Inserts a node at the beginning of the list.
     * @param newNode A Pointer to the node to be added.
     */
    void insertBegin(Node* newNode){
        newNode->next = head->next;
        head->next = newNode;
        incrementList();
        isEmpty();
    }

    /**
     * @brief Inserts a node at a specified position in the list.
     * @param newNode A Pointer to the node to be added.
     * @param position The position at which the node must be added.
     */
    void insertAt(Node* newNode, int position){
        if (empty){
            insertBegin(newNode);
        }

        else if(position >= head->data){
            insertEnd(newNode);
        }

        else{
            Node* preNode = findPrenode(position);
            newNode->next = preNode->next;
            preNode->next = newNode;
            incrementList();
            isEmpty();
        }


    }


    /**
     * @brief Inserts a node at the end of the list.
     * @param newNode A Pointer to the node to be added.
     */
    void insertEnd(Node* newNode){
        if (empty){
            insertBegin(newNode);
        }

        else{
            Node* endNode = traverseToEnd();
            newNode->next = endNode->next;
            endNode->next = newNode;
            incrementList();
            isEmpty();
        }
    }


    /**
     * @brief Deletes the node at the beginning of the list.
     */
    void deleteBegin(){
        Node* deleteNode = head->next;
        head->next = deleteNode->next;
        delete deleteNode;
        decrementList();
        isEmpty();
    }

    /**
     * @brief Deletes the node at the end of the list.
     */
    void deleteEnd(){
        if (empty){
            return;
        }
        else{
            Node*prev, *deleteNode;
            deleteNode = head;

            while(deleteNode->next != NULL){
                prev = deleteNode;
                deleteNode = deleteNode->next;
            }
            prev->next = deleteNode->next;
            delete deleteNode;
            decrementList();
            isEmpty();
        }
    }


    /**
     * @brief Deletes the node at a specified position in the list.
     * @param position The position of the node to be deleted.
     */
    void deleteAt(int position){
        if (empty){
            return;
        }
        else{
            if (position >= head->data){
                position = head->data;
            }
            Node* preNode = findPrenode(position);
            Node* deleteNode = preNode->next;
            preNode->next = deleteNode->next;
            delete deleteNode;
            decrementList();
            isEmpty();


        }
    }


    /**
     * @brief Searches the list for a specified key.
     * @param key Key to be found.
     * @return If the key was found.
     */
    bool searchData(int key){
        if (empty == false){
            Node* currNode = head;
            while (currNode->next != NULL){
                currNode = currNode->next;
                if (currNode->data == key){
                    return true;
                }
            }
        }
        return false;
    }

    /**
     * @brief Appends a linked list to the end to make a new list.
     * @param appended The linked list to be appended.
     */
    void appendList(LinkedList appended){
        Node* endNode = traverseToEnd();
        endNode->next = appended.head->next;
        int appendedCount = appended.head->data;
        int thisListCount = head->data;
        int newListCount = thisListCount += appendedCount;
        head->data = newListCount;
        delete appended.head;
        delete endNode;
    }


    /**
     * @brief Sums up the keys in the list.
     * @return The total sum of the keys in the list.
     */
    int sumList(){
        int total = 0;
        int count = 0;
        Node* currentNode = head;
        while (count < head->data){
            currentNode = currentNode->next;
            total += currentNode->data;
            count++;
        }
        return total;
    }


    /**
     * @brief Prints the linked list
     */
    void printList(){
        Node* currentNode = head;
        while (currentNode->next != NULL){
            currentNode = currentNode->next;
            cout << currentNode->data << " ";
        }
        cout << endl;
    }

    /**
     * @brief Prints the value at the front of the linked list.
     */
    void printBegin(){
        Node* firstNode = head->next;
        cout << firstNode->data << endl;
    }


    /**
     * @brief Prints the value at the end of the linked list.
     */
    void printEnd(){
        Node* endNode = traverseToEnd();
        cout << endNode->data << endl;
    }


    /**
     * @brief Prints the value at a specified position in the linked list.
     * @param position The position of the node to be printed.
     */
    void printAt(int position){
        if (position >= head->data){
            position = head->data;
        }

        Node* currNode = head;
        int count = 0;
        while (count < position){
            currNode = currNode->next;
            count++;
        }
        cout << currNode->data << endl;
    }

    /**
     * @brief Prints the total number of items in the list.
     */
    void printCount(){
        cout << head->data << endl;
    }


    /**
     * @brief Swaps two nodes in the linked list.
     * @param position1 The position of the first node to be swapped.
     * @param position2 The position of the second node to be swapped.
     */
    void swap(int position1, int position2){
        if (head->data != 0){
            Node* pPre1;
            Node* pPre2;
            Node* currNode1 = head;
            Node* currNode2 = head;
            int counter = 0;
            while (counter < position1){
                pPre1 = currNode1;
                currNode1 = currNode1->next;
                counter++;
            }
            counter = 0;
            while (counter < position2){
                pPre2 = currNode2;
                currNode2 = currNode2->next;
                counter++;
            }

            Node* temp = currNode2->next;
            currNode2->next = currNode1->next;
            currNode1->next = temp;
            temp = pPre2->next;
            pPre2->next = pPre1->next;
            pPre1->next = temp;

		}
    }
};


int main(){
/*    LinkedList list1;
    int amount,input;

    cout << "How many pieces of data would you like to add to the list1: ";
    cin >> amount;

    for (int x = 1; x <= amount; x++){
        cout << "Enter data for node " << x<<": ";
        cin >> input;
        Node* node = list1.createNode(input);
        list1.insertEnd(node);
    }
    list1.printList();
    list1.swap(3,5);
    list1.printList();
*/


    LinkedList list4;
    Node* newNode = list4.createNode(788);
    list4.insertBegin(newNode);
    newNode = list4.createNode(67);
    list4.insertBegin(newNode);
    newNode = list4.createNode(120);
    list4.insertBegin(newNode);
    list4.printList();

    list4.deleteEnd();
    list4.printList();

}
