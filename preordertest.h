 

TEST(PreorderTest, addTest)
{
        Base* a  = new Op(1);
        Base* b  = new Op(2);
	Base* c  = new Op(3);
	Base* d = new Op(4);
	Base* e = new Op(5);

	
        Base* one  = new Add(a, b);

	Base* two = new Add(one, c);

	Base* three = new Add(two, d);

	Base* four = new Add(three, e);

        Base* dummy = new Add(four, a);

        Iterator* it = new PreorderIterator(dummy);

        it->first();

        CountVisitor* visit = new CountVisitor();
        while(it->is_done() == false)
        {
                Base* c = it->current();
                c->accept(visit);
                it->next();
        }

        EXPECT_EQ(visit->add_count(), 4);
	EXPECT_EQ(visit->op_count(), 6);
}
TEST(PreorderTest, subTest)
{
        Base* a  = new Op(1);
        Base* b  = new Op(2);
        Base* c  = new Op(3);
        Base* d = new Op(4);
        Base* e = new Op(5);


        Base* one  = new Sub(a, b);

        Base* two = new Sub(one, c);

        Base* three = new Sub(two, d);

        Base* four = new Sub(three, e);

        Base* dummy = new Sub(four, a);

        Iterator* it = new PreorderIterator(dummy);

        it->first();

        CountVisitor* visit = new CountVisitor();
        while(it->is_done() == false)
        {
                Base* c = it->current();
                c->accept(visit);
                it->next();
        }

        EXPECT_EQ(visit->sub_count(), 4);
        EXPECT_EQ(visit->op_count(), 6);
}
TEST(PreorderTest, multTest)
{
        Base* a  = new Op(1);
        Base* b  = new Op(2);
        Base* c  = new Op(3);
        Base* d = new Op(4);
        Base* e = new Op(5);


        Base* one  = new Mult(a, b);

        Base* two = new Mult(one, c);

        Base* three = new Mult(two, d);

        Base* four = new Mult(three, e);

        Base* dummy = new Mult(four, a);

        Iterator* it = new PreorderIterator(dummy);

        it->first();

        CountVisitor* visit = new CountVisitor();
        while(it->is_done() == false)
        {
                Base* c = it->current();
                c->accept(visit);
                it->next();
        }

        EXPECT_EQ(visit->mult_count(), 4);
        EXPECT_EQ(visit->op_count(), 6);
}
TEST(PreorderTest, divTest)
{
        Base* a  = new Op(1);
        Base* b  = new Op(2);
        Base* c  = new Op(3);
        Base* d = new Op(4);
        Base* e = new Op(5);


        Base* one  = new Div(a, b);

        Base* two = new Div(one, c);

        Base* three = new Div(two, d);

        Base* four = new Div(three, e);

        Base* dummy = new Div(four, a);

        Iterator* it = new PreorderIterator(dummy);

        it->first();

        CountVisitor* visit = new CountVisitor();
        while(it->is_done() == false)
        {
                Base* c = it->current();
                c->accept(visit);
                it->next();
        }

        EXPECT_EQ(visit->div_count(), 4);
        EXPECT_EQ(visit->op_count(), 6);
}
TEST(PreorderTest, PowTest)
{
        Base* a  = new Op(1);
        Base* b  = new Op(2);
        Base* c  = new Op(3);
        Base* d = new Op(4);
        Base* e = new Op(5);


        Base* one  = new Pow(a, b);

        Base* two = new Pow(one, c);

        Base* three = new Pow(two, d);

        Base* four = new Pow(three, e);

        Base* dummy = new Pow(four, a);

        Iterator* it = new PreorderIterator(dummy);

        it->first();

        CountVisitor* visit = new CountVisitor();
        while(it->is_done() == false)
        {
                Base* c = it->current();
                c->accept(visit);
                it->next();
        }

        EXPECT_EQ(visit->pow_count(), 4);
        EXPECT_EQ(visit->op_count(), 6);
}

TEST(PreorderTest, randTest)
{
        Base* a  = new Rand();
        Base* b  = new Rand();
        Base* c  = new Rand();
        Base* d = new Rand();
        Base* e = new Rand();


	
        Base* dummy = new Add(c,d);

        Iterator* it = new PreorderIterator(dummy);

        it->first();

        CountVisitor* visit = new CountVisitor();
        while(it->is_done() == false)
        {
                Base* c = it->current();
                c->accept(visit);
                it->next();
        }

        EXPECT_EQ(visit->rand_count(), 2);
        EXPECT_EQ(visit->op_count(), 0);
}

