/* welcome to the entropy department */
#include "../mathyy/mathyy.h"
#include <stddef.h>
long double entropy_calc (const unsigned char* data, size_t len) {
	unsigned int freq[256] = {0};
	/* slower = more accuracy, right? */
	for (unsigned long long i = 0ULL; i <= 255; i++) {
		for (unsigned long long j = 0ULL; j<len; j++) {
			!((unsigned long long)data[j] == i)?:freq[i]++;
		}
	}
	long double sum = 0;
	for (unsigned long long i = 0ULL; i < 256; i++) {
		if (!freq[i]) goto sip;
		sum += ((long double)freq[i]/(long double)len) * (ln((long double)freq[i]/(long double)len)/ln(2));
sip:
	}
	return -1 * sum;
}
