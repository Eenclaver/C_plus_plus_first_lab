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
	std::cout << "������ �.�. 415� ������, ������������ ������ ����� 1, ������� 12." << std::endl;
	while (globalMenu != exitMenu) {
		while (inputMenu != exitMenu) {
			std::cout << std::endl;
			std::cout << "�������� ��� ������ ������:" << std::endl << " 1)����� �������" << std::endl << " 2)����� ����" << std::endl << "��� �����:";
			userInput = Input::user_Int_Input();
			std::cout << std::endl;
			switch (userInput)
			{
			case console:
				Input::user_Console_Input(massPtr);
				inputMenu = exitMenu;
				mainMenu = 0;
				std::cout << "��������� ������ � ����?" << std::endl << " 1)��" << std::endl << " 2)���" << std::endl << "��� �����:";
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
						std::cout << "������ ������ ���." << std::endl;
						break;
					}
				}
				break;
			case file:
				std::cout << std::endl;
				erorCatcher = Input::user_File_Input(massPtr);
				if (erorCatcher == error) {
					std::cout << "������ � �����, ���������� ��� ���" << std::endl;
				}
				else {
					std::cout << "��������� ������ � ����?" << std::endl << " 1)��" << std::endl << " 2)���" << std::endl << "��� �����:";
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
							std::cout << "������ ������ ���." << std::endl;
							break;
						}
					}
					inputMenu = exitMenu;
				}
				break;
			default:
				std::cout << std::endl;
				std::cout << "������ ������ ���." << std::endl;
				break;
			}
		}
		mainMenu = 0;
		while (mainMenu != exitMenu) {
			std::cout << std::endl;
			std::cout << "�������� ��� ������ ������:" << std::endl << "1)������� ������ ������� ������� �������� ����� ������" << std::endl << "2)������� ������ �������, ������� �������� ����� ������ � ������������� �� �����, ������� ��������� � ������������ ���������� " << std::endl << "3) ������� ������ �������, ������� �������, ������������� �������� " << std::endl << "4)������ ����� �����" << std::endl << "5)��������� �����" << std::endl << "6)�����" << std::endl << "��� �����:";
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
				std::cout << "������ ������ ���." << std::endl;
				break;
			}
		}
	}
}