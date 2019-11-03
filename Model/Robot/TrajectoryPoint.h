#pragma once
#include <vector>
//#include <deque> 

class TrajectoryPoints
{
public:
	double* q;
	double* v;
	double* a;
	int TrajLength;
//	ULONG dooo(ULONG a);
	TrajectoryPoints()
	{
		q = new double[1000000];
		v = new double[1000000];
		a = new double[1000000];
	}
	~TrajectoryPoints()
	{
		delete q;
		delete v;
		delete a;
	}
	void FillTraj(double* qq, double* vv, double* aa, int len) {
		q = qq;
		v = vv;
		a = aa;
		TrajLength = len;
	}
};
class TrajectoryPoint
{
public:
	double Q;
	double V;
	TrajectoryPoint(double q1, double v1)
	{
		Q = q1;
		V = v1;
	}
	TrajectoryPoint()
	{
		Q = V = 0.0;
	}
};

template<class T>
class TrajectoryPointList
{
public:
	bool init = true;
	//deque<T> q;// = new List<T>();
	std::vector<T> q;// = new List<T>();
	std::vector<T> v;// = new List<T>();
	std::vector<T> a;// = new List<T>();
	int TrajLength = 0;
	TrajectoryPointList()
	{
	}

	~TrajectoryPointList()
	{
		/*delete q;
		delete v;
		delete a;*/
	}

	void AddPoint(T qq, T vv, T aa)
	{
		//q.push
		q.push_back(qq);
		v.push_back(vv);
		a.push_back(aa);
		TrajLength++;
	}

	void clearAll() {
		q.clear();
		v.clear();
		a.clear();
		TrajLength = 0;
	}

double getPoint(int i) {
	
	return q.at(i);
		//T point = q[0];
		//q.erase(q.begin());		
		//v.erase(v.begin());
		//a.erase(a.begin());
		//return point;// q.pop_front();
	}

double getV(int i) {

    return v.at(i);
        //T point = q[0];
        //q.erase(q.begin());
        //v.erase(v.begin());
        //a.erase(a.begin());
        //return point;// q.pop_front();
    }

double getAcc(int i) {

    return a.at(i);
        //T point = q[0];
        //q.erase(q.begin());
        //v.erase(v.begin());
        //a.erase(a.begin());
        //return point;// q.pop_front();
    }

	void FillTraj(T qq[], T vv[], T aa[], int len)
	{		
		q.erase();
		q = std::vector<int> (qq, qq + sizeof qq / sizeof qq[0]);
		//q = q.insert(0, sizeof(qq) / sizeof(*qq), qq);
		v.erase();
		v = std::vector<int>(vv, vv + sizeof vv / sizeof vv[0]);
		//v = v.insert(0, sizeof(vv) / sizeof(*vv), vv);
		a.erase();
		a = std::vector<int>(aa, aa + sizeof aa / sizeof aa[0]);
		//a = a.insert(0, sizeof(aa) / sizeof(*aa), aa);
		TrajLength = len;
	}
	
};
