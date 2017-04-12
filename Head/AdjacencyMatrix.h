#include  <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <queue>

#define EMPTY 0
#define MAXINT 2147483647


namespace Graph
{
  class AdjacencyMatrix
  {
    struct edge
    {
      bool hasEdge;    // active or desactive Edge
      int value;       // value edge
      edge() : hasEdge(EMPTY),value(EMPTY){};
    };

  private:
    int numVertices;         //num vertices in Graph
    int *enterDegreeVertice; //enter degree vertices
    int *outDegreeVertice;   //out degree vertices
    edge *matrixAdj;        // matrix edgs

    bool HasEdge(int,int);
    bool HasLoop();
    bool IsBipartite();
    bool IsCircuit(int*,int);
    bool IsCircular();
    bool IsClosePath(int*,int);
    bool IsComplete();
    bool IsConnect();
    bool IsDirectioned();
    bool IsEulerGraph();
    bool IsLonelyVertice(int);
    bool IsNullGraph();
    bool IsOpenPath(int*,int);
    bool IsPath(int*,int);
    bool IsPendingVertice(int);
    bool IsRegular();
    bool IsUnicursal();

    int GetNComponents(int,bool*);
    int  BellmanFord(int,int);

    short GetDegree(int);
    short GetEnterDegree(int);
    short GetOutDegree(int);

    std::queue<int> BFS(int);
    std::queue<int> DFS(int);
    std::queue<int> visit(int,bool*,std::queue<int>);

    void BellmanFordPass(int*);

    AdjacencyMatrix* GetComplement();
    AdjacencyMatrix* Transpose();

  public:

    //constructors ================
    AdjacencyMatrix();
    AdjacencyMatrix(int);

    //makers ======================
    void AddEdge(int,int,int);
    void AddVertice();
    void DeleteEdge(int,int);
    void DeleteVertice(int);

    //prints ======================
    void PrintMatrix();
    void PrintYesNo(bool);
    void PrintIsRegular();
    void PrintIsCircular();
    void PrintIsNullGraph();
    void PrintIsCompleteGraph();
    void PrintGetDegree(int);
    void PrintGetEnterDegree(int);
    void PrintGetOutDegree(int);
    void PrintHasLoop();
    void PrintIsDirectioned();
    void PrintIsConect();
    void PrintGetComplement();
    void PrintIsEulerGraph();
    void PrintIsUnicursal();
    void PrintIsLonelyVertice(int);
    void PrintIsPendingVertice(int);
    void PrintIsPath(int*,int);
    void PrintIsOpenPath(int*,int);
    void PrintIsClosePath(int*,int);
    void PrintIsBipartite();
    void PrintIsCircuit(int*,int);
    void PrintTranspose();
    void PrintBFS(int);
    void PrintDFS(int);
    void PrintBelmanFord(int,int);

    ~AdjacencyMatrix();
  };
}
