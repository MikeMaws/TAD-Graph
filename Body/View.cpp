#include "AdjacencyMatrix.cpp"

using namespace std;

namespace Graph
{
  //Print matrixAdj Edge link
  void AdjacencyMatrix::PrintMatrix()
  {
    int i,j;

    printf("\n   ");
    for(i = 0; i< this->numVertices; i++)
    {
      if(i < 10)
      printf(" 0%d", i);
      else
      printf(" %d", i);
    }
    printf("\n");

    printf("   ");
    for(i = 0; i< this->numVertices*3; i++)
    printf("-");
    printf("-\n");

    for(i = 0; i< this->numVertices; i++)
    {
      if(i<10)
      printf("0%d|",i);
      else
      printf("%d|",i);
      for(j = 0; j < this->numVertices; j++)
      {
        printf("  %d", this->matrixAdj[i * this->numVertices + j].hasEdge);
      }
      printf("\n");
    }
    printf("\n");
  }

  //Print isRegular
  void AdjacencyMatrix::PrintIsRegular()
  {
    printf("It's a regular graph? : ");
    PrintYesNo(this -> IsRegular());
  }

  //Print isNullGraph
  void AdjacencyMatrix::PrintIsNullGraph()
  {
    printf("It's a null graph? : ");
    PrintYesNo(this -> IsNullGraph());
  }

  //Print isCompleteGraph
  void AdjacencyMatrix::PrintIsCompleteGraph()
  {
    printf("It's a complete graph? : ");
    PrintYesNo(this -> IsComplete());
  }

  //Print DegreeVertice
  void AdjacencyMatrix::PrintGetDegree(int vector)
  {
    int degree = GetDegree(vector);
    printf("Degree vector %d = ",vector);
    if (degree == -1)
    printf("it's a directioned graph.\n\n");
    else
    printf(" %d. \n\n",degree);
  }

  //Print EnterDegreeVertice
  void AdjacencyMatrix::PrintGetEnterDegree(int vector)
  {
    int enterDegree = GetEnterDegree(vector);
    printf("Enter Degree vector %d = ",vector);
    if (enterDegree == -1)
    printf("it's not a directioned graph.\n\n");
    else
    printf(" %d. \n\n",enterDegree);
  }

  //Print EnterDegreeVertice
  void AdjacencyMatrix::PrintGetOutDegree(int vector)
  {
    int outDegree = GetOutDegree(vector);
    printf("Out Degree vector %d = ",vector);
    if (outDegree == -1)
    printf("it's not a directioned graph.\n\n");
    else
    printf(" %d. \n\n",outDegree);
  }

  //Print loop occurrence
  void AdjacencyMatrix::PrintHasLoop()
  {
    printf("Have Loop? : ");
    PrintYesNo(this -> HasLoop());
  }

  //Print type graph
  void AdjacencyMatrix::PrintIsDirectioned()
  {
    printf("It's a directioned graph? : ");
    PrintYesNo(this -> IsDirectioned());
  }

  //Print IsConnect
  void AdjacencyMatrix::PrintIsConect()
  {
    printf("It's a Connect graph? : ");
    PrintYesNo(this -> IsConnect());
  }

  //Print IsCircular
  void AdjacencyMatrix::PrintIsCircular()
  {
    printf("It's a Circular graph? : ");
    PrintYesNo(this -> IsCircular());
  }

  // Print yes or no
  void AdjacencyMatrix::PrintYesNo(bool value)
  {
    value ? printf("YES.\n\n") : printf("NO.\n\n");
  }

  //Print complement graph
  void AdjacencyMatrix::PrintGetComplement()
  {
    printf("complement graph : \n ");
    GetComplement() -> PrintMatrix();
  }

  //Print isEulerGraph
  void AdjacencyMatrix::PrintIsEulerGraph()
  {
    printf("It's a Euler graph? : ");
    PrintYesNo(this -> IsEulerGraph());
  }

  //Print isEulerGraph
  void AdjacencyMatrix::PrintIsUnicursal()
  {
    printf("It's a Unicursal graph? : ");
    PrintYesNo(this -> IsUnicursal());
  }

  //Print isLonely
  void AdjacencyMatrix::PrintIsLonelyVertice(int vertice)
  {
    printf("Vertice %d is a lonely Vertice? : ",vertice);
    PrintYesNo(this -> IsLonelyVertice(vertice));
  }

  //Print isPending
  void AdjacencyMatrix::PrintIsPendingVertice(int vertice)
  {
    printf("Vertice %d is a Pending Vertice? : ",vertice);
    PrintYesNo(this -> IsPendingVertice(vertice));
  }

  //Print isPath
  void AdjacencyMatrix::PrintIsPath(int* path,int n)
  {
    printf("Has path ->");
    for (int i = 0; i < n; i++)
    printf(" %d",path[i]);

    printf(" ? : ");
    PrintYesNo(this -> IsPath(path,n));
  }

  //Print isOpenPath
  void AdjacencyMatrix::PrintIsOpenPath(int* path,int n)
  {
    printf("Has open path ->");
    for (int i = 0; i < n; i++)
    printf(" %d",path[i]);

    printf(" ? : ");
    PrintYesNo(this -> IsOpenPath(path,n));
  }

  //Print isClosePath
  void AdjacencyMatrix::PrintIsClosePath(int* path,int n)
  {
    printf("Has close path ->");
    for (int i = 0; i < n; i++)
    printf(" %d",path[i]);

    printf(" ? : ");
    PrintYesNo(this -> IsClosePath(path,n));
  }

  //Print isBipartite
  void AdjacencyMatrix::PrintIsBipartite()
  {
    printf("It's a Bipartite graph? : ");
    PrintYesNo(this -> IsBipartite());
  }

  //Print isCircuit
  void AdjacencyMatrix::PrintIsCircuit(int* vectors,int n)
  {
    printf("Has circuit ->");
    for (int i = 0; i < n; i++)
    printf(" %d",vectors[i]);

    printf(" ? : ");
    PrintYesNo(this -> IsCircuit(vectors,n));
  }

  //Print transpose graph
  void AdjacencyMatrix::PrintTranspose()
  {
    printf("transpose graph : ");
    if(!IsDirectioned())
    printf("it's not a directioned graph.\n\n");
    else
    Transpose() -> PrintMatrix();
  }

  //Print BFS
  void AdjacencyMatrix::PrintBFS(int vector)
  {
    printf("BFS order : ");
    if (vector >= numVertices || vector < 0)
    printf("Invalid start vector");
    else
    {
      queue<int> order =  BFS(vector);
      while(!order.empty())
      {
        printf("%d ",order.front());
        order.pop();
      }
    }
    printf("\n\n");
  }

  //Print DFS
  void AdjacencyMatrix::PrintDFS(int vector)
  {
    printf("DFS order : ");
    if (vector >= numVertices || vector < 0)
    printf("Invalid start vector");
    else
    {
      queue<int> order =  DFS(vector);
      while(!order.empty())
      {
        printf("%d ",order.front());
        order.pop();
      }
    }
    printf("\n\n");
  }

  //Print BellmanFord
  void AdjacencyMatrix::PrintBelmanFord(int begin,int end)
  {
    printf("BellmanFord path : ");
    int result = BellmanFord(begin,end);
    if(result == -1)
    printf("Graph contains a negative-weight cycle.\n\n");
    else
    printf("%d\n",result);
  }

}
