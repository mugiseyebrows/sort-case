#include <vector>
#include <iostream>
#include <algorithm>

class Bool {
public:
    Bool(bool value = false) : value(value) {

    }
    bool value;
};

int main(int argc, char *argv[])
{
    std::vector<bool> values = {
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, true, true, false, false, false
    };

    std::vector<Bool> bools;
    for(bool value: values) {
        bools.push_back(Bool(value));
    }

    auto cmpAsc = [](const Bool& a, const Bool& b) {
        return a.value < b.value;
    };

    auto cmpDesc = [&](const Bool& a, const Bool& b){
        return !cmpAsc(a, b);
    };

    std::sort(bools.begin(), bools.end(), cmpDesc);

    std::cout << bools[0].value << "\n";

    return 0;
}
