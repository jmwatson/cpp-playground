#include <iostream>
#include <fstream>
#include <string>


using namespace std;

// Finds the city with the minimum time value from the cities not yest visited
int FindMinIndex(int* times, bool* visited, int size)
{
  int min = INT32_MAX, min_index = -1;

  // Check all adjacent cities
  for (int adj = 0; adj < size; ++adj)
  {
    // Exclude already visited or if the time is higher than the current min
    if (!visited[adj] && times[adj] <= min)
    {
      // Set min to current time for adjacent city and index to track the index
      min = times[adj], min_index = adj;
    }
  }

  return min_index;
}

// Returns a list of the minimum time it takes to reach each city from the
// capital. With this list we can then just get the max time and that will tell
// us how long it takes to reach all cities from the capital. The one assumption
// we make here is that the capital is always node zero.
int* Dijkstra(int** adjMatrix, int size)
{
  int* times = new int[size];
  bool* visited = new bool[size];

  // Initialize arrays with values
  for (int i = 0; i < size; ++i)
  {
    times[i] = INT32_MAX;
    visited[i] = false;
  }

  // Time it takes to send to capital is zero
  times[0] = 0;

  // Find shortest path for all cities
  for (int count = 0; count < size - 1; ++count)
  {
    // Find the node with the minimum time from the set of cities not yet
    // visited and mark that city as visited.
    // minIndex is always equal to the capital in the first iteration.
    int minIndex = FindMinIndex(times, visited, size);
    visited[minIndex] = true;

    // Update time values of the adjacent cities if times through adjacent cities are lower
    for (int adj = 0; adj < size; ++adj)
    {
      if (!visited[adj] &&
          adjMatrix[minIndex][adj] != INT32_MAX &&
          times[minIndex] != INT32_MAX &&
          times[minIndex] + adjMatrix[minIndex][adj] < times[adj])
      {
        times[adj] = times[minIndex] + adjMatrix[minIndex][adj];
      }
    }
  }

  // Release memory for visited
  delete[] visited;
  
  return times;
}

// Finds the longest time it takes to reach a city from the capital which
// gives us the time to distribute the message throughout the graph
int FindMaxTime(int* times, int size)
{
  int max = times[0];

  for (int i = 1; i < size; ++i)
  {
    if (max < times[i])
    {
      max = times[i];
    }
  }

  return max;
}

// Moved initialization into it's own function
// We now have a matrix of size nxn
int** InitializeAdjacencyMatrix(int size)
{
  int** adjacencyMatrix = new int*[size];
  for (int i = 0; i < size; ++i)
  {
    adjacencyMatrix[i] = new int[size];
    for (int j = 0; j < size; ++j)
    {
      // Defaults get defined as zero because there is no connection to that city
      adjacencyMatrix[i][j] = INT32_MAX;
    }
  }

  return adjacencyMatrix;
}

// Lets build something that will take inputs and put them in an adjacency matrix
int** BuildAdjacencyMatrixFromFile(ifstream& fileHandle, int size)
{
  // Initialize matrix
  int** adjacencyMatrix = InitializeAdjacencyMatrix(size);
  adjacencyMatrix[0][0] = 0;

  // We are safe to skip the first row initialization since we can initialize it
  // as we go through the rest.
  for (int i = 1; i < size; ++i)
  {
    // This is a triangle so we only need to read so many values
    for (int j = 0; j < i; ++j)
    {
      string vector;
      fileHandle >> vector;

      if (vector != "x")
      {
        // Undirected graph so upper triangle values are the same as lower
        adjacencyMatrix[i][j] = adjacencyMatrix[j][i] = stoi(vector);
      }
    }

    // Cities have a time of zero to send messages to themselves
    adjacencyMatrix[i][i] = 0;
  }

  return adjacencyMatrix;
}

int main() {
  // Open file stream
  ifstream fileHandle("/home/coderpad/data/input.txt");

  // Get size from file
  int size;
  fileHandle >> size;

  int** adjacencyMatrix = BuildAdjacencyMatrixFromFile(fileHandle, size);

  int* times = Dijkstra(adjacencyMatrix, size);

  int finalTime = FindMaxTime(times, size);

  cout << "Final time taken: " << finalTime << endl;

  // Release memory allocation
  for (int i = 0; i < size; ++i)
  {
    delete[] adjacencyMatrix[i];
  }

  delete[] adjacencyMatrix;
  delete[] times;

  return 0;
}

/***
requirements:
X - 1 <= size <= 100
X - A(i,j) = time required to travel from i to j
X - -1 indicates a message cannot be sent to the city
X - diagonals will be 0 indicating it takes 0 time to send to itself
X - undirected adjacency matrix, A(i,j) = A(j,i)
***/

/***
Adjacency Matrix (size x size)
================
{ {a, b, c},
  {d, e, f},
  {g, h, i} }

sample input
============
first line is size, size = 5
{ {  x,  50,  30, 100,  10},
  { 50,   x,   5,  20,   x},
  { 30,   5,   x,  50,   x},
  {100,  20,  50,   x,  10},
  { 10,   x,   x,  10,   x} }

sample algorithm
================
A(0) > A(0) = 0
A(0) > A(1) = A(2) + 5
A(0) > A(2) = 30
A(0) > A(3) = A(4) + 10
A(0) > A(4) = 10

max(A(4), A(3), A(2), A(1), A(0)) = 35
***/

// Output minimum time required for message to traverse whole network. This is basically a shortest path to travese the graph.
