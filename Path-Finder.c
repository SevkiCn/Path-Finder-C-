
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define N 12 //Number of nodes in graph (undirected)

/* @Author
Student Name: Sevki Can Sentuna
Student ID: 040180214
Date : 04.06.2021 */

int DFS(int); // function prototype

// Adjacency matrix
int graph_matrix[N][N]= {
//A       B       C       D       E       F       G       H       I       J       K       L
{ 0,      1,      0,      0,      0,      0,      0,      0,      0,      1,      1,      0 }, // A 0
{ 0,      0,      0,      0,      0,      0,      0,      0,      1,      0,      0,      0 }, // B 1
{ 0,      0,      0,      1,      0,      0,      0,      0,      0,      0,      0,      0 }, // C 2
{ 0,      0,      0,      0,      0,      1,      0,      0,      0,      0,      0,      0 }, // D 3
{ 1,      0,      1,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // E 4
{ 0,      0,      0,      0,      0,      0,      0,      1,      0,      0,      0,      1 }, // F 5
{ 0,      1,      0,      0,      0,      0,      0,      1,      0,      0,      0,      0 }, // G 6
{ 0,      0,      0,      1,      0,      0,      0,      0,      0,      0,      0,      0 }, // H 7
{ 0,      0,      0,      0,      0,      1,      0,      0,      0,      0,      1,      0 }, // I 8
{ 0,      0,      1,      1,      0,      0,      0,      0,      0,      0,      0,      0 }, // J 9
{ 0,      0,      0,      0,      1,      0,      1,      0,      0,      0,      0,      0 }, // K 10
{ 0,      0,      0,      0,      0,      0,      1,      0,      1,      0,      0,      0 }  // L 11
};

char node[12][10] = { // node names
"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L"};

int visited[N]; // Flag array to keep the status of nodes
int global_ending = 0; // global variable for ending node in order to be reachable by function
int j=0; // index variable for path_storage
int path_storage[N]; // array for storing the current updated path




/// Recursive Depth-First-Search function
int DFS(int x)
{



      visited[x] = TRUE; //Mark the x node as “visited”

      path_storage[j] = x; // Put the current variable to the path array.
      j = j+1;



      // Visit all nodes which are adjacent to node x, if they are unvisited.
      for(int i=0; i<N; i++)
      {

            if(x == global_ending){ // if ending node is found, finish the process.
                break;
                return 0;
           }

           // Check if there is a connection in graph (map) from node x
           // to node i, and node i was unvisited
           else if(graph_matrix [x][i] !=0 &&  ! visited [i] ){

                DFS(i);   // Recursive calling
                return 1;

            }

            /* If a visited node is encountered, recall the process until finding the next unvisited node. */
            else if (graph_matrix [x][i] !=0 && visited[i]){
                /// Delete the node from path array since it is not the node we want.
                j = j-1;
                path_storage[j] = 0;
                x = path_storage[j-1];

                /// Check the connections around the current node
                int counter = 0;
                for(int q = 0; q<N; q++){
                    if(graph_matrix[x][q] == 0)
                        counter = counter + 1;

                }
                /// If there is no unvisited node we can go, turn back previous node again.
                if (counter == N-1){
                    j = j-1;


                    path_storage[j] = 0;

                    x = path_storage[j-1];
                    continue;

                }




            }


       }
}

//-------------------------------------------------------- MAIN FUNCTION-----------------------------------------------------------//

int main()
{

        int i; //loop variable
        int starting = 0; // starting node index
        int ending = 0; // ending node index


       printf("RECURSIVE DEPTH-FIRST SEARCH METHOD\n\n");
       printf("NODES IN DIRECTED GRAPH:\n");

        /// Print available choices.
        for (i=0; i < N; i++)
            printf("%d. %s \n", i+1, node[i]);

       printf("Enter the numbers of both Starting and Ending nodes with a space between them : ");
       scanf("%d%d", &starting, &ending);

       global_ending = ending - 1; // Translating the ending index to global variable.


        for (i=0; i<N; i++)
             visited[i] = FALSE; //Initially all nodes are unvisited

       printf("\nSOLUTION PATH = \n");
       DFS(starting-1); // Array index starts from 0 in C

        /// Print all nodes in the path array one by one.
        int count = 0;
        for(int h=0; h<=j-1; h++){

            printf("%s  ", node[path_storage[h]]);

        }
        /* Fixing a bug when ending node is 'A' */

        if (ending == 1)
            printf("%s ", node[0]);
        printf("\n\n\n");






       system("pause");
       return 0;
}

