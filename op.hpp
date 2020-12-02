#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include <string>
class Op : public Base {
    private:
	double val;

    public:
        Op(double value) : Base() {
	      val = value;		
 	      }

        double evaluate() { return val; }
        std::string stringify() {
		    return std::to_string(val);
	       }
	Iterator* create_iterator(){return new NullIterator()}
};


#endif //__OP_HPP__
