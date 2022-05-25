#include "OrgChart.hpp"

namespace ariel{

    OrgChart::OrgChart(){
        this->root = NULL;
    }
    

    OrgChart OrgChart::add_root(string r){
        if(this-> root == NULL){
            this->root = new Node{NULL,r};
            
        }
        else{
            this->root->name = r;
            
        }
        return *this;

    }

    OrgChart OrgChart::add_sub(string a, string b){
        if(this->root == NULL){
            throw runtime_error("no ceo is found");
        }

        Node* emp = this->FindEmployee(this->root, a);
        if(emp == NULL){
            throw runtime_error("no employee with that name exists");
        }

        Node* newEmp = new Node{emp,b};
        emp->subordinates.push_back(newEmp);
        

        return *this;
    }

    Iterator OrgChart::begin_level_order() const{
        return Iterator("level",true,this->root);
    }

    Iterator OrgChart::end_level_order() const{
        return Iterator("end",true,this->root);
    }
    Iterator OrgChart::begin_reverse_order() const{
        return Iterator("level",false,this->root);
    }
    Iterator OrgChart::reverse_order() const{
        return Iterator("end",true,this->root);
    }
    Iterator OrgChart::begin_preorder() const{
        return Iterator("pre",true,this->root);
    }
    Iterator OrgChart::end_preorder() const{
        return Iterator("end",true,this->root);
    }

    Iterator OrgChart::begin() const{
        return Iterator("level",true,this->root);
    }

    Iterator OrgChart::end() const{
        return Iterator("end",true,this->root);
    }

    ostream& operator<<(ostream& COUT, OrgChart& org){
        if(org.root == NULL){
            return COUT;
        }
        Iterator p = org.begin_level_order();

        for(Node* n : p.IterarorOrder){
            cout << "worker name: " << n->name << ", worker's subordinates: ";
            for(Node* o : n->subordinates){
                cout << o->name << ", ";
            }
            cout << "\n";
        }

        return COUT;
        
    }

    Node::Node(Node* s, string& name){
        this->name = name;
        this->subordinates = {};
        this->superior = s;
    }

    Node* OrgChart::FindEmployee(Node* employee, string& searchTarget){
        if(employee->name == searchTarget){
            return employee;
        }
        for(Node* n : employee->subordinates){
            if(n->name == searchTarget){
                return n;
            }
            Node* currentCheck = this->FindEmployee(n,searchTarget);
            if(currentCheck != NULL){
                return currentCheck;
            }
        }
        return NULL;
    }
}