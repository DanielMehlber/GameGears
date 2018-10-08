#include "GearCompiler.h"



GearCompiler::GearCompiler(std::string source)
{
	this->sk = source;
}


GearCompiler::~GearCompiler()
{
}

bool startsWith(std::string mainStr, std::string toMatch)
{
	// std::string::find returns 0 if toMatch is found at starting
	if (mainStr.find(toMatch) == 0)
		return true;
	else
		return false;
}

std::vector<std::string> split(std::string str, char delimiter) {
	std::vector<std::string> internal;
	std::stringstream ss(str); // Turn the string into a stream.
	std::string tok;

	while (std::getline(ss, tok, delimiter)) {
		internal.push_back(tok);
	}

	return internal;
}

enum Linetype {OBJECT, ATTRIBUTE, TAG};
enum Tag {CREATE, PULL, EDIT};

struct Context {
	Linetype linetype;
	Tag global_tag;
	Tag local_tag;
	std::string local_tag_attrib;
	std::string global_tag_attrib;
};


int GearCompiler::compile(std::string dest)
{
	std::ofstream out(dest);

	current = {};
	std::istringstream source(sk);
	Context context;
	std::string line;
	int _line = 0;
	while (std::getline(source, line)) {
		_line++;
		//context
		if (startsWith(line, "\t") && line.find("=")) {
			context.linetype = ATTRIBUTE;
		}
		else if (!startsWith(line, "\t")) {
			//is local tag
			if (startsWith(line, "@")) {
				//which one?
				std::vector<std::string> elems = split(line, ' ');
				if (startsWith(elems[0], "@create")) {
					context.local_tag = Tag::CREATE;
				}
				else if (startsWith(elems[0], "@pull")) {
					context.local_tag = Tag::PULL;
					if (elems.size() != 2) {
						GearOut::err(_line, "local tag argument count. Missing or too many args.");
						return -1;
					}
					context.local_tag_attrib = elems[1];
				}
				else if (startsWith(elems[1], "@edit")) {
					context.local_tag = Tag::EDIT;
				}
				else {
					GearOut::err(_line, "Unkown Local Tag");
					return -1;
				}

			}
			//is global tag
			else if (startsWith(line, "$")) {
				//which one?
				std::vector<std::string> elems = split(line, ' ');
				if (startsWith(elems[0], "$create")) {
					context.global_tag = Tag::CREATE;
				}
				else if (startsWith(elems[0], "$pull")) {
					context.global_tag = Tag::PULL;
					if (elems.size() != 2) {
						GearOut::err(_line, "global tag argument count. Missing or too many args");
						return -1;
					}
					context.global_tag_attrib = elems[1];
				}
			}
		}
	}
}

