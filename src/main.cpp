#include "main.h"

int main(int argc, char* argv[]) {
#if _OPENMP
	std::cout << "δ�����Զ����У�" << std::endl;
#else
	std::cout << "�������Զ����У�" << std::endl;
#endif

	std::cout << "��������������������Ŀ¼������ֱ�Ӱ��»س�����Ĭ��ΪC:/CloudMusic��" << std::endl;
	char buffer[100] = { 0 };
	std::cin.get(buffer, 100);
	std::string input = buffer;
	input = input == "" ? "C:/CloudMusic" : input;
	std::cout << "��ѡ���Ŀ¼Ϊ��" << input << std::endl;

	std::filesystem::path path(input);
	if (!exists(path)) {
		std::cout << "·�������ڣ�" << input << std::endl;
		return 1;
	}
	else {
		std::filesystem::directory_entry entry(path);
		if (entry.status().type() != std::filesystem::file_type::directory) {
			std::cout << "��·���ǲ�һ��Ŀ¼��" << std::endl;
			return 2;
		}
		else {
			std::filesystem::directory_iterator list(path);
			visite_dir(list);
		}
	}

	std::system("pause");
	return 0;
}