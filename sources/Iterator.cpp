#include "Iterator.hpp"

namespace ariel{
    Iterator::Iterator(){
        this->IterarorOrder = {};
        
    }
    Iterator::Iterator(string const & command, bool semiCommand, Node* root){
        if(root == NULL){
            throw runtime_error("ceto cant be null");
        }

        this->IterarorOrder = {};
        

        if(command == "level"){
            if(semiCommand){
                this->level(root,true);
            }
            else{
                this->level(root,false);
            }
        }
        else if(command == "pre"){
            this->preorder(root);
        }
        else if (command == "end"){
            this->IterarorOrder.push_back(nullptr);
        }
    }

    void Iterator::nullRoot(Node* testSUbject){
        Iterator x = *this;
        if(testSUbject == NULL){
            throw runtime_error("root is null");
        }
    }

    void Iterator::level(Node* initial, bool flag){
        this->nullRoot(initial);
        queue<Node*> q1 = {};
        queue<Node*> q2 = {};
        q1.push(initial);
        q2.push(initial);
        Node* c = NULL;
        while(!q1.empty())
        {
            //cout << "name: " << q1.front()->name <<endl;
            c = q1.front();
            q1.pop();
            if(flag){
                for (Node* child : c->subordinates)
                {
                    q1.push(child);
                    q2.push(child);
                }
            }
            else{
                vector<Node*> x = {};
                for (Node* child : c->subordinates)
                {
                    x.insert(x.begin(),child);
                }
                for (Node* child : x)
                {
                    q1.push(child);
                    q2.push(child);
                }
            }
           
        }

        while (!q2.empty()){
            if(flag){
                this->IterarorOrder.push_back(q2.front());
                q2.pop();
            }
            else{
                this->IterarorOrder.insert(this->IterarorOrder.begin(),q2.front());
                q2.pop();
            }
            
        }
    }

    void Iterator::normal_level_order(Node* initial){
        this->level(initial,true);
    }

    void Iterator::reverse_order(Node* initial){
        this->level(initial,false);
    }

    void Iterator::preorder(Node* initial){
        this->nullRoot(initial);
        queue<Node*> q1 = {};
        q1.push(initial);
        this->preorderAssist(initial,q1);

        while (!q1.empty()){
            this->IterarorOrder.push_back(q1.front());
                q1.pop();
            
        }
    }

    void Iterator::preorderAssist(Node* initial, queue<Node*>&q){
        if(initial == NULL){
            return;
        }

        for (Node* child : initial->subordinates)
        {
            q.push(child);
            this->preorderAssist(child,q);
        }

        
    }

    // //operator
    Iterator Iterator::operator++ (int){
        Iterator i = *this;
        if(!this->IterarorOrder.empty()){
            this->IterarorOrder.erase(this->IterarorOrder.begin());
        }
        if(this->IterarorOrder.empty()){
            this->IterarorOrder.push_back(nullptr);
        }
        return i;
    }

    Iterator& Iterator::operator++ (){
        
        if(!this->IterarorOrder.empty()){
            this->IterarorOrder.erase(this->IterarorOrder.begin());
        }
        if(this->IterarorOrder.empty()){
            this->IterarorOrder.push_back(nullptr);
        }
        return *this;
    }

    bool Iterator::operator== (const Iterator& iter2) const{
        return this->IterarorOrder[0] == iter2.IterarorOrder[0];
    }

    bool Iterator::operator!= (const Iterator& iter2) const{
        return !(*this==iter2);
    }

    string Iterator::operator* () const{
        if(this->IterarorOrder.empty()){
            return std::string();
        }
        return this->IterarorOrder[0]->name;
    }

    string* Iterator::operator-> () const{
        if(this->IterarorOrder.empty()){
            return NULL;
        }

        return &(this->IterarorOrder[0]->name);
    }
}