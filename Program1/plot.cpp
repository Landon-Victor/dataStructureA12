#include"Graph.h"
#include <igraph.h>
#include <fstream>
#include <stdlib.h>



bool Graph::plot(string filename1)
{
    igraph_t graph;
    igraph_empty(&graph, numNodes, IGRAPH_UNDIRECTED);
    //将图从邻接表的存储结构转为igraph的存储结构
    for (int i = 0; i < numNodes; ++i) {
        EdgeNode* edge = vertexNodes[i].firstEdge;
        while (edge != nullptr) {
            // 无向边只被添加一次
            if (i < edge->adjvex) {
                igraph_add_edge(&graph, i, edge->adjvex);
            }
            edge = edge->next;
        }
    }
    //将显示下标改为显示编号
    igraph_vector_t vertex_names;
    igraph_vector_init(&vertex_names, igraph_vcount(&graph)); 
    for (int i = 0; i < igraph_vcount(&graph); ++i) 
    {
        VECTOR(vertex_names)[i] = i+1; 
    }

    //编写dot文件
    std::ofstream file((filename1+".dot"));
    if (!file) {
        std::cerr << "无法打开文件!" << std::endl;
        return -1;
    }
    file << "graph G {" << std::endl;
    for (int i = 0; i < igraph_vcount(&graph); ++i)
    {
        file << "  " << i << " [label=\"" << VECTOR(vertex_names)[i] << "\"];" << std::endl;
    }
    for (int i = 0; i < igraph_ecount(&graph); ++i) {
        igraph_integer_t from, to;
        igraph_edge(&graph, i, &from, &to);
        file << "  " << from << " -- " << to << ";" << std::endl;
    }
    file << "}" << std::endl;
    file.close();

    //graphviz将dot文件转化为png文件
    string command = "dot -Tpng ";
    command += filename1+".dot";
    command += " -o ";
    command += filename1+".png";
    system(command.c_str());
    return 1;
}