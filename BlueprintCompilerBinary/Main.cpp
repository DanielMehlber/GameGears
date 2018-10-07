#include "GearCompiler.h"

int main(int argc, char** argv) {
	if (argc != 3) {
		std::cerr << "args: [sk-file-location] [cr-destination-file]" << std::endl;
		std::system("PAUSE");
		return -1;
	}

	std::string src_loc(argv[1]);
	std::string dest_loc(argv[2]);

	std::string src = Blueprint(src_loc).getSource();
	if (src.empty())
		return -1;

	std::cout << "Compiler started..." << std::endl;

	GearCompiler compiler = GearCompiler(src);
	compiler.compile(dest_loc);
}