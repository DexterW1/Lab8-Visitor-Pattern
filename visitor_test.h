TEST(VisitorTest, longexpression){
	Base* a = new Op(5);
	Base* b = new Op(7);
	Base* c = new Op(9);
	Base* d = new Op(20);
	Base* e = new Op(4);

	Base* one = new Add(a,b);
	Base* two = new Sub(one,c);
	Base* three = new Mult(two,d);
	Base* four = new Div(three,e);
	Base* dummy = new Pow(four,a);

	Iterator* it = new PreorderIterator(dummy);
	it->first();
	CountVisitor* visit = new CountVisitor();
	while(it->is_done() == false){
		Base* c = it->current();
		c->accept(visit);
		it->next();
	}
	EXPECT_EQ(visit->add_count(),1);
	EXPECT_EQ(visit->sub_count(),1);
	EXPECT_EQ(visit->mult_count(),1);
	EXPECT_EQ(visit->div_count(),1);
}
TEST(VisitorTest, longexpressionpt2){
        Base* a = new Op(5);
        Base* b = new Op(7);
        Base* c = new Op(9);
        Base* d = new Op(20);
        Base* e = new Op(4);

        Base* one = new Add(a,b);
        Base* two = new Add(one,c);
        Base* three = new Mult(two,one);
        Base* four = new Mult(three,e);
	Base* five = new Sub(four,d);
	Base* six = new Div(five,a);
        Base* dummy = new Pow(six,a);

        Iterator* it = new PreorderIterator(dummy);
        it->first();
        CountVisitor* visit = new CountVisitor();
        while(it->is_done() == false){
                Base* c = it->current();
                c->accept(visit);
                it->next();
        }
        EXPECT_EQ(visit->add_count(),3);
        EXPECT_EQ(visit->sub_count(),1);
        EXPECT_EQ(visit->mult_count(),2);
        EXPECT_EQ(visit->div_count(),1);

}
TEST(VisitorTest, longexpressionpt3){
        Base* a = new Op(5);
        Base* b = new Op(7);
        Base* c = new Op(9);
        Base* d = new Op(20);
        Base* e = new Op(4);
	Base* f = new Op(2);	

        Base* one = new Add(a,b);
        Base* two = new Sub(one,c);
        Base* three = new Mult(two,one);
        Base* four = new Mult(three,e);
        Base* five = new Sub(four,d);
        Base* six = new Div(five,a);
	Base* seven = new Pow(six,f);
        Base* dummy = new Pow(seven,a);

        Iterator* it = new PreorderIterator(dummy);
        it->first();
        CountVisitor* visit = new CountVisitor();
        while(it->is_done() == false){
                Base* c = it->current();
                c->accept(visit);
                it->next();
        }
        EXPECT_EQ(visit->add_count(),2);
        EXPECT_EQ(visit->sub_count(),2);
        EXPECT_EQ(visit->mult_count(),2);
        EXPECT_EQ(visit->div_count(),1);
	EXPECT_EQ(visit->pow_count(),1);
}
TEST(VisitorTest, longexpressionpt4){
        Base* a = new Op(5);
        Base* b = new Op(7);
        Base* c = new Op(9);
        Base* d = new Op(20);
        Base* e = new Op(4);
	Base* f = new Op(9);
	Base* g = new Op(2);

	Base* zero = new Rand();
        Base* one = new Add(zero,b);
        Base* two = new Add(one,c);
        Base* three = new Mult(two,one);
        Base* four = new Mult(three,e);
        Base* five = new Sub(four,d);
        Base* six = new Div(five,a);
	Base* seven = new Pow(six,three);
	Base* eight = new Div(seven,f);
	Base* nine = new Sub(eight,g);
	Base* ten = new Pow(nine,six);
        Base* dummy = new Pow(ten,a);

        Iterator* it = new PreorderIterator(dummy);
        it->first();
        CountVisitor* visit = new CountVisitor();
        while(it->is_done() == false){
                Base* c = it->current();
                c->accept(visit);
                it->next();
        }
        EXPECT_EQ(visit->add_count(),9);
        EXPECT_EQ(visit->sub_count(),3);
        EXPECT_EQ(visit->mult_count(),5);
        EXPECT_EQ(visit->div_count(),3);
	EXPECT_EQ(visit->pow_count(),2);
	EXPECT_EQ(visit->rand_count(),6);

}

