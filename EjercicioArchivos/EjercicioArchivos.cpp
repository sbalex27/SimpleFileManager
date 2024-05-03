#include <iostream>
#include <string>
#include <fstream>

constexpr auto DATA_DIRECTORY = "C:\\Users\\alex2\\cpp\\";

using namespace std;

struct Recipt
{
	string CorrelativeNumber;
	string Description;
	string Price;
	string signature;
};

string random_string() {
	string random_string = "";
	for (int i = 0; i < 10; i++) {
		random_string += (char)(rand() % 26 + 65);
	}
	return random_string;
}

static void save_receipt(Recipt receipt) {
	string file_name = DATA_DIRECTORY + random_string() + ".txt";
	ofstream file(file_name);
	if (file.is_open()) {
		file << "NUMERO DE CORRELATIVO: " << receipt.CorrelativeNumber << endl;
		file << "DESCRIPCION: " << receipt.Description << endl;
		file << "PRECIO: " << receipt.Price << endl;
		file << "FIRMA: " << receipt.signature << endl;
		file.close();
	}
	else {
		cout << "NO SE PUDO CREAR EL ARCHIVO " << endl;
	}
}

static Recipt read_receipt(string unique_identificator) {
	Recipt receipt;
	string file_name = DATA_DIRECTORY + unique_identificator + ".txt";
	ifstream file(file_name);
	if (file.is_open()) {
		string line;
		getline(file, line);
		receipt.CorrelativeNumber = line.substr(line.find(":") + 2);
		getline(file, line);
		receipt.Description = line.substr(line.find(":") + 2);
		getline(file, line);
		receipt.Price = line.substr(line.find(":") + 2);
		getline(file, line);
		receipt.signature = line.substr(line.find(":") + 2);
		file.close();
	}
	else {
		cout << "NO SE PUDO LEER EL ARCHIVO" << endl;
	}
	return receipt;
}

static void delete_receipt(string correlative_number) {
	string file_name = DATA_DIRECTORY + correlative_number + ".txt";
	if (remove(file_name.c_str()) != 0) {
		cout << "NO SE PUDO ELIMINAR EL ARCHIVO" << endl;
	}
	else {
		cout << "ARCHIVO BORRADO" << endl;
	}
}

int main()
{
	int option;

	do
	{
		cout << "MENU" << endl;
		cout << "1. Crear recibo" << endl;
		cout << "2. Leer recibo" << endl;
		cout << "3. Eliminar recibo" << endl;


		cout << "Ingrese una opcion: ";
		cin >> option;

		switch (option)
		{
		case 1:
		{
			Recipt receipt;
			cout << "Ingrese el numero de correlativo: ";
			cin >> receipt.CorrelativeNumber;
			cout << "Ingrese la descripcion: ";
			cin >> receipt.Description;
			cout << "Ingrese el precio: ";
			cin >> receipt.Price;
			cout << "Ingrese la firma: ";
			cin >> receipt.signature;
			save_receipt(receipt);
			break;
		}
		case 2:
		{
			string unique_identificator;
			cout << "Ingrese el identificador: ";
			cin >> unique_identificator;
			Recipt receipt = read_receipt(unique_identificator);
			cout << "NUMERO DE CORRELATIVO: " << receipt.CorrelativeNumber << endl;
			cout << "DESCRIPCION: " << receipt.Description << endl;
			cout << "PRECIO: " << receipt.Price << endl;
			cout << "FIRMA: " << receipt.signature << endl;
			break;
		}
		case 3:
		{
			string correlative_number;
			cout << "Ingrese el identificador: ";
			cin >> correlative_number;
			delete_receipt(correlative_number);
			break;
		}
		default:
			break;
		}
	} while (option != 0);
	return 0;
}
