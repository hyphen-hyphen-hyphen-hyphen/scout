#include "mathyy.h"
long double power (int base, long double exp) {
	long double reslt = 1.0L;
	for (int i=1; i<base+1;i++) {
		reslt *= exp;
		
	}
	return reslt;
}
long double ln (long double xx) {
	long double lnans = 0;
	for (int i = 1; i<10; i += 2) {
		lnans += (power(i, (xx-1)/(xx+1)))/i;
	}
	lnans *= 2;
	return lnans;
}


long long factorial (int numb) {
	long long oth_numb = 1;
	for (int j = 1; j < numb+1; j++) {
		oth_numb *= j;
	}
	return oth_numb;
}
long double compute_e() {
	long double e = 1.0L;
	
	for (int i = 1; i < 50; i++) {
		e += 1.0L/ factorial(i);
	}
	return e;
}
