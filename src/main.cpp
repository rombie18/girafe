#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include "pugixml.hpp"
#include <stdexcept> // For throwing errors


// CONSTANTS
// String definitions: these are necessary for the string.compare() method.
std::string graph_string ("graph");
std::string edge_string ("edge");
std::string vertex_string ("vertex");
std::string sensornode_string("sensornode");

// Create an empty graph. This is needed due to the if statements that have nothing to do with 'if graph_string'.
// For example, the 'if edge_string' does not know about graph g.
// TODO, studenten: maak hier nieuwe grafe aan.


struct simple_walker: pugi::xml_tree_walker
{
    // Depth-first traversal
    // Source: https://pugixml.org/docs/quickstart.html#access
    // To perform a deep tree traversal, not just the immediate children of a node.
    virtual bool for_each(pugi::xml_node& node)
    {
        if(vertex_string.compare(node.name()) == 0) {
            // If XML node is a vertex

            // TODO, studenten: Maak hier een nieuwe vertex en verwerk deze (ken bv. id toe). Voeg op het einde deze vertex toe aan de grafe.
            // Je kan de id uitlezen met 'node.attribute("id").as_int()'. Analoog kan je bv. vertex1 uitlezen met 'node.attribute("vertex1").as_int()'.
        }
        else if(edge_string.compare(node.name()) == 0) {
            // If XML node is an edge

            // TODO, studenten: Maak hier een nieuwe vertex en verwerk deze (ken bv. id toe). Voeg op het einde deze vertex toe aan de grafe.
            // Je kan de id uitlezen met 'node.attribute("id").as_int()'. Analoog kan je bv. vertex1 uitlezen met 'node.attribute("vertex1").as_int()'.
        }

        std::cout << std::endl;

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


    std::cin.get();
    return 0;
}