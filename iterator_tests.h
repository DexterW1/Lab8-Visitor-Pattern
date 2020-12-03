TEST(IteratorTests, addTest)
{
	Base* one  = new Op(1);
	Base* two  = new Op(2);

	Base* addition = new Add(one, two);

	Base* dummy = new Add(addition, one);

	Iterator* it =  dummy->create_iterator();

	it->first();

	CountVisitor* visit = new CountVisitor();
	while(it->is_done() == false)
	{
		Base* c = it->current();
		c->accept(visit);
		it->next();
	}

	EXPECT_EQ(visit->op_count(), 1);
	EXPECT_EQ(visit->add_count(), 1);

}
TEST(IteratorTests, subTest)
{
        Base* five  = new Op(5);
        Base* two  = new Op(2);

        Base* subtraction = new Sub(five, two);

        Base* dummy = new Sub(subtraction, two);

        Iterator* it =  dummy->create_iterator();

        it->first();

        CountVisitor* visit = new CountVisitor();
        while(it->is_done() == false)
        {
                Base* c = it->current();
                c->accept(visit);
                it->next();
        }

        EXPECT_EQ(visit->op_count(), 1);
        EXPECT_EQ(visit->sub_count(), 1);

}
TEST(IteratorTests, multTest)
{
        Base* nine  = new Op(9);
        Base* five  = new Op(5);

        Base* multiply = new Mult(nine, five);

        Base* dummy = new Mult(multiply, five);

        Iterator* it =  dummy->create_iterator();

        it->first();

        CountVisitor* visit = new CountVisitor();
        while(it->is_done() == false)
        {
                Base* c = it->current();
                c->accept(visit);
                it->next();
        }

        EXPECT_EQ(visit->op_count(), 1);
        EXPECT_EQ(visit->mult_count(), 1);

}
TEST(IteratorTests, divTest)
{
        Base* four  = new Op(4);
        Base* two  = new Op(2);

        Base* division = new Div(four, two);

        Base* dummy = new Div(division, two);

        Iterator* it =  dummy->create_iterator();

        it->first();

        CountVisitor* visit = new CountVisitor();
        while(it->is_done() == false)
        {
                Base* c = it->current();
                c->accept(visit);
                it->next();
        }

        EXPECT_EQ(visit->op_count(), 1);
        EXPECT_EQ(visit->div_count(), 1);

}
TEST(IteratorTests, powTest)
{
        Base* four  = new Op(4);
        Base* two  = new Op(2);

        Base* power = new Pow(four, two);

        Base* dummy = new Pow(power, two);

        Iterator* it =  dummy->create_iterator();

        it->first();

        CountVisitor* visit = new CountVisitor();
        while(it->is_done() == false)
        {
                Base* c = it->current();
                c->accept(visit);
                it->next();
        }

        EXPECT_EQ(visit->op_count(), 1);
        EXPECT_EQ(visit->pow_count(), 1);

}
TEST(IteratorTests, randTest)
{
        Base* random = new Rand();
	Base* one = new Op(1);
        Base* dummy = new Div(random, one);

        Iterator* it =  dummy->create_iterator();

        it->first();

        CountVisitor* visit = new CountVisitor();
        while(it->is_done() == false)
        {
                Base* c = it->current();
                c->accept(visit);
                it->next();
        }

        EXPECT_EQ(visit->op_count(), 1);
        EXPECT_EQ(visit->rand_count(), 1);

}

