#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream cin("interesant.in");
ofstream cout("interesant.out");

bool is_in(const string& a, const string& b) {
	for (int i = 0, j = 0; i < a.size(); i++) {
		while (j < b.size() && a[i] != b[j]) {
			j++;
		}
		if (j == b.size()) {
			return false;
		} else {
			j++;
		}
	}
	return true;
}

void cerinta2(const vector<string>& v) {
	vector<bool> interesant(v.size(), true);

	int cnt = 0;
	for (int i = 0; i + 1 <= v.size(); i++) {
		if (!interesant[i]) { continue; }
		for (int j = i + 1; j < v.size(); j++) {
			if (is_in(v[j], v[i])) {
				interesant[j] = false;
			} else if (is_in(v[i], v[j])) {
				interesant[i] = false;
			}
		}
		if (interesant[i]) {
			cnt++;
		}
	}

	cout << cnt << "\n";
	for (int i = 0; i < v.size(); i++) {
		if (interesant[i]) {
			cout << v[i] << "\n";
		}
	}
}

void cerinta1(const vector<string>& v) {
	string best = "";
	for (const auto& s : v) {
		if (s.size() > best.size()) {
			best = s;
		} else if (s.size() == best.size() && s < best) {
			best = s;
		}
	}
	cout << best << "\n";
}

int main() {
	int c; cin >> c;
	
	int n; cin >> n;
	vector<string> v(n);
	for (auto& s : v) {
		cin >> s;
	}

	if (c == 1) {
		cerinta1(v);
	} else {
		cerinta2(v);
	}

	return 0;
}
