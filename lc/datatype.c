int main() {
	
	//datatypes
	// char		-(2^7) to (2^7-1)
	// int		-(2^31) to (2^31-1)
	// float
	// double 
	
	//modifiers
	// unsigned		{char, int}		0 to +1 power
	// short		{int}			-(2^15) to (2^15 - 1)
	// long			{int}			-(2^63) to (2^63 - 1)
	// long long	{int}			 -- same as above --
	// const		{all datatypes}
	
	unsigned char a;
	unsigned int b;
	float f;
	double d;
	
	unsigned char m = -10;
	unsigned int n = 10;			// unsigned n = 10;
	unsigned short int o = 10;		// unsigned short o = 10;
	unsigned long int p = 12;		// unsigned long p = 10;
	
	long int q= 1;					// long q = 1;
	short int r = 1;				// short r = 1;
	
	const int s;
	const t = 10;
	
	// constants
	// 	character constant
	'a';
	'\n';
	'\022';
	
	// integer
	10;		// int constant
	10u;	// unsigned int
	077;
	0xba;
	
	//float
	0.2f;
	101.3f;
	
	//double
	0.2;
	101.0;
	
	#define PI if(d) {}
	// draw(0,0,20,(3.14)*2);
}

