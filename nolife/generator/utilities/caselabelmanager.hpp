#include <string>

class CaseLabelManager {
    public: CaseLabelManager();
        std::string generateLabel();
        void newCase();
        std::string getEnd();
    private:
        uint mNextIDNumber;
        uint mNextSubIDNumber;
};
