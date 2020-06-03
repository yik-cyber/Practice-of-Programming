#include<bits/stdc++.h>
using namespace std;

int maze[6][6];
bool visits[6][6];
struct Point{
	int x, y, f;
	Point(int _x, int _y, int _f):x(_x), y(_y), f(_f){
	}
	Point(){
	}
}myque[110];
int head = 0;
int tail = 1;

int main(){
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			cin >> maze[i][j];
		}
	}
	memset(visits, false, sizeof(visits));
	myque[0] = Point(0,0,-1);
	Point p;
	vector<Point> path;
	while(head != tail){
		p = myque[head];
		visits[p.x][p.y] = true;
		if(p.x == 4 && p.y == 4){
			while(p.f != -1){
				path.push_back(p);
				p = myque[p.f];
			}
			path.push_back(Point(0,0,-1));
			break;
		}
		if(p.x+1 < 5 && maze[p.x+1][p.y] == 0 && !visits[p.x+1][p.y]){
			myque[tail] = Point(p.x+1, p.y, head);
			tail++;
		}
		if(p.y+1 < 5 && maze[p.x][p.y+1] == 0 && !visits[p.x][p.y+1]){
			myque[tail] = Point(p.x, p.y+1, head);
			tail++;
		}
		if(p.x-1 >= 0 && maze[p.x-1][p.y] == 0 && !visits[p.x-1][p.y]){
			myque[tail] = Point(p.x-1, p.y, head);
			tail++;
		}
		if(p.y-1 >= 0 && maze[p.x][p.y-1] == 0 && !visits[p.x][p.y-1]){
			myque[tail] = Point(p.x, p.y-1, head);
			tail++;
		}
		head++;
	}
	int l = path.size();
	for(int i = l - 1; i >= 0; i--){
		cout << "(" << path[i].x << ", " << path[i].y << ")" << endl;
	} 
	return 0;
}
