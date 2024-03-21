#include <iostream>
#include <iomanip>

struct Edge {
    int start;
    int finish;
};

void printMatrix(int** matrix, const int numRows, const int numCols) {
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            std::cout << std::setw(2) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int** generateAdjacencyMatrix(const Edge* edges, const int numEdges, const int numVertices) {
    // початкова матриця з усіма нулями
    int** adjacencyMatrix = new int* [numVertices];
    for (int i = 0; i < numVertices; ++i) {
        adjacencyMatrix[i] = new int[numVertices]();
    }

    // ставимо одиниці для всіх дуг
    for (int i = 0; i < numEdges; ++i) {
        adjacencyMatrix[edges[i].start - 1][edges[i].finish - 1] = 1;
    }

    std::cout << "Adjacency Matrix:" << std::endl;
    printMatrix(adjacencyMatrix, numVertices, numVertices);

    return adjacencyMatrix;
}

void generateIncidenceMatrix(const Edge* edges, const int numEdges, const int numVertices) {
    // початкова матриця з усіма нулями
    int** incidenceMatrix = new int* [numVertices];
    for (int i = 0; i < numVertices; ++i) {
        incidenceMatrix[i] = new int[numEdges]();
    }

    // ставимо -1 на вершину, що є початком дуги, 1 - на кінець дуги
    for (int i = 0; i < numEdges; ++i) {
        incidenceMatrix[edges[i].start - 1][i] = -1;
        incidenceMatrix[edges[i].finish - 1][i] = 1;
    }

    std::cout << "Incidence Matrix:" << std::endl;
    printMatrix(incidenceMatrix, numVertices, numEdges);
}

void generateReachabilityMatrix(int** adjacencyMatrix, const int numVertices) {
    // створюємо матрицю досяжності на основі матриці суміжності (бо суміжні завжди досяжні)
    int** reachabilityMatrix = new int* [numVertices];
    for (int i = 0; i < numVertices; ++i) {
        reachabilityMatrix[i] = new int[numVertices];
        for (int j = 0; j < numVertices; ++j) {
            reachabilityMatrix[i][j] = adjacencyMatrix[i][j];
        }
    }

    // проставляємо 0 або 1 за допомогою алгоритма Флойда-Уоршелла
    for (int k = 0; k < numVertices; ++k) {
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                reachabilityMatrix[i][j] = reachabilityMatrix[i][j]
                    ? reachabilityMatrix[i][j]
                    : (reachabilityMatrix[i][k] && reachabilityMatrix[k][j]);
            }
        }
    }

    std::cout << "Reachability Matrix:" << std::endl;
    printMatrix(reachabilityMatrix, numVertices, numVertices);
}

int main() {
    Edge edges[] = {
            {1,  1},
            {1,  3},
            {2,  1},
            {2,  8},
            {2,  13},
            {3,  1},
            {3,  4},
            {3,  7},
            {3,  8},
            {4,  2},
            {4,  5},
            {4,  1},
            {5,  10},
            {5,  12},
            {6,  1},
            {6,  8},
            {6,  9},
            {6,  13},
            {7,  3},
            {7,  8},
            {8,  1},
            {8,  3},
            {8,  6},
            {8,  10},
            {9,  11},
            {10,  2},
            {10,  4},
            {11,  5},
            {11,  7},
            {11, 9},
            {12, 1},
            {12, 10},
            {13, 1},
            {13, 7}
    };

    const int edgesCount = sizeof(edges) / sizeof(Edge);
    int verticesCount = 0;
    for (int i = 0; i < edgesCount; ++i) {
        verticesCount = std::max(verticesCount, std::max(edges[i].start, edges[i].finish));
    }

    std::cout << "Count of verticies: " << verticesCount << ";\tCount of edges: " << edgesCount << ";"
        << std::endl << std::endl;

    int** adjacencyMatrix = generateAdjacencyMatrix(edges, edgesCount, verticesCount);
    std::cout << std::endl;
    generateIncidenceMatrix(edges, edgesCount, verticesCount);
    std::cout << std::endl;
    generateReachabilityMatrix(adjacencyMatrix, verticesCount);

    return 0;
}
