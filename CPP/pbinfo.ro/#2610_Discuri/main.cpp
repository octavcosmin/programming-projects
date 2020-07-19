#include <bits/stdc++.h>

using namespace std;

int N;
vector<double> raze;
stack<int> sol;

bool verificare(int i) {
    int r1 = raze[i], r2 = raze[i-1], r3 = raze[i-2];
    int c = r1+r3, b = r1+r2, a = r2+r3;
    double myCos = (double)(b*b+c*c-a*a)/(double)(2*b*c);

    double verifC = sqrt(a*a + b*b - 2*a*b*myCos);
    return (c == verifC);
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; ++i) {
        double temp;
        cin >> temp;
        raze.push_back(temp);
    }

    int nrDis = 0;
    for(int i = N-1; i >= 2; --i) {
        printf("%d = %d\n", i, verificare(i));
        if(!verificare(i)) {
            raze.erase(raze.begin()+i-1);
            sol.push(i-1);
        }
    }

    cout << sol.size() << '\n';
    while(!sol.empty()) {
        cout << sol.top() << '\n';
        sol.pop();
    }
    return 0;
}
