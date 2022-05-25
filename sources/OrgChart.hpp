#pragma once
#include <vector>
#include <string>
#include "Iterator.hpp"
#include <memory>

using namespace std;

namespace ariel{

    class Iterator;
    class Node{
        private:
            
        public:
            Node(Node*,string&);
            string name;
            vector<Node*> subordinates;
            Node* superior;
    };

    class OrgChart{
        private:
            Node* FindEmployee(Node*, string&);

        public:
            Node* root;
            OrgChart();
            OrgChart add_root(string);
            OrgChart add_sub(string,string);
            Iterator begin_level_order() const;
            Iterator end_level_order() const;
            Iterator begin_reverse_order() const;
            Iterator reverse_order() const;
            Iterator begin_preorder() const;
            Iterator end_preorder() const;

            Iterator begin() const;
            Iterator end() const;

            

            friend ostream& operator<<(ostream&, OrgChart&);

            

    };

}