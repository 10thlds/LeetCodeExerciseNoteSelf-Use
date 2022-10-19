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
	vector<int> nums {1,1,1,1,2,3,2,3,4,5,6,7,6,5,4,8,8};
	int solutionA(){
		int eor = 0;
		for (int i = 0; i<nums.size(), i++){
			eor = eor ^ nums[i];  // exclusive OR
		}
		return eor;
	}
};

class SolutionB{
public:
	vector<int> nums {1,1,1,2,3,2,3,4,5,6,7,6,5,4,8,8};
	void solutionB(){
		int eor = 0;
		for (int curNum : nums){
			eor ^= curNum;  // exclusive OR
		}
		// Now, eor == A ^ B
		// A does not equal to B, so that there must be some bits which result to 1 in eor
		// Suppose the 8th bit of eor is 1, bring a new variable eorR= 0, repeat eOR operation with numbers whose 8th bit is 1 or 0
		// Then we find eorR == one of A and B; // Finally eor ^ eorR == A ^ B ^ A(or B) == A or B
		
		int rightOne = eor & (~eor + 1);
		// eor == 1010111100
		// ~eor == 0101000011
		// ~eor + 1 == 0101000100
		// eor & (~eor + 1) == 0000000100
		
		int onlyOne = 0;
		for (int cur : nums){
			if ((cur & rightOne) == 0){ // repeat eOR operation with numbers whose 8th bit is 1 or 0
				onlyOne ^= cur;
			}
		}
		int anotherOne = eor^onlyOne;
		std::cout << onlyOne << " " << anotherOne << std::endl;
	}
};
