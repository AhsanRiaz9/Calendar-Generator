#include<iostream>
using namespace std;
void displayMonth(int array[][7], int row, int col);
bool isLeapYear(int year);
void displayCalender(int array[][7],int startWeekDay, int totalMonthDays[], int row, int col);
void fillSpaces(int array[][7], int row, int col);
void displayMonthName(int month);
int generateStartWeekDay(int year);
char months_names[12][30] = {"January","Faburary","March","April","March","May","June","July","August","October","November","December"};
int main()
{
	int array[6][7];
	int year,startWeekDay;
	cout << "Enter Year:\t";
	cin >> year;
	startWeekDay=generateStartWeekDay(year);
	int totalMonthDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	if (isLeapYear(year))
	{
		totalMonthDays[1] = 29;
	}
	displayCalender(array,startWeekDay,totalMonthDays, 6, 7);
}
bool isLeapYear(int year)
{
	if((year % 4== 0 && year%100) || year%400==0) // note leap year is year which divisible by 400 and 4 and not by 100
	{
		return true;
	}
	else
	{
		return false;
	}
}
int generateStartWeekDay(int year)
{
	int startYear, startWeekDay;
	startYear = 1947; // starting year where you want to set calendar year donot change it
	startWeekDay = 3; // 1 january of the year 1947,if you change this then calender will not give write output
	int inc = 0;
	for (int i = startYear; i < year; i = i + 1)
	{
		if (isLeapYear(i) == true)
		{
			inc = inc + 2;
		}
		else
		{
			inc = inc + 1;
		}
	}
	startWeekDay = (startWeekDay + inc) % 7;
	if (startWeekDay == 0)
	{
		startWeekDay = 7;
	}
	return startWeekDay;
}
void displayCalender(int array[][7], int startWeekDay,int totalMonthDays[], int row, int col)
{
	int month = 0;
	int day;
	for(int month=0;month < 12;month=month+1)
	{
		displayMonthName(month);
		fillSpaces(array, row, col);
		day = 1;
		for (int i = startWeekDay - 1; i < col; i = i + 1)
		{
			array[0][i] = day;
			day = day + 1;
		}
		int i = 1;
		int j;
		while (i < row && day <= totalMonthDays[month])
		{
			j = 0;
			while (j < col && day <= totalMonthDays[month])
			{
				array[i][j] = day;
				day = day + 1;
				j = j + 1;
			}
			i = i + 1;
		}
		startWeekDay = j+1;
		if (startWeekDay == 8)
		{
			startWeekDay = 1;
		}
		cout << "\n";
		displayMonth(array, row, col);
	}
}
void fillSpaces(int array[][7], int row, int col)
{
	for (int i = 0; i < row; i = i + 1)
	{
		for (int j = 0; j < col; j = j + 1)
		{
			array[i][j] = ' ';
		}
	}
}
void displayMonthName(int month)
{
	cout<<"\n\t\t\t"<<months_names[month]<<'\n';
}
void displayMonth(int array[][7], int row, int col)
{
	cout << "\tMon\tTu\tWed\tThur\tFri\tSat\tSun\n";
	for (int i = 0; i < row; i = i + 1)
	{
		cout<<'\t';
		for (int j = 0; j < col; j = j + 1)
		{
			if (array[i][j] == ' ')
			{
				cout << (char)array[i][j] << '\t';
			}
			else
			{
				cout << array[i][j] << "\t";
			}
		}
		cout << '\n';
	}
}
