#include <iostream>

using namespace std;

const int N = 110;
int st[4 * N + 3], lazy_a[4 * N + 3], lazy_b[4 * N + 3];


/// calculeaza valoarea, tinand cont de lazy
int get_value(int nod, int left, int right) { 
	if(lazy_a[nod] == 0 && lazy_b[nod] == 0)
		return st[nod];
	int k = (right - left + 1);
	return st[nod] + lazy_b[nod] * k + lazy_a[nod] * (k - 1) * k / 2; 
	// atentie la overflow 
}


void push(int nod, int left, int right) {
	
	st[nod] = get_value(nod, left, right);
	int mid = (left + right) / 2;

	if(lazy_a[nod] != 0 || lazy_b[nod] != 0) {	
		if(left != right) {// nu sunt in frunza
			//stanga
			lazy_a[2 * nod] 	  += lazy_a[nod];
			lazy_b[2 * nod] 	  += lazy_b[nod];

			lazy_a[2 * nod + 1]   += lazy_a[nod];
			lazy_b[2 * nod + 1]   += lazy_b[nod] + lazy_a[nod] * (mid - left + 1);
		}
		lazy_a[nod] = 0;
		lazy_b[nod] = 0;
	}
}


void upd(int nod, int l, int r, int ul, int ur, int a, int b) {
	
	push(nod, l, r);

	if(ul <= l and r <= ur) { // (l, r) e inclus in (ul, ur)
		lazy_a[nod] += a;
		lazy_b[nod] += b;
		return;
	}
	
	int mid = (l + r) / 2;
	if(mid >= ul)
		upd(2 * nod , l, mid, ul, ur, a, b);
	if(mid + 1 <= ur) 
		upd(2 * nod + 1, mid + 1, r, ul, ur, a, b);

	st[nod] = get_value(2 * nod, l, mid)
				 + get_value(2 * nod + 1, mid + 1, r);
}

int que(int nod, int l, int r, int ql, int qr) {

	push(nod, l, r);

	if(ql <= l and r <= qr) //(l, r) e inclus in intervalul de query 
		return st[nod];

	int mid = (l + r) / 2, sum_stanga = 0, sum_dreapta = 0;
	if(mid >= ql) // intervalul (l, mid) se intersecteaza cu (ql, qr)
		sum_stanga = que(2 * nod, l, mid, ql, qr);
	if(mid + 1 <= qr) // intervalul (mid+1, r) se intersecteaza cu (ql, qr)
		sum_dreapta = que(2 * nod + 1, mid + 1, r, ql, qr);

	return sum_stanga + sum_dreapta;
}





int main() {


	upd(1, 1, N , 1, 4, 1, 1);
	//[1, 2, 3, 4, 0, 0, 0, 0]
	// upd(1, 1, N , 2, 5, 3);
	// upd(1, 1, N , 3, 3, 2);

	cout << que(1, 1, N, 1, 1) << ' ';
	cout << que(1, 1, N, 2, 2) << ' ';
	cout << que(1, 1, N, 3, 3) << ' ';
	cout << que(1, 1, N, 4, 4) << ' ';

	upd(1, 1, N , 2, 5, 0, 2);
	//[1, 4, 5, 6, 2, 0, 0, 0]
	cout << que(1, 1, N, 1, 6) << ' ';

	// cout << que(1, 1, N, 5, 6);
	// cout << que(1, 1, N, 3, 4);
}


















int aib[N];

int lsb(int x) {
	return ((x ^ (x - 1)) + 1) / 2;
}

void upd_aib(int pos, int val) {
	while(pos <= N) {
		aib[pos] += val;
		pos += lsb(pos);
	}
}

int que_aib(int pos) {
	int sum = 0;
	while(pos != 0) {
		sum += aib[pos]; // aib[pos] tine suma pe interv (pos - lsb(pos) + 1, pos)
		pos -= lsb(pos);
	}
	return sum;
}
