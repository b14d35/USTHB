#include <stdlib.h>
#include <ctype.h>

int MyAtoi(string) register char *string;{
    register int result = 0;
    register unsigned int digit;
    int sign = 1;
    while (isspace(*string)) {
		string++;
    }
    if(*string == '('){
		sign = -1;
		string += 2;
	}else if (*string == '+') {
		string++;
    }
    for ( ; ; string++) {
		digit = *string - '0';
		if (digit > 9) {
			break;
		}
		result *= 10;
		result += digit;
    }
	return sign * result;
}
