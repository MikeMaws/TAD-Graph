#include "../Head/AdjacencyMatrix.h"

using namespace std;

namespace Graph
{
  //constructor 1 - make generic matrix 5x5
  AdjacencyMatrix::AdjacencyMatrix()
  {
    numVertices = 5;
    matrixAdj = (edge*) malloc(25 * sizeof(edge));
    enterDegreeVertice =(int*) malloc(numVertices * sizeof(int));
    outDegreeVertice =(int*) malloc(numVertices * sizeof(int));
    for (int i = 0; i < numVertices; i++)
    {
      for (int j = 0; j < numVertices; j++)
      {
        matrixAdj[i*numVertices + j].hasEdge =false;
        matrixAdj[i*numVertices + j].value = 0;
      }

      enterDegreeVertice[i] = 0;
      outDegreeVertice[i] = 0;
    }
  }

  //constructor 2 - make matrix numVertices x numVertices
  AdjacencyMatrix::AdjacencyMatrix(int numVertices)
  {
    this->numVertices = numVertices;
    matrixAdj = (edge*) malloc((numVertices * numVertices) * sizeof(edge));
    enterDegreeVertice =(int*) malloc(numVertices * sizeof(int));
    outDegreeVertice =(int*) malloc(numVertices * sizeof(int));
    for (int i = 0; i < numVertices; i++)
    {
      for (int j = 0; j < numVertices; j++)
      {
        matrixAdj[i*numVertices + j].hasEdge = false;
        matrixAdj[i*numVertices + j].value = 0;
      }

      enterDegreeVertice[i] = 0;
      outDegreeVertice[i] = 0;
    }
  }

  // Add edge between the vector1(v1) and vector2(v2) with value(value);
  void AdjacencyMatrix::AddEdge(int v1,int v2, int value)
  {
    matrixAdj[v1* numVertices + v2].hasEdge = true;
    matrixAdj[v1* numVertices + v2].value = value;
    outDegreeVertice[v1]++;
    enterDegreeVertice[v2]++;
  }

  // Delete edge between the vector1(v1) and vector2(v2)
  void AdjacencyMatrix::DeleteEdge(int v1,int v2)
  {
    matrixAdj[v1 * numVertices + v2].hasEdge = EMPTY;
    matrixAdj[v1 * numVertices + v2].value = 0;

    if (enterDegreeVertice[v2] > 0)
    enterDegreeVertice[v2]--;

    if (outDegreeVertice[v1] > 0)
    outDegreeVertice[v1]--;
  }

  // checks for edges between the vector1(v1) and vector2(v2)
  bool AdjacencyMatrix::HasEdge(int v1, int v2)
  {
    return  matrixAdj [v1 * numVertices + v2].hasEdge;
  }

  // checks Regular Graph
  bool AdjacencyMatrix::IsRegular()
  {
    int grau1,grau2;
    for (int i = 1; i < numVertices; i++)
    {
      grau1 = enterDegreeVertice[i-1] + outDegreeVertice[i-1];
      grau2 = enterDegreeVertice[i] + outDegreeVertice[i];
      if (grau1 != grau2)
      return false;
    }
    return true;
  }

  // check Null graph
  bool AdjacencyMatrix::IsNullGraph()
  {
    int grau;
    for(int i = 0; i < numVertices; i++)
    {
      grau = enterDegreeVertice[i] + outDegreeVertice[i];
      if (grau != 0)
      return false;
    }
    return true;
  }

  //check Complete graph
  bool AdjacencyMatrix::IsComplete()
  {
    bool roundEdge;
    //checks for edge
    for (int i = 0; i < numVertices ; i++)
    {
      for (int j = i+1; j < numVertices ; j++)
      {
        roundEdge = matrixAdj[i*numVertices+j].hasEdge == matrixAdj[j*numVertices+i].hasEdge == 1;
        if (roundEdge)
        return false;
      }
    }
    return true;
  }

  // add new vertice in matrix
  void AdjacencyMatrix::AddVertice()
  {
    ++numVertices;
    edge *aux = (edge*) malloc( numVertices * numVertices * sizeof(edge));

    for(int i = 0; i< numVertices-1; i++)
    {
      for(int j = 0; j< numVertices-1; j++)
      {
        aux[i*numVertices+j] = matrixAdj[i*(numVertices-1)+j];
      }
    }
    matrixAdj = aux;

    aux = NULL;
    free(aux);
  }

  // delete vertice
  void AdjacencyMatrix::DeleteVertice(int delVertice)
  {
    -- numVertices;
    edge *aux = (edge*) malloc( numVertices * numVertices * sizeof(edge));

    int jumpLin = 0;
    int jumpCol = 0;

    // copy to aux jumping the position [delvertice] colunm and line
    for(int i = 0; i< numVertices; i++)
    {
      if(i == delVertice)
      jumpLin = 1;

      for(int j = 0; j< numVertices; j++)
      {
        if (j == delVertice)
        jumpCol = 1;

        aux[i*numVertices+j] = matrixAdj[ (i + jumpLin) * (numVertices + 1) + (j + jumpCol)];
      }
      jumpCol = 0;
    }

    matrixAdj = aux;
    aux = NULL;
    free(aux);
  }

  // get vertice degree
  short AdjacencyMatrix::GetDegree(int vertice)
  {
    if (!IsDirectioned())
    return enterDegreeVertice[vertice];
    else
    return -1;
  }

  // get vertice enter degree
  short AdjacencyMatrix::GetEnterDegree(int vertice)
  {
    if (IsDirectioned())
    return enterDegreeVertice[vertice];
    else
    return -1;
  }

  // get vertice out degree
  short AdjacencyMatrix::GetOutDegree(int vertice)
  {
    if (IsDirectioned())
    return outDegreeVertice[vertice];
    else
    return -1;
  }

  // check has loop
  bool AdjacencyMatrix::HasLoop()
  {
    for(int i = 0; i<numVertices; i++)
    {
      if (matrixAdj[i * numVertices + i].hasEdge)
      return true;
    }
    return false;
  }

  // check is directioned
  bool AdjacencyMatrix::IsDirectioned()
  {
    for(int i = 0; i< numVertices; i++)
    {
      for(int j = i+1; j< numVertices; j++)
      {
        if (!(matrixAdj[i * numVertices + j].hasEdge == matrixAdj[j * numVertices + i].hasEdge))
        return true;
      }
    }
    return false;
  }

  // check is connect
  bool AdjacencyMatrix::IsConnect()
  {
    if (IsNullGraph())
    return false;

    bool * visitedVertice = (bool*) malloc(numVertices*sizeof(bool));
    for (int i = 0; i < numVertices ; i++)
    {
      visitedVertice[i] = 0;
    }
    int result = GetNComponents(0,visitedVertice);

    visitedVertice = NULL;
    free(visitedVertice);

    return result > 1 ? 0 : 1;
  }

  // check is lonely
  bool AdjacencyMatrix::IsLonelyVertice(int vertice)
  {
    return (GetEnterDegree(vertice) + GetOutDegree(vertice)) == 0;
  }

  // check is pending
  bool AdjacencyMatrix::IsPendingVertice(int vertice)
  {
    return (!IsDirectioned() && (GetDegree(vertice) == 1));
  }

  //check is path
  bool AdjacencyMatrix::IsPath(int* path,int n)
  {
    for(int i = 1; (i < n); i++)
    {
      if(!HasEdge(path[i-1],path[i]))
      return false;
    }
    return true;
  }

  //check is open path
  bool AdjacencyMatrix::IsOpenPath(int* path , int n)
  {
    return (IsPath(path, n)) && (path[0] != path[n-1]);
  }

  //check is close path
  bool AdjacencyMatrix::IsClosePath(int* path , int n)
  {
    return (IsPath(path, n)) && (path[0] == path[n-1]);
  }

  // search conections
  int AdjacencyMatrix::GetNComponents(int vertice,bool* visitedVertice)
  {
    int nComponents = 1;
    visitedVertice[vertice] = 1;

    //explore adj vertices
    for (int j = 0; j < numVertices; j++)
    {
      if (this -> matrixAdj[vertice*numVertices + j].hasEdge && visitedVertice[j] == 0)
      nComponents = GetNComponents(j,visitedVertice);
    }

    // check visit all vertices
    for (int i = 0; i < numVertices; i++)
    {
      if (visitedVertice[i] == 0)
      {

        visitedVertice[i] = 1;
        nComponents += GetNComponents(i,visitedVertice);
        i = numVertices;
      }
    }

    return nComponents;
  }

  //get complement graph
  AdjacencyMatrix* AdjacencyMatrix::GetComplement()
  {
    AdjacencyMatrix* resp = new AdjacencyMatrix(numVertices);

    for(int i = 0; i < numVertices; i++)
    {
      for(int j = 0; j < numVertices; j++)
      {
        if (i != j)
        {
          bool aux = !matrixAdj[i*numVertices + j].hasEdge;
          if (aux == 1)
          resp-> AddEdge(i,j,1);
        }
      }
    }
    return resp;
  }

  // check isEulerGraph
  bool AdjacencyMatrix::IsEulerGraph()
  {
    int value = 0;
    int pos1 = -1;
    int pos2 = -1;
    int degree;
    bool check;

    //check Connect
    if (!IsConnect() || IsNullGraph())
    return false;

    //check parity
    for (int i = 0; i < numVertices; i++)
    {
      degree = enterDegreeVertice[i] + outDegreeVertice[i];
      check = !(degree % 2 == 0);
      value += check;

      if (check)
      {
        if (pos1 == -1)
        pos1 = i;

        else if (pos2 == -1)
        pos2 = i;
      }
    }

    if(value == 0) // check all parity
    return true;

    else if (value != 2) //check has 2 odds
    return false;

    else if(HasEdge(pos1,pos2))// check hasEdge between oods
    return true;

    else
    return false;
  }

  // check isEulerGraph
  bool AdjacencyMatrix::IsUnicursal()
  {
    int value = 0;
    int pos1 = -1;
    int pos2 = -1;
    int degree;
    bool check;


    //check Connect
    if (!IsConnect() ||IsNullGraph())
    return false;

    //check parity
    for (int i = 0; i < numVertices; i++)
    {
      degree = enterDegreeVertice[i]+outDegreeVertice[i];
      check = !(degree % 2 == 0);
      value += check;

      if (check)
      {
        if (pos1 == -1)
        pos1 = i;

        else if (pos2 == -1)
        pos2 = i;
      }
    }

    if(value == 0) // check all parity
    return false;

    else if (value != 2) //check has 2 odds
    return true;

    else if(HasEdge(pos1,pos2))// check hasEdge between oods
    return false;

    else
    return true;
  }

  //check is Bipartite
  bool AdjacencyMatrix::IsBipartite()
  {
    int colors[numVertices];
    int currentVertice;
    memset(colors, 0, numVertices*sizeof(int));

    colors[0] = 1;
    queue <int> verticesToVisit;
    verticesToVisit.push(0);

    while(!verticesToVisit.empty())
    {
      currentVertice = verticesToVisit.front();
      verticesToVisit.pop();

      for(int j = 0; j < numVertices; j++)
      {
        if(matrixAdj[currentVertice * numVertices + j].hasEdge)
        {
          if(colors[j] == 0)
          {
            colors[j] = colors[currentVertice] == 1? 2:1;
            verticesToVisit.push(j);
          }
          else if(colors[j] == colors[currentVertice])
          return false;
        }
      }
    }
    return true;
  }

  //check is Circuit
  bool AdjacencyMatrix::IsCircuit(int* vertices, int n)
  {
    if (!IsClosePath(vertices,n))
    return false;

    bool frequency[numVertices];

    for (int i = 0; i < numVertices; i++)
    frequency[i] = 0;

    for(int i = 0; i < n; i++)
    {
      if(vertices[i] < numVertices)
      frequency[vertices[i]] = 1;
      else
      return false;
    }

    for(int i = 0; i < numVertices; i++)
    {
      if (!frequency[i])
      return false;
    }
    return true;
  }

  //make transpose
  AdjacencyMatrix* AdjacencyMatrix::Transpose()
  {
    AdjacencyMatrix* resp = new AdjacencyMatrix(numVertices);
    if(IsDirectioned())
    {
      for(int i = 0; i < numVertices; i++)
      {
        for(int j = i+1; j < numVertices; j++)
        {
          if (matrixAdj[i*numVertices+j].hasEdge)
          resp -> AddEdge(j,i,matrixAdj[i*numVertices+j].value);

          if (matrixAdj[j*numVertices+i].hasEdge)
          resp -> AddEdge(i,j,matrixAdj[j*numVertices+i].value);
        }
      }
    }
    return resp;
  }

  //BFS
  queue<int> AdjacencyMatrix::BFS(int vector)
  {
    queue <int> verticesToVisit;
    queue <int> orderVisitedVertices;
    bool visitedVertices[numVertices];

    int currentVertice;

    for(int i = 0; i < numVertices; i++)
    visitedVertices[i] = 0;

    //initial vertice
    visitedVertices[vector] = 1;
    verticesToVisit.push(vector);

    while(!verticesToVisit.empty())
    {
      currentVertice = verticesToVisit.front();
      for (int i = 0; i < numVertices; i++)
        if (matrixAdj[currentVertice * numVertices + i].hasEdge == 1 && visitedVertices[i] == 0)
        {
          verticesToVisit.push(i);
          visitedVertices[i] = 1;
        }

      orderVisitedVertices.push(currentVertice);
      verticesToVisit.pop();
    }

    return orderVisitedVertices;
  }

  // DFS
  queue<int> AdjacencyMatrix::DFS(int vertice)
  {
    bool visitedVertices[numVertices];
    queue <int> orderVisitedVertices;

    for (int i = 0; i < numVertices; i++)
    visitedVertices[i] = 0;

    orderVisitedVertices = visit(vertice,visitedVertices,orderVisitedVertices);

    return orderVisitedVertices;
  }

  // DFS Visit
  queue<int> AdjacencyMatrix::visit(int vertice, bool* visitedVertices,queue<int> order)
  {
    visitedVertices[vertice] = 1;
    order.push(vertice);

    for(int i = 0; i < numVertices; i++)
      if(visitedVertices[i] == 0 && matrixAdj[vertice * numVertices + i].hasEdge)
        order = visit(i, visitedVertices,order);

    return order;
  }

  // circular graph
  bool AdjacencyMatrix::IsCircular()
  {
    if (IsConnect() && IsEulerGraph() && IsBipartite())
    {
      for (int i = 0; i < numVertices; i++)
        if(!(enterDegreeVertice[i] == 2))
          return false;

      return true;
    }
    return false;
  }

  //BellmanFord
  int AdjacencyMatrix::BellmanFord(int begin, int end)
  {
    int dists[numVertices];
    int cmp[numVertices];

    for(int i = 0; i < numVertices; i++)
    {
      dists[i] = MAXINT;
      cmp[i] = 0;
    }

    dists[begin] = 0; // start position

    for(int c = 1; c <= numVertices -1; c++)
      BellmanFordPass(dists);

    memcpy(&cmp, &dists, sizeof(dists));

    BellmanFordPass(dists);

    for(int i = 0; i < numVertices; i++)
      if(dists[i] != cmp[i])
        return -1;

    return dists[end];
  }

  void AdjacencyMatrix::BellmanFordPass(int* data)
  {
    for(int i = 0; i < numVertices; i++)
      if(data[i] < MAXINT)
        for(int j = 0; j < numVertices; j++)
          if(matrixAdj[i * numVertices + j].hasEdge)
            if(matrixAdj[i * numVertices + j].value + data[i] < data[j])
              data[j] = matrixAdj[i * numVertices + j].value + data[i];
  }

  AdjacencyMatrix::~AdjacencyMatrix()
  {
    matrixAdj = NULL;
    free(matrixAdj);
  }
}
