#define GRIDDEPTH 4
#include <iostream>
#include <map>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

class CollisionGrid {

	public:
		void setObjects(vector< pair<int,int> > objs);
		
		void init(int depth);
	
	private:
		CollisionGrid *subgrids;
		vector< pair<int,int> > m_objects;
		
		int m_maximum_depth;
};

void CollisionGrid::init(int depth) {
	
	m_maximum_depth = depth;
	
	// Create 2x2 subgrid
	if (m_maximum_depth > 1) {
		
		subgrids = new CollisionGrid[4];
		
		for (uint i = 0; i < 4; i++) {
			
			subgrids[i].init(m_maximum_depth-1);
		}
	}
}

void CollisionGrid::setObjects(vector< pair<int,int> > objects) {

	float mean_x = 0, mean_y = 0;
	
	for (uint i=0; i<objects.size(); i++) {
		
		this->m_objects.push_back(objects[i]);
		
		mean_x += objects[i].first;
		mean_y += objects[i].second;
	}
	
	mean_x /= objects.size();
	mean_y /= objects.size();
	
	vector< pair<int,int> > ul, ur, ll, lr;

	for (uint i=0; i<objects.size(); i++) {
		
		if (objects[i].first < mean_x) {
			
			if (objects[i].second < mean_y) {
				
				ul.push_back(objects[i]);
			}
			else {
				
				ll.push_back(objects[i]);
			}
		}
		else {
			
			if (objects[i].second < mean_y) {
				
				ur.push_back(objects[i]);
			}
			else {
				
				lr.push_back(objects[i]);
			}
		}
	}
	
	if (m_maximum_depth > 1) {
		subgrids[0].setObjects(ul);
		subgrids[1].setObjects(ur);
		subgrids[2].setObjects(lr);
		subgrids[3].setObjects(ll);
	}
}

int main() {
	CollisionGrid grid;
	grid.init(GRIDDEPTH);
	vector <pair <int, int> > points;
	//populate points
	srand(time(NULL));
	time_t start, finish;
	timespec ts_start, ts_finish;
	for (int numPoints = 10; numPoints <= 10000000; numPoints *= 10) {
		for (int i = 0; i < numPoints; ++i) {
			points.push_back(pair<int, int>(rand() % 100, rand() % 100));
		}
		start = time(NULL);
		clock_gettime(CLOCK_REALTIME, &ts_start);
		grid.setObjects(points);
		clock_gettime(CLOCK_REALTIME, &ts_finish);
		finish = time(NULL);
		cout << "With " << numPoints << "points, grid creation took " << (long long)(ts_finish.tv_nsec - ts_start.tv_nsec) << " time units\n";
	}
	
	return 0;
}
