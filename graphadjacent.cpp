#include <iostream>
#include <vector>


//Creates a Undirected Weighted Graph
class Graph{
    private:
    struct Vertex{
        int index;    // Stores the index of the Node (Vertex)
        int weight;   // Stores the weight of the edge connected to another Node (Vertex)
        Vertex* next; // Stores the link to the next Vertex in the list
    };

    /**
     * @brief Creates an edge with the specified weight.
     * @param index The index of the Vertex
     * @param weight The weight of the edge
     * @return The newly created Edge
     */
    Vertex* createEdge(const int index, const int weight){
        Vertex* newEdge = new Vertex;
        newEdge->index = index;
        newEdge->weight = weight;
        newEdge->next = NULL;
        return newEdge;
    }

    Vertex** adjList;
    int vertices;

    public:

    /**
     * @brief Public Constructor
     * @param vertices Total number of vertices in the Graph
     */
    Graph(const int vertices){
        this->vertices = vertices;
        adjList = new Vertex*[vertices];
        for(int i = 0; i < vertices; i++){
            adjList[i] = NULL;
        }
    }


    /**
     * @brief Adds an edge to the Graph. If the specified vertices do not exist, nothing is done.
     * @param source The index of the starting vertex
     * @param destination The index of the ending vertex
     * @param weight The weight of the edge
     */

    void addEdge(const int source, const int destination, const int weight){
        if(source < 0 || source >= this->vertices || destination < 0 || destination >= this->vertices){
            std::cout << "Unable to add edge." << std::endl;
            return;
        }
        else{
            Vertex* newEdge;
            if(adjList[source] == NULL){
                adjList[source] = createEdge(destination, weight);
            }
            else{
                newEdge = createEdge(destination, weight);
                newEdge->next = adjList[source];
                adjList[source] = newEdge;
            }
            if(adjList[destination] == NULL){
                adjList[destination] = createEdge(source, weight);
            }
            else{
                newEdge = createEdge(source, weight);
                newEdge->next = adjList[destination];
                adjList[destination] = newEdge;
            }
        }
    }

    /**
     * @brief Removes edge from Graph
     * @param source Index of the starting vertex
     * @param destination Index of the ending vertex
     */ 
    void removeEdge(const int source, const int destination){
        if(source < 0 || source >= this->vertices || destination < 0 || destination >= this->vertices){
            std::cout << "Unable to remove edge." << std::endl;
            return;
        }
        else{
            if(adjList[source] != NULL && adjList[destination] != NULL){
                Vertex* temp = adjList[source];
                Vertex* deleteVertex;
                if(temp->index == destination){
                    adjList[source] = temp->next;
                    delete temp;
                    std::cout << "Edge Removed From Vertex " << source << std::endl;
                }
                else{   
                    while(temp != NULL){
                        if(temp->next->index == destination){
                            deleteVertex = temp->next;
                            temp->next = deleteVertex->next;
                            delete deleteVertex;
                            break;
                        }
                        else{
                            temp = temp->next;
                        }
                    }
                    std::cout << "Edge Removed From Vertex " << source << std::endl;
                }
                temp = adjList[destination];
                if(temp->index == source){
                    adjList[destination] = temp->next;
                    delete temp;
                    std::cout << "Edge Removed From Vertex " << destination << std::endl;
                } 
                else{
                    while(temp != NULL){
                        if(temp->next->index == source){
                            deleteVertex = temp->next;
                            temp->next = deleteVertex->next;
                            delete deleteVertex;
                            break;
                        }
                        else{
                            temp = temp->next;
                        }
                    }
                    std::cout << "Edge Removed From Vertex " << destination << std::endl;
                }
            } 
        }
    }


    /**
     * @brief Change the weight of an edge
     * @param source Index of the starting vertex
     * @param destination Index of the ending vertex
     * @param weight New weight
     */
    void changeEdgeWeight(const int source, const int destination, const int weight){
        if(source < 0 || source >= this->vertices || destination < 0 || destination >= this->vertices){
            std::cout << "Unable to change weight." << std::endl;
            return;
        }
        else{
            Vertex* temp = adjList[source];
            while(temp != NULL){
                if(temp->index == destination){
                    temp->weight = weight;
                    break;
                }
                temp = temp->next;
            }

            temp = adjList[destination];
            while(temp != NULL){
                if(temp->index == source){
                    temp->weight = weight;
                    break;
                }
                temp = temp->next;
            }
        }
    }


    /**
     * @brief Prints the edges of a specified vertex
     * @param vertex Index of the vertex
     */
    void printEdges(const int vertex){
        if(vertex >= 0 && vertex <= this->vertices){
            Vertex* temp = adjList[vertex];
            while(temp != NULL){
                std::cout << "Vertex: " << temp->index << "\nWeight: " << temp->weight << std::endl;
                std::cout << "------------------------" << std::endl;
                temp = temp->next;
            }
        }
    }
};


int main(){
    Graph g(4);
    g.addEdge(0,1,60);
    g.addEdge(0,2,90);
    g.addEdge(0,3,100);
    g.printEdges(0);
    g.removeEdge(0,2);
    g.printEdges(0);
    return 0;
}
