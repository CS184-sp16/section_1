#include <vector>
#include <string>

namespace GrafixRules {

class Printer {
public:
    Printer(): left_bound(-1.f), right_bound(1.f) { }

    Printer(float l, float r): left_bound(l), right_bound(r) { }
    
    ~Printer() { }

    void graph(float x);

protected:
    // Always use protection

private:
    float left_bound, right_bound;

    void print(int n);

};

}