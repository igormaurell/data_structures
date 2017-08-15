#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

using namespace std;

namespace aedds{
template <class Node> 
class Vector{
	private:
		Node *nodes;
	
		int length;
		int s;
		int e;
		
		void move_right_i(int _p){
            int i;
            for(i = e;i>=_p;i--){
                nodes[i+1] = nodes[i];
            }
            e++;
            
        }
		void move_left_i(int _p){
            int i;
            for(i = s;i<=_p;i++){
                nodes[i-1] = nodes[i];
            }
            s--;
        }
		void move_right_r(int _p){
            int i;
            for(i = _p-1;i>=s;i--){
                nodes[i+1] = nodes[i];
            }
            s++;
        }
		void move_left_r(int _p){
            int i;
            for(i = _p;i<e;i++){
                nodes[i] = nodes[i+1];
            }
            e--;
        }
		
	public:
		Vector(): s(-1), e(-1), length(10){
	        nodes = new Node[length];
        }
		Vector(int _len): s(-1), e(-1), length(_len){
	        nodes = new Node[length];
        }
		
		int getSize(){
            return (e-s)+1;
        }
		
        Node& operator[](int _p){
	        return nodes[_p+s];
        }
		
		bool insert(int _p, Node _elem){
	        if(s==0 && e==length-1){
	            cout<<"Lista cheia."<<e<<endl;
	            return false;
	        }
	
	        if(_p<0 || _p>(e-s)+1){
		        cout<<"Posicao invalida para insercao."<<endl;
	            return false;
	        }
	
	        if(s==-1 && e==-1){
	            s = 0;
	            e = 0;
	            nodes[s] = _elem;
	            return true;	
	        }
	
	        int p = s+_p;
	        if(s==0 || _p-s<e-_p){
	            move_right_i(p);
	        }
	        else{
	            p--;
	            move_left_i(p);
	        }
	
            if(e==-1){
	            s=-1;
	        }
	
	        nodes[p] = _elem;
	        return true;	
        }
		
		void remove(int _p){
            if(s==-1 && e==-1){
	            cout<<"Lista Vazia."<<endl;
	            return;	
	        }
	
            if(_p<0 || _p>e){
		        cout<<"Posicao invalida para remocao."<<endl;
	            return;
	        }
	
	        if(s==0 && e==0){
	            s = -1;
				e = -1;
	            nodes[0] = Node();
	            return;
	        }
	
	        if(_p-s<e-_p){
	            move_right_r(_p);
	        }
	        else{
	            move_left_r(_p);
			}
        }

		friend ostream& operator<<(ostream& _out, Vector<Node> _l){
	        _out<<'[';
	        for(int i = _l.s;i<=_l.e && _l.s!=-1;i++){
		        if(i!=_l.e)_out<<_l.nodes[i]<<", ";
		        else _out<<_l.nodes[i];
	        }
	        _out<<']';
	        return _out;
        }
};
}

#endif //VECTOR_H
