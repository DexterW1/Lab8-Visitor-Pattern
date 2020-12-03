 

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

