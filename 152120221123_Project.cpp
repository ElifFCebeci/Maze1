#include <iostream>
using std::cout;
using std::cin;
using std::endl;
//Size of the maze
const int N= 12;

//To change the size of the maze, you only need to modify the value of N,and to alter the maze itself, you just need to make changes on the maze.

// This function is a general DFS function used in pathfinding operations
bool pathfinding(int maze[][N],int a,int b,int N,int path[][2],int& p) {
   
    // Check if it is outside the maze
    if (a< 0||b< 0|| a>= N ||b>= N||maze[a][b]== 1) {
        return false;}
     
     //Check if the exit is found
    if (a== N - 1 && b== N - 1) {
        path[p][0]= a;
        path[p][1]= b;
        p++;
        return true;}
     
     // Temporarily mark the visited path 
    maze[a][b]= 1;

    // Add the current position to the path
    path[p][0]= a;
    path[p][1]= b;
    p++;

    // Call pathfinding function in right, left, up and down directions
    if (pathfinding(maze, a+ 1, b, N, path, p)|| pathfinding(maze, a, b+ 1, N, path, p)|| pathfinding(maze, a- 1, b, N, path, p)|| pathfinding(maze, a, b- 1, N, path, p)) {
        return true;}

    // If path is not found, remove the current position from the path
    p--;
    maze[a][b]= 0; // Undo the marking

    return false;}
    
// Function to print the path if found
void printPath(const int path[][2], int ThepathLength) {
    cout<< "Output Path"<<endl;
    cout<<"   |x|y|"<<endl;
    for (int i= 0; i< ThepathLength; i++) {
    cout<< "   (" << path[i][0]<< ","<<path[i][1] << ")"<<endl;}}

int main() {
//The upper left corner of the matrix is the entrance to the maze, and the lower right corner is the exit of the maze.
//Attention: For the code to work correctly, the number of rows and columns of the maze must be equal.
         //The maze array=>
   int arr[N][N] = {
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 1,1,1},
        {1, 0, 1, 1, 1, 1, 1, 1, 1, 1,1,1},
        {1, 0, 0, 0, 0, 1, 1, 1, 1, 1,1,1},
        {1, 1, 1, 1, 0, 1, 1, 1, 1, 1,1,1},
        {1, 1, 0, 0, 0, 0, 1, 1, 1, 1,1,1},
        {1, 0, 0, 1, 1, 0, 0, 0, 1, 1,1,1},
        {1, 1, 0, 1, 1, 0, 0, 1, 1, 1,1,1},
        {1, 1, 0, 0, 1, 1, 0, 0, 1, 1,1,1},
        {1, 1, 1, 1, 1, 1, 1, 0, 0, 1,1,1},
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 0,0,1},
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 1,1,1},
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 0,0,1}
   };
    // Keeping the found path
    int path[N*N][2]; 
    
    // Index to track the path
    int p = 0; 

    if (pathfinding(arr, 0, 0, N, path, p)) {
        printPath(path, p);} 
        else {
        cout<<"There is no path"<<endl;}

    return 0;
}