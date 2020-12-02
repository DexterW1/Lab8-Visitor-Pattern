#ifndef __SUB_H__
#define __SUB_H__

#include "Operator.h"
class Sub: public Operate {

	public:
		Sub(Base* left,Base* right): Operate(left,right) {};

		double evaluate(){
			return left->evaluate() - right->evaluate();
		}
		std::string stringify(){
			return "(" + left->stringify() +")" + "-"+ "(" + right->stringify() + ")";
		}
    Base* get_left() {return left;};
    Base* get_right(){return right;};
    void accept(CountVisitor* v){
             v->visit_sub();
     }
		Iterator* create_iterator(){return new BinaryIterator(this)}
};
#endif //__SUB_H__  
