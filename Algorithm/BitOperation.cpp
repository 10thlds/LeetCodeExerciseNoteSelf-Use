/*
The characteristics of "exclusive OR": {[(\In Binary/)]}
(1). 0 ^ A == A;
(2). A ^ B == B ^ A;			// Commutative property
(3). A ^ B ^ C == A ^ (B ^ C);	// Associative property
1 ^ 1 == 0;
1 ^ 0 == 1;
*/

/*
For AND, {[(\In Binary/)]}, 1 & 1 == 1. Otherwise == 0.
*/

/* Giving a vector<int> which contains a lot of numbers that appear even times:

a). Only one number only appears only once, find it.

b). Two numbers only appear only once, find them.
*/

class SolutionA{
public:
	std::vector<int> nums{1,1,1,1,2,3,2,3,4,5,6,7,6,5,4,8,8};
	int solutionA(){
		int eor = 0;
		for (int i = 0; i<nums.size(); i++){
			eor = eor ^ nums[i];  // exclusive OR
		}
		return eor;
	}
};

class SolutionB{
public:
	std::vector<int> nums{1,1,4,2,3,2,3,4,5,6,7,6,5,8,8,9};
	void solutionB(){
		int aXORb = 0;
		for (int curNum : nums){
			aXORb ^= curNum;  // exclusive OR
		}
		// Now, aXORb == A ^ B
		// A does not equal to B, so that there must be some bits which result to 1 in aXORb
		// Suppose the 8th bit of aXORb is 1, bring a new variable eorR= 0, repeat XOR operation with numbers whose 8th bit is 1 or 0
		// Then we find eorR == one of A and B; // Finally aXORb ^ eorR == A ^ B ^ A(or B) == A or B
		
		int rightOne = aXORb & (~aXORb + 1); //for example:
		// aXORb 		== 1010111100
		// ~aXORb 		== 0101000011
		// ~aXORbr + 1 		== 0101000100
		// aXORb & (~aXORb + 1)	== 0000000100
		
		int firstOne = 0;
		for (int cur : nums){
			if ((cur & rightOne) == 0){ // repeat eOR operation with numbers whose 8th bit is 1 or 0
				firstOne ^= cur;
			}
		}
		int anotherOne = aXORb^firstOne;
		std::cout << firstOne << " " << anotherOne << std::endl;
	}
};
