#ifndef BYTE_MANAGER_H
#define BYTE_MANAGER_H

#include <Constants.h>

class ByteManager {

    private:
        int currNumber;

        int activatedBytes[NB_OF_BUTTONS];
        void initActivatedBytes();

    public:
        ByteManager();

        void generateNewNumber();
        int getCurrNumber();
        void handleButtonClicked(int byte, int btnLedPosition);
};

#endif // BYTE_MANAGER_H