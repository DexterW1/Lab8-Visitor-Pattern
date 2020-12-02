#include "gtest/gtest.h"
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
#include "container.hpp"
#include "sort.hpp"
#include "op_test.hpp"
#include "selection_sort.h"
#include "ListContainer.h"
#include "bubble_sort.h"
TEST(VectorContainerTest, Add_Element_Test){
	Op* seven = new Op(7);
	VectorContainer* container = new VectorContainer();
	container->add_element(seven);

	ASSERT_EQ(container->size(),1);
	EXPECT_EQ(container->at(0)->evaluate(),7);
}
TEST(VectorContainerTest, Add_Multiple_Elements_Test){
	Op* twenty = new Op(20);
	Op* hundered = new Op(100);
	Op* three = new Op(3);
	Op* ten = new Op(10);

	VectorContainer* container = new VectorContainer();

	container->add_element(twenty);
	container->add_element(hundered);
	container->add_element(three);
	container->add_element(ten);

	ASSERT_EQ(container->size(),4);
	EXPECT_EQ(container->at(0)->evaluate(),20);
	EXPECT_EQ(container->at(1)->evaluate(),100);
	EXPECT_EQ(container->at(2)->evaluate(),3);
	EXPECT_EQ(container->at(3)->evaluate(),10);
}
TEST(VectorContainerTest, SwapTest){
	Op* three = new Op(3);
	Op* eight = new Op(8);
	VectorContainer* container = new VectorContainer();
	container->add_element(three);
	container->add_element(eight);	
        ASSERT_EQ(container->size(),2);
	EXPECT_EQ(container->at(0)->evaluate(),3);
	EXPECT_EQ(container->at(1)->evaluate(),8);

	container->swap(0,1);
	
	ASSERT_EQ(container->size(),2);	
        EXPECT_EQ(container->at(0)->evaluate(),8);
        EXPECT_EQ(container->at(1)->evaluate(),3);


}
TEST(VectorContainerTest, SwapTestPt2){
        Op* three = new Op(3);
        Op* eight = new Op(8);
	Op* five = new Op(5);
	Op* ten = new  Op(10);
	Op* two = new Op(2);
	Op* one = new Op(1);
        VectorContainer* container = new VectorContainer();
        container->add_element(three);
        container->add_element(eight);
	container->add_element(five);
	container->add_element(ten);
	container->add_element(two);
	container->add_element(one);
        ASSERT_EQ(container->size(),6);

        EXPECT_EQ(container->at(0)->evaluate(),3);
        EXPECT_EQ(container->at(1)->evaluate(),8);
        EXPECT_EQ(container->at(2)->evaluate(),5);
        EXPECT_EQ(container->at(3)->evaluate(),10);
        EXPECT_EQ(container->at(4)->evaluate(),2);
        EXPECT_EQ(container->at(5)->evaluate(),1);

        container->swap(0,5);
	container->swap(1,4);
	container->swap(2,3);

        ASSERT_EQ(container->size(),6);
        EXPECT_EQ(container->at(0)->evaluate(),1);
        EXPECT_EQ(container->at(1)->evaluate(),2);
        EXPECT_EQ(container->at(2)->evaluate(),10);
        EXPECT_EQ(container->at(3)->evaluate(),5);
        EXPECT_EQ(container->at(4)->evaluate(),8);
        EXPECT_EQ(container->at(5)->evaluate(),3);


}

TEST(VectorContainerTest, Print){
        Op* three = new Op(3);
        Op* eight = new Op(8);
        Op* five = new Op(5);
        Op* ten = new  Op(10);
        Op* two = new Op(2);
        Op* one = new Op(1);
        VectorContainer* container = new VectorContainer();
        container->add_element(three);
        container->add_element(eight);
        container->add_element(five);
        container->add_element(ten);
        container->add_element(two);
        container->add_element(one);


	testing::internal::CaptureStdout();
	container->print();
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ("3->8->5->10->2->1->", output);	


}
TEST(ListContainerTest, Print){
        Op* three = new Op(3);
        Op* eight = new Op(8);
        Op* five = new Op(5);
        Op* ten = new  Op(10);
        Op* two = new Op(2);
        Op* one = new Op(1);
        ListContainer* container = new ListContainer();
        container->add_element(three);
        container->add_element(eight);
        container->add_element(five);
        container->add_element(ten);
        container->add_element(two);
        container->add_element(one);


        testing::internal::CaptureStdout();
        container->print();
        std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ("3->8->5->10->2->1->", output);


}


TEST(VectorContainerTest, VectorSize){
	Op* seven = new Op(7);
	Op* five = new Op(5);
	Op* three = new Op(3);
	Op* six = new Op(6);
	Op* two = new Op(2);
	VectorContainer* container = new VectorContainer();
	container->add_element(seven);
	container->add_element(five);
	container->add_element(three);
	container->add_element(six);
	container->add_element(two);
	
	ASSERT_EQ(container->size(),5);
	EXPECT_EQ(container->size(),5);

}
TEST(VectorContainerTest, SelectionSort){
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

    	ASSERT_EQ(container->size(), 3);
    	EXPECT_EQ(container->at(0)->evaluate(), 28);
    	EXPECT_EQ(container->at(1)->evaluate(), 5);
    	EXPECT_EQ(container->at(2)->evaluate(), 4);

    	container->set_sort_function(new SelectionSort());
    	container->sort();

    	ASSERT_EQ(container->size(), 3);
    	EXPECT_EQ(container->at(0)->evaluate(), 4);
    	EXPECT_EQ(container->at(1)->evaluate(), 5);
    	EXPECT_EQ(container->at(2)->evaluate(), 28);

}
TEST(VectorContainerTest, SelectionSortPt2){
	Op* one = new Op(1);
	Op* two = new Op(2);
	Op* three = new Op(3);
	Op* four = new Op(4);
	Op* five = new Op(5);
	Op* six = new Op(6);
	Op* seven = new Op(7);
	Op* eight = new Op(8);
	Op* nine = new Op(9);
	Op* ten = new Op(10);
	Op* zero = new Op(0);
	
	VectorContainer* container = new VectorContainer();
	container->add_element(four);
        container->add_element(two);
        container->add_element(three);
        container->add_element(one);
        container->add_element(zero);
        container->add_element(ten);
        container->add_element(eight);
        container->add_element(nine);
        container->add_element(two);
        container->add_element(five);
        container->add_element(seven);
        container->add_element(ten);

        ASSERT_EQ(container->size(), 12);
        EXPECT_EQ(container->at(0)->evaluate(), 4);
        EXPECT_EQ(container->at(1)->evaluate(), 2);
        EXPECT_EQ(container->at(2)->evaluate(), 3);
	EXPECT_EQ(container->at(3)->evaluate(), 1);
        EXPECT_EQ(container->at(4)->evaluate(), 0);
        EXPECT_EQ(container->at(5)->evaluate(), 10);
        EXPECT_EQ(container->at(6)->evaluate(), 8);
        EXPECT_EQ(container->at(7)->evaluate(), 9);
        EXPECT_EQ(container->at(8)->evaluate(), 2);
        EXPECT_EQ(container->at(9)->evaluate(), 5);
        EXPECT_EQ(container->at(10)->evaluate(), 7);
        EXPECT_EQ(container->at(11)->evaluate(), 10);

	container->set_sort_function(new SelectionSort());
	container->sort();

        ASSERT_EQ(container->size(), 12);
        EXPECT_EQ(container->at(0)->evaluate(), 0);
        EXPECT_EQ(container->at(1)->evaluate(), 1);
        EXPECT_EQ(container->at(2)->evaluate(), 2);
        EXPECT_EQ(container->at(3)->evaluate(), 2);
        EXPECT_EQ(container->at(4)->evaluate(), 3);
        EXPECT_EQ(container->at(5)->evaluate(), 4);
        EXPECT_EQ(container->at(6)->evaluate(), 5);
        EXPECT_EQ(container->at(7)->evaluate(), 7);
        EXPECT_EQ(container->at(8)->evaluate(), 8);
        EXPECT_EQ(container->at(9)->evaluate(), 9);
        EXPECT_EQ(container->at(10)->evaluate(), 10);
        EXPECT_EQ(container->at(11)->evaluate(), 10);	
}

TEST(VectorContainerTest, SelectionSortpt3){
        Op* eight = new Op(8);
        Op* four = new Op(4);
        Div* TreeA = new Div(eight, four);

        Op* three = new Op(3);
        Op* two = new Op(2);
        Add* TreeB = new Add(three, two);

        Op* ten = new Op(10);
        Op* six = new Op(6);
        Mult* TreeC = new Mult(ten, six);
	
	Op* five = new Op(5);
	Op* one = new Op(1);
	Sub* TreeD = new Sub(five,one);



        VectorContainer* container = new VectorContainer();
        container->add_element(TreeA);
        container->add_element(TreeB);
        container->add_element(TreeC);
	container->add_element(TreeD);

        ASSERT_EQ(container->size(), 4);
        EXPECT_EQ(container->at(0)->evaluate(), 2);
        EXPECT_EQ(container->at(1)->evaluate(), 5);
        EXPECT_EQ(container->at(2)->evaluate(), 60);
	EXPECT_EQ(container->at(3)->evaluate(),4);


        container->set_sort_function(new SelectionSort());
        container->sort();

        ASSERT_EQ(container->size(), 4);
        EXPECT_EQ(container->at(0)->evaluate(), 2);
        EXPECT_EQ(container->at(1)->evaluate(), 4);
        EXPECT_EQ(container->at(2)->evaluate(), 5);
	EXPECT_EQ(container->at(3)->evaluate(), 60);

}
TEST(VectorContainerTest, SelectionSortpt4){
        Op* eight = new Op(8);
        Op* four = new Op(4);
        Div* TreeA = new Div(eight, four);

        Op* three = new Op(3);
        Op* two = new Op(2);
        Add* TreeB = new Add(three, two);

        Op* ten = new Op(10);
        Op* six = new Op(6);
        Mult* TreeC = new Mult(ten, six);

        Op* five = new Op(5);
        Op* one = new Op(1);
        Sub* TreeD = new Sub(five,one);

	Op* twentytwo = new Op(22);
	Op* hunderedten = new Op(110);
	Add* TreeE = new Add (twentytwo,hunderedten);

	Pow* TreeF = new Pow (two,five);
	Sub* TreeG = new Sub (TreeE,TreeF);


        VectorContainer* container = new VectorContainer();
        container->add_element(TreeA);
        container->add_element(TreeB);
        container->add_element(TreeC);
        container->add_element(TreeD);
	container->add_element(TreeE);
	container->add_element(TreeF);
	container->add_element(TreeG);

        ASSERT_EQ(container->size(), 7);
        EXPECT_EQ(container->at(0)->evaluate(), 2);
        EXPECT_EQ(container->at(1)->evaluate(), 5);
        EXPECT_EQ(container->at(2)->evaluate(), 60);
        EXPECT_EQ(container->at(3)->evaluate(),4);
	EXPECT_EQ(container->at(4)->evaluate(),132);
	EXPECT_EQ(container->at(5)->evaluate(),32);
	EXPECT_EQ(container->at(6)->evaluate(),100);


        container->set_sort_function(new SelectionSort());
        container->sort();

        ASSERT_EQ(container->size(), 7);
        EXPECT_EQ(container->at(0)->evaluate(), 2);
        EXPECT_EQ(container->at(1)->evaluate(), 4);
        EXPECT_EQ(container->at(2)->evaluate(), 5);
        EXPECT_EQ(container->at(3)->evaluate(), 32);
	EXPECT_EQ(container->at(4)->evaluate(),60);
	EXPECT_EQ(container->at(5)->evaluate(),100);
	EXPECT_EQ(container->at(6)->evaluate(),132);

}


TEST(ListContainerTest, LISTAdd_Element_Test){
        Op* seven = new Op(7);
        ListContainer* container = new ListContainer();
        container->add_element(seven);

        ASSERT_EQ(container->size(),1);
        EXPECT_EQ(container->at(0)->evaluate(),7);
}

 
TEST(ListContainerTest, LISTAdd_Multiple_Elements_Test){
        Op* twenty = new Op(20);
        Op* hundered = new Op(100);
        Op* three = new Op(3);
        Op* ten = new Op(10);

        ListContainer* container = new ListContainer();

        container->add_element(twenty);
        container->add_element(hundered);
        container->add_element(three);
        container->add_element(ten);

        ASSERT_EQ(container->size(),4);
        EXPECT_EQ(container->at(0)->evaluate(),20);
        EXPECT_EQ(container->at(1)->evaluate(),100);
        EXPECT_EQ(container->at(2)->evaluate(),3);
        EXPECT_EQ(container->at(3)->evaluate(),10);
}
TEST(ListContainerTest, LISTSwapTest){
        Op* three = new Op(3);
        Op* eight = new Op(8);
        ListContainer* container = new ListContainer();
        container->add_element(three);
        container->add_element(eight);
        ASSERT_EQ(container->size(),2);
        EXPECT_EQ(container->at(0)->evaluate(),3);
        EXPECT_EQ(container->at(1)->evaluate(),8);

        container->swap(0,1);

        ASSERT_EQ(container->size(),2);
        EXPECT_EQ(container->at(0)->evaluate(),8);
        EXPECT_EQ(container->at(1)->evaluate(),3);


}


TEST(ListContainerTest, LISTSwapTestPt2){
        Op* three = new Op(3);
        Op* eight = new Op(8);
        Op* five = new Op(5);
        Op* ten = new  Op(10);
        Op* two = new Op(2);
        Op* one = new Op(1);
        ListContainer* container = new ListContainer();
        container->add_element(three);
        container->add_element(eight);
        container->add_element(five);
        container->add_element(ten);
        container->add_element(two);
        container->add_element(one);
        ASSERT_EQ(container->size(),6);

        EXPECT_EQ(container->at(0)->evaluate(),3);
        EXPECT_EQ(container->at(1)->evaluate(),8);
        EXPECT_EQ(container->at(2)->evaluate(),5);
        EXPECT_EQ(container->at(3)->evaluate(),10);
        EXPECT_EQ(container->at(4)->evaluate(),2);
        EXPECT_EQ(container->at(5)->evaluate(),1);

        container->swap(0,5);
        container->swap(1,4);
        container->swap(2,3);

        ASSERT_EQ(container->size(),6);
        EXPECT_EQ(container->at(0)->evaluate(),1);
        EXPECT_EQ(container->at(1)->evaluate(),2);
        EXPECT_EQ(container->at(2)->evaluate(),10);
        EXPECT_EQ(container->at(3)->evaluate(),5);
        EXPECT_EQ(container->at(4)->evaluate(),8);
        EXPECT_EQ(container->at(5)->evaluate(),3);


}


TEST(ListContainerTest, LISTSize){
        Op* seven = new Op(7);
        Op* five = new Op(5);
        Op* three = new Op(3);
        Op* six = new Op(6);
        Op* two = new Op(2);
        ListContainer* container = new ListContainer();
        container->add_element(seven);
        container->add_element(five);
        container->add_element(three);
        container->add_element(six);
        container->add_element(two);

        ASSERT_EQ(container->size(),5);
        EXPECT_EQ(container->size(),5);

}
TEST(ListContainerTest, BubbleSort){
        Op* seven = new Op(7);
        Op* four = new Op(4);
         Mult* TreeA = new Mult(seven, four);

        Op* three = new Op(3);
        Op* two = new Op(2);
        Add* TreeB = new Add(three, two);

        Op* ten = new Op(10);
        Op* six = new Op(6);
        Sub* TreeC = new Sub(ten, six);

        ListContainer* container = new ListContainer();
        container->add_element(TreeA);
        container->add_element(TreeB);
        container->add_element(TreeC);

        ASSERT_EQ(container->size(), 3);
        EXPECT_EQ(container->at(0)->evaluate(), 28);
        EXPECT_EQ(container->at(1)->evaluate(), 5);
        EXPECT_EQ(container->at(2)->evaluate(), 4);

        container->set_sort_function(new BubbleSort());
        container->sort();

        ASSERT_EQ(container->size(), 3);
        EXPECT_EQ(container->at(0)->evaluate(), 4);
        EXPECT_EQ(container->at(1)->evaluate(), 5);
        EXPECT_EQ(container->at(2)->evaluate(), 28);

}

TEST(ListContainerTest, BubbleSortPt2){
        Op* one = new Op(1);
        Op* two = new Op(2);
        Op* three = new Op(3);
        Op* four = new Op(4);
        Op* five = new Op(5);
        Op* six = new Op(6);
        Op* seven = new Op(7);
        Op* eight = new Op(8);
        Op* nine = new Op(9);
        Op* ten = new Op(10);
        Op* zero = new Op(0);

        ListContainer* container = new ListContainer();
        container->add_element(four);
        container->add_element(two);
        container->add_element(three);
        container->add_element(one);
        container->add_element(zero);
        container->add_element(ten);
        container->add_element(eight);
        container->add_element(nine);
        container->add_element(two);
        container->add_element(five);
        container->add_element(seven);
        container->add_element(ten);

        ASSERT_EQ(container->size(), 12);
        EXPECT_EQ(container->at(0)->evaluate(), 4);
        EXPECT_EQ(container->at(1)->evaluate(), 2);
        EXPECT_EQ(container->at(2)->evaluate(), 3);
        EXPECT_EQ(container->at(3)->evaluate(), 1);
        EXPECT_EQ(container->at(4)->evaluate(), 0);
        EXPECT_EQ(container->at(5)->evaluate(), 10);
        EXPECT_EQ(container->at(6)->evaluate(), 8);
        EXPECT_EQ(container->at(7)->evaluate(), 9);
        EXPECT_EQ(container->at(8)->evaluate(), 2);
        EXPECT_EQ(container->at(9)->evaluate(), 5);
        EXPECT_EQ(container->at(10)->evaluate(), 7);
        EXPECT_EQ(container->at(11)->evaluate(), 10);

        container->set_sort_function(new BubbleSort());
        container->sort();

        ASSERT_EQ(container->size(), 12);
        EXPECT_EQ(container->at(0)->evaluate(), 0);
        EXPECT_EQ(container->at(1)->evaluate(), 1);
        EXPECT_EQ(container->at(2)->evaluate(), 2);
        EXPECT_EQ(container->at(3)->evaluate(), 2);
        EXPECT_EQ(container->at(4)->evaluate(), 3);
        EXPECT_EQ(container->at(5)->evaluate(), 4);
        EXPECT_EQ(container->at(6)->evaluate(), 5);
        EXPECT_EQ(container->at(7)->evaluate(), 7);
        EXPECT_EQ(container->at(8)->evaluate(), 8);
        EXPECT_EQ(container->at(9)->evaluate(), 9);
        EXPECT_EQ(container->at(10)->evaluate(), 10);
        EXPECT_EQ(container->at(11)->evaluate(), 10);
}
TEST(ListContainerTest,BubbleSortpt3){

	Op* eight = new Op(8);
        Op* four = new Op(4);
        Div* TreeA = new Div(eight, four);

        Op* three = new Op(3);
        Op* two = new Op(2);
        Add* TreeB = new Add(three, two);

        Op* ten = new Op(10);
        Op* six = new Op(6);
        Mult* TreeC = new Mult(ten, six);

        Op* five = new Op(5);
        Op* one = new Op(1);
        Sub* TreeD = new Sub(five,one);

        Op* twentytwo = new Op(22);
        Op* hunderedten = new Op(110);
        Add* TreeE = new Add (twentytwo,hunderedten);

        Pow* TreeF = new Pow (two,five);
        Sub* TreeG = new Sub (TreeE,TreeF);


        ListContainer* container = new ListContainer();
        container->add_element(TreeA);
        container->add_element(TreeB);
        container->add_element(TreeC);
        container->add_element(TreeD);
        container->add_element(TreeE);
        container->add_element(TreeF);
        container->add_element(TreeG);

        ASSERT_EQ(container->size(), 7);
        EXPECT_EQ(container->at(0)->evaluate(), 2);
        EXPECT_EQ(container->at(1)->evaluate(), 5);
        EXPECT_EQ(container->at(2)->evaluate(), 60);
        EXPECT_EQ(container->at(3)->evaluate(),4);
        EXPECT_EQ(container->at(4)->evaluate(),132);
        EXPECT_EQ(container->at(5)->evaluate(),32);
        EXPECT_EQ(container->at(6)->evaluate(),100);


        container->set_sort_function(new BubbleSort());
        container->sort();

        ASSERT_EQ(container->size(), 7);
        EXPECT_EQ(container->at(0)->evaluate(), 2);
        EXPECT_EQ(container->at(1)->evaluate(), 4);
        EXPECT_EQ(container->at(2)->evaluate(), 5);
        EXPECT_EQ(container->at(3)->evaluate(), 32);
        EXPECT_EQ(container->at(4)->evaluate(),60);
        EXPECT_EQ(container->at(5)->evaluate(),100);
        EXPECT_EQ(container->at(6)->evaluate(),132);

}
TEST(ListContainerTest, BubbleSortpt4){
        Op* eight = new Op(8);
        Op* four = new Op(4);
        Div* TreeA = new Div(eight, four);

        Op* three = new Op(3);
        Op* two = new Op(2);
        Add* TreeB = new Add(three, two);

        Op* ten = new Op(10);
        Op* six = new Op(6);
        Mult* TreeC = new Mult(ten, six);

        Op* five = new Op(5);
        Op* one = new Op(1);
        Sub* TreeD = new Sub(five,one);



        ListContainer* container = new ListContainer();
        container->add_element(TreeA);
        container->add_element(TreeB);
        container->add_element(TreeC);
        container->add_element(TreeD);

        ASSERT_EQ(container->size(), 4);
        EXPECT_EQ(container->at(0)->evaluate(), 2);
        EXPECT_EQ(container->at(1)->evaluate(), 5);
        EXPECT_EQ(container->at(2)->evaluate(), 60);
        EXPECT_EQ(container->at(3)->evaluate(),4);


        container->set_sort_function(new BubbleSort());
        container->sort();

        ASSERT_EQ(container->size(), 4);
        EXPECT_EQ(container->at(0)->evaluate(), 2);
        EXPECT_EQ(container->at(1)->evaluate(), 4);
        EXPECT_EQ(container->at(2)->evaluate(), 5);
        EXPECT_EQ(container->at(3)->evaluate(), 60);


}
TEST(VectorContainerTest, BubbleSort){
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

        ASSERT_EQ(container->size(), 3);
        EXPECT_EQ(container->at(0)->evaluate(), 28);
        EXPECT_EQ(container->at(1)->evaluate(), 5);
        EXPECT_EQ(container->at(2)->evaluate(), 4);

        container->set_sort_function(new BubbleSort());
        container->sort();

        ASSERT_EQ(container->size(), 3);
        EXPECT_EQ(container->at(0)->evaluate(), 4);
        EXPECT_EQ(container->at(1)->evaluate(), 5);
        EXPECT_EQ(container->at(2)->evaluate(), 28);

}
TEST(VectorContainerTest, BubbleSortpt2){
        Op* one = new Op(1);
        Op* two = new Op(2);
        Op* three = new Op(3);
        Op* four = new Op(4);
        Op* five = new Op(5);
        Op* six = new Op(6);
        Op* seven = new Op(7);
        Op* eight = new Op(8);
        Op* nine = new Op(9);
        Op* ten = new Op(10);
        Op* zero = new Op(0);

        VectorContainer* container = new VectorContainer();
        container->add_element(four);
        container->add_element(two);
        container->add_element(three);
        container->add_element(one);
        container->add_element(zero);
        container->add_element(ten);
        container->add_element(eight);
        container->add_element(nine);
        container->add_element(two);
        container->add_element(five);
        container->add_element(seven);
        container->add_element(ten);

        ASSERT_EQ(container->size(), 12);
        EXPECT_EQ(container->at(0)->evaluate(), 4);
        EXPECT_EQ(container->at(1)->evaluate(), 2);
        EXPECT_EQ(container->at(2)->evaluate(), 3);
        EXPECT_EQ(container->at(3)->evaluate(), 1);
        EXPECT_EQ(container->at(4)->evaluate(), 0);
        EXPECT_EQ(container->at(5)->evaluate(), 10);
        EXPECT_EQ(container->at(6)->evaluate(), 8);
        EXPECT_EQ(container->at(7)->evaluate(), 9);
        EXPECT_EQ(container->at(8)->evaluate(), 2);
        EXPECT_EQ(container->at(9)->evaluate(), 5);
        EXPECT_EQ(container->at(10)->evaluate(), 7);
        EXPECT_EQ(container->at(11)->evaluate(), 10);

        container->set_sort_function(new BubbleSort());
        container->sort();

        ASSERT_EQ(container->size(), 12);
        EXPECT_EQ(container->at(0)->evaluate(), 0);
        EXPECT_EQ(container->at(1)->evaluate(), 1);
        EXPECT_EQ(container->at(2)->evaluate(), 2);
        EXPECT_EQ(container->at(3)->evaluate(), 2);
        EXPECT_EQ(container->at(4)->evaluate(), 3);
        EXPECT_EQ(container->at(5)->evaluate(), 4);
        EXPECT_EQ(container->at(6)->evaluate(), 5);
        EXPECT_EQ(container->at(7)->evaluate(), 7);
        EXPECT_EQ(container->at(8)->evaluate(), 8);
        EXPECT_EQ(container->at(9)->evaluate(), 9);
        EXPECT_EQ(container->at(10)->evaluate(), 10);

}


TEST(VectorContainerTest, BubbleSortpt3){
        Op* eight = new Op(8);
        Op* four = new Op(4);
        Div* TreeA = new Div(eight, four);

        Op* three = new Op(3);
        Op* two = new Op(2);
        Add* TreeB = new Add(three, two);

        Op* ten = new Op(10);
        Op* six = new Op(6);
        Mult* TreeC = new Mult(ten, six);

        Op* five = new Op(5);
        Op* one = new Op(1);
        Sub* TreeD = new Sub(five,one);



        VectorContainer* container = new VectorContainer();
        container->add_element(TreeA);
        container->add_element(TreeB);
        container->add_element(TreeC);
        container->add_element(TreeD);

        ASSERT_EQ(container->size(), 4);
        EXPECT_EQ(container->at(0)->evaluate(), 2);
        EXPECT_EQ(container->at(1)->evaluate(), 5);
        EXPECT_EQ(container->at(2)->evaluate(), 60);
        EXPECT_EQ(container->at(3)->evaluate(),4);


        container->set_sort_function(new BubbleSort());
        container->sort();

        ASSERT_EQ(container->size(), 4);
        EXPECT_EQ(container->at(0)->evaluate(), 2);
        EXPECT_EQ(container->at(1)->evaluate(), 4);
        EXPECT_EQ(container->at(2)->evaluate(), 5);
        EXPECT_EQ(container->at(3)->evaluate(), 60);

}




TEST(VectorContainerTest, BubbleSortpt4){
        Op* eight = new Op(8);
        Op* four = new Op(4);
        Div* TreeA = new Div(eight, four);

        Op* three = new Op(3);
        Op* two = new Op(2);
        Add* TreeB = new Add(three, two);

        Op* ten = new Op(10);
        Op* six = new Op(6);
        Mult* TreeC = new Mult(ten, six);

        Op* five = new Op(5);
        Op* one = new Op(1);
        Sub* TreeD = new Sub(five,one);

        Op* twentytwo = new Op(22);
        Op* hunderedten = new Op(110);
        Add* TreeE = new Add (twentytwo,hunderedten);

        Pow* TreeF = new Pow (two,five);
        Sub* TreeG = new Sub (TreeE,TreeF);


        VectorContainer* container = new VectorContainer();
        container->add_element(TreeA);
        container->add_element(TreeB);
        container->add_element(TreeC);
        container->add_element(TreeD);
        container->add_element(TreeE);
        container->add_element(TreeF);
        container->add_element(TreeG);

        ASSERT_EQ(container->size(), 7);
        EXPECT_EQ(container->at(0)->evaluate(), 2);
        EXPECT_EQ(container->at(1)->evaluate(), 5);
        EXPECT_EQ(container->at(2)->evaluate(), 60);
        EXPECT_EQ(container->at(3)->evaluate(),4);
        EXPECT_EQ(container->at(4)->evaluate(),132);
        EXPECT_EQ(container->at(5)->evaluate(),32);
        EXPECT_EQ(container->at(6)->evaluate(),100);


        container->set_sort_function(new BubbleSort());
        container->sort();

        ASSERT_EQ(container->size(), 7);
        EXPECT_EQ(container->at(0)->evaluate(), 2);
        EXPECT_EQ(container->at(1)->evaluate(), 4);
        EXPECT_EQ(container->at(2)->evaluate(), 5);
        EXPECT_EQ(container->at(3)->evaluate(), 32);
        EXPECT_EQ(container->at(4)->evaluate(),60);
        EXPECT_EQ(container->at(5)->evaluate(),100);
        EXPECT_EQ(container->at(6)->evaluate(),132);

}

TEST(ListContainerTest, LISTSelectionSort)
{
        Op* seven = new Op(7);
        Op* four = new Op(4);
        Mult* TreeA = new Mult(seven, four);

        Op* three = new Op(3);
        Op* two = new Op(2);
        Add* TreeB = new Add(three, two);

        Op* ten = new Op(10);
        Op* six = new Op(6);
        Sub* TreeC = new Sub(ten, six);

        ListContainer* container = new ListContainer();
        container->add_element(TreeA);
        container->add_element(TreeB);
        container->add_element(TreeC);

        ASSERT_EQ(container->size(), 3);
        EXPECT_EQ(container->at(0)->evaluate(), 28);
        EXPECT_EQ(container->at(1)->evaluate(), 5);
        EXPECT_EQ(container->at(2)->evaluate(), 4);

        container->set_sort_function(new SelectionSort());
        container->sort();

        ASSERT_EQ(container->size(), 3);
        EXPECT_EQ(container->at(0)->evaluate(), 4);
        EXPECT_EQ(container->at(1)->evaluate(), 5);
        EXPECT_EQ(container->at(2)->evaluate(), 28);

	

}

TEST(ListContainerTest, LISTSelectionSort2)
{
        Op* one = new Op(1);
        Op* two = new Op(2);
        Op* three = new Op(3);
        Op* four = new Op(4);
        Op* five = new Op(5);
        Op* six = new Op(6);
        Op* seven = new Op(7);
        Op* eight = new Op(8);
        Op* nine = new Op(9);
        Op* ten = new Op(10);
        Op* zero = new Op(0);

        ListContainer* container = new ListContainer();
        container->add_element(four);
        container->add_element(two);
        container->add_element(three);
        container->add_element(one);
        container->add_element(zero);
        container->add_element(ten);
        container->add_element(eight);
        container->add_element(nine);
        container->add_element(two);
        container->add_element(five);
        container->add_element(seven);
        container->add_element(ten);

        ASSERT_EQ(container->size(), 12);
        EXPECT_EQ(container->at(0)->evaluate(), 4);
        EXPECT_EQ(container->at(1)->evaluate(), 2);
        EXPECT_EQ(container->at(2)->evaluate(), 3);
        EXPECT_EQ(container->at(3)->evaluate(), 1);
        EXPECT_EQ(container->at(4)->evaluate(), 0);
        EXPECT_EQ(container->at(5)->evaluate(), 10);
        EXPECT_EQ(container->at(6)->evaluate(), 8);
        EXPECT_EQ(container->at(7)->evaluate(), 9);
        EXPECT_EQ(container->at(8)->evaluate(), 2);
        EXPECT_EQ(container->at(9)->evaluate(), 5);
        EXPECT_EQ(container->at(10)->evaluate(), 7);
        EXPECT_EQ(container->at(11)->evaluate(), 10);

        container->set_sort_function(new SelectionSort());
        container->sort();

        ASSERT_EQ(container->size(), 12);
        EXPECT_EQ(container->at(0)->evaluate(), 0);
        EXPECT_EQ(container->at(1)->evaluate(), 1);
        EXPECT_EQ(container->at(2)->evaluate(), 2);
        EXPECT_EQ(container->at(3)->evaluate(), 2);
        EXPECT_EQ(container->at(4)->evaluate(), 3);
        EXPECT_EQ(container->at(5)->evaluate(), 4);
        EXPECT_EQ(container->at(6)->evaluate(), 5);
        EXPECT_EQ(container->at(7)->evaluate(), 7);
        EXPECT_EQ(container->at(8)->evaluate(), 8);
        EXPECT_EQ(container->at(9)->evaluate(), 9);
        EXPECT_EQ(container->at(10)->evaluate(), 10);




}
TEST(ListContainerTest, LISTSelectionSort3){
        Op* eight = new Op(8);
        Op* four = new Op(4);
        Div* TreeA = new Div(eight, four);

        Op* three = new Op(3);
        Op* two = new Op(2);
        Add* TreeB = new Add(three, two);

        Op* ten = new Op(10);
        Op* six = new Op(6);
        Mult* TreeC = new Mult(ten, six);

        Op* five = new Op(5);
        Op* one = new Op(1);
        Sub* TreeD = new Sub(five,one);



        ListContainer* container = new ListContainer();
        container->add_element(TreeA);
        container->add_element(TreeB);
        container->add_element(TreeC);
        container->add_element(TreeD);

        ASSERT_EQ(container->size(), 4);
        EXPECT_EQ(container->at(0)->evaluate(), 2);
        EXPECT_EQ(container->at(1)->evaluate(), 5);
        EXPECT_EQ(container->at(2)->evaluate(), 60);
        EXPECT_EQ(container->at(3)->evaluate(),4);


        container->set_sort_function(new SelectionSort());
        container->sort();

        ASSERT_EQ(container->size(), 4);
        EXPECT_EQ(container->at(0)->evaluate(), 2);
        EXPECT_EQ(container->at(1)->evaluate(), 4);
        EXPECT_EQ(container->at(2)->evaluate(), 5);
        EXPECT_EQ(container->at(3)->evaluate(), 60);


}
TEST(ListContainerTest, LISTSelectionSortpt4){
        Op* eight = new Op(8);
        Op* four = new Op(4);
        Div* TreeA = new Div(eight, four);

        Op* three = new Op(3);
        Op* two = new Op(2);
        Add* TreeB = new Add(three, two);

        Op* ten = new Op(10);
        Op* six = new Op(6);
        Mult* TreeC = new Mult(ten, six);

        Op* five = new Op(5);
        Op* one = new Op(1);
        Sub* TreeD = new Sub(five,one);

        Op* twentytwo = new Op(22);
        Op* hunderedten = new Op(110);
        Add* TreeE = new Add (twentytwo,hunderedten);

        Pow* TreeF = new Pow (two,five);
        Sub* TreeG = new Sub (TreeE,TreeF);


        ListContainer* container = new ListContainer();
        container->add_element(TreeA);
        container->add_element(TreeB);
        container->add_element(TreeC);
        container->add_element(TreeD);
        container->add_element(TreeE);
        container->add_element(TreeF);
        container->add_element(TreeG);

        ASSERT_EQ(container->size(), 7);
        EXPECT_EQ(container->at(0)->evaluate(), 2);
        EXPECT_EQ(container->at(1)->evaluate(), 5);
        EXPECT_EQ(container->at(2)->evaluate(), 60);
        EXPECT_EQ(container->at(3)->evaluate(),4);
        EXPECT_EQ(container->at(4)->evaluate(),132);
        EXPECT_EQ(container->at(5)->evaluate(),32);
        EXPECT_EQ(container->at(6)->evaluate(),100);


        container->set_sort_function(new SelectionSort());
        container->sort();

        ASSERT_EQ(container->size(), 7);
        EXPECT_EQ(container->at(0)->evaluate(), 2);
        EXPECT_EQ(container->at(1)->evaluate(), 4);
        EXPECT_EQ(container->at(2)->evaluate(), 5);
        EXPECT_EQ(container->at(3)->evaluate(), 32);
        EXPECT_EQ(container->at(4)->evaluate(),60);
        EXPECT_EQ(container->at(5)->evaluate(),100);
        EXPECT_EQ(container->at(6)->evaluate(),132);




}
TEST(ListContainerTest, atTest)
{
	Op* a = new Op(3);
 	ListContainer* container = new ListContainer();
	
	container->add_element(a);

	Base* temp = container->at(0);
	EXPECT_EQ(container->at(0), temp);  

}



TEST(ListContainerTest, atTest2)
{
        Op* a = new Op(3);
	
        ListContainer* container = new ListContainer();

        container->add_element(a);
	
        Base* temp = container->at(0);
        EXPECT_EQ(container->at(0)->evaluate(), temp->evaluate());

}
TEST(VectorContainerTest, atTest)
{
        Op* a = new Op(3);
        VectorContainer* container = new VectorContainer();

        container->add_element(a);

        Base* temp = container->at(0);
        EXPECT_EQ(container->at(0), temp);

}

TEST(VectorContainerTest, atTest2)
{
	Op* b = new Op(4);
	Op* c = new Op(5);

	VectorContainer* container = new VectorContainer();
	
	container->add_element(b);
	container->add_element(c);
	
	EXPECT_EQ(container->at(0)->evaluate(), 4);
	EXPECT_EQ(container->at(1)->evaluate(), 5);

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
