#include "common.h"
#include <time.h>

void Spin(unsigned int seconds) {
	clock_t start = clock();
	while ((double)(clock() - start) / CLOCKS_PER_SEC < seconds) {
	}
}
