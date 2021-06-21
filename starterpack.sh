# !sh
mkdir $1
echo "#include <iostream>
#include <vector>
#include <algorithm>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
typedef long long ll;
using namespace std;

int main() {
	FAST;
}
" > $1/$1.cpp
