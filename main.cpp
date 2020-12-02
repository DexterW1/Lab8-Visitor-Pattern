#include <iostream>
#include "base.hpp"
#include "div.h"
#include "pow.h"
#include "add.h"
#include "op.hpp"
#include "sub.h"
#include "rand.h"
#include "mult.h"
#include "VectorContainer.h"
#include "sort.hpp"
#include "container.hpp"
int main(){
    // This is a very basic main, and being able to correctly execute this main
    // does not constitute a completed lab. Make sure you write unit tests for
    // all the classes that you create (and can be instantiated) in this lab

   // Base* three = new Op(3);
   // Base* seven = new Op(7);
   // Base* four = new Op(4);
   // Base* two = new Op(2);
   // Base* mult = new Mult(seven, four);
   // Base* add = new Add(three, mult);
   // Base* minus = new Sub(add, two);
   
    Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* TreeA = new Mult(seven, four);

    Op* three = new Op(3);
    Op* two = new Op(2);
    Add* TreeB = new Add(three, two);

    Op* ten = new Op(10);
    Op* six = new Op(6);
    Sub* TreeC = new Sub(ten, six);
    
    VectorContainer* container = new VectorContainer();
    container->add_element(TreeA);
    container->add_element(TreeB);
    container->add_element(TreeC);

    std::cout << container->at(0)->evaluate()<<endl;
    std::cout << container->at(1)->evaluate()<<endl;
    std::cout << container->at(2)->evaluate()<<endl; 
   // std::cout << minus->stringify() << " = " << minus->evaluate() << std::endl;
   // return 0;
}
