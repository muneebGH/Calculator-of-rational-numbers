#include"pch.h"
#include<iostream>
#include"structTask2.h"
using namespace std;




int main()
{
	Rational Number1, Number2;
	inputRational(Number1);
	inputRational(Number2);
	//add rational 
	//Rational Add= addRational( Number_1,Number_2);
	//printRational(Add);

	//diffRational 
	//Rational Diff= diffRational(Number_1,Number_2);
	//printRational(Diff);

	//div rational
	//Rational Div=divRational(Number_1,Number_2);
	//printRational(Diff);




	
}

void inputRational(Rational & StructIn) 
{
	
	
	cout << "enter the numerator :  ";
	cin>>StructIn.numerator;
	
		cout << " enter the denominator : ";
		do
		{
			cin >> StructIn.denominator;
		}
			while (StructIn.denominator == 0);


}

void printRational(Rational & StructOut) 
{
	cout << StructOut.numerator;
		if (StructOut.denominator > 1) 
		{
				cout << "/" << StructOut.denominator;
		}

}

Rational addRational(Rational A, Rational B) 
{

	int LCM = getLCM(A.denominator, B.denominator);
	
	Rational C;
	C.denominator = LCM;
	
	int num1, num2;
	num1 = LCM / A.denominator;
	
	A.numerator = A.numerator*num1;
	
	num2 = LCM / B.denominator;
	B.numerator = num2 * B.numerator;
	
	C.numerator = A.numerator + B.numerator;
	reduce(&C);



	return C;
	

}

Rational diffRational(Rational A, Rational B) 
{
	int LCM = getLCM(A.denominator, B.denominator);

	Rational C;
	C.denominator = LCM;

	int num1, num2;
	num1 = LCM / A.denominator;

	A.numerator = A.numerator*num1;

	num2 = LCM / B.denominator;
	B.numerator = num2 * B.numerator;

	C.numerator = A.numerator - B.numerator;
	reduce(&C);
	return C;

}

Rational divRational(Rational A, Rational B) 
{
	Rational C;

	int temp = 0;
	temp = B.numerator;
	B.numerator = B.denominator;
	B.denominator = temp;
	C.numerator = A.numerator*B.numerator;
	C.denominator = A.denominator*B.denominator;
	reduce(&C);
	return C;
}
int * getPrimeFactors(int num,int & totalFactors) 
{
    totalFactors = 0;
	int toDivide = 2;
	int * factors = new int[30];
	for (int i = 0; i < 30; i++)
	{
		factors[i] = 0;
	}
	int k = 0;
	while (num != 1) 
	{

		for (int i = 0; i < 9; i++)
		{
			if ((num%toDivide) == 0)
			{
				num = num / toDivide;
				factors[k] = toDivide;
				k++;
				toDivide = 2;
				totalFactors = totalFactors + 1;
				break;
			}
			else
			{
				toDivide = toDivide + 1;
			}
		}
	}
	return factors;
}

int getLCM(int num1, int num2) {


	int sizeA = 0;
	int sizeB = 0;
	int * a = getPrimeFactors(num1, sizeA);

	int * b = getPrimeFactors(num2, sizeB);
	int tempCounter = 0;
	int LCM = 1;
	for (int i = 0; i < sizeA; i=i+1) 
	{
		for (int j = 0; j < sizeB; j = j + 1)
		{
			if ((a[i] == b[j]) && a[i]!=0 )
			{
				LCM = LCM * a[i];
				a[i] = 0;
				b[j] = 0;
			}
		}
	}
	for (int i = 0; i < sizeA; i++)
	{
		if (a[i] != 0) 
		{
			LCM = LCM * a[i];
		}
	}

	for (int i = 0; i < sizeB; i++)
	{
		if (b[i] != 0) 
		{
			LCM = LCM * b[i];
		}
	}
	
	return LCM;
}


void reduce(Rational * A) 
{
	int toDivide = 2;
	if ((A->numerator) % (A->denominator) == 0)
	{
		A->numerator = A->numerator / A->denominator;
		A->denominator = 1;
	}
	else if ((A->denominator) % (A->numerator) == 0) 
	{
		A->denominator = A->denominator / A->numerator;
		A->numerator = 1;
	}
	while (toDivide <= A->numerator && toDivide <= A->denominator)
	{
		if ((A->numerator) % toDivide == 0 && (A->denominator) % toDivide == 0)
		{
			A->numerator = A->numerator / toDivide;
			A->denominator = A->denominator / toDivide;
			toDivide = 2;
		}
		else
		{
			toDivide = toDivide + 1;
		}
	}


}