#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include "pugixml.hpp"
#include <stdexcept> // For throwing errors
#include "Vertex.h"
#include "Graph.h"
#include "Edge.h"
#include "SensorNode.h"

using namespace std;

// CONSTANTS
// String definitions: these are necessary for the string.compare() method.
string graph_string ("graph");
string edge_string ("edge");
string vertex_string ("vertex");
string sensornode_string("sensornode");

// Create an empty graph. This is needed due to the if statements that have nothing to do with 'if graph_string'.
// For example, the 'if edge_string' does not know about graph g.
Graph graph;

struct simple_walker: pugi::xml_tree_walker
{
    // Depth-first traversal
    // Source: https://pugixml.org/docs/quickstart.html#access
    // To perform a deep tree traversal, not just the immediate children of a node.
    virtual bool for_each(pugi::xml_node& node)
    {
        if(vertex_string.compare(node.name()) == 0) {
            // If XML node is a vertex

            Vertex* vertex = new Vertex();
            vertex->setId(node.attribute("id").as_int());


            string name = node.attribute("name").as_string();
            SensorNode* sensorNode = new SensorNode(
                    name,
                node.attribute("room").as_string(),
                (rand() % 10) + 20,
                (rand() % 30) + 40,
                (rand() % 800) + 400
           );

            vertex->setSensorNode(sensorNode);
            graph.addVertexToList(vertex);
        }
        else if(edge_string.compare(node.name()) == 0) {
            // If XML node is an edge

            // Je kan de id uitlezen met 'node.attribute("id").as_int()'. Analoog kan je bv. vertex1 uitlezen met 'node.attribute("vertex1").as_int()'.

            Edge* edge = new Edge();
            edge->setId(node.attribute("id").as_int());

            Vertex* vertex1;
            Vertex* vertex2;
            for(Vertex* vertex : graph.getVertices()) {
                if (vertex->getId() == node.attribute("vertex1").as_int()) {
                    vertex1 = vertex;
                }
                if (vertex->getId() == node.attribute("vertex2").as_int()) {
                    vertex2 = vertex;
                }
            }

            edge->setVertex1(vertex1);
            edge->setVertex2(vertex2);

            graph.addEdgeToList(edge);
        }

        cout << endl;

        return true; // continue traversal
    }
};


int main()
{

    // Pugi::xml initialization
    pugi::xml_document file;
    file.load_file("../../data/graph.graphml");


    // Make 'root' the root of the XML tree.
    // 'child("graph")' returns the first node which has that name "graph".
    pugi::xml_node root = file.child("graph"); // 'root' contains a list of graphs. But in reality, there is only one graph. Therefore, let's make this one graph the root.

    
    // Use 'tree_walker' to step through the .graphml file.
    // Source: https://pugixml.org/docs/quickstart.html#access
    simple_walker tree_walker;
    file.traverse(tree_walker); // Start the XML tree traversal

    // The graph data should now be present in memory in the form of your graph data structure.


    //cout << "BFS result: " + to_string(bfs(&graph)) + endl;

    Vertex* startVertex = nullptr;
    for(Vertex* vertex : graph.getVertices()) {
        if (vertex->getSensorNode()->room == "E116") {
            startVertex = vertex;
        }
    }

    list<Edge*> edges = graph.incidentEdges(startVertex);

    bfs(&graph, startVertex);


    //for(Vertex* vertex : graph.getVertices()){
    //    cout << vertex->getSensorNode()->name << endl;
    //    cout << vertex->getSensorNode()->room << endl;
    //    cout << vertex->getSensorNode()->temperature << endl;
    //}


    /*
    Graph graph;
    SensorNode sn1;
    SensorNode sn2;
    sn1.name = "Wout";
    sn2.name = "Daan";
    sn1.room = "E110";
    sn2.room = "E220";
    sn1.humidity = 0;
    sn2.humidity = 0;
    sn1.temperature = 0;
    sn2.temperature = 0;
    sn1.co2 = 0;
    sn2.co2 = 0;


    Vertex v1;
    Vertex v2;
    v1.setSensorNode(&sn1);
    v2.setSensorNode(&sn2);
    v1.setId(1);
    v2.setId(2);

    Edge edge;
    edge.setVertex1(&v1);
    edge.setVertex2(&v2);

    graph.addEdgeToList(&edge);
    graph.addVertexToList(&v1);
    graph.addVertexToList(&v2);

    cout << v1.getId() << endl;
    cout << v2.getId() << endl;
    cout << sn1.name << endl;
    cout << sn2.name << endl;
    */




    return 0;
}
