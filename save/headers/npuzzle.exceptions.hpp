#ifndef NPUZZLE_EXCEPTIONS
# define NPUZZLE_EXCEPTIONS

class Usage : public std::exception {
public:
	virtual const char 	* what() const throw() {
		return "Usage: ./npuzzle <map_file.txt>";
	}
};

class FileNotExist : public std::exception {
public:
	virtual const char 	* what() const throw() {
		return "\033[31mError: No such file\033[0m";
	}
};

class SizeError : public std::exception {
public:
	virtual const char 	* what() const throw() {
		return "\033[31mError: Size can't be less than 3\033[0m";
	}
};


#endif
