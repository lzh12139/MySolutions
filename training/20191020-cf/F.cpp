#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-8;
const int N = 81000;

int sgn(double x){
	if (fabs(x) < eps) return 0;
	if (x < 0) return -1;
	return 1;
}

struct Point {
	double x, y;
	Point(){};
	Point(double _x, double _y) : x(_x), y(_y){};
	Point operator+(const Point &a) const {
		return Point(x + a.x, y + a.y);
	}
	Point operator-(const Point &a) const {
		return Point(x - a.x, y - a.y);
	}
	double operator*(const Point &a) const {
		return x * a.x + y * a.y;
	}
	double operator^(const Point &a) const {
		return x * a.y - y * a.x;
	}
};

struct Line {
	Point s, e;
	Line(){};
	Line(Point _s, Point _e) : s(_s), e(_e){};
	// 两直线相交   0代表重合  1代表平行  2代表相交
	pair<int, Point> operator&(const Line &a) const {
		Point res = s;
		if (sgn((s - e) ^ (a.s - a.e)) == 0) {
			if (sgn((s - a.e) ^ (a.s - a.e)) == 0)
				return make_pair(0, res);
			return make_pair(1, res);
		}
		double t = ((s - a.s) ^ (a.s - a.e)) / ((s - e) ^ (a.s - a.e));
		res.x += (e.x - s.x) * t;
		res.y += (e.y - s.y) * t;
		return make_pair(2, res);
	}
	// 两线段相交   0代表不相交  1代表相交（不穿过） 2代表相交（穿过） 3代表重合（有复数个交点）
	pair<int, Point> operator^(const Line &a) const {
		Point res = s;
		double cmp1 = sgn((a.s - s) ^ (a.e - s)) * sgn((a.s - e) ^ (a.e - e));
		double cmp2 = sgn((s - a.s) ^ (e - a.s)) * sgn((s - a.e) ^ (e - a.e));
		if (cmp1 == 1 || cmp2 == 1)
			return make_pair(0, res);

		if (sgn((a.s - a.e) ^ (s - e)) == 0)
			if (max(a.s.x, a.e.x) >= min(s.x, e.x) && max(s.x, e.x) >= min(a.s.x, a.e.x) &&
				max(a.s.y, a.e.y) >= min(s.y, e.y) && max(s.y, e.y) >= min(a.s.y, a.e.y))
				return make_pair(3, res);
			else
				return make_pair(0, res);

		double t = ((s - a.s) ^ (a.s - a.e)) / ((s - e) ^ (a.s - a.e));
		res.x += (e.x - s.x) * t;
		res.y += (e.y - s.y) * t;
		if (cmp1 + cmp2 == -2)
			return make_pair(2, res);
		else
			return make_pair(1, res);
	}
};

double dist(Point a, Point b) {
	return sqrt((a - b) * (a - b));
}

double getangle(Line a) {
	return atan2(a.e.y - a.s.y, a.e.x - a.s.x);
}

bool cmp(Line a, Line b) {
	double A = getangle(a), B = getangle(b);
	if (sgn(A - B) == 0)
		return sgn((a.e - a.s) ^ (b.e - a.s)) > 0;
	return sgn(A - B) == -1;
}

Point point[N + 10]; // 答案(半平面交的点)
Line q[2 * N + 10];
int halfplane(Line line[], int n) {
	sort(line + 1, line + 1 + n, cmp);
	int cnt = 0;
	for (int i = 1; i < n; i++)
		if (sgn(getangle(line[i]) - getangle(line[i + 1])))
			line[++cnt] = line[i];
	line[++cnt] = line[n];
	int l = 1, r = 0;
	for (int i = 1; i <= cnt; i++) {
		while (l < r && sgn(((q[r] & q[r - 1]).second - line[i].s) ^ (line[i].e - line[i].s)) == 1)
			r--;
		while (l < r && sgn(((q[l] & q[l + 1]).second - line[i].s) ^ (line[i].e - line[i].s)) == 1)
			l++;
		q[++r] = line[i];
	}
	while (l < r && sgn(((q[r] & q[r - 1]).second - q[l].s) ^ (q[l].e - q[l].s)) == 1)
		r--;
	while (l < r && sgn(((q[l] & q[l + 1]).second - q[r].s) ^ (q[r].e - q[r].s)) == 1)
		l++;

	if (r - l <= 1) return -1;
	for (int i = l, o = 1; i < r; i++, o++)
		point[o] = (q[i] & q[i + 1]).second;
	point[r - l + 1] = (q[l] & q[r]).second;
	return r - l + 1;
}

// 判断点的顺序，计算面积<0，则顺序为逆时针时返回true
bool judge(Point p[], int n) {
	double pend = 0;
	for (int i = 2; i < n; i++)
		pend += ((p[i] - p[1]) ^ (p[i + 1] - p[1]));
	return pend < 0;
}
double cal(Point p[],int n){
	double res=0;
	for(int i=2;i<n;i++)res+=((p[i]-p[1])^(p[i+1]-p[1]));
	return res/2.0;
}

Line line[N + 10],cur[N+10];
int main() {
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lf%lf%lf%lf",&cur[i].s.x,&cur[i].s.y,&cur[i].e.x,&cur[i].e.y);
		if(cur[i].s.x>cur[i].e.x)swap(cur[i].s.x,cur[i].e.x);
		if(cur[i].s.y>cur[i].e.y)swap(cur[i].s.y,cur[i].e.y);
	}
	int p;scanf("%d",&p);
	Point a,b;scanf("%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y);
	long long S=1ll*abs(a.x-b.x)*abs(a.y-b.y);

	int l=1,r=1;
	while(l<=r){
		printf("%d %d\n",l,r);
		int mid=l+r>>1;
		mid=5;

		int cnt=0;
		line[++cnt]=Line(a,Point(b.x,a.y));
		line[++cnt]=Line(Point(b.x,a.y),b);
		line[++cnt]=Line(b,Point(a.x,b.y));
		line[++cnt]=Line(Point(a.x,b.y),a);
		for(int i=1;i<=n;i++){
			Point p1,p2,p3,p4;
			p1=p2=cur[i].s,p3=p4=cur[i].e;
			p1.x-=mid,p1.y-=mid;
			p2.x-=mid,p2.y+=mid;
			p3.x+=mid,p3.y+=mid;
			p4.x+=mid,p4.y-=mid;
			line[++cnt]=Line(p1,p4);
			line[++cnt]=Line(p4,p3);
			line[++cnt]=Line(p3,p2);
			line[++cnt]=Line(p2,p1);
		}
		int tmp=halfplane(line,cnt);
		double ans=cal(point,tmp);
		for(int i=1;i<=tmp;i++)printf("%lf %lf\n",point[i].x,point[i].y);
		printf("%lf\n",ans);
		if(sgn(ans-S*p/100.0)>=0)r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",l);
}
