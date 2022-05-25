#pragma once
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include "OrgChart.hpp"

using namespace std;

namespace ariel{
    class Node;
    class OrgChart;
    class Iterator{
        public:
            Iterator();
            Iterator(string const &,bool,Node*);
            // //~Iterator();
            vector<Node*> IterarorOrder;


            Iterator& operator++ ();
            Iterator operator++ (int);

            bool operator== (const Iterator& iter2) const;
            bool operator!= (const Iterator& iter2) const;
            
            string operator* () const;
            string* operator-> () const;


            void nullRoot(Node*);
            void level(Node*,bool);
            void normal_level_order(Node*);
            void reverse_order(Node*);
            void preorder(Node*);
            void preorderAssist(Node*,queue<Node*>&);
    };
}