#include"Algorithms.h"

void user_Menu() {
	setlocale(LC_ALL, "Russian");
	Array mass;
	Array* massPtr = &mass;
	int userInput = 0;
	int inputMenu = 0;
	int mainMenu = 0;
	int globalMenu = 0;
	int additionalMenu = 0;
	int erorCatcher;
	std::cout << "Сошнев А.В. 415а группа, лабораторная работа номер 1, вариант 12." << std::endl;
	while (globalMenu != exitMenu) {
		while (inputMenu != exitMenu) {
			std::cout << std::endl;
			std::cout << "Выберете как ввести данные:" << std::endl << " 1)Через консоль" << std::endl << " 2)Через файл" << std::endl << "Ваш выбор:";
			userInput = Input::user_Int_Input();
			std::cout << std::endl;
			switch (userInput)
			{
			case console:
				Input::user_Console_Input(massPtr);
				inputMenu = exitMenu;
				mainMenu = 0;
				std::cout << "Сохранить данные в файл?" << std::endl << " 1)Да" << std::endl << " 2)Нет" << std::endl << "Ваш выбор:";
				userInput = Input::user_Int_Input();
				std::cout << std::endl;
				while (additionalMenu != exitMenu)
				{
					switch (userInput)
					{
					case yes:
						Output::save_User_Data_To_File(massPtr);
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
				break;
			case file:
				std::cout << std::endl;
				erorCatcher = Input::user_File_Input(massPtr);
				if (erorCatcher == error) {
					std::cout << "Ошибка в файле, попробуйте ещё раз" << std::endl;
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
							Output::save_User_Data_To_File(massPtr);
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
					inputMenu = exitMenu;
				}
				break;
			default:
				std::cout << std::endl;
				std::cout << "Такого пункта нет." << std::endl;
				break;
			}
		}
		mainMenu = 0;
		while (mainMenu != exitMenu) {
			std::cout << std::endl;
			std::cout << "Выберете что делать дальше:" << std::endl << "1)Вывести список квартир имеющих заданное число комнат" << std::endl << "2)Вывести список квартир, имеющих заданное число комнат и расположенных на этаже, который находится в определенном промежутке " << std::endl << "3) Вывести список квартир, имеющих площадь, превосходящую заданную " << std::endl << "4)Ввести новые даные" << std::endl << "5)Модульные тесты" << std::endl << "6)Выход" << std::endl << "Ваш выбор:";
			userInput = Input::user_Int_Input();
			std::cout << std::endl;
			switch (userInput)
			{
			case massOutputRooms:
				Output::massOutputRooms(massPtr);
				break;
			case massOutputRoomsAndFloor:
				Output::massOutputRoomsAndFloor(massPtr);
				break;
			case massOutputSpace:
				Output::massOutputSpace(massPtr);
				break;
			case newData:
				inputMenu = 0;
				mainMenu = exitMenu;
				break;
			case moduleTests:
				Output::module_Tests();
				break;
			case exitMenu:
				mainMenu = exitMenu;
				globalMenu = exitMenu;
				break;
			default:
				std::cout << std::endl;
				std::cout << "Такого пункта нет." << std::endl;
				break;
			}
		}
	}
}