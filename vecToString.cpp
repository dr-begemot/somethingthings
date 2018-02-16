#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

template<typename InIt, typename OutIt>
bool MakeList1(
	 InIt begin,
	 InIt end,
	 int max_size,
	 OutIt output,
	 char delimeter = ','
	) {
		using namespace std;
		static const auto kDelimeterSize = 1;
		if (begin == end) return false;
		vector<string> result(1);
		auto current = result.rbegin();
		int delimeter_factor = 0;
		for(auto i = begin; i != end; ++i) {
			auto item_size = (*i).size();
			if (item_size > max_size) {
			  return false;
			}
			if (((*current).size() + item_size + delimeter_factor*kDelimeterSize > max_size)) {
			    result.emplace_back("");
			    current = result.rbegin();
			    delimeter_factor = 0;
			}
			if (delimeter_factor) {
			   *current += delimeter;
			}
		            *current  += (*i);
		            delimeter_factor = 1;
		}
		std::copy(result.begin(), result.end(), output);
		return true;
		
	}
	
	template<typename InIt, typename OutIt>
bool MakeList2(
	 InIt begin,
	 InIt end,
	 int max_size,
	 OutIt output,
	 char delimeter = ','
	) {

		using namespace std;
		static const auto kDelimeterSize = 1;
		if (begin == end) return false;
		bool new_bucket = true;
		vector<string> result(1);
		auto current = result.rbegin();
		for(auto i = begin; i != end; ++i) {
			auto item_size = (*i).size();
			if (item_size > max_size) {
			  return false;
			}
			if (!new_bucket && ((*current).size() + item_size + kDelimeterSize > max_size)) {
			    result.emplace_back("");
			    current = result.rbegin();
			    new_bucket = true;
			}
			if (!new_bucket) {
			   *current += delimeter;
			}
		            *current  += (*i);
			new_bucket = false;
		}
		std::copy(result.begin(), result.end(), output);
		return true;
	}
	
	
    /* Bug! No empty lines in output
	template<typename InIt, typename OutIt>
bool MakeList3(
	 InIt begin,
	 InIt end,
	 int max_size,
	 OutIt output,
	 char delimeter = ','
	) {
		using namespace std;
		static const auto kDelimeterSize = 1;
		if (begin == end) return false;
		vector<string> result(1);
		auto current = &result.back();
		for(auto i = begin; i != end; ++i) {
			auto item_size = (*i).size();
			if (item_size > max_size) {
			  return false;
			}
			if ((*current).size() && ((*current).size() + item_size + kDelimeterSize > max_size)) {
			  result.emplace_back("");
			  current = &result.back();
			}
			if (!(*current).empty()) {
			  *current += delimeter;
			}
			*current  += (*i);
		}
		std::copy(result.begin(), result.end(), output);
		return true;
	}*/

int main() {
	// your code goes here
	std::vector<std::string> vec1 = {"foo", "bar", "tar"};
	std::vector<std::string> vec2 = {"foo", "bar", "tar", "foobar", "carzar"};
	std::vector<std::string> vec = {"aaa", "bbb","b", "bb4", "c2", "c", "d", "e"};
	std::vector<std::string> l, l2, l3, l4;
	const int max_size = 3; 

	std::cout << "\n=======================================================\n";
	std::vector<std::string> l11, l22, l33, l44;
	bool res = MakeList4(vec.begin(), vec.end(), max_size, std::back_inserter(l11));
	std::cout << "result: " << std::string(res?"ok":"fail") << "\n";
	for(auto i : l11) {
	  std::cout << i <<" : ";
	}
	res = MakeList4(vec1.begin(), vec1.end(), max_size, std::back_inserter(l22));
	std::cout << "\nresult: " << std::string(res?"ok":"fail") << "\n";
	for(auto i : l22) {
	  std::cout << i <<" : ";
	}
	res = MakeList4(vec2.begin(), vec2.end(), 7, std::back_inserter(l33));
	std::cout << "\nresult: " << std::string(res?"ok":"fail") << "\n";
	for(auto i : l33) {
	  std::cout << i <<" : ";
	}
	
	return 0;
}