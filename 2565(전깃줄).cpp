//������ - DP
#include<cstdio>
#include<vector>
using namespace std;

int N;
vector< pair<int, int> > p;
vector<int> cross;
int main() {
	int a, b;
	scanf("%d", &N);
	
	//�Է¹ް� ������ �� ���� cross �� ����
	for (int i = 0; i < N; i++) {
		int cross_counter = 0;
		scanf("%d %d", &a, &b);
		p.push_back(make_pair(a, b));
		for (int j = 0; j < p.size()-1; j++) {
			int pa = p[j].first, pb = p[j].second;
			
			if ((pa - a) * (pb - b) < 0)
				cross_counter++;
		}
	}
}