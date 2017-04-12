#include "../Body/View.cpp"


using namespace std;
using namespace Graph;

int main(int argc, char** argv)
{
    AdjacencyMatrix* am = new AdjacencyMatrix(6);

    am->AddEdge(0,1,-4);
    am->AddEdge(1,0,-2);

    am->AddEdge(1,2,-1);
    am->AddEdge(2,1,-7);
    am->AddEdge(2,3,-5);
    am->AddEdge(3,2,-3);

    am->AddEdge(3,4,-9);
    am->AddEdge(4,3,-3);

    am->AddEdge(4,5,-8);
    am->AddEdge(5,4,-8);

    am->AddEdge(5,0,-2);
    am->AddEdge(0,5,-5);

    am->PrintMatrix();
    am->PrintIsRegular();
    am->PrintIsNullGraph();
    am->PrintIsCompleteGraph();
    am->PrintGetDegree(1);
    am->PrintGetEnterDegree(1);
    am->PrintGetOutDegree(1);
    am->PrintHasLoop();
    am->PrintIsDirectioned();
    am->PrintIsConect();
    am->PrintGetComplement();
    am->PrintMatrix();
    am->PrintIsEulerGraph();
    am->PrintIsUnicursal();
    am->PrintIsCircular();
    am->PrintIsLonelyVertice(1);
    am->PrintIsPendingVertice(1);
    int path [7] = {0,1,2,3,4,5,0};
    am->PrintIsPath(path,7);
    am->PrintIsOpenPath(path,7);
    am->PrintIsClosePath(path,7);
    am->PrintIsBipartite();
    am->PrintIsCircuit(path,7);

    am->PrintTranspose();
    am->PrintBFS(5);
    am->PrintDFS(1);
    am->PrintBelmanFord(0,5);

    return 0;
}
