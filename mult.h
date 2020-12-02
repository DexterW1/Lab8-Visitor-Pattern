#ifndef __Mult_H__
#define __Mult_H__

#include "Operator.h"
class Mult: public Operate {

	public:
		Mult(Base* left,Base* right): Operate(left,right) {};

		double evaluate() {
			return left->evaluate() * right->evaluate();
		}
		std::string stringify(){
			return "(" + left->stringify() +")" + "*"+ "(" + right->stringify() + ")";
		}
                Base* get_left() {return left;};
                Base* get_right(){return right;};
                void accept(CountVisitor* v){
                        v->visit_mult();
                }

};
#endif //__Mult_H__  
