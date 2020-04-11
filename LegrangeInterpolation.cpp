#include<iostream>
using namespace std;
double* getL(double** dataValues,int nPoints,double pointOfInterest) {
	double den = 1, num = 1;
	double *L = new double[nPoints];
	for (int i = 0; i < nPoints; i++)
	{
		for (int j = 0; j < nPoints; j++)
		{
			if (j != i)
			{
				num *= (pointOfInterest - dataValues[0][j]);
				den *= (dataValues[0][i] - dataValues[0][j]);
			}
		}
		L[i] = num / den;
		num = den = 1;
	}
	return L;
}
void main() {
	int nPoints = 0,index = 0;
	double pointOfInterest = 0;
	cout << "Enter number of points" << endl;
	cin >> nPoints;
	double **dataValues = new double*[2],
	*L = new double[nPoints];
	for (int i = 0; i < nPoints;i++) {
		dataValues[i] = new double[nPoints];
	}
	cout << "Enter Data Points" << endl;
	for (int i = 0; i < nPoints; i++) {
		cout << endl << "X:" << endl;
		cin >> dataValues[0][i];//input in x row
		//---------------------------------
		cout << endl << "f(x):" << endl;
		cin >> dataValues[1][i];//input in f(x) row

		cout << endl;
	}

	cout << "Enter Point of Interest" << endl;
	cin >> pointOfInterest;

	L = getL(dataValues,nPoints,pointOfInterest);

	double sum = 0;
	for (int i = 0; i < nPoints;i++) {
		sum += L[i] * dataValues[1][i];
		cout << L[i] << endl;
	}

	cout << "By using Legrange Interpolation : " <<sum<<endl;


	system("pause");
}