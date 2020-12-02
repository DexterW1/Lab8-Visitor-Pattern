TEST(IteratorTests, addTest)
{
	Base* one  = new Op(1);
	Base* two  = new Op(2);

	Base* addition = new Add(one, two);

	Base* dummy = new Add(addition, one);

	Iterator* it = new PreorderIterator(dummy);

	it->first();

	CountVisitor* visit = new CountVisitor();
	while(it->is_done() == false)
	{
		Base* c = it->current();
		c->accept(visit);
		it->next();
	}

	EXPECT_EQ(visit->op_count(), 2);
	EXPECT_EQ(visit->add_count(), 1);

}
