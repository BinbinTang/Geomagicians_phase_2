#include "pointSet.h"
#include "lmath.h"

int PointSet::addPoint(LongInt x1, LongInt y1){
	struct MyPoint thisPoint;
	thisPoint.x = x1;
	thisPoint.y = y1;
	thisPoint.z = 0;

	myPoints.push_back(thisPoint);
	return (myPoints.size());
}

int PointSet::inCircle(int p1Idx, int p2Idx, int p3Idx, int pIdx) {
	MyPoint a = this->myPoints.at(p1Idx-1);
	MyPoint b = this->myPoints.at(p2Idx-1);
	MyPoint c = this->myPoints.at(p3Idx-1);
	MyPoint p = this->myPoints.at(pIdx-1);

	int det1 = signDet(a.x, a.y, 1,
		b.x, b.y, 1,
		c.x, c.y,1);
	int det2 = signDet(a.x - p.x, a.y - p.y, square((a.x - p.x))+square(a.y - p.y),
		b.x - p.x, b.y - p.y, square(b.x - p.x)+square(b.y - p.y),
		c.x - p.x, c.y - p.y, square(c.x - p.x)+square(c.y - p.y));
	return det1*det2;
}

int PointSet::sameSide(MyPoint p1, MyPoint p2, MyPoint a, MyPoint b){
	return signDet2D(b.x-a.x, b.y-a.y, p1.x - a.x, p1.y - a.y)*
		signDet2D(b.x-a.x, b.y-a.y, p2.x - a.x, p2.y - a.y);
}

int PointSet::inTri(int p1Idx, int p2Idx, int p3Idx, int pIdx) {
	MyPoint a = this->myPoints.at(p1Idx-1);
	MyPoint b = this->myPoints.at(p2Idx-1);
	MyPoint c = this->myPoints.at(p3Idx-1);
	MyPoint p = this->myPoints.at(pIdx-1);

	if(sameSide(p,a,b,c)==1 && sameSide(p,b,a,c)==1 && sameSide(p,c,a,b)==1){
		return 1;
	}else if(sameSide(p,a,b,c)==-1 || sameSide(p,b,a,c)==-1 || sameSide(p,c,a,b)==-1) {
		return -1;
	}else{
		return 0;
	}
				
}