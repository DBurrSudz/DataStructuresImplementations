#include <iostream>
#include <queue>
#include <string>


//Person structure containing a person's name, id and age.
struct Person{
    std::string name;
    std::string key;
    int age;
};


//Node structure containing a person's information and a pointer to a next node.
struct Node{
    //Stores a person's information
    Person data;
    //Stores the memory address to the next node in the list
    Node* next;
};


//Creates an hashtable allowing for constant time storage and retrieval of data.
template <int N>
class Hashtable{
    private:
    int size = N;
    Node* hashtable[N];

    /**
     * @brief Creates a node structure.
     * @param person The person to be added to the node structure.
     * @return The newly create node with the person's information.
     */
    Node* createNode(const Person person){
        Node* newNode = new Node();
        newNode->data = person;
        newNode->next = NULL;
        return newNode;
    }


    /**
     * @brief Resolves a collision in the hashtable by creating a new node for the collided key and chaining it to a linked list.
     * @param person The person structure to be added.
     * @param collisionAddress The hashed index where the collision occurred.
     */
    void chain(Person person, int collisionAddress){
        Node* newNode = createNode(person);
        newNode->next = hashtable[collisionAddress];
        hashtable[collisionAddress] = newNode;
    }

    /**
     * @brief Takes a person's id (key) and hashes it to an index in the hashtable.
     * @param key The person's id (key) to be hashed.
     * @return The resulting hashed index of the person's key.
     */
    int hashFunction(std::string key){
        int length = key.length();
        int total = 0;
        for(int i = 0; i < length; i++){
            total += key.at(i);
        }
        return (total / length) % N;
    }
    
    public:
    Hashtable(){
        for(int i = 0; i < N; i++){
            hashtable[i] = NULL; //Initializes all values in the table to NULL
        }
    }

    /**
     * @brief Searches for a person's information in the hashtable.
     * @param key The key that is to be searched for in the array.
     */
    void retrieveInformation(std::string key){
        int homeAddress = hashFunction(key);
        //The hashed index is occupied and the person's information is stored right there.
        if(hashtable[homeAddress] != NULL && hashtable[homeAddress]->data.key == key){
            std::cout << "Name is : " << hashtable[homeAddress]->data.name << std::endl;
            std::cout << "ID is: " << hashtable[homeAddress]->data.key << std::endl;
            std::cout << "Age is: " << hashtable[homeAddress]->data.age << std::endl;
        }

        //The hashed index is occupied but the key collided. Go down the linked list to find the actual key.
        else if(hashtable[homeAddress] != NULL && hashtable[homeAddress]->data.key != key){
            Node* temp = hashtable[homeAddress];
            bool found = false;
            //Goes through the linked list to find the key.
            while(temp->next != NULL){
                temp = temp->next;
                if(temp->data.key == key){
                    found = true;
                    break;
                }
            }
            //If the key is found in the linked list, the information is printed out.
            if(found){
                std::cout << "Name: " << temp->data.name << std::endl;
                std::cout << "ID: " << temp->data.key << std::endl;
                std::cout << "Age: " << temp->data.age << std::endl;
            }
            else{
                std::cout << "Information was not found." << std::endl;
            }
        }

        //The hashed index is not yet occupied and does not point to any memory address.
        else{
            std::cout << "No Info" << std::endl;
            return;
        }
    }
    /**
     * @brief Adds a person structure to the array
     * @param person The person object to be added to the array
     */
    void storeInformation(const Person person){
        int homeAddress = hashFunction(person.key);
        //If the hashed index is not already occupied, store the person there.
        if(hashtable[homeAddress] == NULL){
            hashtable[homeAddress] = createNode(person);
        }
        //If the hashed index is occupied, call the chain function to resolve the collision.
        else{
            
            std::cout << "Collision at home address " << homeAddress << ". Resolving..." << std::endl;
            chain(person,homeAddress);
        }
    }
};



int main(){
    Hashtable<5> table;
    Person person;

    //Creating a person object
    person.name = "Daniel";
    person.key = "Akkdwppoee";
    person.age = 21;
    
    table.storeInformation(person);
    table.retrieveInformation(person.key);
    return 0;
}






