#include<bits/stdc++.h>
using namespace std;

//THIS CODE ONLY ENCRYPTS THE GIVEN PLAIN TEXT BASED ON KEY USING REQUIRED ALGORITHMS

void caserCipher(string str, int key)
{
	int convert;
	int len = str.length();  //finding length of plain text.
	for (int i = 0; i < len; i++)
	{
		str [i] = tolower(str[i]);		// converting to lowercase.
		convert = int(str[i]) + key - 97; // according to ASCII small letters starts from 97 so, I subtracted 97 to start from 0.
		convert = convert % 26;
		str[i] = char(convert + 97);
	}
	cout << endl;
	cout << "The cipher text = ";
	cout << str << endl << endl; //printing the encoded string.
}


void vignereCipher(string str, string strkey)
{
	int l1 = str.length(), l2 = strkey.length();  // finding the lengths of plan text and key.
	if (l2 < l1)				 // if plaintext length > key length then modifying the key string.
	{
		strkey.resize(l1);
		for (int i = l2; i < l1; i++) strkey[i] = strkey[i - l2];
	}
	int convert;
	for (int i = 0; i < l1; i++)
	{
		str [i] = tolower(str[i]);			//converting to lowercase.
		strkey[i] = tolower(strkey[i]);		//converting to lowercase.
		convert = int(str[i]) + int(strkey[i]) - 194;	// encoding each char from plaintext and key. Subtracted 97 two times due ASCII value.
		convert = convert % 26;
		str[i] = char(convert + 97);
	}
	cout << endl;
	cout << "The cipher text = ";
	cout << str << endl << endl;			//printing the encoded string.
}

void railFenceCipher(string str, int key)
{
	int len = str.length();
	int column_size, k;

	if (len % key == 0) column_size = len / key;	// calculating no.of columns should be present in matrix.
	else column_size = (len / key) + 1;

	char a[key][column_size];		// matrix with key rows and column_size columns.
	k = 0;
	for (int i = 0; i < column_size; i++)
	{
		for (int j = 0; j < key; j++)
		{
			if (k > len - 1) a[j][i] = '0';
			else
			{
				a[j][i] = str[k];	// storing the chars in the matrix in each column from the plain text.
				k++;
			}
		}
	}
	k = 0;
	for (int i = 0; i < key; i++)
	{
		for (int j = 0; j < column_size; j++)
		{
			if (a[i][j] == '0') continue;
			else
			{
				str[k]	= a[i][j];		// shifting all chars from matrix to string in required order.
				k++;
			}
		}
	}
	cout << endl;
	cout << "The cipher text = ";
	cout << str << endl << endl;		//printing the encoded string.
}






void affineCipher(string pt, int k1, int k2)	//affinecipher algorithm
{
	int len = pt.length();		// calculating length of plaintext
	int i = 0;
	string out = "", c = "";
	while (len > 0)
	{
		int s = (((int(pt[i]) - 97) * k1) + k2) % 26 + 97;	// calculating the cipher value of each character
		c = char(s);				// converting the cipher value into character and storing into string
		out.append(c);			//appending the cipher chars into out string
		i++;
		len--;
	}
	cout << endl;
	cout << "The cipher text = ";
	cout << out << endl << endl;		//printing the out string (cipher text)
}


void hillCipher(string pt, string key)		//HillCipher encryption
{
	int len1 = key.length(), len2 = pt.length();		// finding the length of key and plaintext
	int n = sqrt(len1);
	int a[n][n];							// matrix to store key

	int count = 0;
	while (len2 % n != 0 )
	{
		pt.append("x");				// adding 'x' at the end of the plaintext if it is necessary
		len2++;
	}
	int k1 = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = int(key[k1]) - 97;		//inserting values into the key matrix
			k1++;
		}
	}
	int c = 0, c1 = len2;
	if (n == len2) c = 1;
	else if (n < len2)
	{
		while (c1 > 0)
		{
			c++;	//calculating how many times plaintext matrix should be multiplied with key matrix
			c1 = c1 - n;
		}
	}
	int k = 0;
	string k2 = "";
	while (c > 0)		// executing the loop based on length of plaintext and key
	{
		int p[n];
		for (int i = 0; i < n; i++)
		{
			p[i] = int(pt[k]) - 97;	//each tim inserting n values into the matrix to calculate cipher text
			k++;
		}
		int sum, r[n];
		for (int i = 0; i < n; i++)
		{
			sum = 0;
			for (int j = 0; j < n; j++)
			{
				sum = sum + a[i][j] * p[j];		//multiplying key matrix and plaintext matrix
			}
			r[i] = sum;
		}
		string out = "";
		for (int i = 0; i < n; i++)
		{
			out = char((r[i] % 26) + 97);		// calculating the cipher text from plaintext matrix
			k2.append(out);	// appending parts of cipher text to form full cipher text
		}
		c--;
	}
	cout << endl;
	cout << "The cipher text = ";
	cout << k2 << endl << endl;				// finally printing the cipher text
}






int gcd(int a, int m)			//calculating GCD for multiplicative inverse
{
	if (a % m == 1) return 1;		//if GCD =1 retrun 1
	else if (a % m == 0) return 0;	// else return 0

	gcd(m, a % m);					//GCD recursive all
}

void multiplicativeInverse(int a, int m)	//Multiplicative inverse calculator
{
	int g = gcd(a, m);			//calling gcd function to check the gcd is 1 or not
	if (g == 1)
	{
		for (int i = 1; i < m; i++)
		{
			if ((a * i) % m == 1)		// calculating the multiplicative inverse
			{
				cout << endl;
				cout << "Multiplicative inverse = " << i << endl << endl;	//printing the multplicative inverse if exist
				break;
			}
		}
	}
	else cout << "Multiplicative inverse Does not exist" << endl;
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int choice;
	while (1)
	{
		string plain_text;
		int key, a, m, key1;
		string strkey;
		cout << "1) Caser Cipher\n";
		cout << "2) Vignere Cipher\n";
		cout << "3) Rail-Fence Cipher\n";
		cout << "4) Affine Cipher\n";
		cout << "5) Hill Cipher\n";
		cout << "6) Multiplicative Inverse\n";
		cout << "7) Exit\n";

		cout << "Select one technique to encode the data = ";
		cin >> choice;



		switch (choice)
		{
		case 1:
			cout << "Enter the plain text to proceed = ";
			cin >> plain_text;
			cout << "Enter the key = ";
			cin >> key;
			caserCipher(plain_text, key);
			break;
		case 2:
			cout << "Enter the plain text to proceed = ";
			cin >> plain_text;
			cout << "Enter the key = ";
			cin >> strkey;
			vignereCipher(plain_text, strkey);
			break;
		case 3:
			cout << "Enter the plain text to proceed = ";
			cin >> plain_text;
			cout << "Enter the key = ";
			cin >> key;
			railFenceCipher(plain_text, key);
			break;
		case 4:
			cout << "Enter the plain text to proceed = ";
			cin >> plain_text;
			cout << "First key value = ";
			cin >> key;
			cout << "Second key value = ";
			cin >> key1;
			affineCipher(plain_text, key, key1);
			break;
		case 5:
			cout << "Enter the plain text to proceed = ";
			cin >> plain_text;
			cout << "Enter the key = ";
			cin >> strkey;
			hillCipher(plain_text, strkey);
			break;
		case 6:
			cout << "Enter the number to find multiplicative inverse = ";
			cin >> a;
			cout << "Enter the range = ";
			cin >> m;
			multiplicativeInverse(a, m);
			break;
		case 7:
			exit(1);
		default:
			cout << "Invalid\n";
			break;
		}
	}
}
