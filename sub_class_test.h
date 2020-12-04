TEST(SubclassTest, get_left_rightAddTest){
	Base* one = new Op(1);
	Base* two = new Op(2);

	Base* add = new Add(one,two);
	
	EXPECT_EQ(add->get_left(),one);
	EXPECT_EQ(add->get_right(),two);
}
TEST(SubclassTest, get_left_rightSubTest){
        Base* one = new Op(1);
        Base* two = new Op(2);

        Base* sub = new Sub(one,two);

        EXPECT_EQ(sub->get_left(),one);
	EXPECT_EQ(sub->get_right(),two);
}
TEST(SubclassTest, get_left_rightMultTest){
        Base* one = new Op(1);
        Base* two = new Op(2);

        Base* mult = new Mult(one,two);

        EXPECT_EQ(mult->get_left(),one);
	EXPECT_EQ(mult->get_right(),two);
}
TEST(SubclassTest, get_left_rightDivTest){
        Base* one = new Op(1);
        Base* two = new Op(2);

        Base* div = new Div(one,two);

        EXPECT_EQ(div->get_left(),one);
	EXPECT_EQ(div->get_right(),two);
}
TEST(SubclassTest, get_left_rightPowTest){
        Base* one = new Op(1);
        Base* two = new Op(2);

        Base* pow = new Pow(one,two);

        EXPECT_EQ(pow->get_left(),one);
	EXPECT_EQ(pow->get_right(),two);
}
