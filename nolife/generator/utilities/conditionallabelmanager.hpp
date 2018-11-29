#include <string>

class ConditionalLabelManager {
    public: ConditionalLabelManager();
        struct LabelTriple {
            LabelTriple(std::string a, std::string b, std::string c);
            std::string labelTrue;
            std::string labelFalse;
            std::string labelEnd;
        };
        
        ConditionalLabelManager::LabelTriple generateLabelTriple();
    private:
        uint mNextIDNumber;
};
