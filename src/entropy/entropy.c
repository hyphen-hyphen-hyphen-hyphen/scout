/* welcome to the entropy department */
#include "../mathyy/mathyy.h"
#include <stddef.h>
long double entropy_calc (const unsigned char* data, size_t len) {
	unsigned int freq[256] = {0};
	/* for (unsigned long long i = 0ULL; i <= 255; i++) {
		for (unsigned long long j = 0ULL; j<len; j++) {
			!((unsigned long long)data[j] == i)?:freq[i]++;
		}
	} */
	for (unsigned long long J = 0ULL; J<len;J++) freq[(unsigned long long)data[J]]++;
	long double sum = 0;
	long double ln2 = 0.69314718056;
	for (unsigned long long i = 0ULL; i < 256; i++) {
		if (!freq[i]) goto skip;
		sum += ((long double)freq[i]/(long double)len) * (ln((long double)freq[i]/(long double)len)/ln2);
skip:
	}
	return -1 * sum;
}
