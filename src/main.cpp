#include <iostream>                  // for std::cout
#include <utility>                   // for std::pair
#include <string>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>

struct node_t
{
    std::string name;
    int data;
};

std::ostream& operator<<(std::ostream& ostr, const node_t& node)
{
    
    return ostr << "[label=\"City: " <<  node.name << "\\nAvg. Income: $" << node.data << ".00\"]";
}

int main(int,char*[])
{
    // create a typedef for the Graph type
    using graph_t = boost::adjacency_list< boost::vecS,
                                           boost::vecS,
                                           boost::bidirectionalS,
                                           node_t >;
    using graph_traits = boost::graph_traits<graph_t>;
    using edge_t = std::pair<node_t, node_t>;
                                           

    // Make convenient labels for the vertices
    enum { A, B, C, D, E, N };
    const char* name = "ABCDE";

    // writing out the edges in the graph
    std::clog << "Building edges...\n";
    std::array edge_array = { edge_t{{"Toronto, ON",   3500}, {"New York, NY",  4000}},
                              edge_t{{"Vancouver, BC", 3300}, {"San Diego, CA", 5000}},
                              edge_t{{"Austin, TX",    2000}, {"Calgary, AL",   2000}} };

    // declare a graph object
    graph_t g;

    // add the edges to the graph object
    std::clog << "Adding edges to graph...\n";
    for(auto edge : edge_array) {
        auto src_city = boost::add_vertex(edge.first, g);
        auto dst_city = boost::add_vertex(edge.second, g);
        boost::add_edge(src_city, dst_city, g);
    }

    std::clog << "Dumping vertices...\n";
    auto vertices = boost::vertices(g);
    boost::write_graphviz(std::cout, g, [&g](auto& ostr, const auto& v) {
        ostr << g[v];
    });
    std::cout << std::flush;
    return 0;
}
