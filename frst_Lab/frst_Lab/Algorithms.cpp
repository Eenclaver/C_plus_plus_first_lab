#include"Algorithms.h"

namespace Checks {
	bool is_Number_Check(std::string inputData) {
		bool tmp = true;
		for (unsigned int i = 0; i < inputData.length(); i++) {
			tmp = isdigit(inputData[i]);
		}
		return tmp;
	}
	int user_Is_Number_Check(std::string inputData) {
		while (!is_Number_Check(inputData)) {
			std::cout << "Ошибка ввода" << std::endl << "Введите число:";
			std::cin >> inputData;
		}
		return stoi(inputData);
	}
	bool File_Exists(std::string fileName) {
		const char* path = fileName.c_str();
		if (!_access(path, 0))
			return true;
		else
			return false;
	}
	bool Only_Read(std::string fileName) {
		const char* path = fileName.c_str();
		if (_access(path, 2))
			return true;
		else
			return false;
	}
	int isNumberAndIsMoreThanZeroCheck() {
		std::string number;
		int tmp;
		number = std::to_string(Input::user_Int_Input());
		std::cout << std::endl;
		tmp = Checks::user_Is_Number_Check(number);
		while (tmp < 1)
		{
			std::cout << "Введите положительное число:";
			std::cin >> number;
			std::cout << std::endl;
			tmp = Checks::user_Is_Number_Check(number);
		}
		return tmp;
	}
	int complexUserDataChecker(std::string elementName,int numberOfElement) {
		std::string userData;
		int output;
		std::cout << std::endl;
		std::cout << "Введите "<< elementName << numberOfElement + 1 << " квартиры:";
		output = isNumberAndIsMoreThanZeroCheck();
		return output;
	}
}

namespace Input {
	int user_Int_Input() {
		int val = 0;
		std::cin >> val;
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			std::cout << "Некорректное значение!" << std::endl << "Введите корректное значение:";
			std::cin >> val;
		}
		std::cin.ignore(INT_MAX, '\n');
		return val;
	}
	void user_Console_Input(Array* mass) {
		std::string tmp;
		int numberOfElements=0;
		Flat userElement;
		std::cout << "Введите количество элементов:";
		numberOfElements = Checks::isNumberAndIsMoreThanZeroCheck();
		mass->Set_len(numberOfElements);
		for (int i = 0; i < numberOfElements;i++) {
			std::cout << std::endl;
			std::cout << "Введите адрес "<<i+1<< " квартиры:";
			tmp = std::to_string(user_Int_Input());
			std::cout << std::endl;
			userElement.set_Address(tmp);
			userElement.set_Floor(Checks::complexUserDataChecker("этаж ",i));
			userElement.set_Number_Of_Rooms(Checks::complexUserDataChecker("количество комнат ", i));
			userElement.set_Space(Checks::complexUserDataChecker("площадь ", i));
			mass->set_Element(userElement,i);
		}
	}
	int user_File_Input(Array* mass) {
		Flat userElement;
		std::string userData;
		int amount;
		std::ifstream fin;
		std::cout << "Введите путь: ";
		std::cin.clear();
		std::cin >> userData;
		while (!Checks::File_Exists(userData)) {
			std::cout << "Файл не существует, попробуйте ввести другой путь." << std::endl;
			std::cout << "Введите путь: ";
			std::cin >> userData;
		}

		fin.open(userData);
		fin >> amount;
		mass->Set_len(amount);
		for (int i = 0; i < amount; i++) {
			fin >> userData;
			if (userData.length() == 0) {
				return error;
			}
			userElement.set_Address(userData);

			userData.clear();
			fin >> userData;
			if (userData.length() == 0) {
				return error;
			}
			if (!Checks::is_Number_Check(userData)) {
				return error;
			}
			userElement.set_Floor(stoi(userData));

			userData.clear();
			fin >> userData;
			if (userData.length() == 0) {
				return error;
			}
			if (!Checks::is_Number_Check(userData)) {
				return error;
			}
			userElement.set_Number_Of_Rooms(stoi(userData));

			userData.clear();
			fin >> userData;
			if (userData.length() == 0) {
				return error;
			}
			if (!Checks::is_Number_Check(userData)) {
				return error;
			}
			userElement.set_Space(stoi(userData));
			userData.clear();
			mass->set_Element(userElement,i);
		}
		fin.close();
		return allGood;
	}
};

namespace Output {
	void module_Tests() {
		int testNum = 0;
		Array array;
		Flat flat;
		array.Set_len(3);
		try {

			for (int i = 0; i < 3; i++) {
				testNum = i;
				flat.set_Address("test");
				flat.set_Floor(1);
				flat.set_Number_Of_Rooms(1);
				flat.set_Space(1);
				array.set_Element(flat,i);
			}
			std::cout << "Тестирование прошло успешно.";
		}
		catch (...) {
			std::cout << "Тест номер " << testNum << std::endl;
			std::cout << "Набор данных - " << std::endl;
			for (int i = 0; i < 5; i++)
			{
				std::cout << std::endl;
				//std::cout << "Название: " << moduleMass[i].name << std::endl << moduleMass[i].size << std::endl << moduleMass[i].getTitle() << std::endl;
			}
			std::cout << "Ожидаемый результат - заполнение массива структур в классе данными." << std::endl;
			std::cout << "Полученный результат - критическая ошибка. " << std::endl;
			std::cout << "Полученный результат - критическая ошибка. " << std::endl;
		}
	}
	void massOutputRooms(Array* mass) {
		Flat tmpFlat;
		int number;
		bool bubbleIsReady=true;
		std::string tmp;
		int userInput;
		int counter = 0;
		int additionalMenu = 0;
		std::cout << "Введите число комнат:";
		number = Checks::isNumberAndIsMoreThanZeroCheck();
		for (int i = 0; i < mass->get_Len(); i++) {
			if (mass->get_Element(i).get_Number_Of_Rooms()== number) {
				counter += 1;
			}
		}
		Flat* bubleArray = new Flat[counter+1];
		for (int i = 0; i < mass->get_Len(); i++) {
			if (mass->get_Element(i).get_Number_Of_Rooms() == number) {
				bubleArray[i] = mass->get_Element(i);
			}
		}
		while (!bubbleIsReady) {
			bubbleIsReady = true;
			for (int i = 0; i < counter-1; i++)
			{
				if (bubleArray[i].get_Space() > bubleArray[i + 1].get_Space()) {
					tmpFlat = bubleArray[i];
					bubleArray[i] = bubleArray[i + 1];
					bubleArray[i + 1] = tmpFlat;
					bubbleIsReady = false;
				}
			}
		}
		counter = 0;
		for (int i = 0; i < mass->get_Len(); i++) {
			if (mass->get_Element(i).get_Number_Of_Rooms()== number) {
				std::cout << "Квартира номер:" << i+1 << std::endl;
				std::cout << "Aдрес квартиры:" << bubleArray[i].get_Address() << std::endl;
				std::cout << "Этаж  квартиры:" << bubleArray[i].get_Floor() << std::endl;
				std::cout << "Количество комнат квартиры:" << bubleArray[i].get_Number_Of_Rooms() << std::endl;
				std::cout << "Площадь квартиры:" << bubleArray[i].get_Space() << std::endl;
				counter += 1;
			}
		}
		if (counter == 0) {
			std::cout << "Квартир по вашёму запросу не найдено" << std::endl;
		}
		else {
			std::cout << "Сохранить данные в файл?" << std::endl << " 1)Да" << std::endl << " 2)Нет" << std::endl << "Ваш выбор:";
			userInput = Input::user_Int_Input();
			std::cout << std::endl;
			while (additionalMenu != exitMenu)
			{
				switch (userInput)
				{
				case yes:
					Output::save_User_Data_To_File_Rooms(mass, number);
					additionalMenu = exitMenu;
					break;
				case no:
					additionalMenu = exitMenu;
					break;
				default:
					std::cout << std::endl;
					std::cout << "Такого пункта нет." << std::endl;
					break;
				}
			}
		}
	}
	void massOutputRoomsAndFloor(Array* mass) {
		int number;
		int begining;
		int end;
		std::string tmp;
		int userInput;
		int counter = 0;
		int additionalMenu = 0;
		std::cout << "Введите число комнат:";
		number = Checks::isNumberAndIsMoreThanZeroCheck();
		std::cout << "Введите начало промежутка этажей:";
		begining = Checks::isNumberAndIsMoreThanZeroCheck();
		std::cout << "Введите конец промежутка этажей:";
		end = Checks::isNumberAndIsMoreThanZeroCheck();
		while (end <= begining) {
			std::cout << "Ошибка ввода, конец промежутка не может быть меньше чем начало"<<std::endl;
			std::cout << "Введите конец промежутка этажей:";
			end = Checks::isNumberAndIsMoreThanZeroCheck();
		}
		for (int i = 0; i < mass->get_Len(); i++) {
			if ((mass->get_Element(i).get_Number_Of_Rooms() == number)&&((mass->get_Element(i).get_Floor()>begining)&&(mass->get_Element(i).get_Floor()<end))) {
				std::cout << "Aдрес " << i + 1 << " квартиры:" << mass->get_Element(i).get_Address() << std::endl;
				std::cout << "Этаж " << i + 1 << " квартиры:" << mass->get_Element(i).get_Floor() << std::endl;
				std::cout << "Количество комнат " << i + 1 << " квартиры:" << mass->get_Element(i).get_Number_Of_Rooms() << std::endl;
				std::cout << "Площадь " << i + 1 << " квартиры:" << mass->get_Element(i).get_Space() << std::endl;
				counter += 1;
			}
		}
		if (counter == 0) {
			std::cout << "Квартир по вашёму запросу не найдено" << std::endl;
		}
		else {
			std::cout << "Сохранить данные в файл?" << std::endl << " 1)Да" << std::endl << " 2)Нет" << std::endl << "Ваш выбор:";
			userInput = Input::user_Int_Input();
			std::cout << std::endl;
			while (additionalMenu != exitMenu)
			{
				switch (userInput)
				{
				case yes:
					Output::save_User_Data_To_File_RoomsAndFloor(mass, number,begining,end);
					additionalMenu = exitMenu;
					break;
				case no:
					additionalMenu = exitMenu;
					break;
				default:
					std::cout << std::endl;
					std::cout << "Такого пункта нет." << std::endl;
					break;
				}
			}
		}
	}
	void massOutputSpace(Array* mass) {
		int number;
		std::string tmp;
		int userInput;
		int counter = 0;
		int additionalMenu = 0;
		std::cout << "Введите площадь:";
		number = Checks::isNumberAndIsMoreThanZeroCheck();
		for (int i = 0; i < mass->get_Len(); i++) {
			if (mass->get_Element(i).get_Number_Of_Rooms() > number) {
				std::cout << "Aдрес " << i + 1 << " квартиры:" << mass->get_Element(i).get_Address() << std::endl;
				std::cout << "Этаж " << i + 1 << " квартиры:" << mass->get_Element(i).get_Floor() << std::endl;
				std::cout << "Количество комнат " << i + 1 << " квартиры:" << mass->get_Element(i).get_Number_Of_Rooms() << std::endl;
				std::cout << "Площадь " << i + 1 << " квартиры:" << mass->get_Element(i).get_Space() << std::endl;
				counter += 1;
			}
		}
		if (counter == 0) {
			std::cout << "Квартир по вашёму запросу не найдено" << std::endl;
		}
		else {
			std::cout << "Сохранить данные в файл?" << std::endl << " 1)Да" << std::endl << " 2)Нет" << std::endl << "Ваш выбор:";
			userInput = Input::user_Int_Input();
			std::cout << std::endl;
			while (additionalMenu != exitMenu)
			{
				switch (userInput)
				{
				case yes:
					Output::save_User_Data_To_File_Rooms(mass, number);
					additionalMenu = exitMenu;
					break;
				case no:
					additionalMenu = exitMenu;
					break;
				default:
					std::cout << std::endl;
					std::cout << "Такого пункта нет." << std::endl;
					break;
				}
			}
		}
	}
	void save_User_Data_To_File(Array* mass) {
		int userChoice;
		std::string userData;
		std::ofstream fout;
		std::cout << "Введите путь сохранения: ";
		std::cin >> userData;
		while (Checks::File_Exists(userData)) {
			std::cout << "Файл уже существует." << std::endl << "1) Перезаписать файл." << std::endl << "2) Ввести другой путь." << std::endl;
			if (Checks::Only_Read(userData)) {
				std::cout << "Файл доступен только для чтения, автоматический переход к пункту 2." << std::endl;
				userChoice = no;
			}
			else userChoice = Input::user_Int_Input();

			if (userChoice == yes) {
				std::cout << "Файл успешно перезаписан." << std::endl;
				break;
			}

			if (userChoice == no) {
				std::cout << "Введите путь сохранения: ";
				std::cin >> userData;
			}
		}

		fout.open(userData);
		fout << mass->get_Len() << " ";
		for (int i = 0; i < mass->get_Len(); i++) {
			fout << mass->get_Element(i).get_Address() << " ";
			fout << mass->get_Element(i).get_Floor() << " ";
			fout << mass->get_Element(i).get_Number_Of_Rooms() << " ";
			fout << mass->get_Element(i).get_Space() << " ";
		}
		fout.close();
		std::cout << "Данные успешно сохранены" << std::endl;
	}
	void save_User_Data_To_File_Rooms(Array* mass,int userNumber) {
		int userChoice;
		std::string userData;
		std::ofstream fout;
		std::cout << "Введите путь сохранения: ";
		std::cin >> userData;
		while (Checks::File_Exists(userData)) {
			std::cout << "Файл уже существует." << std::endl << "1) Перезаписать файл." << std::endl << "2) Ввести другой путь." << std::endl;
			if (Checks::Only_Read(userData)) {
				std::cout << "Файл доступен только для чтения, автоматический переход к пункту 2." << std::endl;
				userChoice = no;
			}
			else userChoice = Input::user_Int_Input();

			if (userChoice == yes) {
				std::cout << "Файл успешно перезаписан." << std::endl;
				break;
			}

			if (userChoice == no) {
				std::cout << "Введите путь сохранения: ";
				std::cin >> userData;
			}
		}

		fout.open(userData);
		fout << mass->get_Len() << " ";
		for (int i = 0; i < mass->get_Len(); i++) {
			if (mass->get_Element(i).get_Number_Of_Rooms() == userNumber) {
				fout << mass->get_Element(i).get_Address() << " ";
				fout << mass->get_Element(i).get_Floor() << " ";
				fout << mass->get_Element(i).get_Number_Of_Rooms() << " ";
				fout << mass->get_Element(i).get_Space() << " ";
			}
		}
		fout.close();
		std::cout << "Данные успешно сохранены" << std::endl;
	}
	void save_User_Data_To_File_RoomsAndFloor(Array* mass, int number,int begining,int end) {
		int userChoice;
		std::string userData;
		std::ofstream fout;
		std::cout << "Введите путь сохранения: ";
		std::cin >> userData;
		while (Checks::File_Exists(userData)) {
			std::cout << "Файл уже существует." << std::endl << "1) Перезаписать файл." << std::endl << "2) Ввести другой путь." << std::endl;
			if (Checks::Only_Read(userData)) {
				std::cout << "Файл доступен только для чтения, автоматический переход к пункту 2." << std::endl;
				userChoice = no;
			}
			else userChoice = Input::user_Int_Input();

			if (userChoice == yes) {
				std::cout << "Файл успешно перезаписан." << std::endl;
				break;
			}

			if (userChoice == no) {
				std::cout << "Введите путь сохранения: ";
				std::cin >> userData;
			}
		}

		fout.open(userData);
		fout << mass->get_Len() << " ";
		for (int i = 0; i < mass->get_Len(); i++) {
			if ((mass->get_Element(i).get_Number_Of_Rooms() == number) && ((mass->get_Element(i).get_Floor() > begining) && (mass->get_Element(i).get_Floor() < end))) {
				fout << mass->get_Element(i).get_Address() << " ";
				fout << mass->get_Element(i).get_Floor() << " ";
				fout << mass->get_Element(i).get_Number_Of_Rooms() << " ";
				fout << mass->get_Element(i).get_Space() << " ";
			}
		}
		fout.close();
		std::cout << "Данные успешно сохранены" << std::endl;
	}
	void save_User_Data_To_File_Space(Array* mass, int userNumber) {
		int userChoice;
		std::string userData;
		std::ofstream fout;
		std::cout << "Введите путь сохранения: ";
		std::cin >> userData;
		while (Checks::File_Exists(userData)) {
			std::cout << "Файл уже существует." << std::endl << "1) Перезаписать файл." << std::endl << "2) Ввести другой путь." << std::endl;
			if (Checks::Only_Read(userData)) {
				std::cout << "Файл доступен только для чтения, автоматический переход к пункту 2." << std::endl;
				userChoice = no;
			}
			else userChoice = Input::user_Int_Input();

			if (userChoice == yes) {
				std::cout << "Файл успешно перезаписан." << std::endl;
				break;
			}

			if (userChoice == no) {
				std::cout << "Введите путь сохранения: ";
				std::cin >> userData;
			}
		}

		fout.open(userData);
		fout << mass->get_Len() << " ";
		for (int i = 0; i < mass->get_Len(); i++) {
			if (mass->get_Element(i).get_Number_Of_Rooms() > userNumber) {
				fout << mass->get_Element(i).get_Address() << " ";
				fout << mass->get_Element(i).get_Floor() << " ";
				fout << mass->get_Element(i).get_Number_Of_Rooms() << " ";
				fout << mass->get_Element(i).get_Space() << " ";
			}
		}
		fout.close();
		std::cout << "Данные успешно сохранены" << std::endl;
	}
}