#include "vector.inl"
#include <conio.h>

int GetKey()
{
	int key = _getch();
	if ((key == 0) || (key == 224))
		key = _getch();
	return key;
}

int MenuInfo()
{
	system("cls");
	std::cout << "Select data type" << std::endl << std::endl;
	std::cout << "  [1] Int" << std::endl;
	std::cout << "  [2] Float" << std::endl;
	std::cout << "  [3] Double" << std::endl;
	std::cout << "  [4] Complex<Float>" << std::endl;
	std::cout << "  [5] Complex<Double>" << std::endl << std::endl;
	std::cout << "[ESC] Exit" << std::endl;
	while (true)
	{
		int key = GetKey();
		if (key == 49 || key == 50 || key == 51 || key == 52 || key == 53 || key == 27)
			return key;
	}
}

template <typename T>
void Test(Vector<T>& a, Vector<T>& b)
{
	try
	{
		system("cls");
		std::cout << "TEST: vector<" << typeid(T).name() << ">" << std::endl << std::endl;

		std::cout << "Fill vector a:" << std::endl;
		std::cin >> a;
		std::cout << std::endl << "Fill vector b:" << std::endl;
		std::cin >> b;

		system("cls");
		std::cout << "Vector a = " << a << std::endl;
		std::cout << "Vector b = " << b << std::endl << std::endl;
				
		std::cout << "Vector a : Enter index = ";
		int index = SetValue<int>();
		std::cout << "a[" << index << "] = " << a[index] << std::endl;
		std::cout << "Vector b : Enter index = ";
		index = SetValue<int>();
		std::cout << "b[" << index << "] = " << b[index] << std::endl << std::endl;
				
		std::cout << "a + b = " << a + b << std::endl;
		std::cout << "a - b = " << a - b << std::endl;
		std::cout << "a * b = " << a * b << std::endl << std::endl;
				
		std::cout << "Enter value = ";
		T value = SetValue<T>();
		std::cout << "a * " << value << " = " << a * value << std::endl;
		std::cout << value << " * b = " << value * b << std::endl;
		std::cout << "b / " << value << " = " << b / value << std::endl << std::endl;
				
		std::cout << "a == b : ";
		if (a == b)
			std::cout << "true" << std::endl;
		else
			std::cout << "false" << std::endl;

		std::cout << "a != b : ";
		if (a != b)
			std::cout << "true";
		else
			std::cout << "false";
		
		std::cout << std::endl << std::endl << "Press any button...";
		GetKey();
	}
	catch (VectorException& err)
	{
		std::cout << std::endl << std::endl << "ERROR: " << err.getError() << std::endl;
		std::cout << std::endl << "Press any button...";
		GetKey();
	}
}

int Menu()
{
	while (true)
	{
		int key = MenuInfo();
		system("cls");
		if (key == 27)
		{
			return 0;
		}
		if (key == 49 || key == 50 || key == 51 || key == 52 || key == 53)
		{
			try
			{
				std::cout << "Enter vector a size = ";
				int sizeA = SetValue<int>();
				std::cout << "Enter vector b size = ";
				int sizeB = SetValue<int>();
				if (key == 49)
				{
					Vector<int> a(sizeA), b(sizeB);
					Test(a, b);
				}
				if (key == 50)
				{
					Vector<float> a(sizeA), b(sizeB);
					Test(a, b);
				}
				if (key == 51)
				{
					Vector<double> a(sizeA), b(sizeB);
					Test(a, b);
				}
				if (key == 52)
				{
					Vector<std::complex<float>> a(sizeA), b(sizeB);
					Test(a, b);
				}
				if (key == 53)
				{
					Vector<std::complex<double>> a(sizeA), b(sizeB);
					Test(a, b);
				}
			}
			catch (VectorException & err)
			{
				std::cout << std::endl << std::endl << "ERROR: " << err.getError() << std::endl;
				std::cout << std::endl << "Press any button...";
				GetKey();
			}
		}
	}
}

int main()
{
	return Menu();
}