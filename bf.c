#include <stdio.h>

const int COLUMN_MAX = 10;

int  p, r, q, d_num, line_num, p_num, line, cnt, i;
char a[50000], f[50000], b, o, *s = f;

void interpret(char *c) {
	char *d;
	r++;
	while (*c) {
		switch (o = 1, *c++) {
			case '<':
				p--;
				break;
			case '>':
				p++;
				break;
			case '+':
				a[p]++;
				break;
			case '-':
				a[p]--;
				break;
			case '.':
				putchar(a[p]);
				fflush(stdout);
				break;
			case ',':
				a[p] = getchar();
				fflush(stdout);
				break;
			case '[':
				for (b = 1, d = c; b && *c; c++) b += *c == '[', b -= *c == ']';
				if (!b) {
					c[-1] = 0;
					while (a[p]) interpret(d);
					c[-1] = ']';
					break;
				}
			case ']':
				puts("UNBALANCED BRACKETS");
				return;
			case '#':
				if (q > 2) {
					p_num = p / COLUMN_MAX;
					i = 0;
					for (line = 0; line < line_num; ++line) {
						for (cnt = 0; cnt < COLUMN_MAX && i < d_num; ++cnt) printf("%3d ", a[i++]);
						printf("\n");
						if (line == p_num) printf("%*s@%d\n", 4 * (p % COLUMN_MAX) + 3, "^", p);
					}
				}
				break;
			default:
				o = 0;
		}
		if (p < 0 || p > 1000) {
			puts("RANGE ERROR");
			return;
		}
	}
	r--;
}

int main(int argc, char *argv[]) {
	FILE *z;
	q = argc;
	if (q > 2) sscanf(argv[2], "%d", &d_num), line_num = (d_num - 1) / 10 + 1;
	if (z = fopen(argv[1], "r")) {
		while ((b = getc(z)) > 0)
			* s++ = b;
		*s = 0;
		interpret(f);
	}
	return 0;
}
