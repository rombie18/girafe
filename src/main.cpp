#include <iostream>
#include <list>
#include <string>
#include "pugixml.hpp"
#include "Vertex.h"
#include "Graph.h"
#include "Edge.h"
#include "SensorNode.h"
#include "Algorithm.h"
#include "Exceptions.h"

using namespace std;

// CONSTANTS
// String definitions: these are necessary for the string.compare() method.
std::string graph_string ("graph");
std::string edge_string ("edge");
std::string vertex_string ("vertex");
std::string sensornode_string("sensornode");

Graph graph;

struct simple_walker: pugi::xml_tree_walker
{
    // Depth-first traversal
    // Source: https://pugixml.org/docs/quickstart.html#access
    // To perform a deep tree traversal, not just the immediate children of a node.
    virtual bool for_each(pugi::xml_node& node)
    {
        // If XML node is a vertex
        if(vertex_string.compare(node.name()) == 0) {

            // First check if the vertex en sensor node have a correct layout in the XML file
            if (!validXmlVertex(node)) {
                throw InvalidXmlException("A vertex node in the XML file has an invalid format.");
            }
            if (!validXmlSensornode(node.first_child())) {
                throw InvalidXmlException("A sensor node in the XML file has an invalid format.");
            }

            // Create new sensornode object and set attributes
            SensorNode* sensorNode = new SensorNode(
                    node.first_child().attribute("name").as_string(),
                    node.first_child().attribute("room").as_string(),
                    (rand() % 10) + 20,
                    (rand() % 30) + 40,
                    (rand() % 800) + 400
            );

            // Create new vertex object and set attributes
            Vertex<SensorNode>* vertex = new Vertex<SensorNode>();
            vertex->setId(node.attribute("id").as_int());
            vertex->setSensorNode(sensorNode);

            // Add vertex to graph by pointer
            graph.addVertexToList(vertex);

        // If XML node is an edge
        } else if(edge_string.compare(node.name()) == 0) {

            // First check if the edge node has a correct layout in the XML file
            if (!validXmlEdge(node)) {
                throw InvalidXmlException("An edge node in the XML file has an invalid format.");
            }

            // Get vertex objects from the graph by id
            Vertex<SensorNode>* vertex1;
            Vertex<SensorNode>* vertex2;
            for(Vertex<SensorNode>* vertex : graph.getVertices()) {
                if (vertex->getId() == node.attribute("vertex1").as_int()) {
                    vertex1 = vertex;
                }
                if (vertex->getId() == node.attribute("vertex2").as_int()) {
                    vertex2 = vertex;
                }
            }

            // Create new edge object and set attributes
            Edge* edge = new Edge();
            edge->setId(node.attribute("id").as_int());
            edge->setVertex1(vertex1);
            edge->setVertex2(vertex2);

            // Add edge to graph by pointer
            graph.addEdgeToList(edge);

        }

        // continue traversal
        return true;
    }
};

int main()
{
    try {
        // Pugi::xml initialization
        pugi::xml_document file;
        file.load_file("../../data/graph.graphml");

        // Make 'root' the root of the XML tree.
        // 'child("graph")' returns the first node which has that name "graph".
        pugi::xml_node root = file.child(
                "graph"); // 'root' contains a list of graphs. But in reality, there is only one graph. Therefore, let's make this one graph the root.

        // Use 'tree_walker' to step through the .graphml file.
        // Source: https://pugixml.org/docs/quickstart.html#access
        simple_walker tree_walker;
        file.traverse(tree_walker); // Start the XML tree traversal

        // The graph data should now be present in memory in the form of your graph data structure.


        // Get a specific startvertex from the vertices in the graph
        string startvertexroom = "E116";
        Vertex<SensorNode> *startVertex = nullptr;
        for (Vertex<SensorNode> *vertex: graph.getVertices()) {
            if (vertex->getSensorNode()->room == startvertexroom) {
                startVertex = vertex;
            }
        }
        if (startVertex == nullptr) {
            throw InvalidStartVertexException("De startvertex met " + startvertexroom + " als room atribuut bestaat niet.");
        }

        // Start Breadth First Search algorithm
        map<int, vector<Vertex<SensorNode>*>> vertices = bfs(&graph, startVertex);

        // Print all vertices by level
        cout << endl << "Levels:"<< endl;
        map<int, vector<Vertex<SensorNode>*>>::iterator i;
        for(i = vertices.begin(); i != vertices.end(); i++) {
            cout << "  Level " + to_string(i->first) + ":"<< endl;
            for(Vertex<SensorNode>* vertex : i->second) {
                cout << "    Vertex " + to_string(vertex->getId()) + ": " + vertex->getSensorNode()->room << endl;
            }
        }

        return 0;

    } catch (exception& e) {
        // In case of an exception, print the error in console
        cerr << e.what();
        return 1;
    }
}
