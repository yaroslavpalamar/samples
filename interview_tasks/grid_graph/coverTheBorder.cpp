#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * 1. Radars cover the border but overlaps sometimes
 * 2. The strip is represented as a line, which is L meters long.
 * 3. For each radar we know the left and right end of its coverage strip relative
 * 		to the left end of the border.
 *		Hence, all such coverage strips will begin and end somewhere in the range [0, L]
 * 4. You will have to write a function, which receives as arguments L and
 * 			a list of pairs of integers -
 * 			the radar coverage strips ends.
 * 5. You can assume that 1 <= L <= 10^9 and there will be no more than 1,000 radars.
 * example:
 * L = 100
	radars = [ [5, 10], [3, 25], [46, 99], [39, 40], [45, 50] ]
	result 77
 * */

int cover_the_border(int l, const vector< pair<int,int>> &radars) {
    vector<pair<int,int> >radar(radars);
    sort(radar.begin(), radar.end());
    int start = 0, end = 0;
    int cover = 0;
    for (int i = 0; i < radar.size(); i++) {
        if (i == 0 || radar[i].first > end) {
            start = radar[i].first;
            end = radar[i].second;
            cover += end - start ;
        } else if (radar[i].second > end) {
            cover += radar[i].second - end;
            start = radar[i].first;
            end = radar[i].second;
        }
    }
    return cover;
}

int main() {
	int L=100;
	vector< pair<int, int> > radars = {make_pair(5,10), make_pair(3,25), make_pair(46,99),
							make_pair(39,40),make_pair(45,59)};
	cout << cover_the_border(L, radars) <<endl;
	return 0;
}
